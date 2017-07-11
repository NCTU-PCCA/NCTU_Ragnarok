// a0919610611/fuyu0425/twleo
#include <algorithm>
#include <cmath>
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
    a %= n;
    b %= n;
    int r = 0;
    while (b) {
        if (b & 1)
            r = ((a + r >= n) ? a + r - n : a + r);
        a = ((a + a >= n) ? a + a - n : a + a);
        b >>= 1;
    }
    return r;
}

int ExExPower(int a, int d, int n)
{
    if (d == 0)
        return 1;
    int k = ExExPower(a, d / 2, n);
    if (d % 2)
        return ExMultiply(ExMultiply(k, k, n), a, n);
    return ExMultiply(k, k, n);
}

bool MillerRabin(int n, int a)
{
    if (n == a)
        return true;
    //even
    if (gcd(n, a) == n)
        return true;
    if (gcd(n, a) != 1)
        return false;
    // a^(d*2^r)
    int d = n - 1, r = 0;
    while (!(d & 1)) {
        d >>= 1;
        r++;
    }
    // a^d = ? (mod n)
    int remain = ExExPower(a, d, n);
    if (remain == 1 || remain == n - 1)
        return true;
    while (r--) {
        remain = ExMultiply(remain, remain, n);
        if (remain == n - 1)
            return true;
    }
    return false;
}

bool IsPrime(int n)
{
    if (n == 2)
        return true;
    if (!(n & 1))
        return false;
    int a[5] = { 2, 3, 7, 61, 24251 };
    for (int i = 0; i < 5; i++)
        if (!MillerRabin(n, a[i]))
            return false;
    return true;
}
int PollardRho(int n, int c)
{
    int x = rand() % n, y = 2, k = 2;
    for (int i = 2;; i++) {
        x = (x * x + c) % n;
        int d = gcd(x - y, n);
        if (d != 1 && d != n)
            return d;
		if(x==y)return n;
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
    fac(n / p);
    fac(p);
}
#undef int
int main()
{
#define int long long
    int N;
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        if (IsPrime(N)) {
            cout << "Prime" << endl;
        } else {
            ans = 1e18;
            fac(N);
            cout << ans << endl;
        }
    }

    return 0;
}
