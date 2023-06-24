import nltk
nltk.download('stopwords')

from nltk.corpus import stopwords
from nltk.tokenize.toktok import ToktokTokenizer
from nltk.stem import WordNetLemmatizer
nltk.data.path.append('./nltk_data/')

import re

def remove_stopwords(text: str) -> str:
    '''
    E.g.,
        text: 'Here is a dog.'
        preprocessed_text: 'Here dog.'
    '''
    stop_word_list = stopwords.words('english')
    tokenizer = ToktokTokenizer()
    tokens = tokenizer.tokenize(text)
    tokens = [token.strip() for token in tokens]
    filtered_tokens = [token for token in tokens if token.lower() not in stop_word_list]
    preprocessed_text = ' '.join(filtered_tokens)

    return preprocessed_text

def remove_tags(html = ""):
    clean = re.compile('<.*?>')
    return re.sub(clean, '', html)

def preprocessing_function(text: str) -> str:
    preprocessed_text = remove_stopwords(text)
    
    # TO-DO 0: Other preprocessing function attemption
    # Begin your code 

    # delete html labels
    noHtml = remove_tags(preprocessed_text)

    # apply lemmatization
    lemmatizer = WordNetLemmatizer()
    tokenizer = ToktokTokenizer()
    tokens = tokenizer.tokenize(noHtml)
    tokens = [token.strip() for token in tokens]
    lemmatized_tokens = [lemmatizer.lemmatize(token) for token in tokens]
    preprocessed_text = ' '.join(lemmatized_tokens)

    # change to lower case
    preprocessed_text = preprocessed_text.lower()

    # remove all non-alphabetic characters
    preprocessed_text = re.sub(r'[^a-zA-Z]', ' ', preprocessed_text)

    # strip extra white space
    tokens = tokenizer.tokenize(preprocessed_text)
    tokens = [token.strip() for token in tokens]
    preprocessed_text = ' '.join(tokens)

    # End your code

    return preprocessed_text