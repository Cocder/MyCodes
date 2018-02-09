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


int bitt[nsize];
void update(int n,int index,int val)
{
    while (index <= n)
    {
       bitt[index]=max(val,bitt[index]);
       index += index & (-index);
    }
}
int maxi(int index)
{
    int mas = 0;
	while (index>0)
    {
        mas=max(mas,bitt[index]);
        index -= index & (-index);
    }
    return mas;
}
int main(){
	

    return 0;
}