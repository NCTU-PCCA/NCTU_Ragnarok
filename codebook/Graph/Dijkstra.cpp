int* Dijkstra(vector<VPII> E,int N,int S){
    bool *visit=new bool[N+1];for(int i=1;i<=N;i++)visit[i]=false;
    int *D=new int[N+1];for(int i=1;i<=N;i++)D[i]=INF;
    priority_queue<PII,VPII,greater<PII>> P;
    P.push(MP(0,S));D[S]=0;
    while(!P.empty()){
        int weight=P.top().ff,now=P.top().ss;P.pop();
        if(visit[now])continue;
        visit[now]=true;
        for(auto i:E[now]){
            int potential=D[now]+i.ff;
            if(!visit[i.ss] && potential < D[i.ss]){
                P.push(MP(D[i.ss]=potential,i.ss));
            }
        }
    }
    return D;
}
