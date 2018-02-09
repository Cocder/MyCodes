int low[10010],disc[10010],cycle[10010];
int par[10010],sizz[10010],idx,tok;
int minr[10010];
stack<int> path;
int root(int a)
{
	if(par[a]==a){return a;}
    return par[a]=root(par[a]);
}
void Union(int a,int b)
{
	a=root(a);b=root(b);
	if(a==b){return;}
	if(sizz[a]>sizz[b])
	  {
		  swap(a,b);
	  }
	par[a]=b;
	sizz[b]+=sizz[a];
}