using namespace std;
#define ld long double
#define ll unsigned  long long
#define tll long long int
#define mp make_pair
#define maxn 1000010
#define ln 20
#define mod 1000000007
//sqrt decomposition
 
int n,q,arr[maxn];
vector<vector<int>> bucket; 
int bsiz,numb;
void build(int bk){
	int beg=bk*bsiz;
	int fin=min(n,beg+bsiz);
	bucket[bk].clear();
	for(int i=beg;i<fin;i++){
		if(!bucket[bk].size() || bucket[bk].back()<arr[i]){
			bucket[bk].push_back(arr[i]);
		}
	}
}
int query(int bk,int x,int l,int r){
	int beg=bk*bsiz;
	int fin=min(n,beg+bsiz);
	int ans=0,maxh=0;
	for(int i=beg;i<fin;i++){
		if(i>=x){
			if(arr[i]<=maxh){continue;}
			if(arr[i]>=l && maxh<r){ans++;}
			maxh=arr[i];
		}
	}
	for(int i=bk+1;i<numb;i++){
		if(maxh>=r){break;}
		auto lef=upper_bound(bucket[i].begin(),bucket[i].end(),maxh);
		if(maxh<l){
			lef=lower_bound(bucket[i].begin(),bucket[i].end(),l);
		}
		auto rig=lower_bound(bucket[i].begin(),bucket[i].end(),r);
		int rang=0;
		if (lef!=bucket[i].end()){
            if(rig==bucket[i].end()){
                rang=bucket[i].end()-lef;
			}
            else
			{
                rang=rig-lef+1;
			}
        }
        ans+=rang;
		maxh=max(maxh,bucket[i].back());
	}
	return ans;
}
int main() {
	int test;
	cin>>test;
	while(test--){
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++){scanf("%d",&arr[i]);}
		bsiz=6000;
		numb=n/bsiz;if(n%bsiz){numb++;}
		bucket.resize(numb);
		for(int i=0;i<numb;i++){
			build(i);
		}
		while(q--){
			char tp;
			cin>>tp;
			if(tp=='+'){
				int i,x;scanf("%d%d",&i,&x);i--;arr[i]+=x;
				build(i/bsiz);
			}
			else{
				int i,l,r;scanf("%d%d%d",&i,&l,&r);i--;
				int ans=query(i/bsiz,i,l,r);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}     