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
#define maxsize 1000010
#define ln 23
#define inf 100000000000000000
const int mod=1000000007;
/****************************************/
//http://codeforces.com/contest/622/problem/F
ll fpow(ll p, ll q){
	ll ret = 1;
	for(; q; q>>=1){
		if (q & 1){
			ret = ret * p % mod;
		}
		p = p * p % mod;
	}
	return ret;
}
ll pre[maxsize];
int main(){
	int n,k;cin>>n>>k;//k+2 point need and we have polynomial with degree k+1
	//f(x)=a0+a1 * x^1 + ... + a(k+1)x^(k+1) ---> use lagrange --> f(x)= L_0(x)*(1)^k + L_1(x)*(2)^k + ... + L_k+1(x)*(k+2)^k
	for(int i=1;i<=k+3;i++){
		pre[i]=fpow(i,k);
	}
	for(int i=2;i<=k+3;i++){
		pre[i]=(pre[i]+pre[i-1])%mod;
	}
	if(n<=k+3){
		cout<<pre[n]<<endl;
	}
	else{
		ll sorat=1;
		for(int i=1;i<=k+2;i++){
			sorat=(ll)sorat*(n-i)%mod;
		}
		ll makhraj=1;
		for(int i=1;i<=k+1;i++){//for exp: l_0 --> (1-2)*(1-3)*....*(1-(k+2))=(-1)^? * 1*2*..*(k+1)
			makhraj=(ll)makhraj*i%mod;
		}
		ll br=1;
		if((k+1)%2!=0){br=-1;}
		ll res=0;
		for(int i=1;i<=k+2;i++){//from L_0 to L_k+1 
			res+=(sorat*pre[i]%mod*fpow(n-i,mod-2)%mod*fpow(makhraj,mod-2)*br%mod);if(res<0){res+=mod;}
			makhraj=makhraj*(i)%mod*fpow(k+2-i,mod-2)%mod;
			br=-br;
		}
		cout<<(res+mod)%mod<<endl;
	}
	return 0;
} 