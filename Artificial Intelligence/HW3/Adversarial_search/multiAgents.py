# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
#
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and child states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best
        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed child
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        childGameState = currentGameState.getPacmanNextState(action)
        newPos = childGameState.getPacmanPosition()
        newFood = childGameState.getFood()
        newGhostStates = childGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
        return childGameState.getScore()

def scoreEvaluationFunction(currentGameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (par1-1)
    """
    def getAction(self, gameState, agentIndex = 0):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.getNextState(agentIndex, action):
        Returns the child game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"
        # Begin your code

        # util.raiseNotDefined()

        bestAction, evalValue = self.__getActionAndEval(gameState, self.depth * gameState.getNumAgents(), agentIndex)
        # print("evalValue: ", evalValue)
        return bestAction
        
        # End your code

    def __getActionAndEval(self, gameState, depth, agentIndex):
        # base case
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return None, self.evaluationFunction(gameState)
        
        # pacman's turn
        if agentIndex == 0: 
            maxEval = float('-inf')
            bestAction = None
            for action in gameState.getLegalActions(agentIndex):
                successor = gameState.getNextState(agentIndex, action)
                _, eval = self.__getActionAndEval(successor, depth - 1, (agentIndex + 1) % gameState.getNumAgents())
                if eval > maxEval:
                    maxEval = eval
                    bestAction = action
            return bestAction, maxEval
        # ghost's turn
        else:
            minEval = float('inf')
            bestAction = None
            for action in gameState.getLegalActions(agentIndex):
                successor = gameState.getNextState(agentIndex, action)
                _, eval = self.__getActionAndEval(successor, depth - 1, (agentIndex + 1) % gameState.getNumAgents())
                if eval < minEval:
                    minEval = eval
                    bestAction = action
            return bestAction, minEval

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (part1-2)
    """

    def getAction(self, gameState, agentIndex = 0):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"
        # Begin your code

        # util.raiseNotDefined()

        bestAction, evalValue = self.__getActionAndEval(gameState, self.depth * gameState.getNumAgents(), agentIndex)
        # print("evalValue: ", evalValue)
        return bestAction

        # End your code

    def __getActionAndEval(self, gameState, depth, agentIndex):
        # base case
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return None, self.evaluationFunction(gameState)
        
        # pacman's turn
        if agentIndex == 0: 
            maxEval = float('-inf')
            bestAction = None
            for action in gameState.getLegalActions(agentIndex):
                successor = gameState.getNextState(agentIndex, action)
                _, eval = self.__getActionAndEval(successor, depth - 1, (agentIndex + 1) % gameState.getNumAgents())
                if eval > maxEval:
                    maxEval = eval
                    bestAction = action
            return bestAction, maxEval
        # ghost's turn
        else:
            averageEval = 0
            legalActions = gameState.getLegalActions(agentIndex)
            for action in legalActions:
                successor = gameState.getNextState(agentIndex, action)
                _, eval = self.__getActionAndEval(successor, depth - 1, (agentIndex + 1) % gameState.getNumAgents())
                averageEval += eval / len(legalActions)
            return None, averageEval

better = scoreEvaluationFunction
