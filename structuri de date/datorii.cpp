// https://www.infoarena.ro/problema/datorii

	
#include <fstream>
	
#include <algorithm>
	
#define NMAX 15005
	
 
	
using namespace std;
	
 
	
ifstream f("datorii.in");
	
ofstream g("datorii.out");
	
 
	
int i, n, v[4 * NMAX], Left, Right, Ans, nrquery, type, value, index;
	
 
	
void Update(int left, int right, int node)
	
{
	
    if (left == right)
	
    {
	
        v[node] += value;
	
        return;
	
    }
	
 
	
    int mid = (left + right) / 2;
	
 
	
    if (index <= mid)
	
        Update(left, mid, 2 * node);
	
    else
	
        Update(mid + 1, right, 2 * node + 1);
	
 
	
    v[node] = v[2 * node] + v[2 * node + 1];
	
}
	
 
	
void Query(int left, int right, int node)
	
{
	
    if (Left <= left && right <= Right)
	
    {
	
        Ans += v[node];
	
        return;
	
    }
	
 
	
    int mid = (left + right) / 2;
	
 
	
    if (Left <= mid)
	
        Query(left, mid, 2 * node);
	
 
	
    if (mid < Right)
	
        Query(mid + 1, right, 2 * node + 1);
	
}
	
 
	
int main()
	
{
	
    f >> n >> nrquery;
	
 
	
    for (i = 1; i <= n; ++ i)
	
    {
	
        f >> value;
	
        index = i;
	
        Update(1, n, 1);
	
    }
	
 
	
    while (nrquery --)
	
    {
	
        f >> type;
	
 
	
        if (type == 0)
	
        {
	
            f >> index >> value;
	
            value *= -1;
	
            Update(1, n, 1);
	
        }
	
 
	
        if (type == 1)
	
        {
	
            Ans = 0;
	
            f >> Left >> Right;
	
            Query(1, n, 1);
	
            g << Ans << '\n';
	
        }
	
    }
	
    return 0;
	
}