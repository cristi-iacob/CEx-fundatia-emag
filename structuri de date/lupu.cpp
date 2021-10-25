// https://www.infoarena.ro/problema/lupu

#include <fstream>
	
#include <vector>
	
#include <queue>
	
#include <algorithm>
	
#define NMAX 100001
	
 
	
using namespace std;
	
 
	
ifstream f("lupu.in");
	
ofstream g("lupu.out");
	
 
	
int i, n, x, l, j, tmax = -1, heap[2*NMAX], nn = 0;
	
long long ans = 0;
	
 
	
struct oaie
	
{
	
    int dist, lana;
	
};
	
oaie v[NMAX];
	
 
	
bool cmp(oaie a, oaie b)
	
{
	
    return a.dist < b.dist;
	
}
	
 
	
priority_queue < int > pq;
	
 
	
int father(int x)
	
{
	
    return x/2;
	
}
	
 
	
int left_son(int x)
	
{
	
    return 2*x;
	
}
	
 
	
int right_son(int x)
	
{
	
    return 2*x + 1;
	
}
	
 
	
void get_down(int k)
	
{
	
    int aux;
	
 
	
    do
	
    {
	
        aux = 0;
	
 
	
        if (left_son(k) <= nn)
	
            aux = left_son(k);
	
 
	
        if (right_son(k) <= nn && heap[right_son(k)] > heap[aux])
	
            aux = right_son(k);
	
 
	
        if (heap[left_son(k)] <= heap[k] && heap[right_son(k)] <= heap[k])
	
            aux = 0;
	
 
	
        if (aux)
	
        {
	
            swap(heap[k], heap[aux]);
	
            k = aux;
	
        }
	
    } while (aux);
	
}
	
 
	
void get_up(int k)
	
{
	
    while (k > 1 && heap[k] > heap[father(k)])
	
    {
	
        swap(heap[k], heap[father(k)]);
	
        k = father(k);
	
    }
	
}
	
 
	
void insert_heap(int x)
	
{
	
    heap[++ nn] = x;
	
    get_up(nn);
	
}
	
 
	
void delete_heap(int k)
	
{
	
    swap(heap[k], heap[nn]);
	
    heap[nn] = -1;
	
    nn --;
	
    get_down(k);
	
}
	
 
	
int main()
	
{
	
    f >> n >> x >> l;
	
 
	
    for (i=1; i<=n; ++i)
	
    {
	
        f >> v[i].dist >> v[i].lana;
	
 
	
        if (l == 0) v[i].dist = 0;
	
            else
	
            v[i].dist = (x - v[i].dist) / l + 1;
	
        tmax = max(tmax, v[i].dist);
	
    }
	
 
	
    i = n;
	
    sort(v + 1, v + n + 1, cmp);
	
 
	
    for (j = tmax; j >= 1; -- j)
	
    {
	
        while (v[i].dist == j && i)
	
               insert_heap(v[i].lana), i--;
	
 
	
        if (nn)
	
        ans += (long long) heap[1], delete_heap(1);
	
    }
	
 
	
    g << ans << '\n';
	
    return 0;
	
}