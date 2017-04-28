#include <bits/stdc++.h>
using namespace std;
const int p = 5; //prime
int fac[p + 1];
void build_fac(int p)
{
    fac[0] = 1;
    for (int i = 1; i <= p; i++)
        fac[i] = fac[i - 1] * i % p;
}
//mod inverse
int inv(int a, int p)
{
}
//called after build_fac
int Lucas(int n, int m, int p)
{
    if (m == 0)
        return 1;
    if (m > n)
        return 0;
    if (n < m)
        return fac[n] * inv(fac[m] * fac[n - m] % p, p) % p;
    else
        return Lucas(n / p, m / p, p) * Lucas(n % p, m % p, p) % p;
}
