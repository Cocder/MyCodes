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
#define ln 13
ll mul2 (ll a, ll b, ll m) {
  ll q=(ll)((ld)a*(ld)b/(ld)m);
  ll r=a*b-q*m;
  return (r+5*m)%m;
}
ll mult(ll a,ll b,ll p){
	ll ret=mul2(abs(a),abs(b),p);
	if(a<0)ret*=-1;
	if(b<0)ret*=-1;
	if(ret<0)ret+=p;
	return ret;
}
int main(){

   return 0;
}