from cs50 import get_string

text = get_string("text:")

c = letters = words = sentences = L = S = 0

while c < len(text):
    if ((text[c] >= 'a' and text[c] <= 'z') or (text[c] >= 'A' and text[c] <= 'Z')):
        letters += 1
    if (text[c] == ' '):
        words += 1
    if ((text[c] == '.') or (text[c] == '!') or (text[c] == '?')):
        sentences += 1
    c += 1

words += 1

L = (letters / words * 100)
S = (sentences / words * 100)

index = 0.0588 * L - 0.296 * S - 15.8

if (index < 1):
    print("Before Grade 1 ")

elif (index >= 16):
    print("Grade 16+")

else:
    print("Grade", round(index))