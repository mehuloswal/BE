#include <bits/stdc++.h>
using namespace std;
int c = 0;
void NaiveSearch(string pat, string txt)
{
    int m = pat.size();
    int n = txt.size();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < n; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == m)
        {
            c = 1;
            cout << "Pattern found at index " << i << endl;
        }
    }
}
int main()
{
    string text = "AABAACAADAABAAABAA";
    string pat = "AABA";
    NaiveSearch(pat, text);
    if (!c)
    {
        cout << "Pattern Not Found" << endl;
    }
    return 0;
}