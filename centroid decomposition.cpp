#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/************ BEGIN CODING .. . .. OOOM .... I LIKE THIS ... OOOM YES ************/
#define ll long long int
#define ld long double
#define maxn 100010
#define mp make_pair
#define pi pair<int,int>
#define inf 1000000001
#define ln 13

#define mod 1000000007
vector<int> adj[maxn];
vector<pair<int,int>> query[maxn];
int n,m,subsiz[maxn],sbtsiz,order_vis[maxn],color[maxn],mindist[maxn],finans[maxn],depth[maxn];
bool vis[maxn];
int dsz(int node,int par){
	sbtsiz++;
	order_vis[sbtsiz]=node;
	subsiz[node]=1;
	for(auto v:adj[node]){
		if(vis[v] || par==v){continue;}
		subsiz[node]+=dsz(v,node);
	}
	return subsiz[node];
}
int get_centroid(){
	int hcent,mxsiz;
	int optsiz=mod,cent=1;
	for(int i=1;i<=sbtsiz;i++){
		hcent=order_vis[i];
		mxsiz=sbtsiz-subsiz[hcent];
		for(auto v:adj[order_vis[i]]){
			if(vis[v] || subsiz[v]>subsiz[hcent]){continue;}
			mxsiz=max(mxsiz,subsiz[v]);
		}
		if(optsiz>mxsiz){
			cent=hcent;
			optsiz=mxsiz;
		}
	}
	return cent;
}
void dfs(int node,int par,int dis){
	mindist[color[node]]=min(dis,mindist[color[node]]);
	depth[node]=dis;
	for(auto v:adj[node]){
		if(v!=par && !vis[v]){
			dfs(v,node,dis+1);
		}
	}
}
void recursive(int node){
	sbtsiz=0;
	dsz(node,-1);
	int cent=get_centroid();
	vis[cent]=true;
	for(int i=1;i<=sbtsiz;i++){
		mindist[color[order_vis[i]]]=mod;
	}
	dfs(cent,-1,0);//our goal!logn
	for(int i=1;i<=sbtsiz;i++){
		int nd=order_vis[i];
		for(auto v:query[nd]){
			finans[v.second]=min(finans[v.second],depth[nd]+mindist[v.first]);
		}
	}
	for(int i=1;i<=sbtsiz;i++){
		mindist[color[order_vis[i]]]=mod;
	}
	for(auto v:adj[cent]){
		if(vis[v]){continue;}
		recursive(v);
	}
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		query[x].push_back(mp(y,i));
		finans[i]=mod;
	}
	for(int i=0;i<=n;i++){vis[i]=false;}
	recursive(1);
	for(int i=1;i<=q;i++){
		cout<<finans[i]<<endl;
	}
 
 
 
 
 
	return 0;
}         