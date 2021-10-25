// https://www.infoarena.ro/problema/deque

#include <fstream>
	
#include <deque>
	
#define NMAX 5000005
	
 
	
using namespace std;
	
 
	
ifstream f("deque.in");
	
ofstream g("deque.out");
	
 
	
int i, n, k, v[NMAX];
	
long long s = 0;
	
deque < int > d;
	
 
	
int main()
	
{
	
    f >> n >> k;
	
 
	
    for (i = 1; i <= n; ++ i)
	
    {
	
        f >> v[i];
	
 
	
        while (d.size() && v[i] < v[d.back()])
	
            d.pop_back();
	
        d.push_back(i);
	
 
	
        if (i - d.front() == k)
	
            d.pop_front();
	
 
	
        if (i >= k)
	
            s += (long long) v[d.front()];
	
    }
	
 
	
    g << s << '\n';
	
    return 0;
	
}