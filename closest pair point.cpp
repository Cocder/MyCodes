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
int n;
vector<pair<ll,ll>> arr;
ll dist(int i,int j){
	return (ll)(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
}
ll bruth(vector<pair<int,int>> pt){
	ll ans=inf;
	for(int i=0;i<pt.size();i++){
		for(int j=i+1;j<pt.size();j++){
			ans=min(ans,dist(pt[i].second,pt[j].second));
		}
	}
	return ans;
}
ll halve(vector<int> our,int ses){
	ll ans=ses;
	for(int i=0;i<our.size();i++){
		int j=i+1;
		while(j<our.size() && abs(arr[our[j]].second-arr[our[i]].second)<ans){
			ans=min(ans,dist(our[i],our[j]));
			j++;
		}
	}
	return ans;
}
ll mini(vector<pair<int,int>> px,vector<pair<int,int>> py){//O(nlog(n))
	if(px.size()<3){
		return bruth(px);
	}
	ll md=inf;
	int sz=px.size();
	int mid=(sz/2);
	vector<pair<int,int>> pxl,pyl,pxr,pyr;
	for(int i=0;i<mid;i++){pxl.push_back(px[i]);}
	for(int i=mid,j=0;i<sz;i++,j++){pxr.push_back(px[i]);}
	int l=0;
	for(int i=0;i<sz;i++){
		if(arr[py[i].second].first<=px[mid-1].first && l<mid){
			pyl.push_back(py[i]);l++;
		}
		else{
			pyr.push_back(py[i]);
		}
	}
	ll dl=mini(pxl,pyl);
	ll dr=mini(pxr,pyr);
	md=min(dl,dr);
	//now between two halve
	vector<int> our;
	for(int i=0;i<sz;i++){
		if(abs(px[mid-1].first-arr[py[i].second].first)<md){
			our.push_back(py[i].second);
		}
	}
	return min(md,halve(our,md));;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		arr.push_back(mp(a,b));
	}
	vector<pair<int,int>> px,py;
	for(int i=0;i<n;i++){
		px.push_back(mp(arr[i].first,i));
		py.push_back(mp(arr[i].second,i));
	}
	sort(px.begin(),px.end());
	sort(py.begin(),py.end());
	ll ans=mini(px,py);
	ld ds=sqrt(ans);
	cout<<fixed<<setprecision(10)<<ds<<endl;
	return 0;
}  