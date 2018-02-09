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
/****************************/
#define ll long long int
#define ld long double
#define nsize 100010
#define mp make_pair
#define pi pair<int,int>
#define inf 1000000001
#define ln 13

int arr[nsize],n;
int tree[nsize*4];
void build(int node, int a, int b)
{
    if(b<a)
        return ;
    if(a==b){
		tree[node]=arr[a];
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, (a+b)/2+1, b);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
void update(int node, int a, int b, int i, int j,int vl)
{
    if(b<a||a>j||b<i){
		return;}
    if(a>=i && b<=j){
        tree[node]=vl;
        return;
    }
    update(node*2, a, (a+b)/2, i, j,vl);
    update(node*2+1, (a+b)/2+1, b, i, j,vl);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
int sum(int node, int a, int b, int i, int j)
{
    if(b<a||a>j||b<i){
		return 0;}
    if(a>=i && b<=j){
        return tree[node];
    }
    return max(sum(node*2,a,(a+b)/2,i,j),sum(node*2+1,(a+b)/2+1,b,i,j));
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	while(1){
		int tp;cin>>tp;
		if(tp==1){
			int l,r;cin>>l>>r;
			cout<<sum(1,1,n,l,r)<<endl;
		}
		else{
			int dx,vl;cin>>dx>>vl;
			update(1,1,n,dx,dx,vl);
		}
	}
    return 0;
}