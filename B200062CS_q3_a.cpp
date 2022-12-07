// string matching Naive Algorithm
// NAME: UJJWAL KUMAR
// ROLL: B200062CS

#include <iostream>
using namespace std;

int main()
{
    string T, P;
    cout << "enter a text :  ";
    cin >> T;
    cout << "enter a pattern to search : ";
    cin >> P;
    int n = T.length();
    int m = P.length();
    // int numberOfIterations = 0;
    int count = 0;
    cout << "Pattern matches at index : ";
    for (int i = 0; i <= n - m; i++)
    {
        int c = 0;
        for (int j = 0; j < m; j++)
        {
            // numberOfIterations++;
            if (P[j] == T[i + j])
                c++;
        }
        if (c == m)
        {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nTotal matches : " << count;
    // cout << "\n n = " << n << " m = " << m;
    // cout << "\nTotal iterations : " << numberOfIterations << " (n-m+1)*m";
}
