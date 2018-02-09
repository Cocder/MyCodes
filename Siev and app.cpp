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
#define inf 1000000000
#define ln 13
int a[1000005];
bool prime[1000005];
vector<int> pn(1000005);
 
void SieveOfEratosthenes() {
 	fill (prime, prime + 1000005, true);
    for (int p = 2; p <= 1000001; p++) {
        if (prime[p] == true) {
        	pn[p] = p;
            for (int i = p * 2; i <= 1000001; i += p) {
            	prime[i] = false;
            	pn[i] = p;
            }   
        }
    }
}
 
int main() {
	SieveOfEratosthenes();
	int t, n;
 
	cin>>t;
	while (t--) {
		map<int, int> freq;
 
		cin>>n;
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
 
		for (int i = 0; i < n; i++) {
			int temp = a[i];
			int cans;
			while (temp != 1) {
				int val = pn[temp];
				cans = 0;
				while (temp % val == 0) {
					cans++;
					temp = temp / val;
				}
				if (cans % 2 == 1) {
					freq[val]++;
				}
			}
		}
		int ans = 0;
		for (auto it : freq) {
			ans += min(n - it.second, it.second);
		}
		cout<<ans<<"\n";
	}
 
	
	return 0;
}  