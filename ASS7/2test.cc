#include <iostream>
#include <stack>
#include <string>

using namespace std;

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

    // Function to get column based on input symbol
    auto getCol = [](char ch) {
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
    };

    // Main parsing loop
    while (!parseStack.empty()) {
        string top = parseStack.top();
        parseStack.pop();

        // Display stack and input status
        cout << "Stack: ";
        for (auto s = parseStack; !s.empty(); s.pop()) cout << s.top() << " ";
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
            int row = -1;
            if (top == "S") row = 0;
            else if (top == "W") row = 1;
            else if (top == "E") row = 2;
            else if (top == "Q") row = 3;
            else if (top == "T") row = 4;
            else if (top == "R") row = 5;
            else if (top == "F") row = 6;

            int col = getCol(w[i]);
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



