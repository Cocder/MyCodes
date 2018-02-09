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
 //last submit:Fuck you Compiler :(
using namespace std;
#define ll long long int
#define ld long double
#define mp make_pair
#define maxn 2000100
#define ln 23
#define inf 100000000000000000
const int mod=1000000007;
/*************************************timer***/
class rando{
    unsigned y;
public:
	rando(){
		y=2463534242;
	}
    unsigned next() {
        return y ^= (y ^= (y ^= y << 13) >> 17) << 5;
    }
    int next(int b) {
        return next() % b;
    }
    int next(int a, int b) {
        return next(b - a) + a;
    }
    double nextDouble(double b = 1) {
        return b * next() / 4294967296.0;
    }
    double nextDouble(double a, double b) {
        return nextDouble(b - a) + a;
    }
    int operator() (int b) {
        return next(b);
    }
    double nextNormalDistribution(double mu, double sigma) {
        static double a, b, bm1, bm2;
        static bool flag = false;
        flag = !flag;
        if (flag) {
            a = nextDouble();
            b = nextDouble() * 6.28318530718;
            bm1 = sqrt(log(a) * -2);
            bm2 = sin(b);
        } else {
            bm2 = cos(b);
        }
        return sigma * (bm1 * bm2) + mu;
    }
    double nextLogNormalDistribution(double mu, double sigma) {
        return exp(nextNormalDistribution(log(mu * mu) - log(mu * mu + sigma * sigma) / 2, sqrt(log(sigma * sigma / mu / mu + 1))));
    }
};
rando rnd;
/*
above:
  1-produce random shuffle of array in permutation manner!
  2- produce LogNormalDistribution for two given float
*/
int main(){
	vector<int> bob;
	for(int i=1;i<=8;i++){
		bob.push_back(i);
	}
	random_shuffle(bob.begin(),bob.end(),rnd);
	for(auto v:bob){
		cout<<v<<" ";
	}
	cout<<endl;
	//*******************************
	ld a,b;cin>>a>>b;
	while(1){
		int tp;cin>>tp;
		if(tp==1){
			cin>>a>>b;
		}
		else{
			cout<<rnd.nextLogNormalDistribution(a,b)<<endl;
		}
	}
	return 0;
}