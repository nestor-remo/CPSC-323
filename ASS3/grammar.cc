#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter a string, followed by $: ";
    string w;
    cin >> w;
    int i = 0, col = 0, state;
    


    // CFG: 
    // S -> aA | bB | cC
    // B -> bB | aC | +
    // C -> aS | +
    int table[4][3] = {
        {0,1,2},
        {2,1,3},
        {0,3,3},
        {3,3,3} 
    }; 

    while (i < w.size()) 
    {
        switch (w[i])
        {
        case 'a': col = 0; break;
        case 'b': col = 1; break;
        case 'c': col = 2; break;
        case '$': if(state == 3)
            {
                cout << "Not Accepted" << endl;
            }
            else
            {
                cout << "Accepted" << endl;
            }
        }
    state = table[state][col];
    i++;
    }
}