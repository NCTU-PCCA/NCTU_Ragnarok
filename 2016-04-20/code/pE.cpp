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

#define MAX_NUMBER 5000

const int module = 5318008;

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        int d,direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};//0 上 1 下 3 左 4 右
        bool x_direction = false;if(abs(x1-x2) > abs(y1-y2))x_direction = true;
        if(x_direction){
            if(x2 < x1)d = 0;
            else d = 1;
        }
        else{
            if(y2 < y1)d = 2;
            else d = 3;
        }
        int dp[N][N];
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=0;
        dp[x1][y1]=1;
        for(int i=0;i<max(abs(x1-x2),abs(y1-y2));i++){
            int x,y;
            x = x1+direction[d][0]*i;
            y = y1+direction[d][1]*i;
            if(x_direction){
                for(int j=y-i;j<=y+i;j++){
                    if(j < 0 || j >= N)continue;
                    int xx = x+direction[d][0];
                    if(j-1 >= 0 && j-1 < N)dp[xx][j-1]=(dp[xx][j-1]+dp[x][j])%module;
                    if(j >= 0 && j < N)dp[xx][j]=(dp[xx][j]+dp[x][j])%module;
                    if(j+1 >= 0 && j+1 < N)dp[xx][j+1]=(dp[xx][j+1]+dp[x][j])%module;
                }
            }
            else{
                for(int j=x-i;j<=x+i;j++){
                    if(j < 0 || j >= N)continue;
                    int yy = y+direction[d][1];
                    if(j-1 >= 0 && j-1 < N)dp[j-1][yy]=(dp[j-1][yy]+dp[j][y])%module;
                    if(j >= 0 && j < N)dp[j][yy]=(dp[j][yy]+dp[j][y])%module;
                    if(j+1 >= 0 && j+1 < N)dp[j+1][yy]=(dp[j+1][yy]+dp[j][y])%module;
                }
            }
        }
        cout << dp[x2][y2] << endl;
    }
    return 0;
}
