sample_string = "abbbaaacc$"

fa = { 'S' : ['aS', 'bB', 'cC'],
       'B' : ['bB', 'aC', 'lambda'],
       'C' : ['aS', 'lambda']}


curr_node = 'S'
for char in sample_string:
    success_flag = False
    if char == '$':
        print('string is accepted')
        break
    for elem in fa[curr_node]:
        #has a path possible
        if elem[0] == char:
            curr_node = elem[1]
            success_flag = True
            break
    if success_flag:
        continue
    else:
        print('string is not accepted')
        break