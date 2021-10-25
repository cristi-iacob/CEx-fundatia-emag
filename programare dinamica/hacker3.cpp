// https://www.infoarena.ro/problema/hacker3

#include <bits/stdc++.h>
	
#define INF 1000000000LL * 1000000000LL
	
 
	
using namespace std;
	
 
	
ifstream f("hacker3.in");
	
ofstream g("hacker3.out");
	
 
	
long long dp[2][51], a, b, ans = INF;
	
int n;
	
 
	
int main()
	
{
	
    f >> n;
	
 
	
    for (int i = 1; i <= n; ++ i) {
	
        f >> a >> b;
	
        dp[i % 2][0] = b + dp[(i + 1) % 2][0];
	
 
	
        for (int j = 1; j <= 50; ++ j) {
	
            long long valA, valB;
	
 
	
            if (b <= INF / (1LL << j)) {
	
                valB = b * (1LL << j);
	
            } else {
	
                valB = INF;
	
            }
	
 
	
            if (a <= INF / (1LL << (j - 1))) {
	
                valA = a * (1LL << (j - 1));
	
            } else {
	
                valA = INF;
	
            }
	
 
	
            dp[i % 2][j] = min(dp[(i + 1) % 2][j] + valB, dp[(i + 1) % 2][j - 1] + valA);
	
        }
	
    }
	
 
	
    for (int i = 0; i <= 50; ++ i) {
	
        ans = min(ans, dp[n % 2][i]);
	
    }
	
 
	
    g << ans << '\n';
	
    return 0;
	
}