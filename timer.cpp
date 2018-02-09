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
#define LIMIT 9.7
#define LOCAL_SCALE 2500000000ULL
#define TC_SCALE 2800000000ULL
class Timer {
	ld start, end;
	ld limit;
	ld getCycle() {
		#ifdef NDEBUG
				ll time;
				time=__rdtsc();
				return (ld)time/LOCAL_SCALE;
		#else
				unsigned long long low, high;
				__asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
				return (double)((low) | (high << 32)) / TC_SCALE;
		#endif
	}
public:
	Timer(){
		start=getCycle();
	}
	Timer(ld l){
		start=getCycle();
		limit=l;
	}
	ld getTime() {
		end=getCycle();
		return end-start;
	}
	bool Over() {
		if (getTime()>limit) {
			return true;
		}
		return false;
	}
	void setLimit(ld l) {
		limit=l;
	}
	void setStart(){start=getCycle();}
	ld getLimit(){return limit; }
};
int main(){
	Timer tmr;
	tmr.setLimit(LIMIT);
	while(1){
		if (tmr.Over())break;
	}
	return 0;
}      
 