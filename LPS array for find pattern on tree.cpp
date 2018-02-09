#include <bits/stdc++.h>
using namespace std; 
#define ld long double
#define ll long long int
#define mp make_pair
const int maxn=200100;
int ans[maxn],ln;
vector<int> adj[maxn];
char tot[maxn];
int nn;
int lps[maxn];
char pat[maxn];
 
void dfs(int node,int par,int j,int tp){
	if(tp==0){
		if(pat[j]==tot[node]){
			for(auto v:adj[node]){
				if(v!=par){
					dfs(v,node,j+1,1);
				}
			}
		}
		else{
			dfs(node,par,j,1);
		}
	}
	else{
		if(j==ln){
			ans[par]=1;
			dfs(node,par,lps[j-1],0);
		}
		else  if(pat[j]!=tot[node]){
			if(j!=0){
				dfs(node,par,lps[j-1],0);
			}
			else{
				for(auto v:adj[node]){
					if(v!=par){
						dfs(v,node,j,0);
					}
				}
			}
		}
		else{
			dfs(node,par,j,0);
		}
	}
}
int sum(int node,int par){
	int kam=0;
	for(auto v:adj[node]){
		if(v!=par){
			kam+=sum(v,node);
		}
	}
	ans[node]+=kam;
	return ans[node];
}
void computeLPSArray(int M)
{
    int len = 0;
    int i;
    lps[0] = 0;
    i = 1;
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if (len != 0)
         {
           len = lps[len-1];
		 }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
} 
int main()
{
	int tt;cin>>tt;
	while(tt--){
		memset(lps,0,sizeof lps);
		cin>>nn>>ln;
		cin>>pat;
		computeLPSArray(ln);
		char t;int num;
		for(int i=1;i<=nn;i++){
			cin>>t>>num;
			tot[i]=t;
			if(num!=0){
				adj[i].push_back(num);
				adj[num].push_back(i);
			}
		}
		int exp=nn+1;
		for(int i=1;i<=nn;i++){
			if(adj[i].size()==1){
				adj[exp].push_back(i);
				adj[i].push_back(exp);
				tot[exp]='!';
				exp++;
			}
		}
		dfs(1,0,0,0);
		sum(1,0);
		if(nn==1){
			ans[0]=0;
			if(tot[1]==pat[0] && ln==1){
				ans[1]=1;
			}
		}
		for(int i=1;i<=nn;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=exp;i++){
			adj[i].clear();
		}
		memset(ans,0,sizeof ans);
	}
    return 0;
}    