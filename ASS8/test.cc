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

    while (!parseStack.empty()) 
    {
        string top = parseStack.top();

        int row = stoi(top);
        int col = getCol(w[i]);

        // Print the current state of the stack
        cout << "Stack: ";
        stack<string> tempStack = parseStack;
        while (!tempStack.empty()) 
        {
            cout << tempStack.top();
            tempStack.pop();
        }
        cout << endl;
    

        if (row == -1 || col == -1 || table[row][col] == "") 
        {
            cout << "Not Accepted" << endl;
            return 0;
        }


        // Check if the table entry is a number entry
        else if ( ){

        }


        // Check if the table entry is an accepted entry
        else if (table[row][col] == "ACC") 
        {
            cout << "Accepted" << endl;
            return 0;
        }

        // Check if the table entry is an 'R' entry
        else if (table[row][col][0] == 'S')
        {
            
        }
        
        // Check if the table entry is an 'S' entry
        else if (table[row][col][0] == 'R') 
        {
            i++;
        }
        
    }

    return 0;
}