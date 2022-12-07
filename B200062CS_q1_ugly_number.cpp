// NAME: UJJWAL KUMAR
// ROLL: B200062CS
// PROGRAM 1: UGLY NUMBER

//  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// Note that 1 is typically treated as an ugly number. As example, 10th ugly number
// is 12, because first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12. Write a
// program to find the n-th ugly number. In this program, input is the n as positive
// integer.0

#include <bits/stdc++.h>
using namespace std;

int minimum(int a, int b, int c)
{
    int min;
    if (a < b && a < c)
    {
        min = a;
    }
    else if (b < c)
    {
        min = b;
    }
    else
    {
        min = c;
    }
    return min;
}

int main()
{
    int n;
    cout << "Which ugly number you want to find : ";
    cin >> n;
    int c2 = 0, c3 = 0, c5 = 0;
    vector<int> vec(n + 1);
    vec[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {

        int a = 2 * vec[c2];
        int b = 3 * vec[c3];
        int c = 5 * vec[c5];

        vec[i] = minimum(a, b, c);

        if (2 * vec[c2] == vec[i])
        {
            c2++;
        }
        if (3 * vec[c3] == vec[i])
        {
            c3++;
        }
        if (5 * vec[c5] == vec[i])
        {
            c5++;
        }
    }
    cout << n << "th ugly number is : " << vec[n - 1];

    return 0;
}