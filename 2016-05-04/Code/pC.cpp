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

int main(){
    IOS;
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        int coin[N];
        for(int i=0;i<N;i++)cin >> coin[i];
        sort(coin,coin+N);
        VPII v;
        int last = -1,e;
        for(int i=0;i<N;i++){
            if(last != coin[i]){
                if(i != 0)v.pb(mp(last*e,last));
                last = coin[i];
                e = 1;
            }
            else e++;
        }
        v.pb(mp(last*e,last));
        sort(v.begin(),v.end(),greater<PII>());
        LL sum = 0;
        bool flag = false;
        for(int i=0;i<v.size();i++){
            sum += v[i].ff;
            if(sum >= M){
                flag = true;
                VII vv;
                for(int j=0;j<=i;j++)vv.pb(v[j].ss);
                sort(vv.begin(),vv.end());
                for(int j=0;j<vv.size();j++)cout << vv[j] << " ";cout << endl;
                break;
            }
        }
        if(!flag)cout << "Impossible" << endl;
    }
    return 0;
}
