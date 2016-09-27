struct Edge {
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[MAXN]; //MAXN:num of point
bool visited[MAXN];int cnt[MAXN];int dist[MAXN];
bool SPFA(int start , int n)
{
    memset(visited,0,sizeof(visited));
    for(int i=1;i<n;i++) dist[i]=INT_MAX;
    visited[start]=true,dist[start]=0;
    queue<int> que; 
    while(!que.empty()) que.pop();
    que.push(start); cnt[start]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        visited[u]=false;
        for(int i=0;i<E[u].size();i++){
            int v=E[u][i].v;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+E[u][i].cost){
                dist[v]=dist[u]+E[u][i].cost;
                if(!visited[v]) {
                    visited[v]=true;
                    que.push(v);
                    if(++cnt[v]>n) return false; //有負環
                }
            }
        }
    }
    return true; //正常
}
