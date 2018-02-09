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
#define ln 31

int table[ln][nsize],n;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>table[0][i];
	}
	for(int j=1;j<ln;j++){
		for(int i=0;i+(1<<(j-1))<n;i++){
			table[j][i]=max(table[j-1][i],table[j-1][i+(1<<(j-1))]);
		}
	}
	while(1){
		int l,r;cin>>l>>r;l--;r--;
		int len=r-l+1;
		int k=(ld)log(len)/log(2.0);
		int res=max(table[k][l],table[k][r+1-(1<<k)]);
		cout<<res<<endl;
	}
    return 0;
}
