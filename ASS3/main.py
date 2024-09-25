file = open("test.txt", "r")

reserved = {"while", "for", "switch", "do", "return"}

res = []

for line in file:
    res.append(line.strip())  

file.close()

print(f"Token        number identifier reserved_word")

for token in res:
    isNumber = "no"
    isIdentifier = "no"
    isReserved = "no"
    if token.lower() in reserved:
        isReserved = 'yes'
    elif token.isdigit():
       isNumber = 'yes'
    elif token[0] == "_" or token[0].isalpha() and token[1:].isidentifier():   
        isIdentifier = 'yes'
        
        
    print(f" {token:11}{isNumber:^10}{isIdentifier:^10}{isReserved:^10}")