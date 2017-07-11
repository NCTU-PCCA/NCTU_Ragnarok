// a0919610611/fuyu0425/twleo
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    if (a < 0)
        return gcd(-a, b);
    return b ? gcd(b, a % b) : a;
}
int ExMultiply(int a, int b, int n)
{
    if (a == 0)
        return 0;
    return ((a & 1) * b % n + (ExMultiply(a >> 1, b, n) << 1) % n) % n;
}
int FastPow(int a, int b, int n)
{
    a %= n;
    int ans = 1;
    int d = a;
    while (b) {
        if (b & 1)
            ans = ExMultiply(ans, d, n);
        d = ExMultiply(d, d, n);
        b >>= 1;
    }
    return ans;
}

bool MillerRabin(int n, int a)
{
    if (n == a)
        return true;
    int d = n - 1, r = 0;
    while (~d & 1) {
        d >>= 1;
    }
    // a^d = ? (mod n)
    int remain = FastPow(a, d, n);
    while (d < n - 1 && remain != 1 && remain != n - 1) {
        remain = ExMultiply(remain, remain, n);
        d <<= 1;
    }
    return (d & 1) || remain == n - 1;
}

bool IsPrime(int n)
{
    if (n == 2)
        return true;
    if (!(n & 1))
        return false;
    static int a[5] = { 2, 3, 7, 61, 24251 };
    for (int i = 0; i < 5; i++) {
        if (!MillerRabin(n, a[i]))
            return false;
    }
    return true;
}
int PollardRho(int n, int c)
{
    int x = rand() % n, y = x, k = 2;
    for (int i = 2;; i++) {
        x = (ExMultiply(x, x, n) + c) % n;
        int d = gcd(x - y, n);
        if (d != 1 && d != n)
            return d;
        if(y==x) return n;
        if (i == k) {
            y = x;
            k <<= 1;
        }
    }
}
int ans;
void fac(int n)
{
    if (IsPrime(n)) {
        ans = min(ans, n);
        return;
    }
    int p = n;
    while (p >= n)
        p = PollardRho(p, rand() % (n - 1) + 1);
    fac(p);
    fac(n / p);
}
#undef int
int main()
{
#define int long long
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (IsPrime(N)) {
            puts("Prime");
        } else {
            ans = 1e18;
            fac(N);
            cout << ans << endl;
        }
    }

    return 0;
}
