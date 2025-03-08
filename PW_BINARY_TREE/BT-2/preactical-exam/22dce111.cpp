// #include <iostream>
// #include <map>
// #include <set>
// #include <vector>
// #include <cctype>

// using namespace std;

// map<char, set<char>> first;
// map<char, vector<string>> grammar;
// char startSymbol;

// void calfi(char symbol) {
//     if (first.find(symbol) != first.end()) return;

//     first[symbol] = {};

//     for (auto prod : grammar[symbol]) {
//         if (islower(prod[0]) || prod[0]=='e') {
//             first[symbol].insert(prod[0]);
//         } else {
//             for (int i = 0; i < prod.length(); i++) {
//                 char ch = prod[i];
//                 if (ch == symbol) break;
//                 calfi(ch);
//                 first[symbol].insert(first[ch].begin(), first[ch].end());
//                 if (first[ch].find('e') == first[ch].end()) break;
//             }
//         }
//     }
// }

// int main() {
//     int numRules;
//     cout << "Enter the number of productions: ";
//     cin >> numRules;
//     cin.ignore();

//     cout << "Enter the productions:"<<endl;
//     for (int i = 0; i < numRules; i++) {
//         string input;
//         getline(cin, input);
//         char lhs = input[0];
//         if (i == 0) startSymbol = lhs;
//         string rhs = input.substr(3);
//         vector<string> productions;
//         int pos = 0;
//         while ((pos = rhs.find('|')) != -1) {
//             productions.push_back(rhs.substr(0, pos));
//             rhs.erase(0, pos + 1);
//         }
//         productions.push_back(rhs);
//         grammar[lhs] = productions;
//     }

//     for (auto &rule : grammar) calfi(rule.first);

//     cout << "\nFIRST Sets:\n";
//     for (auto &p : first) {
//         cout << "FIRST(" << p.first << ") = { ";
//         for (char ch : p.second) cout << ch << " ";
//         cout << "}\n";
//     }

//     return 0;
// }

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

map<char, set<char>> first, follow;
map<char, vector<string>> grammar;
char startSymbol;

void First(char symbol)
{
    if (first.find(symbol) != first.end())
        return;

    first[symbol] = {};

    for (auto prod : grammar[symbol])
    {
        if (islower(prod[0]) || !isalpha(prod[0]))
        {
            first[symbol].insert(prod[0]);
        }
        else
        {
            for (int i = 0; i < prod.length(); i++)
            {
                char ch = prod[i];
                if (ch == symbol)
                    break;
                First(ch);
                first[symbol].insert(first[ch].begin(), first[ch].end());
            }
        }
    }
}

int main()
{
    int numRules;
    cout << "Enter the number of productions: ";
    cin >> numRules;
    cin.ignore();

    cout << endl
         << "Enter the productions:" << endl;
    for (int i = 0; i < numRules; i++)
    {
        string input;
        getline(cin, input);
        char lhs = input[0];
        if (i == 0)
            startSymbol = lhs;
        string rhs = input.substr(3);
        vector<string> productions;
        int pos = 0;
        while ((pos = rhs.find('|')) != -1)
        {
            productions.push_back(rhs.substr(0, pos));
            rhs.erase(0, pos + 1);
        }
        productions.push_back(rhs);
        grammar[lhs] = productions;
    }

    for (auto &rule : grammar)
        First(rule.first);

    cout << endl
         << "FIRST Sets:" << endl;
    for (auto &p : first)
    {
        cout << "FIRST(" << p.first << ") = { ";
        for (char ch : p.second)
            cout << ch << " ";
        cout << "}\n";
    }

    return 0;
}
