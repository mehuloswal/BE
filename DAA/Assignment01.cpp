#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long recursive_fibonacci(long long n) // S:O(n) T:exponential
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;

        return recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
    }
    void recursive_fibonacci(long long a, long long b, long long n)
    {
        if (n == 0)
        {
            return;
        }
        if (a == -1)
        {
            cout << 0 << "\n";
            recursive_fibonacci(0, -1, n - 1);
            return;
        }
        if (b == -1)
        {
            cout << 1 << "\n";
            recursive_fibonacci(0, 1, n - 1);
            return;
        }
        cout << a + b << "\n";
        recursive_fibonacci(b, a + b, n - 1);
        return;
    }
    void non_recursive_fibonacci(long long n) // S:O(1)  T:O(n)
    {
        long long a = 0;
        long long b = 1;
        if (n >= 1)
        {
            cout << a << "\n";
        }
        if (n >= 2)
        {
            cout << b << "\n";
        }
        long long c;
        while (--n > 1)
        {
            c = a + b;
            cout << c << "\n";
            a = b;
            b = c;
        }
    }
};

int main()
{
    Solution s;
    char choice;
    char cont;
    int n;
    while (true)
    {
        cout << "\nEnter the number of digits of the fibonacci series you want to print: ";
        cin >> n;
        while (n <= 0)
        {
            cout << "Enter a valid number : ";
            cin >> n;
        }

        cout << "\n\nChoose method -> Recursive [0] || Non Recursive [1] : ";
        cin >> choice;
        if (choice == '0')
        {
            s.recursive_fibonacci(-1, -1, n);
        }
        else
        {
            s.non_recursive_fibonacci(n);
        }
        cout << "\n\nContinue? (Y/N) : ";
        cin >> cont;
        if (cont != 'Y' && cont != 'y')
        {
            cout << "Thank You!";
            break;
        }
    }
    return 0;
}