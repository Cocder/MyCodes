#define ld long double
#define ll long long int
#define mp make_pair
#define pii pair<ll,ll>
const ll mode=1000000007;
const int maxn=200050;
const ld inf=1000000000.0;

//easy medium
ll dp[55][35555],lol[35555];
vector<int> ss[35555];
int n,k,num;
const int N=35555;
ll tree[4*N], lazy[4*N];
void build(int k,int node, int a, int b)
{
    if(b<a)
        return ;
    if(a==b){
		tree[node]=dp[k][a-1];
        return;
    }
    build(k,node*2, a, (a+b)/2);
    build(k,node*2+1, (a+b)/2+1, b);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
void update(int node, int a, int b, int i, int j)
{
    if(lazy[node]){
        ll x=lazy[node];
        tree[node] += x;
        if(a!=b){
            lazy[node*2]+=x;
            lazy[node*2+1]+=x;
        }
        lazy[node]=0;
    }
    if(b<a || a>j || b<i)
        return;
    if(a>=i && b<=j){
        tree[node] += 1;
        if(a!=b){
            lazy[node*2]+=1;
            lazy[node*2+1]+=1;
        }
        return;
    }
    update(node*2, a, (a+b)/2, i, j);
    update(node*2+1, (a+b)/2+1, b, i, j);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
ll maxi(int node, int a, int b, int i, int j)
{
    if(lazy[node]){
        ll x=lazy[node];
        tree[node]+=x;
        if(a!=b){
            lazy[node*2]+=x;
            lazy[node*2+1]+=x;
        }
        lazy[node]=0;
    }
    if(b<a || a>j || b<i)
        return 0;
    if(a>=i && b<=j){
        return tree[node];
    }
    return max(maxi(node*2, a, (a+b)/2, i, j),maxi(node*2+1, (a+b)/2+1, b, i, j));
}
void kok(int kk){
	memset(tree,0,sizeof tree);
	memset(lazy,0,sizeof lazy);
	build(kk-1,1,1,n);
	for(int i=1;i<=n;i++){
		int dx=lower_bound(ss[lol[i]].begin(),ss[lol[i]].end(),i)-ss[lol[i]].begin();
		if(ss[lol[i]][dx]==i){dx--;}
		update(1,1,n,ss[lol[i]][dx]+1,i);
		dp[kk][i]=max(dp[kk-1][i],maxi(1,1,n,1,i));
	}
}

int main()
{ 
	cin>>n>>k;
	for(int i=0;i<35555;i++){ss[i].push_back(0);}
	for(int i=1;i<=n;i++){
		cin>>lol[i];
		ss[lol[i]].push_back(i);
	}
	set<int> sik;
	for(int i=1;i<=n;i++){
		sik.insert(lol[i]);
		dp[1][i]=sik.size();
	}
	ll ans=sik.size();
	for(int i=2;i<=k;i++){
		kok(i);
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,maxi(1,1,n,i,i));
	}
	cout<<ans<<endl;
	return 0;
}
