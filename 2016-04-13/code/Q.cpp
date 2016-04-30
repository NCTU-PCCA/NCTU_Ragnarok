#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define ff first
#define ss second
#define MP make_pair
#define INF 0x7FFFFFFF
#define MAX_NUMBER 100000
#define SP system("pause")
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M,now;
        cin >> N >> M;
        int B[N][2];
        int D[N];
        int shortest[M];for(int i=0;i<M;i++)shortest[i] = INF;
        for(int i=0;i<N;i++)cin >> B[i][0] >> B[i][1];
        for(int i=0;i<M;i++)cin >> D[i];
        stack<PII> stk;
        now=0;
        for(int i=0;i<M;i++){
            while(!stk.empty() && stk.top().ss < D[i])stk.pop();
            for(;now < N && B[now][0] <= D[i];now++){
                int point = B[now][0]+B[now][1];
                if(point < D[i])continue;
                while(!stk.empty() && point >= stk.top().ss)stk.pop();
                stk.push(MP(B[now][0],point));
            }
            if(!stk.empty())shortest[i]=D[i]-stk.top().ff;
        }
        while(!stk.empty())stk.pop();
        now=N-1;
        for(int i=M-1;i>=0;i--){
            while(!stk.empty() && stk.top().ss > D[i])stk.pop();
            for(;now >= 0 && B[now][0] >= D[i];now--){
                int point = B[now][0]-B[now][1];
                if(point > D[i])continue;
                while(!stk.empty() && point <= stk.top().ss)stk.pop();
                stk.push(MP(B[now][0],point));
            }
            if(!stk.empty())shortest[i]=min(shortest[i],stk.top().ff-D[i]);
        }
        LL Ans=0;
        for(int i=0;i<M;i++)Ans+=shortest[i];
        cout << Ans << endl;
    }
    return 0;
}
