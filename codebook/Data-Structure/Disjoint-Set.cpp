struct DisjointSet{
    int p[N];
    void init(int n){for(int i=1;i<=n;i++)p[i] = i;}
    int Find(int x){return x == p[x] ? x : p[x] = Find(p[x]); }
    void Union(int x,int y){p[Find(x)] = Find(y);}
};
