f = open("test.txt", "r")

res = []

for line in f:
    word = ""
    for char in line:
        if char.isspace():
            if word:
                res.append(word)
                word = ""
            res.append(char)  # Include whitespace as a separate element
        else:
            word += char
    if word:
        res.append(word)
        
        
        

f.close()


print(res)

 