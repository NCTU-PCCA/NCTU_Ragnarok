#include<bits/stdc++.h>
using namespace std;
struct pp
{
    int times;
    int num;
    bool operator < (const pp & a) const
    {
        return times<a.times;
    }
};

int main()
{

    int m,n;
    cin>>m>>n;

        pp p[60];

    bool con[60][60]={};

        int i;

        vector<int>E[60];
        for(i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            if(!con[a][b] && !con[b][a])
            {

            p[a].times++;
            p[b].times++;
            E[a].push_back(b);
            E[b].push_back(a);

            con[a][b]=con[b][a]=true;
            }
        }

        int now=m;
        int ans=0;
       while(now)
       {
           int top=-1;
           int maxx=0;
           for(i=0;i<n;i++)
           {
               if(p[i].times>maxx)
               {
                   top=i;
                   maxx=p[i].times;
               }
           }
           if(top==-1) break;
           ans++;
           for(i=0;i<E[top].size();i++)
           {
               if(con[top][E[top][i]] && con[E[top][i]][top])
               {
                   p[E[top][i]].times--;
                   con[top][E[top][i]]=con[E[top][i]][top]=false;
                   now--;
               }
           }
          // cout<<top<<" "<<now<<endl;
           p[top].times=0;
       }
        cout<<ans<<endl;
    return 0;
}
