// m+t
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string m)
{
    int n = m.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 and m[i] != m[j])
        {
            j = pi[j - 1];
        }

        if (m[i] == m[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int main()
{

    string t, m;
    cout << "enter the text :";
    cin >> t;
    cout << "enter the matching string : ";
    cin >> m;
    vector<int> prefix = prefix_function(m);
    vector<int> ans;
    int val(0);
    int pos = -1;
    int i = 0, j = 0;
    while (i < t.size())
    {
        if (t[i] == m[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == m.size())
        {
            pos = i - m.size();
            // break;
            ans.push_back(pos);
        }
    }
    cout << "string found at index : ";
    // cout << pos;
    for(auto res:  ans){
           cout<<res<<" ";
    }

    cout << endl;
    return 0;
}