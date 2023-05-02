# Introduction to Artificial Intelligence HW3

## Introduction

- I don't know about any of the concepts now.
- I use `python3.10`, while the specs require `python3.7`. I may need to fix it later.

TODO: The following programs need to be modified in order to complete the homework.

| Folder               | File                      |
| -------------------- | ------------------------- |
| `Adversarial_search` | `multiAgents.py`          |
| `Q-learning`         | `valueIterationAgents.py` |
|                      | `qlearningAgents.py`      |
|                      | `featureExtractors.py`    |
| `DQN`                | `DQN.py`                  |
|                      | `pacmanDQN_Agent.py`      |

## Part 1: Adversarial Search

I thought the `depth` means the number of moves (for both pacman and 2 ghosts to move, the total depth would be `3`), but I was wrong. For pacman and all the ghosts to move once, the depth would be `1`.

Observation 1:

When running the following command, the pacman rushes to the closest ghost:

```bash
python pacman.py -p MinimaxAgent -l trappedClassic -a depth=3
```

Note that when pacman notices that its death is inevitable, it will try suicide to prevent the score from decreasing. This is the reason why it rushes to the closest ghost in trapped case.

Observation 2:

When running the following command, the pacman avoid death even when it is trapped by ghosts.

```bash
python pacman.py -p ExpectimaxAgent -l trappedClassic -a depth=3 -q -n 10
```

This is because it believe there is a chance that the ghost will release it, and the pacman can grab more food. In fact, this strategy works better than `MinimaxAgent` in this map.

## Part 2: Q-learning

Problem 1: Implementing Function `runValueIteration`

When I first saw the provided python script, I implemented the formula of values set $V$ and optimal policy set $\pi$ in member function `runValueIteration`. Then I realized that there is more member function below, and I make use of them to simplify my code.

Problem 2: `nextState` parameter in method `mdp.getReward()` is confusing

Also, the `nextState` parameter in method `mdp.getReward()` confuses me. After seeing the implementation in `gridworld.py`, I find out that the parameters `action` and `nextState` are not used in this state and is provided due to convention.

Problem 3: `cgi.escape()` method deprecated

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