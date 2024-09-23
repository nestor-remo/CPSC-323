def evaluatePostFix(expression, variables):
    operands = ['+', '-', '*']
    stack = []

    for char in expression:
        if char in variables:
            stack.append(variables[char])
        elif char.isdigit():
            stack.append(int(char))
        elif char == operands[0]:
            temp = stack.pop()
            stack[-1] += temp
        elif char == operands[1]:
            temp = stack.pop()
            stack[-1] -= temp
        elif char == operands[2]:
            temp = stack.pop()
            stack[-1] *= temp
        elif char == '$':
            return stack.pop()
    return None

def main():
    while True:
        user_input = input("Enter a postfix expression with $ at the end:")
        
        user_input = user_input.split()

        variables = {}

        for token in user_input:
            if token.isalnum() and token[0].isalpha():
                value = int(input(f"Enter value for {token}:"))
                variables[token] = value

        print(f"Value = {evaluatePostFix(user_input, variables)}")

        continuing = input("CONTINUE?(y/n)?")
        if continuing != 'y':
            break
        
if __name__ == "__main__":
    main()