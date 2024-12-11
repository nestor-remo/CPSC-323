'''
Program that parses the data from the final.txt file and creates a new file
called final24.txt that contains a parsed version of the data. The parsed data does nto have any comments defined by
the (* and *) symbols. The parsed data is also formatted with no empty lines or extraneous spaces.

'''
def parse_text(input_file: str, output_file: str = 'final24.txt') -> None:
    with open(input_file, 'r') as file:
        data = file.read()

    data = data.split('\n')
    parsed_data = []
    for line in data:
        if '(*' in line and '*)' in line:
            line = line[:line.index('(*')] + line[line.index('*)') + 2:]
        elif '(*' in line:
            line = line[:line.index('(*')]
        elif '*)' in line:
            line = line[line.index('*)') + 2:]
        if line == '':
            continue
        line = ' '.join(line.split())
        parsed_data.append(line)

    with open(output_file, 'w') as file:
        for line in parsed_data:
            file.write(line + '\n')


if __name__ == '__main__':
    parse_text('final.txt')