// https://www.pbinfo.ro/probleme/589/roy-floyd

#include <fstream>
#include <algorithm>
#define inf (1 << 29)
#define NMAX 105

using namespace std;

ifstream f("roy-floyd.in");
ofstream g("roy-floyd.out");

int i, n, m, j, k, mat[NMAX][NMAX], cost, x, y;

int main()
{
    f >> n >> m;

    for (i = 1; i <= n; ++ i)
        for (j = 1; j <= n; ++ j)
            if (i != j)
                mat[i][j] = inf;

    for (i = 1; i <= m; ++ i)
    {
        f >> x >> y >> cost;
        mat[x][y] = cost;
    }

    for (k = 1; k <= n; ++ k)
        for (i = 1; i <= n ; ++ i)
            for (j = 1; j <= n; ++ j)
                if (mat[i][k] != inf && mat[k][j] != inf && mat[i][k] != 0 && mat[k][j] != 0)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    for (i = 1; i <= n; ++ i)
    {
        for (j = 1; j <= n; ++ j)
            if (mat[i][j] == inf)
                g << "-1 ";
        else
                g << mat[i][j] << " ";
        g << '\n';
    }
    return 0;
}
