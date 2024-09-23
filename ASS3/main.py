file = open("test.txt", "r")

reserved = {"while", "for", "switch", "do", "return"}

res = []

for line in file:
    res.append(line.strip())  

file.close()

for token in res:
    if token.lower() in reserved:
        print(f"{token} is a reserved word")
    elif token[0] == "_" or token[0].isalpha():
        print(f"{token} is an identifier")
    elif token.isdigit():
        print(f"{token} is a number")
    else:
        print(f"{token} is nothing")