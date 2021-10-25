// https://www.pbinfo.ro/probleme/1344/nrsubsircresc2

#include <fstream>
#include <algorithm>
#define NMAX 405

using namespace std;

ifstream f("nrsubsircresc2.in");
ofstream g("nrsubsircresc2.out");

int i, j, n, k, v[NMAX];
long long ans = 0, dp[NMAX][NMAX];

int main()
{
    f >> n >> k;

    for(i = 1; i <= n; ++ i)
    {
        f >> v[i];
        dp[i][1] = 1;
    }

    for (i = 1; i <= n; ++ i)
    {
        for (j = i; j >= 1; -- j)
            for (int l = i; l >= 1; -- l)
                if (v[j] < v[i])
                    dp[i][l] += dp[j][l - 1];

        ans += (long long) dp[i][k];
    }

    g << ans << '\n';
    return 0;
}
