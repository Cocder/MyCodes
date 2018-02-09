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
#define nsize 1010
#define mp make_pair
#define inf 1000000000
#define ln 13

int matrix[nsize][nsize];
struct nod{
	int x,y,mx;
	nod(){}
	nod(int x, int y, int mx) : x(x), y(y), mx(mx) {}
	bool operator < (const nod& other) const {//max
        return mx<other.mx;
    }
};
struct Segtree2d{
	nod T[nsize*nsize];
	int n,m;
	nod build(int node, int a1, int b1, int a2, int b2) {
        if (a1>a2 || b1>b2){
            return def();
		}
        if (a1==a2 && b1==b2){
			return T[node]=nod(a1,b1,matrix[a1][b1]);
		}
        T[node]=def();
        T[node]=maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
        T[node]=maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        T[node]=maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
        T[node]=maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
        return T[node];
    }
	void init(int n, int m) {
        this -> n = n;
        this -> m = m;
        build(1, 1, 1, n, m);
    }
	nod query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
		if(x1>a2 || y1>b2 || x2<a1 || y2<b1 || a1>a2 || b1>b2){
            return def();
		}
        if(x1 <= a1 && y1 <= b1 && a2 <= x2 && b2 <= y2){
            return T[node];
		}
        nod mx = def();
        mx = maxNode(mx, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));
		return mx;
    }
    nod query(int x1, int y1, int x2, int y2) {
        return query(1, 1, 1, n, m, x1, y1, x2, y2);
    }
	nod update(int node, int a1, int b1, int a2, int b2, int x, int y, int value) {
        if (a1>a2 || b1>b2){
            return def();
		}
        if (x>a2 || y>b2 || x<a1 || y<b1){
            return T[node];
		}
        if(x==a1 && y==b1 && x==a2 && y==b2){
            return T[node]=nod(x, y, value);
		}
        nod mx = def();
        mx = maxNode(mx, update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value) );
        mx = maxNode(mx, update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
        mx = maxNode(mx, update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
        mx = maxNode(mx, update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value) );
        return T[node] = mx;
    }
    nod update(int x, int y, int value) {
        return update(1, 1, 1, n, m, x, y, value);
    }
	virtual nod maxNode(nod a, nod b) {
        return max(a, b);
    }
    virtual nod def() {
        return nod(0, 0, -inf);
    }
};
struct Segtree2dMin:Segtree2d{
    nod maxNode(nod a, nod b) {
        return min(a, b);
    }
    nod def() {
        return nod(0,0,inf);
    }
};
Segtree2d Tmax;
Segtree2dMin Tmin;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &matrix[i][j]);
		}
	}
	Tmax.init(n, m);
    Tmin.init(n, m);
	while(1){
		int tp;cin>>tp;
		if(tp==1){
			 int x1, y1, x2, y2;
			 scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			 cout<<Tmax.query(x1, y1, x2, y2).mx<<endl;
			 cout<<Tmin.query(x1, y1, x2, y2).mx<<endl;
		}
		else{
			 int x, y, v;
			scanf("%d %d %d",&x,&y,&v);
			Tmax.update(x,y,v);
			Tmin.update(x,y,v);
		}
	}

    return 0;
}