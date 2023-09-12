# Introduction to Artificial Intelligence Homework 4

## Part 1

Observation 1: Layer 6 is for predicting the end of the sentence.

![[Pasted image 20230519184121.png]]

Observation 2: The 1st header focus on the relationships between words and "girl", "pub", and "her", which are all nouns. Therefore, the 1st header is for nouns.

![[Pasted image 20230519184448.png]]

Observation 3: The 3rd head connect the words with the previous word of them. Therefore the 3rd head focus on the previous word.

![[Pasted image 20230519184850.png]]

Observation 4: The 5th header is relatively complex, so I think it somehow checks grammar. This header do link some nouns to verbs, but I think this header does something more that I can't figure out.

![[Pasted image 20230519190025.png]]

Observation 5: The 6th header handles words such as "to".

![[Pasted image 20230519190225.png]]

Observation 6: The 7th and the 10th head links the words that have the same meaning.

![[Pasted image 20230519190355.png]]

![[Pasted image 20230519190922.png]]

Observation 7: 9th and 11th head links the words to the next (and next 2) words.

![[Pasted image 20230519190729.png]]

![[Pasted image 20230519191807.png]]

## Part 2

### TA_model_1.pt

Attempt 1: "It was a fantastic performance!"

![[Pasted image 20230519181556.png]]

The word "fantastic" and "performance" is the main reason of the comment being positive.

Attempt 2: "That is a terrible movie."

![[Pasted image 20230519182126.png]]

The word "terrible" is the main reason of the comment being negative.

### TA_model_2.pt

![[Pasted image 20230519193642.png]]

The keywords "fantastic" and "terrible" have more weights in the second model. Also, the neighboring words are less important compared to the first model.

## Part 3

The explanation of SHAP based on model 1:

![[Pasted image 20230519194350.png]]

Compare to the explanation using LIME:

![[Pasted image 20230519194804.png]]

We can see that SHAP focus more on the meaning of the words, instead of taking neighboring words into account.

## Part 4

Attack 1: The word "creation" added a positive influence, but LIME is still able to classify this comment.

![[Pasted image 20230519200213.png]]

Attack 2: The word "terrible" is misspelled, but LIME can still classify this comment.

![[Pasted image 20230519201339.png]]

Attack 3: A "not" is added before "a terrible movie". LIME manages to invert the value of "terrible" from negative to possitive, but other words still gives a negative value.

![[Pasted image 20230519201730.png]]

As the attack examples above, the model can easily handle attacks like substitution and character level transformation. However, the model does not handle "not" so well. When retraining the model, it is recommended to use a dataset that have words like "not" which negates the following words.