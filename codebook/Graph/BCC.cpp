int adj[9][9]; 
int visit[9], low[9], t = 0;
int stack[9], top = 0; 
int contract[9]; 
void DFS(int i, int p)
{
    visit[i] = low[i] = ++t;
    stack[top++] = i;   // push i
    for (int j=0; j<9; ++j)
        if (adj[i][j]){
            if (!visit[j]) DFS(j, i);             // tree edge
            if (!(j == p && adj[i][j] == 1))            // tree edge + back edge
                low[i] = min(low[i], low[j]);
        }

    if (visit[i] == low[i])    // 形成BCC i點會是BCC裡面，最早拜訪的點。
    {
        int j;
        do {
            j = stack[--top];   // pop j
            contract[j] = i;
        } while (i != j);
    }
}

void tarjan()
{
    memset(visit, 0, sizeof(visit));
    t = 0;

    for (int i=0; i<9; ++i)
        if (!visit[i])
            DFS(i, i);
}
