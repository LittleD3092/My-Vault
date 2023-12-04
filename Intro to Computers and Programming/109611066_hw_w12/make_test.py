# input_1.txt
# Open the file in write mode
file_path = "./input_1.txt"
file = open(file_path, "w")

# Write content to the file
file.write("6\n")
file.write("2 1 100\n")
file.write("2 2 200\n")
file.write("2 3 300\n")
file.write("2 4 400\n")
file.write("1 2\n")
file.write("3 5 100 1\n")

# Close the file
file.close()

# output_ans_1.txt
# Open the file in write mode
file_path = "./output_ans_1.txt"
file = open(file_path, "w")

# Write content to the file
file.write("ID money: 1 100\n")
file.write("ID money: 5 100\n")
file.write("ID money: 2 200\n")
file.write("ID money: 4 400\n")

# Close the file
file.close()

# input_2.txt
# Open the file in write mode
file_path = "./input_2.txt"
file = open(file_path, "w")

# Write content to the file
file.write("7\n")
file.write("2 3 100\n")
file.write("2 2 200\n")
file.write("3 1 300 0\n")
file.write("2 4 400\n")
file.write("1 3\n")
file.write("3 5 100 2\n")
file.write("1 0\n")

# Close the file
file.close()

# output_ans_2.txt
# Open the file in write mode
file_path = "./output_ans_2.txt"
file = open(file_path, "w")

# Write content to the file
file.write("ID money: 3 100\n")
file.write("ID money: 5 100\n")
file.write("ID money: 2 200\n")

# Close the file
file.close()