/* Write a program for the Rabin-Karp algorithm. Using the written program, find out
number of spurious hits does the Rabin-Karp matcher encounter in the text
T = 3141592653589793 when looking for the pattern P = 26. Consider working modulo
q = 11. */
#include <bits/stdc++.h>
using namespace std;
int M = 11;
int main()
{
    string text, pattern;
    cout << "Enter the text : ";
    cin >> text;
    fflush(stdin);
    cout << "Enter the pattern to be searched :  ";
    cin >> pattern;
    int pmat = 0, t0 = 0;
    int n = text.size(), k = pattern.size();
    for (int i = 0; i < k; i++)
    {
        pmat = ((pmat * 10) % M + (pattern[i] - '0')) % M;
        t0 = ((t0 * 10) % M + (text[i] - '0')) % M;
    }
    vector<int> t(n);
    t[0] = t0;
    // cout<<"pmat= "<<pmat<<"\n";
    // cout<<"t0 = "<<t[0]<<"\n";s
    int prod = ((int)pow(10, k - 1)) % M;
    for (int i = 1; i < n - k + 1; i++)
    {
        int x = 10 * (t[i - 1] - prod * (text[i - 1] - '0'));
        t[i] = (x + (text[i + k - 1] - '0')) % M;
        if (t[i] < 0)
        {
            t[i] += M;
        }

        // cout<<"i= "<<i<<" t[i]= "<<t[i]<<" \n";
    }
    int matchCnt = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        if (t[i] == pmat)
        {
            matchCnt++;
            int j = 0;
            for (j = 0; j < k; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == k)
            {
                cout << "\nPattern found at index : " << i << "\n";
                // matchCnt++;
            }
        }
    }
    cout << "Number of hits : " << matchCnt << "\n";
    if (matchCnt == 0)
    {
        cout << "Pattern not Found!!\n";
    }
}