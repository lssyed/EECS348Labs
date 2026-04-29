#!/bin/bash

input="The five boxing wizards jump quickly"

# Question 1: Match substring "bo", any characters, ending with "ng"
echo "Question 1:"
# 'bo' matches exact letters, '\w*' matches zero or more word characters, 'ng' matches exact letters. 
echo "$input" | grep -oP 'bo\w*ng'

# Question 2: Match any word at least 7 letters long. 
echo "Question 2:"
# '\w' matches word characters, '{7,}' means 7 or more times.
echo "$input" | grep -oP '\w{7,}'

# Question 3: Count total no. of words.
echo "Question 3:"
# '\w+' isolates every word on its own line, 'wc -l' counts total no. of lines. 
echo "$input" | grep -oP '\w+' | wc -l

echo "Question 4:"
# '^EMAIL' matches lines that start with "EMAIL"
grep -E '^EMAIL' emails.txt

echo "Question 5:"
# 'COUNT|NEXT|READ' looks for any of these command words.
grep -E 'COUNT|NEXT|READ' emails.txt

echo "Question 6:"
# '^EMAIL Boss,' looks for emails starting with EMAIL and by "Boss". 
grep -E '^EMAIL Boss,' emails.txt

echo "Question 7:"
# '2025$' looks for 2025 at the end of the line.
grep -E '2025$' emails.txt

echo "Question 8:"
# '12-[0-9]{2}-2024$' matches December, any 2 digits for the day, and ends with 2024. 
grep -E '12-[0-9]{2}-2024$' emails.txt

echo "Question 9:"
# ',Important,' looks for exact word Important surrounded by commas to exclude replies. 
grep -E ',Important,' emails.txt

echo "Question 10:"
# '^EMAIL Boss,Re:' looks for lines starting with Boss, followed by "Re:".
grep -E '^EMAIL Boss,Re:' emails.txt

echo "Question 11:"
# 'Person,' matches sender name ending with "Person" right before comma. 
grep -E 'Person,' emails.txt

echo "Question 12:"
# '-c' tells grep to count the no. of lines that start with "EMAIL", answering the prompt to count the lines of the emails. 
grep -c -E '^EMAIL' emails.txt

echo "Question 13:"
# Filters for command words, then 'tr' translates all uppercase characters to lowercase. 
grep -E 'COUNT|NEXT|READ' emails.txt | tr '[:upper:]' '[:lower:]'

echo "Question 14:"
# Filters for lines containing "Person", then 'sed' substitutes ('s') specific names with "Others" globally ('g').
grep -E 'Person' emails.txt | sed -E 's/ImportantPerson|OtherPerson/Others/g'

echo "Question 15:"
# Filters all EMAIL lines, then 'awk' splits the string by comma and prints second substring. 
grep -E '^EMAIL' emails.txt | awk '{split($0, a, ","); print a[2]}'