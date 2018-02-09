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
#define Maxn (1<<17)
#define ln 23
#define inf 100000000000000000
const int mod=1000000007;
/****************************************/
//http://codeforces.com/contest/914/problem/G
int fibo[Maxn*10];
int one[Maxn*10],two[Maxn*10],tree[2][Maxn*10],onetwo[Maxn*10];
int value[Maxn*10],sos[Maxn*10];
ll Inv(int a)
{
	ll res=1;
	ll p=mod-2;
	while(p){
		if(p&1)res=(ll)res*a%mod;
		p>>=1;a=(ll)a*a%mod;
	}
	return res;
}
void applyXor(int P[], bool inv)
{
	for(int len=1;2*len<=Maxn;len<<= 1)
		for(int i=0;i<Maxn;i+=2*len)
			for (int j=0;j<len;j++) {
				int u=P[i+j];
				int v=P[i+len+j];
				P[i+j]=(u+v);while(P[i+j]>mod){P[i+j]-=mod;}
				P[i+len+j]=(u-v);while(P[i+len+j]<0){P[i+len+j]+=mod;}
			}
	if(inv){
		int val=Inv(Maxn);
		for (int i=0;i<Maxn;i++)
			P[i]=(ll)P[i]*val%mod;
	}
}
void applyAndOR(int P[], bool inv,bool tp)
{
	for (int len=1;2*len<=Maxn;len<<=1)
		for (int i=0;i<Maxn;i+=2*len)
			for (int j=0;j<len;j++) {
				int u=P[i+j];
				int v=P[i+len+j];
				if (!inv) {
					P[i+j]=(tp?v:(u+v));while(P[i+j]>mod){P[i+j]-=mod;}
					P[i+len+j]=(tp?(u+v):u);while(P[i+len+j]>mod){P[i+len+j]-=mod;}
				} else {
					P[i+j]=(tp?(v-u):v);while(P[i+j]<0){P[i+j]+=mod;}
					P[i+len+j]=(tp?u:(u-v));while(P[i+len+j]<0){P[i+len+j]+=mod;}
				}
			}
}
void multiplyAndOR(int A[],int B[],bool ok)
{
	applyAndOR(A,false,ok);applyAndOR(B,false,ok);
	for(int i=0;i<Maxn;i++){A[i]=(ll)A[i]*B[i]%mod;}
	applyAndOR(A,true,ok);
}
void multiplyXOR(int A[],int B[])
{
	applyXor(A,false);applyXor(B,false);
	for(int i=0;i<Maxn;i++){A[i]=(ll)A[i]*B[i]%mod;}
	applyXor(A,true);
}
void gon(int len,int a,int b){
	if(len>=17){
		one[a|b]=(one[a|b]+(ll)value[a]*value[b]%mod)%mod;
	}
	else{
		gon(len+1,a,b);
		gon(len+1,a|(1<<len),b);
		gon(len+1,a,b|(1<<len));
	}
}

int main(){
	for(int i=0;i<17;i++){sos[(int)pow(2,i)]=1;}
	fibo[0]=0;fibo[1]=1;
	for(int i=2;i<Maxn;i++){fibo[i]=(fibo[i-1]+fibo[i-2])%mod;}
	int n,num;cin>>n;
	int maxi=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		value[num]++;maxi=max(maxi,num);
		tree[0][num]++;tree[1][num]++;
	}
	int td=1;
	while(maxi){maxi/=2;td++;}
	int pv=pow(2,td);
	//thw poly nomi
	gon(0,0,0);//for each index find all index that and is zero 
	for(int i=0;i<pv;i++){
		one[i]=(ll)one[i]*fibo[i]%mod;
	}
	for(int i=0;i<pv;i++){
		two[i]=(ll)value[i]*fibo[i]%mod;
	}
	multiplyXOR(tree[0],tree[1]);
	for(int i=0;i<pv;i++){
		tree[0][i]=(ll)tree[0][i]*fibo[i]%mod;
	}
	ll ans=0;
	for(int i=0;i<pv;i++){
		onetwo[i]=one[i];
	}
	multiplyAndOR(onetwo,two,true);
	multiplyAndOR(onetwo,tree[0],true);
	for(int i=0;i<17;i++){
		ans=(ans+(ll)onetwo[(int)pow(2,i)])%mod;
	}
	cout<<ans<<endl;
	return 0;
} 