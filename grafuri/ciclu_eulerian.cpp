// https://www.infoarena.ro/problema/ciclueuler

#include <fstream>
	
#include <stack>
	
#include <vector>
	
#include <list>
	
#include <algorithm>
	
#define NMAX 100005
	
 
	
using namespace std;
	
 
	
ifstream f("ciclueuler.in");
	
ofstream g("ciclueuler.out");
	
 
	
int i, n, m, x, y;
	
 
	
vector < int > ans;
	
stack < int > st;
	
list < int > v[NMAX];
	
 
	
void euler(int node)
	
{
	
    st.push(node);
	
 
	
    while (!st.empty())
	
    {
	
        int curr = st.top();
	
 
	
        while (v[curr].size())
	
        {
	
            int next = v[curr].front();
	
            v[curr].pop_front();
	
            v[next].erase(find(v[next].begin(), v[next].end(), curr));
	
            st.push(next);
	
            curr = next;
	
        }
	
 
	
        ans.push_back(st.top());
	
        st.pop();
	
    }
	
}
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> x >> y;
	
        v[x].push_back(y);
	
        v[y].push_back(x);
	
    }
	
 
	
    for (i = 1; i <= n; ++ i)
	
        if (v[i].size() == 0 || v[i].size() % 2 == 1)
	
    {
	
        g << -1;
	
        return 0;
	
    }
	
 
	
    euler(1);
	
 
	
    for (auto & it : ans)
	
        g << it << " ";
	
    return 0;
	
}