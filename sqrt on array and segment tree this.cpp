using namespace std;
#define ld long double
#define tll long long int
#define mp make_pair
#define maxn 1001100
#define ln 20
#define mod 1000000007
 
using namespace std;
#define ld long double
#define tll long long int
#define mp make_pair
#define maxn 1001100
#define ln 20
#define mod 1000000007
 
int arr[maxn],p;
int B[maxn],bucket,tedad;
int ttree[maxn*4];//on buket
int fsqrt[maxn];
int stree[5010][5010*4];
void sbuild(int node, int a, int b,int dx)
{
	if(b<a){return;}
    if(a==b){
		stree[dx][node]=arr[a-1]%p;
		return;
	}
    sbuild(node*2,a,(a+b)/2,dx);
    sbuild(node*2+1,(a+b)/2+1,b,dx);
	stree[dx][node]=((tll)stree[dx][node*2]*stree[dx][node*2+1])%p;
}
int smult(int node, int a, int b, int i, int j,int dx)
{
    if(b<a || a>j || b<i)
        return 1;
    if(a>=i && b<=j){
        return stree[dx][node];
    }
    int lef=smult(node*2,a,(a+b)/2,i,j,dx);
	int rig=smult(node*2+1,(a+b)/2+1,b,i,j,dx);
	int res=((tll)lef*rig)%p;
	return res;
}
void tbuild(int node, int a, int b)
{
	if(b<a){return;}
    if(a==b){
		ttree[node]=fsqrt[a]%p;
		return;
	}
    tbuild(node*2,a,(a+b)/2);
    tbuild(node*2+1,(a+b)/2+1, b);
	ttree[node]=((tll)ttree[node*2]*ttree[node*2+1])%p;
}
int tmult(int node, int a, int b, int i, int j)
{
    if(b<a || a>j || b<i)
        return 1;
    if(a>=i && b<=j){
        return ttree[node];
    }
    int lef=tmult(node*2,a,(a+b)/2,i,j);
	int rig=tmult(node*2+1,(a+b)/2+1,b,i,j);
	int res=((tll)lef*rig)%p;
	return res;
}
void create(int bs,int n){
	int st=bs*bucket;int fin=min(n,st+bucket);
	int res=1;
	for(int i=st;i<fin;i++){
		res=((tll)res*arr[i])%p;
	}
	fsqrt[bs+1]=res;
	sbuild(1,st+1,fin,bs);
}
#define inchar			getchar_unlocked
#define outchar(x)		putchar_unlocked(x)
 
template<typename T> void inpos(T &x) {
	x = 0; register T c = inchar();
	while(((c < 48) || (c > 57)) && (c != '-')) c = inchar();
	bool neg = false; if (c=='-') neg = true;
	for(; c < 48 || c > 57; c = inchar()) ;
	for(; c > 47 && c < 58; c = inchar()) x = (x<<3) + (x<<1) + (c&15);
	if(neg) x = -x;
}
 
template<typename T> void outpos(T n) {
	if(n < 0) { outchar('-'); n *= -1; }
	char snum[65]; int i = 0;
	do {
		snum[i++] = n % 10 + '0';
		n /= 10;
	} while(n);
	i = i - 1;
	while (i >= 0) outchar(snum[i--]); outchar(' ');
}
int main() {
	int tt;cin>>tt;
	while(tt--){
		int n,q;inpos(n);inpos(p);inpos(q);
		bucket=sqrt(n);
		tedad=n/bucket;if(n%bucket){tedad++;}
		for(int i=0;i<n;i++){
			inpos(arr[i]);
		}
		int bsiz=(int)(q/64)+2;
		for(int i=0;i<bsiz;i++){
			inpos(B[i]);
		}
		//now build segment on sqrt!
		for(int i=0;i<tedad;i++){
			create(i,n);
		}
		tbuild(1,1,tedad);
		int l,r;
		int x=0;
		for(int qq=0;qq<q;qq++){
			if(qq%64==0){
				int dx=qq/64;
				l=(B[dx]+x)%n;
				r=(B[dx+1]+x)%n;
			}
			else{
				l=(l+x)%n;
				r=(r+x)%n;
			}
			if(l>r){swap(l,r);}
			//now must query from l to r!
			int lb=l/bucket;int rb=r/bucket;
			if(lb==rb){
				int st=lb*bucket;
				int fin=min(n,st+bucket);
				int siz=fin-st;
				x=smult(1,1,siz,l-st+1,r-st+1,lb);
			}
			else{
				int fir=lb+1,sec=rb-1;
				x=tmult(1,1,tedad,fir+1,sec+1);
				int st=lb*bucket;
				int fin=min(n,st+bucket);
				int siz=fin-st;
				x=((tll)x*smult(1,1,siz,l-st+1,siz,lb))%p;
				st=rb*bucket;
				fin=min(n,st+bucket);
				siz=fin-st;
				x=((tll)x*smult(1,1,siz,1,r-st+1,rb))%p;
			}
			x=(x+1)%p;
		}
		outpos(x);
		outchar('\n');
 
 
	}
	return 0;
}           