#include <bits/stdc++.h>
using namespace std;
int inverse(int A, int M)
{
    return A == 1 ? 1 : inverse(M % A, M) * (M - M / A) % M;
}

/*
 * chinese remainder theorem 
 * check all m[i] are pairwise coprime
 * if x = a1(mod p) and x=a2(mod p) if a1!=a2 
 * then no solution
 * return first positive answer
 * next answer is answer+M
 */
int CRT(vector<int> a, vector<int> m)
{
    if (a.size() != m.size())
        return -1;
    int M = 1;
    for (int i = 0; i < m.size(); i++) {
        M *= m[i];
    }
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        res = (res + a[i] * (M / m[i]) * inverse(M / m[i], m[i])) % M;
    }
    return (res+M)%M;
}
