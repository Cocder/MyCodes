#include <bits/stdc++.h>
using namespace std; 
#define ll long long int
#define ld long double
#define mp make_pair
const int maxn=400010+10;
const int mode=1000000007;
ll sa[maxn*3], pos[maxn*3], tmp[maxn*3], lcp[maxn*3], N, gap;
int kam=0;
bool Sufcmp(ll i, ll j){
	if(pos[i+kam] != pos[j+kam]){
		return pos[i+kam] < pos[j+kam];
	}
	i += gap; j += gap;
	return (i < N && j < N) ? pos[i+kam] < pos[j+kam] : i > j;
}
void buildSA(string S){
	N = S.size();
	for(ll i = 0; i < N; i++){
		sa[i+kam] = i;
		pos[i+kam] = S[i];
	}
	tmp[0+kam] = 0;
	for(gap = 1; ; gap = (gap << 1)){
		sort(sa+kam, sa+kam + N, Sufcmp);
		for(ll i = 0; i < N-1; i++) tmp[i+1+kam] = tmp[i+kam] + Sufcmp(sa[i+kam], sa[i+1+kam]);
		for(ll i = 0; i < N; i++) pos[sa[i+kam]+kam] = tmp[i+kam];
		if(tmp[N-1+kam] == N-1) break;
	}
 
}
void buildLCP(string S){
	N = S.size();
	lcp[0+kam] = 0;
	for(ll i = 0, k = 0; i < N; i++){
		if(pos[i+kam] != N-1){
			for(ll j = sa[pos[i+kam]+1+kam]; S[i+k] == S[j+k]; )
				k++;
			lcp[pos[i+kam]+1+kam] = k;
			if(k) k--;
		}
	}
}
int main() {
	string ss,ks,tot;
	cin>>ss>>ks;
	tot=ss+"$"+ks;
	ll l1=ss.length(),l2=ks.length(),tt=tot.length();
	buildSA(ss);
	buildLCP(ss);
	ll sub1=(ll)l1*(l1+1)/2;
    for(int i=0;i<=l1;i++){
		sub1-=lcp[i+kam];
	}
	kam+=maxn;
	buildSA(ks);
	buildLCP(ks);
	ll sub2=(ll)l2*(l2+1)/2;
	for(int i=0;i<=l2;i++){
		sub2-=lcp[i+kam];
	}
	kam+=maxn;
	buildSA(tot);buildLCP(tot);
	ll tok=(ll)((tt)*(tt+1))/2;
	for(int i=0;i<=tt;i++){
		tok-=lcp[i+kam];
	}
	tok=tok-(l1+1)*(l2+1);
	cout<<2*tok-sub1-sub2<<endl;
	return 0;
}  