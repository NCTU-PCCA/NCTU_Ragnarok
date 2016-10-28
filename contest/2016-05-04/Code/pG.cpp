/*
    Author: 0Alien0
    School: NCTU
*/
#include<bits/stdc++.h>

#define FI freopen("in.txt", "r", stdin)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define EPS 1E-7
#define INF 0x7FFFFFFF
#define PI 3.1415926535897932384626433832795

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VII;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

//int dx[] = {-1,0,1,0};
//int dy[] = {0,1,0,-1};

#define MAX_NUMBER 10000
#define Module 1000000007

LL factor[2*MAX_NUMBER+1];
LL inverse_factor[MAX_NUMBER+1];

LL inverse(LL A,LL B,LL X = 1,LL Y = 0){
    if(A%B == 0){
        if(Y < 0)Y += Module;
        return Y;
    }
    X-=Y*(A/B);
    return inverse(B,A%B,Y,X);
}

void initialize(){
    factor[0] = 1;
    for(int i=1;i<2*MAX_NUMBER+1;i++)factor[i] = (factor[i-1]*i)%Module;
    inverse_factor[1] = 1;
    for(int i=2;i<MAX_NUMBER+1;i++)inverse_factor[i] = (inverse_factor[i-1]*inverse(i,Module))%Module;
}

int main(){
    IOS;
    initialize();
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        cout << factor[N+M]*inverse_factor[N]%Module*inverse_factor[M]%Module << endl;
    }
    return 0;
}
