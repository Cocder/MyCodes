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
#define pi pair<int,int>
#define inf 1000000001
#define ln 22


int gcdex(int a,int b,int &x,int &y)
{
	if(!a)
	{
		x=0,y=1;return b;
	}
	int k=b/a; 
	int g=gcdex(b-k*a,a,y,x);
	x-=k*y;
	return g;
}
int inv(int a,int m)
{
	int x,y,g;
	g=gcdex(a,m,x,y);
	return (x%(m/g)+m/g)%m/g;
}
int main(){
	while(1){
		int a,m;cin>>a>>m;
		cout<<inv(a,m)<<endl;
	}
   return 0;
}