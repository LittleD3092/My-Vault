def read_dam_words(file_path):
    try:
        with open(file_path, 'r') as file:
            dam_words = set(file.read().split())
        return dam_words
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
        return set()

# def print_wrong_letter(prev_word, current_word, dam_words):
#     # Find and print the incorrect letter
#     for a, b in zip(prev_word, current_word):
#         if a != b:
#             if a not in dam_words:
#                 print(f"Wrong letter: {a} in {prev_word} should be {b} in {current_word}, but {a} is not in the provided file.")
#             else:
#                 print(f"Wrong letter: {a} in {prev_word} should be {b} in {current_word}")

def check_change(input_string, dam_words):
    # Split the input string by ' >> '
    split_list = input_string.split(' >> ')

    # Check if each letter in the list only changes one character from the previous one
    for i in range(1, len(split_list)):
        prev_word = split_list[i-1]
        current_word = split_list[i]

        # Check if the words have the same length
        if len(prev_word) != len(current_word):
            print(f"Invalid input: {prev_word} and {current_word} have different lengths.")
            return False

        # Count the number of differing characters
        diff_count = sum(1 for a, b in zip(prev_word, current_word) if a != b)

        # Check if only one character is different
        if diff_count != 1:
            print(f"\nInvalid input: {prev_word} and {current_word} differ by more than one character.")
            # print_wrong_letter(prev_word, current_word, dam_words)
            return False

        # Check if the letter is in the provided file
        if current_word not in dam_words:
            print(f"\nLetter {current_word} is not in the provided file.")
            return False

    return True

# Read DAMwords.txt file
dam_words_file_path = "DAMwords.txt"
dam_words_set = read_dam_words(dam_words_file_path)

if not dam_words_set:
    exit()

# Read input as string
input_str = input("Input your answer: \n")

# Call the function and print the result
result = check_change(input_str, dam_words_set)

if result:
    print("\nCorrect!\n")
else:
    print("\nWrong!\n")
