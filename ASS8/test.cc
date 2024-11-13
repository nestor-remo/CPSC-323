#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

//determines the column number for the parsing table
int getCol(char ch) {
    switch (ch) {
        case 'i': return 0;
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
        case '(': return 5;
        case ')': return 6;
        case '$': return 7;
        case 'E': return 8;
        case 'T': return 9;
        case 'F': return 10;
        default: return -1;
    }
}

void printStack(stack<string> s) 
{
    stack<string> temp;
    while (!s.empty()) 
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) 
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void printGoTo(string row, char col, string entry)
{
    cout << "Goto [" << row << ", " << col << "] = " << entry << endl;
}

int main()
{

    cout << "Enter a string, followed by $: ";
    string w;
    cin >> w;
    int i = 0;

    stack<string> parseStack;
    parseStack.push("0");

    // Parsing Table
    string table[16][11] = 
    {
        {"S5", "", "", "", "", "S4", "", "", "1", "2", "3"},
        {"", "S6", "S7", "", "", "", "", "ACC", "", "", ""},
        {"", "R3", "R3", "S8", "S9", "", "R3", "R3", "", "", ""},
        {"", "R6", "R6", "R6", "R6", "", "R6", "R6", "", "", ""},
        {"S5", "", "", "", "", "S4", "", "", "10", "2", "3"},
        {"", "R8", "R8", "R8", "R8", "", "R8", "R8", "", "", ""},
        {"S5", "", "", "", "", "S4", "", "", "", "11", "3"},
        {"S5", "", "", "", "", "S4", "", "", "", "12", "3"},
        {"S5", "", "", "", "", "S4", "", "", "", "", "13"},
        {"S5", "", "", "", "", "S4", "", "", "", "", "14"},
        {"", "S6", "S7", "", "", "", "S15", "", "", "", ""},
        {"", "R1", "R1", "S8", "S9", "", "R1", "R1", "", "", ""},
        {"", "R2", "R2", "S8", "S9", "", "R2", "R2", "", "", ""},
        {"", "R4", "R4", "R4", "R4", "", "R4", "R4", "", "", ""},
        {"", "R5", "R5", "R5", "R5", "", "R5", "R5", "", "", ""},
        {"", "R7", "R7", "R7", "R7", "", "R7", "R7", "", "", ""}        
        
    };


    unordered_map<string, string> productions = 
    {
        {"1", "E->E+T"},
        {"2", "E->E-T"},
        {"3", "E->T"},
        {"4", "T->T*F"},
        {"5", "T->T/F"},
        {"6", "T->F"},
        {"7", "F->(E)"},
        {"8", "F->i"}
    };

    // Main parsing loop
    while (true) 
    {
        string top = parseStack.top();

        // Display stack and input status
        cout << "Stack: ";
        printStack(parseStack);
        cout << "Pop: " << top << endl;
        parseStack.pop();
        cout << "Input: " << w.substr(i) << endl;

        int row = stoi(top);
        int col = getCol(w[i]);
        string entry = table[row][col];
        
        printGoTo(to_string(row), w[i], entry);

        // Check if the table entry is empty
        if (row == -1 || col == -1 || entry == "") 
        {
            cout << "Not Accepted" << endl;
            break;
        }



        // Check if the table entry is a number entry
        else if (isdigit(entry[0]))
        {
            parseStack.push(to_string(row));
            parseStack.push(to_string(col));
            parseStack.push(entry);
        }

        // Check if the table entry is an accepted entry
        else if (entry == "ACC") 
        {
            cout << "Accepted" << endl;
            break;
        }

        // Check if the table entry is an 'S' entry
        else if (entry[0] == 'S')
        {
            string n = entry.substr(1);
            parseStack.push(to_string(row));
            parseStack.push(string(1, w[i]));
            parseStack.push(n);

            cout << "Push: " << row << "," << w[i] << "," << n << endl;
            i++;
        }
        
        // Check if the table entry is an 'R' entry
        else if (entry[0] == 'R') 
        {
            parseStack.push(to_string(row));
            cout << "Push: " << row << endl;

            cout << "Stack: ";
            printStack(parseStack);

            string production = productions[string(1, entry[1])];
            cout << "Production #" << string(1, entry[1]) << ": " << production << endl;

            string rhs = production.substr(production.find("->") + 2); 
            string lhs = production.substr(0, production.find("->"));

            for (int x = 0; x < 2 * rhs.length(); x++) 
            {
                parseStack.pop();

            }         
            
            cout << "Stack: ";
            printStack(parseStack);


            string newTop = parseStack.top();

            int newEntry = stoi(table[stoi(newTop)][getCol(lhs[0])]);

            parseStack.push(lhs);
            parseStack.push(to_string(newEntry));

            printGoTo(newTop, lhs[0], to_string(newEntry));
        }
        
    }

    return 0;
}