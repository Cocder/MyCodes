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
#define pi pair<int,int>
#define inf 1000000001
#define ln 13

int n;
pi arr[nsize];
set<int> xc,yc;
map<int,int> xcompress,ycompress;
int page[5002][5002];
int check(int x,int y,int xx,int yy)
{
	//find left_bottom cortinate
	auto itr=xc.lower_bound(x);
	int x1=xcompress[*itr];
	itr=yc.lower_bound(y);
	int y1=ycompress[*itr];
	//find up_right cordinate
	itr=--xc.upper_bound(xx);
	int x2=xcompress[*itr];
	itr=--yc.upper_bound(yy);
	int y2=ycompress[*itr];
	x1=max(x1,1);y1=max(y1,1);//because for 0 and inf in first
	x2=min(x2,5000-1),y2=min(y2,5000-1);
	ll sum=page[x2][y2]-page[x1-1][y2]-page[x2][y1-1]+page[x1-1][y1-1];
	return sum;
}
int main() {
	xc.insert(0);xc.insert(inf);
	yc.insert(0);yc.insert(inf);
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		arr[i]=mp(x,y);
		xc.insert(x);yc.insert(y);
	}
	int ind=0;
	for(auto v:xc){
		 xcompress[v]=ind;
		 ind++;
	}
	ind=0;
	for(auto v:yc){
		   ycompress[v]=ind;
		   ind++;
	}
	for(int i=0;i<n;i++){
		   page[xcompress[arr[i].first]][ycompress[arr[i].second]]=1;
	}
	for(int i=1;i<5002;i++)
	{
		for(int j=1;j<5002;j++)
		{
			page[i][j]+=page[i-1][j]+page[i][j-1]-page[i-1][j-1];//use comulative sum for find number of point in a rectangle
		}
	}
	while(1){
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;//x1,y1:lef-bottom , x2,y2:right-top point
		cout<<check(x1,y1,x2,y2)<<endl;//return sum of value in rectangle with point (x1,y1) to point (x2,y2)
	}





    return 0;
}