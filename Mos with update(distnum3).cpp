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
using namespace std;
#define ld long double
#define ll unsigned  long long
#define tll long long int
#define mp make_pair
#define maxn 100010
#define ln 20
#define mod 1000000007
//can use this on array
int n,q,a,b,tp;
int value[maxn],mosvalue[maxn];
vector<int> adj[maxn],cmprs;
int depth[maxn],anc[ln][maxn],start[maxn],finish[maxn],invert[maxn*2],isq[maxn];
set<int> ezafi;
int cnt;
void dfs1(int u,int p,int lvl){//construct lca and dfs_order arrays
	start[u]=++cnt;
	invert[cnt]=u;
    depth[u]=lvl;
    for (int i=1;i<ln;i++) {
        anc[i][u]=anc[i-1][anc[i-1][u]];
    }
    for (int v:adj[u]){
        if (v!=p) {
            anc[0][v]=u;
            dfs1(v,u,lvl+1);
        }
    }
	finish[u]=++cnt;
	invert[cnt]=u;
}
int lca(int x, int y) {
    if (depth[x]<depth[y]) {
        swap(x,y);
    }
	for (int i=ln-1;i>=0;i--) {
        if (depth[x]-(1<<i)>=depth[y]) {
            x=anc[i][x];
        }
    }
	if(x==y){
        return x;
    }
    for(int i=ln-1;i>=0;i--) {
        if(anc[i][x]!=anc[i][y]) {
            x=anc[i][x];
            y=anc[i][y];
        }
    }
    return anc[0][x];
}
int bucksiz;
struct qnode{//query template for mos
	int tim,l,r,lca,idx;
	bool typ;
	bool operator<(const qnode &anoth)const{//for sorting in mos
		if((l/bucksiz)==(anoth.l/bucksiz)){
			if((r/bucksiz)==(anoth.r/bucksiz)){
				return tim<anoth.tim;
			}
			return r<anoth.r;
		}
		return l<anoth.l;
	}
};
struct unode{
	int tim,indx,now,bef;
};
qnode query[maxn];
unode update[maxn];
int ted=0;
int freq[maxn*2];
bool vis[maxn];
void toggle(int node){
	if(vis[node]){//end of node
		freq[mosvalue[node]]--;
		if(freq[mosvalue[node]]==0){
			ted--;
		}
	}
	else{//start of node
		freq[mosvalue[node]]++;
		if(freq[mosvalue[node]]==1){
			ted++;
		}
	}
	vis[node]^=true;
}
int ans[maxn];
 
 
 
int main() {
	cin>>n>>q;
	bucksiz=pow(n,0.7);
	for(int i=1;i<=n;i++){
		cin>>value[i];
		ezafi.insert(value[i]);
		mosvalue[i]=value[i];
	}
	for(int i=1;i<n;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	anc[0][1] = 1;cnt=0;
    dfs1(1, 0, 0);
	int numup=0,numq=0;int ii=0,qq=q;
	while(q--){
		cin>>tp>>a>>b;
		if(tp==2){//a is index and b is value
			ezafi.insert(b);
			numup++;
			update[numup].tim=numup;update[numup].indx=a;update[numup].now=b;update[numup].bef=mosvalue[a];
			mosvalue[a]=b;
		}
		else{
			int lcc=lca(a,b);
			if(lcc==a || lcc==b){//stone sttwo endtwo endone
				query[numq].tim=numup;query[numq].l=min(start[a],start[b]);query[numq].r=max(start[a],start[b]);query[numq].lca=lcc;
				query[numq].typ=false;query[numq].idx=ii;
			}
			else{//lca is disjoint oon order
				query[numq].tim=numup;query[numq].l=min(finish[a],finish[b]);query[numq].r=max(start[a],start[b]);query[numq].lca=lcc;
				query[numq].typ=true;query[numq].idx=ii;
			}
			numq++;
			isq[ii]=true;
		}
		ii++;
	}
	for(auto v:ezafi){
		cmprs.push_back(v);
	}
	for(int i=1;i<=n;i++){
		value[i]=lower_bound(cmprs.begin(),cmprs.end(),value[i])-cmprs.begin();
	}
	for(int i=1;i<=numup;i++){
		update[i].now=lower_bound(cmprs.begin(),cmprs.end(),update[i].now)-cmprs.begin();
		update[i].bef=lower_bound(cmprs.begin(),cmprs.end(),update[i].bef)-cmprs.begin();
	}
	sort(query,query+numq);
	for(int i=1;i<=n;i++){
		mosvalue[i]=value[i];
	}
	int curl=1,curr=0,now=0;
	for(int i=0;i<numq;i++){
		//must place in true updates
		while(now<query[i].tim){
			now++;
			if(vis[update[now].indx]){
				toggle(update[now].indx);//delete bef value
				mosvalue[update[now].indx]=update[now].now;
				toggle(update[now].indx);//add new value
			}
			else{
				mosvalue[update[now].indx]=update[now].now;
			}
		}
		while(now>query[i].tim){
			if(vis[update[now].indx]){
				toggle(update[now].indx);//delete bef value
				mosvalue[update[now].indx]=update[now].bef;
				toggle(update[now].indx);//add new value
			}
			else{
				mosvalue[update[now].indx]=update[now].bef;
			}
			now--;
		}
		//for query on dfs_order
		while(curl<query[i].l){
			toggle(invert[curl]);
			curl++;
		}
		while(curl>query[i].l){
			curl--;
			toggle(invert[curl]);
		}
		while(curr<query[i].r){
			curr++;
			toggle(invert[curr]);
		}
		while(curr>query[i].r){
			toggle(invert[curr]);
			curr--;
		}
		ans[query[i].idx]=ted;
		if(query[i].typ){//second type
			if(freq[mosvalue[query[i].lca]]==0){//number of lca value is even
				ans[query[i].idx]++;
			}
		}
	}
	for(int i=0;i<qq;i++){
		if(isq[i]){
			cout<<ans[i]<<endl;
		}
	}
 
 
 
 
 
 
	return 0;
}          