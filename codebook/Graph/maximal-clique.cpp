/*
 * compute maximal cliques
 * |maximum clique|=
 * |comp(G)'s maximum independent set|
 * comp(G) Complete Graph's Edge - G's Edge
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull adj[64];
vector<ull> cliques; // if ith bit is 1 then i is in that maximal clique

void BronKerbosch(ull R, ull P, ull X)
{
    if (P == 0 && X == 0) {
        cliques.push_back(R);
    }
    /*
     * Returns the number of trailing 0-bits in x, starting at the least significant bit position.
     * If x is 0, the result is undefined.
     */
    int p = __builtin_ctzll(P | X);
    ull Q = P & ~adj[p];
    while (Q) {
        int i = __builtin_ctzll(Q);
        BronKerbosch(R | (1ULL << i), P & adj[i], X & adj[i]);
        Q&=~(1ULL<<i) ; P&=~(1ULL<<i); X|=(1ULL<<i);
    }
}
