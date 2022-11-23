#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p[5] = {0, 1, 2, 5, 6};
    int wt[5] = {0, 2, 3, 4, 5};
    int W = 8, n = 4;
    int k[5][9];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0; // making the first row of the table as 0
            }
            else if (wt[i] <= w)
            {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            }
            else
                k[i][w] = k[i - 1][w];
        }
    }
    cout << k[n][W];
}