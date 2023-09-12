# --model_type: ngram, RNN, BERT
# --preprocess: 0 - no preprocessing
#               1 - remove stopwords
#               2 - custom preprocessing
# --part: 1 - part 1
#         2 - part 2 (suggest always use this)
python3 main.py --model_type ngram --preprocess 0 --part 2
python3 main.py --model_type ngram --preprocess 1 --part 2
python3 main.py --model_type RNN --preprocess 0 --part 2
python3 main.py --model_type RNN --preprocess 1 --part 2
python3 main.py --model_type BERT --preprocess 0 --part 2
python3 main.py --model_type BERT --preprocess 1 --part 2