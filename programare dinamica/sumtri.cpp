// https://www.pbinfo.ro/probleme/385/sumtri

#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("sumtri.in");
ofstream g("sumtri.out");


int main()
{
    int x[101][101],sume[101][101],i,j,n,z=-1;
    f>>n;
    for (i=1; i<=n; ++i)
        for (j=1; j<=i; ++j)
            f>>x[i][j];

    sume[1][1]=x[1][1];

    for (i=2; i<=n; ++i)
        for (j=1; j<=i; ++j)
        sume[i][j]=max( sume[i-1][j-1]+x[i][j] , sume[i-1][j]+x[i][j] );

    for (i=1; i<=n; ++i)
        z=max(z,sume[n][i]);
    g<<z;
}