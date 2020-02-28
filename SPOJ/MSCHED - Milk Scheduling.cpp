#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <pair<int,int> > vt;
    for(int i=1;i<=n;i++)
    {
        int wt,d;
        cin>>wt>>d;
        vt.push_back({wt,d});
    }
    sort(vt.rbegin(),vt.rend());
    bool taken[100007];
    memset(taken,false,sizeof(taken));
    int ans = 0;
    for(int i=0;i<vt.size();i++)
    {
        for(int j=vt[i].second;j>=1;j--)
        {
            if(!taken[j])
            {
                taken[j]=true;
                ans+=vt[i].first;
                //cout<<ans<<endl;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
