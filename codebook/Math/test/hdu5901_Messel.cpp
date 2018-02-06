#include <bits/stdc++.h>
using namespace std;
#define LL long long
struct Melssel_Lehmer {
    static const int N = 5e6 + 2;
    bool notprime[N];
    int prime[N], pi[N];
    static const int M = 7;
    static const int PM = 2 * 3 * 5 * 7 * 11 * 13 * 17;
    int phi[PM + 1][M + 1], sz[M + 1];
    Melssel_Lehmer()
    {
        int cnt = 0;
        notprime[0] = notprime[1] = true;
        pi[0] = pi[1] = 0;
        for (int i = 2; i < N; ++i) {
            if (!notprime[i])
                prime[++cnt] = i;
            pi[i] = cnt;
            for (int j = 1; j <= cnt && i * prime[j] < N; ++j) {
                notprime[i * prime[j]] = true;
                if (i % prime[j] == 0)
                    break;
            }
        }
         sz[0] = 1;
        for (int i = 0; i <= PM; ++i)
            phi[i][0] = i;
        for (int i = 1; i <= M; ++i) {
            sz[i] = prime[i] * sz[i - 1];
            for (int j = 1; j <= PM; ++j)
                phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
        }
    }
    int sqrt2(LL x)
    {
        LL r = (LL)sqrt(x - 0.1);
        while (r * r <= x)
            ++r;
        return r - 1;
    }
    int sqrt3(LL x)
    {
        LL r = (LL)cbrt(x - 0.1);
        while (r * r * r <= x)
            ++r;
        return r - 1;
    }
    LL getphi(LL x, LL s)
    {
        if (s == 0)
            return x;
        if (s <= M)
            return phi[x % sz[s]][s] + (x / sz[s]) * phi[sz[s]][s];
        if (x <= prime[s] * prime[s])
            return pi[x] - s + 1;
        if (x <= prime[s] * prime[s] * prime[s] && x < N) {
            int s2x = pi[sqrt2(x)];
            LL ans = pi[x] - (s2x + s - 2) * (s2x - s + 1) / 2;
            for (int i = s + 1; i <= s2x; ++i)
                ans += pi[x / prime[i]];
            return ans;
        }
        return getphi(x, s - 1) - getphi(x / prime[s], s - 1);
    }
    LL getpi(LL x)
    {
        if (x < N)
            return pi[x];
        LL ans = getphi(x, pi[sqrt3(x)]) + pi[sqrt3(x)] - 1;
        for (int i = pi[sqrt3(x)] + 1, ed = pi[sqrt2(x)]; i <= ed; ++i)
            ans -= getpi(x / prime[i]) - i + 1;
        return ans;
    }
    LL solve(LL x)
    {
        if (x < N)
            return pi[x];
        int a = (int)solve(sqrt2(sqrt2(x)));
        int b = (int)solve(sqrt2(x));
        int c = (int)solve(sqrt3(x));
        LL sum = getphi(x, a) + (LL)(b + a - 2) * (b - a + 1) / 2;
        for (int i = a + 1; i <= b; i++) {
            LL w = x / prime[i];
            sum -= solve(w);
            if (i > c)
                continue;
            LL lim = solve(sqrt2(w));
            for (int j = i; j <= lim; j++)
                sum -= solve(w / prime[j]) - (j - 1);
        }
        return sum;
    }
};
Melssel_Lehmer solver;
int main()
{
    LL n;
    while (cin >> n)
        cout << solver.solve(n) << endl;

    return 0;
}
