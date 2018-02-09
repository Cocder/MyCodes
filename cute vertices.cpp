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
#define ll long long int
#define ld long double
#define mp make_pair
#define maxn 200100
#define ln 23
#define inf 100000000000000000
const int mod=1000000007;
/****************************************/

vector<vector<int>> arr;
int disc[maxn],lo[maxn],parent[maxn];
set<ll> nodes;//contain cute vertices
int tt=0,child=0,root;
void ancil(int u)
{
	lo[u]=disc[u]=tt++;
	for (int j=0;j<arr[u].size();j++) {
		int v=arr[u][j];
		if (disc[v]==-1) {
			parent[v]=u;
			if(u==root){child++;}
			ancil(v);
			if (lo[v]>=disc[u]){nodes.insert(u);}
			lo[u]=min(lo[u],lo[v]);
		}
		else if(v!=parent[u]){
			lo[u]=min(lo[u],disc[v]);
		}
	}
}
ll ans[maxn];
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	arr.resize(n);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a-1].push_back(b-1);
		arr[b-1].push_back(a-1);
	}
	memset(disc,-1,sizeof disc);
	for(int i=0;i<n;i++)
	   {
		if(disc[i]==-1)
		  {
			child=0;root=i;
			ancil(i);
			if(child>1){
				nodes.insert(root);
			}
			else{
				nodes.erase(root);
			}
		  }
	   }
	ans[0]=1;ans[1]=0;ans[2]=1;
	for(ll i=3;i<n+2;i++){
		ans[i]=((ll)(i-1)*((ans[i-1]+ans[i-2])%mod))%mod;
	}
	while(q--){
		int k;scanf("%d",&k);
		//cmd(n,k)*((n-k)!-1)
		int princ=nodes.size();
		if(princ<k){
			cout<<0<<endl;
		}
		else{
			ll res=ans[princ-k];
			printf("%lld\n",res);
		}
	}
	return 0;
}  