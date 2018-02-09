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
int area(int x1, int y1, int x2, int y2, int x3, int y3)//area of triangle:sum/2
{
	int sum=((int)x1*(y2-y3) + (int)x2*(y3-y1)+ (int)x3*(y1-y2));
	if(sum<0){sum=sum*-1;}
    return sum;
}
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
   int A = area (x1, y1, x2, y2, x3, y3);
   int A1 = area (x, y, x2, y2, x3, y3);
   int A2 = area (x1, y1, x, y, x3, y3);
   int A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

int main() {
	
    return 0;
}