// https://www.pbinfo.ro/probleme/1500/nuclee

#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 205

using namespace std;

ifstream f("nuclee.in");
ofstream g("nuclee.out");

int i, n, m, x, ans = 0, start[NMAX];
bool used[NMAX];
vector < int > v[NMAX], vt[NMAX];

void DFS(int node)
{
    used[node] = 1;

    for (auto & it : v[node])
        if (!used[it])
            DFS(it);

    start[++ ans] = node;
}

void DFS2(int node)
{
    used[node] = 0;

    for (auto & it : vt[node])
        if (used[it])
            DFS2(it);
}

int main()
{
    f >> n;

    for (i = 1; i <= n; ++ i)
    {
        f >> m;

        for (int j = 1; j <= m; ++ j)
        {
            f >> x;
            v[i].push_back(x);
            vt[x].push_back(i);
        }
    }

    for (i = 1; i <= n; ++ i)
        if (!used[i])
            DFS(i);

    ans = 0;

    for (i = n; i >= 1; -- i)
        if (used[start[i]])
    {
        DFS2(start[i]);
        ans ++;
    }

    g << ans << '\n';
    return 0;
}