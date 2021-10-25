// https://www.pbinfo.ro/probleme/595/anarhie

#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#define NMAX 101
#define NNMAX 11

using namespace std;

ifstream f("anarhie.in");
ofstream g("anarhie.out");

int i, n, m, k, start, finish, a, b, d, cont, ans = 2000000000;
bool ok[NMAX];
vector < pair < int, int > > v[NMAX];
bitset < NNMAX > bit;
queue < int > q;

void read()
{
    f >> n >> m >> k >> start >> finish;

    for (int j = 1; j <= m; ++ j)
    {
        f >> a >> b >> d;
        v[a].push_back(make_pair(b, d));
    }
}

void BFS()
{
    bit = cont;
    q.push(start);

    for (int j = 1; j <= n; ++ j)
        ok[j] = 0;

    ok[start] = -1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        ok[current] = 1;

        for (vector < pair < int, int > > :: iterator it = v[current].begin(); it != v[current].end(); ++ it)
            if (ok[it -> first] == 0 && bit[it -> second - 1] == 1)
                q.push(it -> first);
    }

    int c = bit.count();

    if (ok[finish] == 1)
        ans = min(ans, c);
}

int main()
{
    read();

    cont = (1 << k) - 1;

    while (cont)
    {
        BFS();
        cont --;
    }

    g << ans << '\n';
    return 0;
}