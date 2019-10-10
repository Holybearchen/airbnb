#include <iostream>
#include<vector>
using namespace std;
const int N=2e5+20;
vector<int> e[N];
int n,a[N],g[N],vis[N],ans;
//c,d 受所选的点影响:被修改的次数和没被修改的次数 
void dfs(int u,int fa,int c,int d) 
{
	int flag=0;
	if(c%2)
	flag=1;
	if(a[u]^flag!=g[u])
	{
		ans++;
		vis[u]=1;
		c++;
	}
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u,d,c);
	}
}
int main()
{
        cin>>n;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&g[i]);
		dfs(1,0,0,0);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				cout<<i<<endl;
			e[i].clear();
		}
	    return 0;
}