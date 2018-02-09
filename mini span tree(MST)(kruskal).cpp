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
#define nsize 1010
#define mp make_pair
#define pi pair<int,int>
#define inf 1000000000
#define ln 13
int par[10010],sizz[10010];
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
vector<pair<int,pair<int,int>>> adj;
int n;
int main() {
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;cin>>a>>b>>c;
		adj.push_back(mp(c,mp(a,b)));
	}
	for(int i=1;i<=n;i++){
		par[i]=i;sizz[i]=0;
	}
	sort(adj.begin(),adj.end());
	int cost=0;
	for(auto v:adj){
		int x=root(v.second.first);
		int y=root(v.second.second);
		if(x!=y){//diff set!
			Union(v.second.first,v.second.second);
			cost+=v.first;
			root(v.second.first);root(v.second.second);
		}
	}


    return 0;
}