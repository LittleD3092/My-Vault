# Introduction to Artificial Intelligence HW3

## Part 1: Adversarial Search

### Problem 1: `depth` parameter

I thought the `depth` means the number of moves (for both pacman and 2 ghosts to move, the total depth would be `3`), but I was wrong. For pacman and all the ghosts to move once, the depth would be `1`.

### Observation 1: pacman commit suicide

When running the following command, the pacman rushes to the closest ghost:

```bash
python pacman.py -p MinimaxAgent -l trappedClassic -a depth=3
```

Note that when pacman notices that its death is inevitable, it will try suicide to prevent the score from decreasing. This is the reason why it rushes to the closest ghost in trapped case.

### Observation 2: pacman avoid death even when trapped

When running the following command, the pacman avoid death even when it is trapped by ghosts.

```bash
python pacman.py -p ExpectimaxAgent -l trappedClassic -a depth=3 -q -n 10
```

This is because it believe there is a chance that the ghost will release it, and the pacman can grab more food. In fact, this strategy works better than `MinimaxAgent` in this map.

### Implementation 1: class `MinimaxAgent`

```python
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
```

Because the `bestAction` that is required depend on `evalValue`, I return both of them in a tuple. Also, the function `getAction` can only return a single action, so I use a private function `__getActionAndEval` to do the recursion.

### Implementation 2: class `ExpectimaxAgent`

```python
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
```

My implementation of `ExpectimaxAgent` is similar to `MinimaxAgent`. I used the private function `__getActionAndEval` to do the recursion. The only difference is that the ghost's turn is to calculate the average of all possible evaluation values.

## Part 2: Q-learning

### Problem 2: Implementing Function `runValueIteration`

When I first saw the provided python script, I implemented the formula of values set $V$ and optimal policy set $\pi$ in member function `runValueIteration`. Then I realized that there is more member function below, and I make use of them to simplify my code.

### Problem 3: `nextState` parameter in method `mdp.getReward()` is confusing

Also, the `nextState` parameter in method `mdp.getReward()` confuses me. After seeing the implementation in `gridworld.py`, I find out that the parameters `action` and `nextState` are not used in this state and is provided due to convention.

### Problem 4: `cgi.escape()` method deprecated

While running the provided grading python script `autograder.py`, I get the following error:

```python
*** FAIL: Exception raised: module 'cgi' has no attribute 'escape'
Traceback (most recent call last):
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/grading.py", line 79, in grade
    util.TimeoutFunction(getattr(gradingModule, q), 1800)(
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/util.py", line 702, in __call__
    result = self.function(*args, **keyArgs)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/autograder.py", line 312, in <lambda>
    return lambda grades: question.execute(grades)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/testClasses.py", line 57, in execute
    if not f(grades):
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/autograder.py", line 307, in <lambda>
    return lambda grades: testCase.execute(grades, moduleDict, solutionDict)
  File "reinforcementTestClasses.py", line 69, in execute
    return self.testPass(grades)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/testClasses.py", line 176, in testPass
    grades.addMessage('PASS: %s' % (self.path,))
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/grading.py", line 301, in addMessage
    message = cgi.escape(message)
AttributeError: module 'cgi' has no attribute 'escape'

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/autograder.py", line 366, in <module>
    evaluate(options.generateSolutions, options.testRoot, moduleDict,
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/autograder.py", line 323, in evaluate
    grades.grade(sys.modules[__name__], bonusPic=projectParams.BONUS_PIC)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/grading.py", line 83, in grade
    self.addExceptionMessage(q, inst, traceback)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/grading.py", line 153, in addExceptionMessage
    self.fail('FAIL: Exception raised: %s' % inst)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/grading.py", line 277, in fail
    self.addMessage(message, raw)
  File "/home/littled3092/Documents/My-Vault/Artificial Intelligence/HW3/Q-learning/grading.py", line 301, in addMessage
    message = cgi.escape(message)
AttributeError: module 'cgi' has no attribute 'escape'
```

After searching on the Internet, I come across the following github issue:

- [Use html.escape instead of cgi.escape under Python3 - https://github.com/ablab/quast/pull/129](https://github.com/ablab/quast/pull/129)

So I think this is a problem of the provided grading script. In order to run the grading script, I need to modify the importing statement:

```python
# before modification
import cgi

# after modification
import cgi
try:
    from html import escape as cgi_escape
except:
    pass
```

and add try statement to all occurences of `cgi.escape()`:

```python
# before modification
message = cgi.escape(message)

# after modification
try:
    message = cgi.escape(message)
except:
    message = cgi_escape(message)
```

### Implementation 3: class `ValueIterationAgent`

```python
class ValueIterationAgent(ValueEstimationAgent):
    """
        * Please read learningAgents.py before reading this.*

        A ValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs value iteration
        for a given number of iterations using the supplied
        discount factor.
    """
    def __init__(self, mdp, discount = 0.9, iterations = 100):
        """
          Your value iteration agent should take an mdp on
          construction, run the indicated number of iterations
          and then act according to the resulting policy.

          Some useful mdp methods you will use:
              mdp.getStates()
              mdp.getPossibleActions(state)
              mdp.getTransitionStatesAndProbs(state, action)
              mdp.getReward(state, action, nextState)
              mdp.isTerminal(state)
        """
        self.mdp = mdp
        self.discount = discount
        self.iterations = iterations
        self.values = util.Counter() # A Counter is a dict with default 0
        self.optimalPolicy = {}
        self.runValueIteration()

    def runValueIteration(self):
        # Write value iteration code here
        """
            Precondition: A member self.values is a util.Counter()
            Postcondition: self.values is a util.Counter() where
                           self.values[state] is the value of the state
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        k = 0
        while k < self.iterations:
            updatedValues = util.Counter()
            for state in self.mdp.getStates():
                if self.mdp.isTerminal(state):
                    continue
                updatedValues[state] = max(self.getQValue(state, action) for action in self.mdp.getPossibleActions(state))
            self.values = updatedValues
            k += 1
        # End your code


    def getValue(self, state):
        """
          Return the value of the state (computed in __init__).
        """
        return self.values[state]


    def computeQValueFromValues(self, state, action):
        """
          Compute the Q-value of action in state from the
          value function stored in self.values.
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()

        return (
            self.mdp.getReward(state, action, self.mdp.getTransitionStatesAndProbs(state, action)) +
            self.discount * sum(
                prob * self.values[nextState]
                for nextState, prob in self.mdp.getTransitionStatesAndProbs(state, action)
            )
        )

        # End your code

    def computeActionFromValues(self, state):
        """
          The policy is the best action in the given state
          according to the values currently stored in self.values.

          You may break ties any way you see fit.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return None.
        """
        "*** YOUR CODE HERE ***"
        # Begin your code

        #check for terminal
        # util.raiseNotDefined() 

        bestAction = None
        bestValue = float('-inf')
        for action in self.mdp.getPossibleActions(state):
            value = self.getQValue(state, action)
            if value > bestValue:
                bestValue = value
                bestAction = action

        return bestAction

        # End your code

    def getPolicy(self, state):
        """
        The policy is the best action in the given state
        according to the values computed by value iteration.
        You may break ties any way you see fit.  Note that if
        there are no legal actions, which is the case at the
        terminal state, you should return None.
        """
        return self.computeActionFromValues(state)

    def getAction(self, state):
        "Returns the policy at the state (no exploration)."
        return self.computeActionFromValues(state)

    def getQValue(self, state, action):
        """
        The q-value of the state action pair
        (after the indicated number of value iteration
        passes).  Note that value iteration does not
        necessarily create this quantity and you may have
        to derive it on the fly.
        """
        return self.computeQValueFromValues(state, action)
```

#### Member Function `runValueIteration()`

```python
def runValueIteration(self):
    # Write value iteration code here
    """
        Precondition: A member self.values is a util.Counter()
        Postcondition: self.values is a util.Counter() where
                        self.values[state] is the value of the state
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    k = 0
    while k < self.iterations:
        updatedValues = util.Counter()
        for state in self.mdp.getStates():
            if self.mdp.isTerminal(state):
                continue
            updatedValues[state] = max(self.getQValue(state, action) for action in self.mdp.getPossibleActions(state))
        self.values = updatedValues
        k += 1
    # End your code
```

I refer to the following resources:
[Value Iteration](https://artint.info/2e/html/ArtInt2e.Ch9.S5.SS2.html)

The procedure `Value_iteration` shown in the above link does not use $Q$ while updating $V_k$, so I substitute the expression below to $Q$:

$$R(s, a) + \gamma * \sum_{s'} P(s' \vert s, a)* V_{k-1}[s'] = Q_k$$

#### Member Function `computeQValueFromValues()`

```python
    def computeQValueFromValues(self, state, action):
        """
          Compute the Q-value of action in state from the
          value function stored in self.values.
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()

        return (
            self.mdp.getReward(state, action, self.mdp.getTransitionStatesAndProbs(state, action)) +
            self.discount * sum(
                prob * self.values[nextState]
                for nextState, prob in self.mdp.getTransitionStatesAndProbs(state, action)
            )
        )

        # End your code
```

I refer to the same website, and used the following formula:

$$Q_{k + 1}(s, a) = R(s, a) + \gamma * \sum_{s'} P(s' \vert s, a) * V_k(s')$$

#### Member Function `computeActionFromValues()`

```python
def computeActionFromValues(self, state):
    """
        The policy is the best action in the given state
        according to the values currently stored in self.values.

        You may break ties any way you see fit.  Note that if
        there are no legal actions, which is the case at the
        terminal state, you should return None.
    """
    "*** YOUR CODE HERE ***"
    # Begin your code

    #check for terminal
    # util.raiseNotDefined() 

    bestAction = None
    bestValue = float('-inf')
    for action in self.mdp.getPossibleActions(state):
        value = self.getQValue(state, action)
        if value > bestValue:
            bestValue = value
            bestAction = action

    return bestAction

    # End your code
```

I refer to the same website, and used the statement in the procedure `Value_iteration`:

$$
\begin{array}{lll}
\pi[s] &=& \argmax_a R(s, a) + \gamma * \sum_{s'} P(s' \vert s, a) * V_k[s'] \\
&=& \argmax_a Q_{k + 1}(s, a)
\end{array}
$$

I used a for loop to compare the $Q$ values and find the best action.

### Implementation 4: class `QLearningAgent`

```python
class QLearningAgent(ReinforcementAgent):
    """
      Q-Learning Agent

      Functions you should fill in:
        - computeValueFromQValues
        - computeActionFromQValues
        - getQValue
        - getAction
        - update

      Instance variables you have access to
        - self.epsilon (exploration prob)
        - self.alpha (learning rate)
        - self.discount (discount rate)

      Functions you should use
        - self.getLegalActions(state)
          which returns legal actions for a state
    """
    def __init__(self, **args):
        "You can initialize Q-values here..."
        ReinforcementAgent.__init__(self, **args)

        "*** YOUR CODE HERE ***"
        # Begin your code
        self.qValues = util.Counter()
        # End your code


    def getQValue(self, state, action):
        """
          Returns Q(state,action)
          Should return 0.0 if we have never seen a state
          or the Q node value otherwise
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()
        return self.qValues[(state, action)]
        # End your code


    def computeValueFromQValues(self, state):
        """
          Returns max_action Q(state,action)
          where the max is over legal actions.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return a value of 0.0.
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()
        if len(self.getLegalActions(state)) == 0:
            return 0.0

        return max(
            self.getQValue(state, action)
            for action in self.getLegalActions(state)
        )
        # End your code

    def computeActionFromQValues(self, state):
        """
          Compute the best action to take in a state.  Note that if there
          are no legal actions, which is the case at the terminal state,
          you should return None.
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()
        bestValue = -float('inf')
        bestAction = None
        for action in self.getLegalActions(state):
            value = self.getQValue(state, action)
            if value > bestValue:
                bestValue = value
                bestAction = action
        return bestAction
        # End your code

    def getAction(self, state):
        """
          Compute the action to take in the current state.  With
          probability self.epsilon, we should take a random action and
          take the best policy action otherwise.  Note that if there are
          no legal actions, which is the case at the terminal state, you
          should choose None as the action.

          HINT: You might want to use util.flipCoin(prob)
          HINT: To pick randomly from a list, use random.choice(list)
        """
        # Pick Action
        legalActions = self.getLegalActions(state)
        action = None
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()

        if len(legalActions) == 0:
            return None
        
        return (
            random.choice(legalActions) 
            if util.flipCoin(self.epsilon)
            else self.getPolicy(state)
        )
        # End your code
        

    def update(self, state, action, nextState, reward):
        """
          The parent class calls this to observe a
          state = action => nextState and reward transition.
          You should do your Q-Value update here

          NOTE: You should never call this function,
          it will be called on your behalf
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()

        if len(self.getLegalActions(nextState)) == 0: # terminal state
            self.qValues[(state, action)] = (
                (1 - self.alpha) * self.getQValue(state, action) +
                self.alpha * reward
            )
            return

        self.qValues[(state, action)] = (
            (1 - self.alpha) * self.getQValue(state, action) +
            self.alpha * (
                reward + self.discount * max(
                    self.getQValue(nextState, nextAction)
                    for nextAction in self.getLegalActions(nextState)
                )
            )
        )
        # End your code

    def getPolicy(self, state):
        return self.computeActionFromQValues(state)

    def getValue(self, state):
        return self.computeValueFromQValues(state)
```

#### Member Function `__init__()`

```python
def __init__(self, **args):
    "You can initialize Q-values here..."
    ReinforcementAgent.__init__(self, **args)

    "*** YOUR CODE HERE ***"
    # Begin your code
    self.qValues = util.Counter()
    # End your code
```

I initialized member variable `qValues` as a `util.Counter()`.

#### Member Function `getQValue()`

```python
def getQValue(self, state, action):
    """
        Returns Q(state,action)
        Should return 0.0 if we have never seen a state
        or the Q node value otherwise
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    # util.raiseNotDefined()
    return self.qValues[(state, action)]
    # End your code
```

Because I initialized `qValues` as a `util.Counter()`, I can use the operator `[]` to get the value of a key. If the key does not exist, the value will be `0`, which satisfy the requirement of the state that we have never seen.

#### Member Function `computeValueFromQValues()`

```python
def computeValueFromQValues(self, state):
    """
        Returns max_action Q(state,action)
        where the max is over legal actions.  Note that if
        there are no legal actions, which is the case at the
        terminal state, you should return a value of 0.0.
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    # util.raiseNotDefined()
    if len(self.getLegalActions(state)) == 0:
        return 0.0

    return max(
        self.getQValue(state, action)
        for action in self.getLegalActions(state)
    )
    # End your code
```

For the terminal state, I used an if statement that checks the amount of legal actions. If there are no legal actions, I return `0.0`. Otherwise, I return the maximum value of all the Q-values of the legal actions.

#### Member Function `computeActionFromQValues()`

```python
def computeActionFromQValues(self, state):
    """
        Compute the best action to take in a state.  Note that if there
        are no legal actions, which is the case at the terminal state,
        you should return None.
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    # util.raiseNotDefined()
    bestValue = -float('inf')
    bestAction = None
    for action in self.getLegalActions(state):
        value = self.getQValue(state, action)
        if value > bestValue:
            bestValue = value
            bestAction = action
    return bestAction
    # End your code
```

I used a for loop to iterate through all the legal actions. I used a variable `bestValue` to store the maximum value of all the Q-values of the legal actions. I used a variable `bestAction` to store the action that has the maximum value. I returned `bestAction` after the for loop.

#### Member Function `getAction()`

```python
def getAction(self, state):
    """
        Compute the action to take in the current state.  With
        probability self.epsilon, we should take a random action and
        take the best policy action otherwise.  Note that if there are
        no legal actions, which is the case at the terminal state, you
        should choose None as the action.

        HINT: You might want to use util.flipCoin(prob)
        HINT: To pick randomly from a list, use random.choice(list)
    """
    # Pick Action
    legalActions = self.getLegalActions(state)
    action = None
    "*** YOUR CODE HERE ***"
    # Begin your code
    # util.raiseNotDefined()

    if len(legalActions) == 0:
        return None
    
    return (
        random.choice(legalActions) 
        if util.flipCoin(self.epsilon)
        else self.getPolicy(state)
    )
    # End your code
```

I used an if statement to check if there are legal actions. If there are no legal actions, I returned `None`. Because it requires us to choose a random action with a probability of `self.epsilon`, I implemented it using `random.choice(legalActions)` and `flipCoin(self.epsilon)`. If `flipCoin(self.epsilon)` returns `True`, I returned a random action. Otherwise, I returned the best action using `self.getPolicy(state)`.

#### Member Function `update()`

```python
def update(self, state, action, nextState, reward):
    """
        The parent class calls this to observe a
        state = action => nextState and reward transition.
        You should do your Q-Value update here

        NOTE: You should never call this function,
        it will be called on your behalf
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    # util.raiseNotDefined()

    if len(self.getLegalActions(nextState)) == 0: # terminal state
        self.qValues[(state, action)] = (
            (1 - self.alpha) * self.getQValue(state, action) +
            self.alpha * reward
        )
        return

    self.qValues[(state, action)] = (
        (1 - self.alpha) * self.getQValue(state, action) +
        self.alpha * (
            reward + self.discount * max(
                self.getQValue(nextState, nextAction)
                for nextAction in self.getLegalActions(nextState)
            )
        )
    )
    # End your code
```

I refer to the formula in the wikipedia page:

[Q-learning](https://en.wikipedia.org/wiki/Q-learning)

$${\displaystyle Q^{new}(s_{t},a_{t})\leftarrow (1-\underbrace {\alpha } _{\text{learning rate}})\cdot \underbrace {Q(s_{t},a_{t})} _{\text{current value}}+\underbrace {\alpha } _{\text{learning rate}}\cdot {\bigg (}\underbrace {\underbrace {r_{t}} _{\text{reward}}+\underbrace {\gamma } _{\text{discount factor}}\cdot \underbrace {\max _{a}Q(s_{t+1},a)} _{\text{estimate of optimal future value}}} _{\text{new value (temporal difference target)}}{\bigg )}}$$

Note that if the there is no legal actions, $\gamma$ and $\max_a Q(s_{t + 1}, a)$ need to be omitted. It is because that the terminal state has no next state, and the $Q$ should be $0$.

### Implementation 5: class `ApproximateQAgent`

```python
class ApproximateQAgent(PacmanQAgent):
    """
       ApproximateQLearningAgent

       You should only have to overwrite getQValue
       and update.  All other QLearningAgent functions
       should work as is.
    """
    def __init__(self, extractor='IdentityExtractor', **args):
        self.featExtractor = util.lookup(extractor, globals())()
        PacmanQAgent.__init__(self, **args)
        self.weights = util.Counter()

    def getWeights(self):
        return self.weights

    def getQValue(self, state, action):
        """
          Should return Q(state,action) = w * featureVector
          where * is the dotProduct operator
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # get weights and feature
        # util.raiseNotDefined()
        QValue = 0
        w = self.getWeights()
        featureVector = self.featExtractor.getFeatures(state, action)

        return sum(w[key] * featureVector[key] for key in featureVector)
        # End your code

    def update(self, state, action, nextState, reward):
        """
           Should update your weights based on transition
        """
        "*** YOUR CODE HERE ***"
        # Begin your code
        # util.raiseNotDefined()
        correction = reward + self.discount * self.getValue(nextState) - self.getQValue(state, action)
        w = self.getWeights()
        featureVector = self.featExtractor.getFeatures(state, action)
        for key in featureVector:
            w[key] += self.alpha * correction * featureVector[key]

        self.weights = w
        # End your code


    def final(self, state):
        "Called at the end of each game."
        # call the super-class final method
        PacmanQAgent.final(self, state)
```

#### Member Function `getQValue()`

```python
def getQValue(self, state, action):
    """
        Should return Q(state,action) = w * featureVector
        where * is the dotProduct operator
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    # get weights and feature
    # util.raiseNotDefined()
    w = self.getWeights()
    featureVector = self.featExtractor.getFeatures(state, action)

    return sum(w[key] * featureVector[key] for key in featureVector)
    # End your code
```

According to the formula provided in the comment, I implemented the function using `sum()` and a for loop to calculate the dot product of the weights and the feature vector.

#### Member Function `update()`

```python
def update(self, state, action, nextState, reward):
    """
        Should update your weights based on transition
    """
    "*** YOUR CODE HERE ***"
    # Begin your code
    # util.raiseNotDefined()
    correction = reward + self.discount * self.getValue(nextState) - self.getQValue(state, action)
    w = self.getWeights()
    featureVector = self.featExtractor.getFeatures(state, action)
    for key in featureVector:
        w[key] += self.alpha * correction * featureVector[key]

    self.weights = w
    # End your code
```

According to the slide I found:

[Approximate Q-Learning](https://www.cs.swarthmore.edu/~bryce/cs63/s16/slides/3-25_approximate_Q-learning.pdf)

The updated weights have the following formula:

$$
\begin{array}{rll}
w_i & \leftarrow & w_i + \alpha [\text{correction}] f_i(s, a) \\
\text{correction} &=& (R(s, a) + \gamma V(s')) - Q(s, a)
\end{array}
$$

So I updated each weight using the formula and a for loop.

## Part 3: DQN

Default value:

```
Started Pacman DQN algorithm
Model has been trained
Episode no = 1; won: True; Q(s,a) = 216.01706689055456; reward = 701.0; and epsilon = 0.0
Episode no = 2; won: False; Q(s,a) = 222.80669538820243; reward = -25.0; and epsilon = 0.0
Episode no = 3; won: True; Q(s,a) = 217.03599451244423; reward = 774.0; and epsilon = 0.0
Episode no = 4; won: True; Q(s,a) = 202.03268532238192; reward = 694.0; and epsilon = 0.0
Episode no = 5; won: True; Q(s,a) = 217.24104625010315; reward = 734.0; and epsilon = 0.0
Episode no = 6; won: True; Q(s,a) = 214.2216257997232; reward = 680.0; and epsilon = 0.0
Episode no = 7; won: True; Q(s,a) = 206.7581969510947; reward = 722.0; and epsilon = 0.0
Episode no = 8; won: True; Q(s,a) = 225.9402518391309; reward = 746.0; and epsilon = 0.0
Episode no = 9; won: True; Q(s,a) = 197.10807076515093; reward = 753.0; and epsilon = 0.0
Episode no = 10; won: True; Q(s,a) = 223.64456788903996; reward = 780.0; and epsilon = 0.0
Episode no = 11; won: True; Q(s,a) = 220.47638215817304; reward = 740.0; and epsilon = 0.0
Episode no = 12; won: True; Q(s,a) = 196.55103740493072; reward = 710.0; and epsilon = 0.0
Episode no = 13; won: True; Q(s,a) = 205.00495091788295; reward = 732.0; and epsilon = 0.0
Episode no = 14; won: True; Q(s,a) = 224.9098148943664; reward = 714.0; and epsilon = 0.0
Episode no = 15; won: True; Q(s,a) = 214.98720458260024; reward = 649.0; and epsilon = 0.0
Episode no = 16; won: False; Q(s,a) = 196.27857422863997; reward = -78.0; and epsilon = 0.0
Episode no = 17; won: True; Q(s,a) = 195.11727562904954; reward = 751.0; and epsilon = 0.0
Episode no = 18; won: True; Q(s,a) = 220.1039622141997; reward = 736.0; and epsilon = 0.0
Episode no = 19; won: True; Q(s,a) = 195.82433362574025; reward = 661.0; and epsilon = 0.0
Episode no = 20; won: False; Q(s,a) = 196.50722106234508; reward = 66.0; and epsilon = 0.0
Pacman emerges victorious! Score: 1750
Episode no = 21; won: True; Q(s,a) = 222.21446340332105; reward = 776.0; and epsilon = 0.0
Pacman emerges victorious! Score: 936
Episode no = 22; won: True; Q(s,a) = 206.1169270432688; reward = 580.0; and epsilon = 0.0
Pacman emerges victorious! Score: 1536
Episode no = 23; won: True; Q(s,a) = 207.74529007906696; reward = 700.0; and epsilon = 0.0
Pacman emerges victorious! Score: 1478
Episode no = 24; won: True; Q(s,a) = 218.275580794811; reward = 664.0; and epsilon = 0.0
Pacman died! Score: 452
Episode no = 25; won: False; Q(s,a) = 220.98262327816673; reward = 48.0; and epsilon = 0.0
Average Score: 1230.4
Scores:        1750.0, 936.0, 1536.0, 1478.0, 452.0
Win Rate:      4/5 (0.80)
Record:        Win, Win, Win, Win, Loss
```



## Question

1. What is the difference between On-policy and Off-policy?
   On-policy means that the agent uses the same policy to choose actions and to learn. Off-policy means that the agent uses two kinds of policies, one for choosing actions and one for learning.
2. Briefly explain value-based, policy-based and Actor-Critic. Also, describe the value function $V^\pi (S)$.
   Value-based methods use a value function or action-value function to determine the best action to take. Policy-based methods directly maps states to actions. Actor-Critic methods use both value-based and policy-based methods, where the actor is the policy-based method and the critic is the value-based method. The value function $V^\pi (S)$ is the expected return starting from state $S$ and following policy $\pi$.
3. What is the difference between Monte-Carlo (MC) based approach and Temporal-difference (TD) approach for estimating $V^\pi (S)$?
   Monte-Carlo methods calculates and update the value function after each episode, while Temporal-difference methods calculates and update the value function after each step.
4. Describe State-action value function $Q^\pi(s, a)$ and the relationship between $V^\pi(S)$ in Q-learning.
   $Q^\pi(s, a)$ is a function that returns the current estimate of the expected return starting from state $s$ and take action $a$. $V^\pi(S)$ is the expected return starting from state $S$ and following policy $\pi$. $V^\pi(S)$ is the maximum value of $Q^\pi(s, a)$ over all possible actions $a$.
5. Describe following tips Target Network, Exploration and Replay Buffer using in Q-learning.
   Target Network is a copy of the main network that is updated less frequently to stabilize the learning process. Exploration is the process of encouraging the agent to take random actions to explore the environment. Replay Buffer is a data structure that stores states, actions, rewards, and next states. Replay Buffer can be used to train the agent by randomly sampling from the buffer, and this can make more efficient use of the experience.
6. Explain what is different between DQN and Q-learning.
   DQN is a deep learning version of Q-learning. DQN uses a neural network to approximate the Q-function, while Q-learning uses a matrix to store the Q-function.