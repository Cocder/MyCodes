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
#define nsize 100010
#define mp make_pair

struct RangeFenwick2D {
    int n,m;
    vector<vector<ll>> fen[4];
    RangeFenwick2D(int n,int m) {
        this->n=n,this->m=m;
        for (int i = 0; i < 4; i++) {
            fen[i].resize(n+1,vector<ll>(m+1));
        }
    }
    void upd(int x, int y,ll val) {
        for (int xx=x;xx<=n;xx+=xx&-xx) {
            for (int yy=y;yy<=m;yy+=yy&-yy) {
                fen[0][xx][yy]+=(ll)val;
                fen[1][xx][yy]+=(ll)x*val;
                fen[2][xx][yy]+=(ll)y*val;
                fen[3][xx][yy]+=(ll)x*y*val;
            }
        }
    }
    void upd(int x, int y, int z, int t,ll val) {
        upd(x,y,+val);
        upd(x,t+1,-val);
        upd(z+1,y,-val);
        upd(z+1,t+1,+val);
    }
    ll query(int x, int y) {
        ll res=0;
        for (int xx=x;xx>0;xx-=xx&-xx) {
            for (int yy=y;yy>0;yy-=yy&-yy) {
                res+=(ll)(x+1)*(y+1)*fen[0][xx][yy];
                res-=(ll)(y+1)*fen[1][xx][yy];
                res-=(ll)(x+1)*fen[2][xx][yy];
                res+=(ll)fen[3][xx][yy];
            }
        }
        return res;
    }
    ll query(int x,int y,int z,int t) {
        return query(z,t)-query(x-1,t)-query(z,y-1)+query(x-1,y-1);
    }
};
const int maxn = 1e3 + 5;
int n, m, q;
//if x,y>=1000 you must use comression!
int main() {
    int n,m;cin>>n>>m;
	RangeFenwick2D fanc(n+1,m+1);
	while(1){
		int tp;cin>>tp;
		if(tp==1){
			int xlt,ylt,xrb,yrb,vl;cin>>xlt>>ylt>>xrb>>yrb>>vl;
			fanc.upd(xlt,ylt,xrb,yrb,vl);
		}
		else{
			int xlt,ylt,xrb,yrb;cin>>xlt>>ylt>>xrb>>yrb;
			cout<<fanc.query(xlt,ylt,xrb,yrb)<<endl;
		}
	}
    return 0;
}
