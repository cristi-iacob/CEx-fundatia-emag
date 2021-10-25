// https://www.pbinfo.ro/probleme/392/cladire

#include <fstream>

using namespace std;

ifstream f("cladire.in");
ofstream g("cladire.out");

int i,j,n,m,mat[1001][1001];

int main()
{
    f>>n>>m;
    for (i=1; i<=n; ++i) mat[i][1]=1;
    for (i=1; i<=m; ++i) mat[1][i]=1;

    for (i=2; i<=n; ++i)
        for (j=2; j<=m; ++j) mat[i][j]=(mat[i-1][j]+mat[i][j-1])%9901;
    g<<mat[n][m];
    return 0;
}