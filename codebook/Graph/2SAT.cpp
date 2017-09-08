#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;
const int VN = MAXN * 2;
const int EN = 4000010;
#define False(a) a * 2
#define True(a) a * 2 + 1
class Graph {
public:
    void init()
    {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    /*
		1）如果給出A和B的限制關係，A和B必須一起選，(A and B)||(!A and !B )==true 那麼選A必須選B，建邊<i,j>和<j,i>還有<i',j'>和<j',i'>
		2）如果給出A和B的限制關係，選A不能選B，那麼(A && !B)||(!A && B )==true,建邊<i,j'>和<j,i'>
		3）如果必須選A,那麼A==true,建邊<i',i>
		4）如果A一定不能選，那麼!A==true.建邊<i,i'>
	*/
    void addEdge(int u, int v)
    {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }

public:
    int size;
    int head[VN];
    struct Edge {
        int v, next;
    } E[EN];
} g;

class Two_Sat {
public:
    bool check(const Graph& g, const int n)
    {
        scc(g, n);
        for (int i = 0; i < n; ++i)
            if (belong[i * 2] == belong[i * 2 + 1])
                return false;
        return true;
    }

private:
    void tarjan(const Graph& g, const int u)
    {
        int v;
        DFN[u] = low[u] = ++idx;
        sta[top++] = u;
        inStack[u] = true;

        for (int e = g.head[u]; e != -1; e = g.E[e].next) {
            v = g.E[e].v;
            if (DFN[v] == -1) {
                tarjan(g, v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], DFN[v]);
            }
        }
        if (low[u] == DFN[u]) {
            ++bcnt;
            do {
                v = sta[--top];
                inStack[v] = false;
                belong[v] = bcnt;
            } while (u != v);
        }
    }
    void scc(const Graph& g, const int n)
    {
        top = idx = bcnt = 0;
        memset(DFN, -1, sizeof(DFN));
        memset(inStack, 0, sizeof(inStack));
        for (int i = 0; i < 2 * n; ++i) {
            if (DFN[i] == -1)
                tarjan(g, i);
        }
    }

private:
    int top, idx, bcnt;
    int sta[VN];
    int DFN[VN];
    int low[VN];
    int belong[VN];
    bool inStack[VN];
} sat;
