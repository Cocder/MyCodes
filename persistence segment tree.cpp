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
#define mod 1000000007
#define maxsize 100010
#define ln 23
#define inf 100000000000000000
/****************************************/
//presistence segment tree for max val : for other type of this just that type of data structure you must convert to presistence.
struct node{
	node *l,*r;
	int value;
};
int cnt,n;
node *tree[maxsize];
node *root;
int val[maxsize];
void build(node *tre,int l,int r){
	if(l>r){return;}
	if(l==r){
		tre->value=val[l];tre->l=NULL;tre->r=NULL;
		return;
	}
	tre->l=new node;tre->l->l=NULL;tre->l->r=NULL;tre->l->value=-mod;
	tre->r=new node;tre->r->l=NULL;tre->r->r=NULL;tre->r->value=-mod;
	int mid=(l+r)/2;
	build(tre->l,l,mid);
	build(tre->r,mid+1,r);
	tre->value=max(tre->l->value,tre->r->value);
}
void update(node *prev,node *aft,int l,int r,int dx,int val){
	if(l>r){return;}
	if(l==r){
		aft->value=val;
		return;
	}
	int mid=(l+r)/2;
	if(dx<=mid){//must update left
		aft->r=prev->r;
		aft->l=new node;aft->l->l=NULL;aft->l->r=NULL;aft->l->value=-mod;
		update(prev->l,aft->l,l,mid,dx,val);
	}
	else{
		aft->l=prev->l;
		aft->r=new node;aft->r->l=NULL;aft->r->r=NULL;aft->r->value=-mod;
		update(prev->r,aft->r,mid+1,r,dx,val);
	}
	aft->value=max(aft->l->value,aft->r->value);
}
int res(node *tre,int l,int r,int a,int b){
	if(l>r || a>b){return -mod;}
	if(r<a || l>b){return -mod;}
	if(l>=a && r<=b){
		return tre->value;
	}
	int mid=(l+r)/2;
	return max(res(tre->l,l,mid,a,b),res(tre->r,mid+1,r,a,b));
}
int main(){
	cin>>n;
	cnt=0;
	for(int i=1;i<=n;i++){cin>>val[i];}
	root=new node;root->l=NULL;root->r=NULL;root->value=-mod;
	build(root,1,n);
	tree[cnt]=root;cnt++;
	while(1){
		int tp;cin>>tp;
		if(tp==1){
			int dx,vl;cin>>dx>>vl;
			tree[cnt]=new node;tree[cnt]->l=NULL;tree[cnt]->r=NULL;tree[cnt]->value=-mod;
			update(tree[cnt-1],tree[cnt],1,n,dx,vl);
			cnt++;
		}
		else{
			int a,b,c;cin>>a>>b>>c;
			cout<<res(tree[c],1,n,a,b)<<endl;
		}
	}

	return 0;
} 