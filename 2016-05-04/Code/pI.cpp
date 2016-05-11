/*************************************************************************
	> File Name: pI.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月四日 (週三) 廿一時卅分廿六秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
#define int long long 
using namespace std;
struct Point
{
    int x,y,r;
    Point(int _x=0,int _y=0,int _r=0)
    {
        x=_x;
        y=_y;
        r=_r;
    }
};
struct Edge
{
    int to;
    int dis;
    Edge(int _to=0,int _dis=0)
    {
        to=_to;
        dis=_dis;
    }
};
struct Edge2
{
    int to;
    int dis;
    Edge2(int _to,int _dis)
    {
        to=_to;
        dis=_dis;
    }
    bool operator <(const Edge2 & a) const
    {
        return dis>a.dis;
    }
};
vector<Edge>e[103];
#undef int
int main()
{
#define int long long 
    op_io;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<Point>p;
        for(int i=0;i<n+2;i++)
        {
            e[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            p.push_back(Point(a,b,c));
        }
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int dx=abs(p[i].x-p[j].x);
                int dy=abs(p[i].y-p[j].y);
                int dis=dx+dy;
                if(p[i].r*p[i].r>=dx*dx+dy*dy)
                {
                    e[i].push_back(Edge(j,2));
                }else
                {
                    e[i].push_back(Edge(j,dis));
                }
                if(p[j].r*p[j].r>=dx*dx+dy*dy)
                {
                    e[j].push_back(Edge(i,2));
                }else
                {
                    e[j].push_back(Edge(i,dis));
                }
            }
        }
        Point start,end;
        cin>>start.x>>start.y>>end.x>>end.y;
        int dis=abs(start.x-end.x)+abs(start.y-end.y);
        e[n].push_back(Edge(n+1,dis));
        e[n+1].push_back(Edge(n,dis));
        for(i=0;i<n;i++)
        {
            int dis=abs(start.x-p[i].x)+abs(start.y-p[i].y);
            e[n].push_back(Edge(i,dis));
            e[i].push_back(Edge(n,dis));
        }
        for(i=0;i<n;i++)
        {
            int dis=abs(end.x-p[i].x)+abs(end.y-p[i].y);
            e[n+1].push_back(Edge(i,dis));
            e[i].push_back(Edge(n+1,dis));
        }
        priority_queue<Edge2> pq;
        pq.push(Edge2(n,0));
        bool visited[103]={};
        int d[103]={};
        fill(d,d+103,LLONG_MAX);
        d[n]=0;
        visited[n]=1;
        while(!pq.empty())
        {
            Edge2 top=pq.top();
            pq.pop();
            for(int i=0;i<e[top.to].size();i++)
            {
                    int to=e[top.to][i].to;
                    if( e[top.to][i].dis+top.dis<d[to])
                    {
                        d[to]=e[top.to][i].dis+top.dis;
                       // visited[to]=true;
                        pq.push(Edge2(to,d[to]));
                    }
            }

        }
        cout<<d[n+1]<<endl;
    }
    return 0;
}
