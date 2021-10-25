// https://www.pbinfo.ro/probleme/592/kruskal

#include <fstream>
#include <algorithm>
#include <vector>
#define NMAX 200005

using namespace std;

ifstream f("kruskal.in");
ofstream g("kruskal.out");

int i, n, m, comp[2 * NMAX], used = 0, ans = 0;
vector < pair < int, int > > sol;

struct muchie
{
    int x, y, cost;
};
muchie v[2 * NMAX];

bool cmp(muchie a, muchie b)
{
    return a.cost < b.cost;
}

int main()
{
    f >> n >> m;

    for (i = 1; i <= m; ++ i)
        f >> v[i].x >> v[i].y >> v[i].cost;

    for (i = 1; i <= n; ++ i)
        comp[i] = i;

    sort (v + 1, v + m + 1, cmp);

    i = 1;
    while (used < n - 1)
    {
        if (comp[v[i].x] != comp[v[i].y])
        {
            ans += v[i].cost;
            used ++;
            sol.push_back(make_pair(v[i].x, v[i].y));
            int a = comp[v[i].y];
            int b = comp[v[i].x];

            for (int j = 1; j <= n; ++ j)
                if (comp[j] == a)
                    comp[j] = b;
        }
        i ++;
    }

    g << ans << '\n';
  //  g << sol.size() << '\n';

    for (vector < pair < int, int > > :: iterator it = sol.begin(); it != sol.end(); ++ it)
        g << it -> first << " " << it -> second << '\n';

    return 0;
}
