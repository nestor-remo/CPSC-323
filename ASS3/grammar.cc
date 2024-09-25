#include <iostream>
#include <string>
using namespace std;

int main() {
    string w = "abbbcaaa$";
    int i = 0, col = 0, state;
    
    int table[4][3] = {
        {0,1,2},
        {2,1,3},
        {1,3,3},
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