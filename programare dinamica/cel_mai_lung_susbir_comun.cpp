// https://www.infoarena.ro/problema/cmlsc

#include <bits/stdc++.h>
	
 
	
using namespace std;
	
ifstream fin ("cmlsc.in");
	
ofstream fout ("cmlsc.out");
	
int x[1025], y[1025], dp[1025][1025];
	
 
	
int main()
	
{
	
    vector<int> ans;
	
    int n,m;
	
    fin >> m >> n;
	
    for (int i = 1; i <= m; i++)
	
        fin >> x[i];
	
    for (int i = 1; i <= n; i++)
	
        fin >> y[i];
	
 
	
    for (int i = 1; i <= m; i++)
	
        for (int j = 1; j <= n; j++) {
	
            if (x[i] == y[j])
	
                dp[i][j] = dp[i - 1][j - 1] + 1;
	
            else
	
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	
        }
	
    int i = m, j = n;
	
    while (i && j) {
	
        if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1]) {
	
            ans.push_back(x[i]);
	
            i--;
	
            j--;
	
        }
	
        else if (dp[i - 1][j] > dp[i][j - 1])
	
            i--;
	
        else
	
            j--;
	
    }
	
    fout << dp[m][n] << endl;
	
    for (i = ans.size() - 1; i >= 0; i--)
	
        fout << ans.at(i) << ' ';
	
    return 0;
	
}