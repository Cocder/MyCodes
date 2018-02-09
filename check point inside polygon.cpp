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


bool onSegment(pi p, pi q, pi r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
            q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;
    return false;
}
int orientation(pi p, pi q, pi r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool inter(pi p1,pi q1,pi p2,pi q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
		{return true;}
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}
bool isInside(vector<pi> polygon, int n,pi p)
{
    if (n < 3)  return false;
	pi extreme = make_pair(10000,p.second-1);
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
		if (inter(polygon[i], polygon[next], p, extreme))
        {
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);
	return count&1;
}
int main() {
    
	while(1){
		int sz;cin>>sz;
		vector<pi> pol;pi pnt;
		for(int i=0;i<sz;i++){
			int x,y;cin>>x>>y;
			pi hp;hp.first=x;hp.second=y;
			pol.push_back(hp);
		}
		while(1){
			cin>>pnt.first>>pnt.second;
			cout<<isInside(pol,sz,pnt)<<endl;
		}
	}
    return 0;
}