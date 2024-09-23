variables = {
    'a': 5,
    'b': 7,
    'c': 2,
    'd': 4
}

operands = ['+', '-', '*']

isRunning = True

while isRunning:
    user_input = input("Enter a postfix expression with $ at the end: ")
    stack = []
    for char in user_input:
        if char in variables:
            stack.append(variables[char])
        if char == operands[0]:
            temp = stack.pop()
            stack[-1] += temp
        if char == operands[1]:
            temp = stack.pop()
            stack[-1] -= temp
        if char == operands[2]:
            temp = stack.pop()
            stack[-1] *= temp
        if char == '$':
            print(f"Value = {stack.pop()}")
    continuing = input(f"CONTINUE?(y/n)? ")
    if continuing == 'y':
        isRunning = True
    else:
        isRunning = False