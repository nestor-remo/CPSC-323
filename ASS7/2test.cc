#include <iostream>
#include <stack>
#include <string>

using namespace std;

//determines the column number for the parsing table
int getCol(char ch) {
    switch (ch) {
        case 'a': return 0;
        case 'b': return 1;
        case '+': return 2;
        case '-': return 3;
        case '*': return 4;
        case '/': return 5;
        case '(': return 6;
        case ')': return 7;
        case '=': return 8;
        case '$': return 9;
        default: return -1;
    }
}

//determines the row number for the parsing table
int getRow(char ch) {
    switch (ch) {
        case 'S': return 0;
        case 'W': return 1;
        case 'E': return 2;
        case 'Q': return 3;
        case 'T': return 4;
        case 'R': return 5;
        case 'F': return 6;
        default: return -1;
    }
}


int main() {
    cout << "Enter a string, followed by $: ";
    string w;
    cin >> w;
    int i = 0;

    stack<string> parseStack;
    parseStack.push("$");
    parseStack.push("S");

    // Parsing Table
    string table[7][10] = {
        {"aW", "", "", "", "", "", "", "", "", ""}, 
        {"", "", "", "", "", "", "", "", "=E", ""},
        {"TQ", "TQ", "", "", "", "", "TQ", "", "", ""},     
        {"", "", "+TQ", "-TQ", "", "", "", "lambda", "", "lambda"}, 
        {"FR", "FR", "", "", "", "", "FR", "", "", ""},  
        {"", "", "lambda", "lambda", "*FR", "/FR", "", "lambda", "", "lambda"},  
        {"a", "b", "", "", "", "", "(E)", "", "", ""}  
    };

    // Main parsing loop
    while (!parseStack.empty()) {
        string top = parseStack.top();
        parseStack.pop();

        // Display stack and input status
        cout << "Stack: ";
        stack<string> tempStack = parseStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << top << endl;
        cout << "Input: " << w.substr(i) << endl;

        // If the top of stack matches the input symbol, advance
        if (top == string(1, w[i])) {
            cout << "Match with input " << w[i] << endl;
            i++;
        } 
        else if (top == "lambda") {
            continue; // Skip lambda without modifying the stack
        } 
        else {
            // Determine row and column for table lookup
            int row = getRow(top[0]);
            int col = getCol(w[i]);

            // Check for invalid input
            if (row == -1 || col == -1 || table[row][col].empty()) {
                cout << "Input is REJECTED" << endl;
                return 0;
            }

            // Retrieve rule from table
            string production = table[row][col];
            cout << "Go to [" << top << ", " << w[i] << "] = " << production << endl;

            // Push rule in reverse order to stack, if not lambda
            if (production != "lambda") {
                for (int j = production.size() - 1; j >= 0; j--) {
                    parseStack.push(string(1, production[j]));
                }
            }
        }
    }

    // Final validation check
    if (i == w.size()) {
        cout << "Input is ACCEPTED" << endl;
    } else {
        cout << "Input is REJECTED" << endl;
    }

    return 0;
}



