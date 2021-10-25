// https://www.pbinfo.ro/probleme/1661/fotbal1

#include <iostream>
#include <algorithm>
#define NMAX 2505

using namespace std;

int a, b;
unsigned long long dp[NMAX][NMAX];

int main()
{
    cin >> a >> b;

    for (int i = 0; i <= a; ++ i)
        dp[i][0] = 1;

    for (int i = 0; i <= b; ++ i)
        dp[0][i] = 1;

    for (int i = 1; i <= a; ++ i)
        for (int j = 1; j <= b; ++ j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    cout << dp[a][b] << '\n';
    return 0;
}