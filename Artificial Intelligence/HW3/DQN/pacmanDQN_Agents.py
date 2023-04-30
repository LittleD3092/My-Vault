# import pacman game 
from pacman import Directions
from pacmanUtils import *
from game import Agent
import game

# import torch library
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from DQN import *

#import other libraries
import os
import util
import random
import numpy as np
import time
import sys

from time import gmtime, strftime
from collections import deque

# model parameters
model_trained = True

GAMMA = 0.95  # discount factor
LR = 0.01     # learning rate

batch_size = 32            # memory replay batch size
memory_size = 50000		   # memory replay size
start_training = 300 	   # start training at this episode
TARGET_REPLACE_ITER = 100  # update network step

epsilon_final = 0.1   # epsilon final
epsilon_step = 7500
    
class PacmanDQN(PacmanUtils):
    def __init__(self, args):        
		
        print("Started Pacman DQN algorithm")
        if(model_trained == True):
            print("Model has been trained")
        else:
            print("Training model")

        # pytorch parameters
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

		# init model
        if(model_trained == True):
            self.policy_net = torch.load('pacman_policy_net.pt').to(self.device)
            self.target_net = torch.load('pacman_target_net.pt').to(self.device)
        else:
            self.policy_net = DQN().to(self.device)
            self.target_net = DQN().to(self.device)
		
        self.policy_net.double()
        self.target_net.double()        
        
        # init optim
        self.optim = torch.optim.RMSprop(self.policy_net.parameters(), lr=0.00025, alpha=0.95, eps=0.01)
        
        # init counters
        self.counter = 0
        self.win_counter = 0
        self.memory_counter = 0
        self.local_cnt = 0

        if(model_trained == False):
            self.epsilon = 0.5     # epsilon init value
    
        else:
            self.epsilon = 0.0     # epsilon init value

        # init parameters
        self.width = args['width']
        self.height = args['height']
        self.num_training = args['numTraining']
        
        # statistics
        self.episode_number = 0
        self.last_score = 0
        self.last_reward = 0.
        
		# memory replay and score databases
        self.replay_mem = deque()
        
		# Q(s, a)
        self.Q_global = []  
		
		# open file to store information
        self.f= open("data_dqn.txt","a")

    def getMove(self, state): # epsilon greedy
        random_value = np.random.rand() 
         
        if random_value > self.epsilon: # exploit 
            # get current state
            temp_current_state = torch.from_numpy(np.stack(self.current_state))
            temp_current_state = temp_current_state.unsqueeze(0)
            temp_current_state = temp_current_state.to(self.device)
            
			# get Qsa
            self.Q_found = self.policy_net(temp_current_state)        
            self.Q_found =  self.Q_found.detach().cpu()
            self.Q_found = self.Q_found.numpy()[0]
			
			# store max Qsa
            self.Q_global.append(max(self.Q_found))
			
			# get best_action - value between 0 and 3
            best_action = np.argwhere(self.Q_found == np.amax(self.Q_found))          
			
            if len(best_action) > 1:  # two actions give the same max
                random_value = np.random.randint(0, len(best_action)) # random value between 0 and actions-1
                move = self.get_direction(best_action[random_value][0])
            else:
                move = self.get_direction(best_action[0][0])
        else: # explore
            random_value = np.random.randint(0, 4)  # random value between 0 and 3
            move = self.get_direction(random_value)

        # save last_action
        self.last_action = self.get_value(move)
        return move
           
    def observation_step(self, state):
        if self.last_action is not None:
            # get state
            self.last_state = np.copy(self.current_state)
            self.current_state = self.getStateMatrices(state)

            # get reward
            self.current_score = state.getScore()
            reward = self.current_score - self.last_score
            self.last_score = self.current_score

            if reward > 20:
                self.last_reward = 50.    # ate a ghost 
            elif reward > 0:
                self.last_reward = 10.    # ate food 
            elif reward < -10:
                self.last_reward = -500.  # was eaten
                self.won = False
            elif reward < 0:
                self.last_reward = -1.    # didn't eat

            if(self.terminal and self.won):
                self.last_reward = 100.
                self.win_counter += 1
            self.episode_reward += self.last_reward

            # store transition 
            transition = (self.last_state, self.last_reward, self.last_action, self.current_state, self.terminal)
            self.replay_mem.append(transition)
            if len(self.replay_mem) > memory_size:
                self.replay_mem.popleft()
            
            # train model
            self.train()

        # next
        self.local_cnt += 1
        self.frame += 1
		
		# update epsilon
        if(model_trained == False):
            self.epsilon = max(epsilon_final, 1.00 - float(self.episode_number) / float(epsilon_step))

    def final(self, state):
        # Next
        self.episode_reward += self.last_reward

        # do observation
        self.terminal = True
        self.observation_step(state)
        
		# print episode information
        print("Episode no = " + str(self.episode_number) + "; won: " + str(self.won) 
		+ "; Q(s,a) = " + str(max(self.Q_global, default=float('nan'))) + "; reward = " +  str(self.episode_reward) + "; and epsilon = " + str(self.epsilon))
		
		# copy episode information to file
        self.counter += 1
        if(self.counter % 10 == 0):
            self.f.write("Episode no = " + str(self.episode_number) + "; won: " + str(self.won) 
		+ "; Q(s,a) = " + str(max(self.Q_global, default=float('nan'))) + "; reward = " +  str(self.episode_reward) + "; and epsilon = " 
		+ str(self.epsilon) + ", win percentage = " + str(self.win_counter / 10.0) + ", " + str(strftime("%Y-%m-%d %H:%M:%S", gmtime())) + "\n")
            self.win_counter = 0

        if(self.counter % 500 == 0):
            # save model
            torch.save(self.policy_net, 'pacman_policy_net.pt')
            torch.save(self.target_net, 'pacman_target_net.pt')
        
        if(self.episode_number % TARGET_REPLACE_ITER == 0):
            print("UPDATING target network")
            self.target_net.load_state_dict(self.policy_net.state_dict())

    def train(self):
        if (self.local_cnt > start_training):
            batch = random.sample(self.replay_mem, batch_size)
            batch_s, batch_r, batch_a, batch_n, batch_t = zip(*batch)
            
            # convert from numpy to pytorch 
            batch_s = torch.from_numpy(np.stack(batch_s))
            batch_s = batch_s.to(self.device)
            batch_r = torch.DoubleTensor(batch_r).unsqueeze(1).to(self.device)
            batch_a = torch.LongTensor(batch_a).unsqueeze(1).to(self.device)
            batch_n = torch.from_numpy(np.stack(batch_n)).to(self.device)
            batch_t = torch.ByteTensor(batch_t).unsqueeze(1).to(self.device)
            
            # get Q(s, a)
            state_action_values = self.policy_net(batch_s).gather(1, batch_a)

            # get V(s')
            next_state_values = self.target_net(batch_n)

            # Compute the expected Q values                        
            next_state_values = next_state_values.detach().max(1)[0]
            next_state_values = next_state_values.unsqueeze(1)
            
            expected_state_action_values = (next_state_values * GAMMA) + batch_r
            
			# calculate loss
            loss_function = torch.nn.SmoothL1Loss()
            self.loss = loss_function(state_action_values, expected_state_action_values)
            
			# optimize model - update weights
            self.optim.zero_grad()
            self.loss.backward()
            self.optim.step()            
