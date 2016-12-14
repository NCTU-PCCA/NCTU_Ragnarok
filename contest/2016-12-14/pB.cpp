/*
    Author: 0Alien0
    Country: Taiwan
    School: NCTU
*/
#include<bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) ((int)((x).size()))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long LL;

const int MOD = 1000000009;
const int HASH = 137;
const int NUM = 1000000;

const double pi = 3.14159265358979323846;
const double eps = 1e-7;

#define int LL

int dp[35][2];

int Go(int x,int last){
    if(x == 1){
        if(last == 0)return 3;
        else return 2;
    }
    if(dp[x][last] == -1){
        if(last == 0)dp[x][last] = (Go(x-1,0)+Go(x-1,1))*2+Go(x-1,0);
        else dp[x][last] = (Go(x-1,0)+Go(x-1,1))+Go(x-1,0);
    }
    return dp[x][last];
}

#undef int

int main(){
    #define int LL
    IOS;
    for(int i=0;i<35;i++)for(int j=0;j<2;j++)dp[i][j] = -1;
    int T;cin >> T;
    while(T--){
        int N;cin >> N;
        cout << Go(N,0)+Go(N,1) << endl;
    }
    return 0;
}
