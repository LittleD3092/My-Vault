# Homework 2 Report

## Part 1

The `remove_stopwords` function use `ToktokTokenizer` to tokenize the text and then remove the stopwords according to the `stopwords` list provided by `nltk.corpus`.

When testing the `remove_stopwords`, I stumbled upon an error about `Resource wordnet not found.`

https://stackoverflow.com/questions/13965823/resource-corpora-wordnet-not-found-on-heroku