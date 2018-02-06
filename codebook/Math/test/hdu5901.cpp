// a0919610611/fuyu0425/twleo
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 320000;
int L[N], H[N];
int SR(int n, int p)
{
    int m;
    for (m = 1; m * m <= n; m++) {
        H[m] = n / m - 1;
    }
    for (int i = 1; i <= m; i++) {
        L[i] = i - 1;
    }
    for (int i = 2; i <= m; i++) {
        if (L[i] == L[i - 1])
            continue;
        for (int j = 1; j <= min(m - 1, n / i / i); j++) {
            if (i * j < m) {
                H[j] -= H[i * j] - L[i - 1];
            } else {
                H[j] -= L[n / i / j] - L[i - 1];
            }
        }
        for (int j = m; j >= i * i; j--) {
            L[j] -= L[j / i] - L[i - 1];
        }
    }
    return H[1];
}
int pi(int n)
{
    return SR(n, n);
}
#undef int
int main()
{
#define int long long
    int n;
    while (cin >> n) {
        cout << pi(n) << endl;
    }

    return 0;
}
