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

//int dx[] = {1,0,-1,0};              int dy[] = {0,1,0,-1};                //4 Direction
//int dx[] = {1,1,0,-1,-1,-1,0,1};    int dy[] = {0,1,1,1,0,-1,-1,-1};      //8 direction
//int dx[] = {2,1,-1,-2,-2,-1,1,2};   int dy[] = {1,2,2,1,-1,-2,-2,-1};     //Knight Direction
//int dx[] = {2,1,-1,-2,-1,1};        int dy[] = {0,1,1,0,-1,-1};           //Hexagonal Direction

int main(){
    IOS;
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        VII V;
        for(int i=0;i<N;i++){
            int x;
            cin >> x;
            V.pb(x);
        }
        VII VV;
        int big = V[N-1];
        for(int i=N-2;i>=0;i--){
            if(V[i] > big)VV.pb(V[i]);
            big = min(big,V[i]);
        }
        sort(VV.begin(),VV.end());
        cout << VV.size() << endl;
        for(int i=0;i<VV.size();i++)cout << VV[i] << endl;
    }
    return 0;
}