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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
    IOS;
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> M >> N;
        char Map[N][M];
        int godzilla[N][M],x,y,destroy = 0;
        bool mech[N][M],running = true;
        queue<PII> q;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++){
            cin >> Map[i][j];
            godzilla[i][j] = -1;
            mech[i][j] = false;
            if(Map[i][j] == 'M'){mech[i][j] = true;q.push(mp(i,j));}
            else if(Map[i][j] == 'G'){x = i;y = j;}
        }
        godzilla[x][y] = 0;
        for(int round=1;running;round++){
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx < 0 || xx >= N || yy < 0 || yy >= M || godzilla[xx][yy] >= 0)continue;
                if(Map[xx][yy] == 'R'){
                    x = xx;y = yy;
                    destroy++;
                    break;
                }
            }
            if(godzilla[x][y] >= 0){
                for(int i=0;i<4;i++){
                    int xx = x+dx[i];
                    int yy = y+dy[i];
                    if(xx < 0 || xx >= N || yy < 0 || yy >= M || godzilla[xx][yy] >= 0)continue;
                    x = xx;y = yy;
                    break;
                }
            }
            godzilla[x][y] = round;
            int L = q.size();
            for(int i=0;i<L;i++){
                PII m = q.front();q.pop();
                for(int j=0;j<4;j++){
                    int xx = m.ff+dx[j];
                    int yy = m.ss+dy[j];
                    if(xx < 0 || xx >= N || yy < 0 || yy >= M || mech[xx][yy] || (Map[xx][yy] == 'R' && godzilla[xx][yy] == -1))continue;
                    mech[xx][yy] = true;q.push(mp(xx,yy));
                }
            }
            //cout << "#" << x << " " << y << endl;
            for(int i=0;i<4;i++){
                for(int xx=x,yy=y;;xx+=dx[i],yy+=dy[i]){
                    if(xx < 0 || xx >= N || yy < 0 || yy >= M || (Map[xx][yy] == 'R' && godzilla[xx][yy] == -1))break;
                    if(mech[xx][yy]){running = false;break;}
                }
                if(!running)break;
            }
            //for(int i=0;i<N;i++){for(int j=0;j<M;j++)cout << mech[i][j] << " ";cout << endl;}cout << endl;
        }
        cout << destroy << endl;
    }
    return 0;
}
