#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> ans;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        vector<int> r;
        int num;
        stringstream ss(line);
        while (ss >> num)
            r.push_back(num);
        ans.push_back(r);
    }
    for (auto it : ans)
    {
        for (auto tit : it)
            cout << tit << " ";
        cout << endl;
    }
    return 0;
}