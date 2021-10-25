// https://www.pbinfo.ro/probleme/414/listavecini

#include <fstream>
#include <cstring>
#define NMAX 101

using namespace std;

ifstream f("listavecini.in");
ofstream g("listavecini.out");

int mat[NMAX][NMAX];
int i, j, n, x, y;
char c[NMAX];

int main()
{
    f>>n;

    while (f.getline(c,NMAX-2))
    {
        f>>x>>y;
        mat[x][y] = mat[y][x] = 1;
    }

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            if (mat[i][j]==1) mat[i][0]++;

    for (i=1; i<=n; ++i)
    {
        g<<mat[i][0]<<" ";
        for (j=1; j<=n; ++j)
            if (mat[i][j]==1) g<<j<<" ";
        g<<'\n';
    }
    return 0;
}