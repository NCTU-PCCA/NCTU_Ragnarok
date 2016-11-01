#include<bits/stdc++.h>
const int N = 500;
int dp[N][N];
void floyd_warshall()
{
    for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX);
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}
