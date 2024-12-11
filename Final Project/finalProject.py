
#Levenshtein Distance : Used to determine whether a terminal is misspelled, or if it is just an identifier name
def levenshteinRecursive(str1, str2, m, n):
      # str1 is empty
    if m == 0:
        return n
    # str2 is empty
    if n == 0:
        return m
    if str1[m - 1] == str2[n - 1]:
        return levenshteinRecursive(str1, str2, m - 1, n - 1)
    return 1 + min(
        # Insert     
        levenshteinRecursive(str1, str2, m, n - 1),
        min(
        # Remove
        levenshteinRecursive(str1, str2, m - 1, n),
        # Replace
        levenshteinRecursive(str1, str2, m - 1, n - 1))
    )

def parseExpression() -> bool:
    tokens = []

    # Read in the file final24.txt and tokenize it
    with open('final24.txt', 'r') as file:
        for line in file:
            tokens += line.split()

    
    parsingTable = [
        ['program I ; var B begin C end', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', 'L K', 'L K', 'L K', 'L K', 'L K', 'L K', '', '', '', '', '', '', '', '', '', ''],
        ['', 'λ', '', 'λ', 'λ', '', '', 'λ', '', 'λ', 'λ', 'λ', 'λ', 'λ', '', '', '', 'L K', 'L K', 'L K', 'L K', 'L K', 'L K', 'J K', 'J K', 'J K', 'J K', 'J K', 'J K', 'J K', 'J K', 'J K', 'J K'],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', 'D : Y ;', 'D : Y ;', 'D : Y ;', 'D : Y ;', 'D : Y ;', 'D : Y ;', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', 'I X', 'I X', 'I X', 'I X', 'I X', 'I X', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', ', D', 'λ', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', 'integer', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', 'S Z', '', '', 'S Z', 'S Z', 'S Z', 'S Z', 'S Z', 'S Z', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', 'W', '', '', 'A', 'A', 'A', 'A', 'A', 'A', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', 'C', '', 'λ', 'C', 'C', 'C', 'C', 'C', 'C', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', 'print ( G I ) ;', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '"value=",', '', 'λ', 'λ', 'λ', 'λ', 'λ', 'λ', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', 'I = E ;', 'I = E ;', 'I = E ;', 'I = E ;', 'I = E ;', 'I = E ;', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', 'T Q', '', 'T Q', 'T Q', '', '', '', '', '', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q', 'T Q'],
        ['', 'λ', '', '', '', '', '', '', '', 'λ', '+ T Q', '- T Q', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', 'F R', '', 'F R', 'F R', '', '', '', '', '', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R', 'F R'],
        ['', 'λ', '', '', '', '', '', '', '', 'λ', 'λ', 'λ', '* F R', '/ F R', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''],
        ['', '', '', '', '', '', '', '', '( E )', '', 'N', 'N', '', '', '', '', '', 'I', 'I', 'I', 'I', 'I', 'I', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'],
        ['', '', '', '', '', '', '', '', '', '', 'M J H', 'M J H', '', '', '', '', '', '', '', '', '', '', '', 'M J H', 'M J H', 'M J H', 'M J H', 'M J H', 'M J H', 'M J H', 'M J H', 'M J H', 'M J H'],
        ['', 'λ', '', '', '', '', '', '', '', 'λ', 'λ', 'λ', 'λ', 'λ', '', '', '', '', '', '', '', '', '', 'J H', 'J H', 'J H', 'J H', 'J H', 'J H', 'J H', 'J H', 'J H', 'J H'],
        ['', '', '', '', '', '', '', '', '', '', '+', '-', '', '', '', '', '', '', '', '', '', '', '', 'λ', 'λ', 'λ', 'λ', 'λ', 'λ', 'λ', 'λ', 'λ', 'λ'],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'],
        ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', 'a', 'b', 'c', 'd', 'l', 'f', '', '', '', '', '', '', '', '', '', '']
    ]
    
    
    terminals = ['program',';','var', ',', ':', 'integer', 
                'begin', '=', '(', ')', '+', '-', '*', '/',
                'print', '"value=",', 'end', 'a', 'b', 'c', 'd', 'l', 'f', 
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    
    misspellableTerminals = ['program', 'var', 'begin', 'end', 'integer', 'print']

    nonterminals = ['P', 'I', 'K', 'B', 'D', 'X', 'Y', 'C', 'S', 'Z', 'W', 'G', 'A', 'E', 'Q', 'T', 'R', 'F', 'N', 'H', 'M', 'J', 'L']

    stack = ['$', 'P']

    print(f"Stack: {stack}")
    print(f"Input: {tokens}")
    
    while tokens:
        
        token = tokens.pop(0)
        print(f"Current token: {token}")
        
        #if the token is not in terminals, break the token into chars and replace that token in place
        if token not in terminals:
            # handle case where a token is misspelled
            for terminal in misspellableTerminals:
                #This will run if the token and terminal are 1 char off from each other (e.g. 'prgram' and 'program')
                if levenshteinRecursive(token, terminal, len(token), len(terminal)) < 2:
                    print(f"ERROR: \"{terminal}\" was expected, but \"{token}\" was found")
                    return False
            
            #breaks the token into characters and reads those tokens (if it is an identifier)
            for c in reversed(token):
                tokens.insert(0, c)
            token = tokens.pop(0)
        print(f"Input: {tokens}")
        
        popped = stack.pop()
        while token != popped:

            # if the popped nonterminal is a terminal, then the input string is invalid
            if popped in terminals:
                print(f"ERROR: {popped} was expected")
                return False
            
            #if the popped nonterminal is lambda, then pop the next nonterminal
            if popped == 'λ':
                popped = stack.pop()
                continue

            #get the row and column of the popped nonterminal and the current character
            row = nonterminals.index(popped)
            col = terminals.index(token)

            #if the cell is empty, then the input string is invalid
            print(f"Go to : [{nonterminals[row]}, {terminals[col]}]= {parsingTable[row][col]}")
            if parsingTable[row][col] == '':
                expected_tokens = []
                for i in range(len(terminals)):
                    if parsingTable[row][i] != '':
                        expected_tokens.append(terminals[i])

                # Check for specific missing punctuation tokens
                missing_token = None
                for tok in [';', ',', '.', '(', ')']:
                    if tok in expected_tokens:
                        missing_token = tok
                        break

                # Print appropriate error message
                if missing_token:
                    print(f"ERROR: \"{missing_token}\" is missing.")
                else:
                    print(f"ERROR: Unexpected token \"{token}\" after \"{popped}\". Expected one of: {', '.join(expected_tokens)}.")
                return False

            #push the characters in the cell to the stack
            for c in reversed(parsingTable[row][col].split()):
                stack.append(c)
            print(f"Stack: {stack}")
            popped = stack.pop() 

        print(f"Matched: {token}")
        
    return True



if __name__ == '__main__':
    if(parseExpression()):
        print("The file is valid")
    else:
        print("The file is invalid")
        