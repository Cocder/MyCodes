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
//positive shif to right and negative shif to left
/*example
 our array: 1 2 3 4 5 6 7 8
 we want rotate subvector fron index [2,5] with 2 left
 a=2 b=-4 c=3
 so we must use ---> rotate(arr.begin()+2,arr.begin()+8-4,arr.end()-c)

*/
int main(){
	vector<int> arr;
	for(int i=1;i<=8;i++){
		arr.push_back(i);
	}
	while(1){
		int a,b,c;cin>>a>>b>>c;
		if(b<0){b=8+b;}
		rotate(arr.begin()+a,arr.begin()+b,arr.end()-c);
		for(int i=0;i<arr.size();i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}



	return 0;
}