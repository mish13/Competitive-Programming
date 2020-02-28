#include<bits/stdc++.h>

using namespace std;

int n,vis[340];
vector <int> adj[340];
map <string,int> mp;
map <int,string> invmp;
vector <string> ans;

void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
    ans.push_back(invmp[u]);
}

int main()
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int asn = 1;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<335;i++)
        {
            adj[i].clear();
        }
        mp.clear();
        invmp.clear();
        cin>>n;
        for(int i=1;i<n;i++)
        {
            string p,c;
            cin>>c>>p;
            if(mp.find(p)==mp.end())
            {
                mp[p]=asn;
                invmp[asn]=p;
                asn++;
            }
            if(mp.find(c)==mp.end())
            {
                mp[c]=asn;
                invmp[asn]=c;
                asn++;
            }
            adj[mp[p]].push_back(mp[c]);
        }
        for(int i=1;i<asn;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
        cout<<"Scenario #"<<t<<":"<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
        cout<<endl;
        ans.clear();
    }
    return 0;
}
