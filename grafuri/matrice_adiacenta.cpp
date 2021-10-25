// https://www.pbinfo.ro/probleme/412/adiacenta

#include <fstream>
#define NMAX 101

using namespace std;

ifstream f("adiacenta.in");
ofstream g("adiacenta.out");

int graph[NMAX][NMAX], i, j, n, m, x, y;

int main()
{
    f >> n >> m;

    for (i=1; i<=m; ++i)
    {
        f >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            g<<graph[i][j]<<" ";
        g<<'\n';
    }
    return 0;
}