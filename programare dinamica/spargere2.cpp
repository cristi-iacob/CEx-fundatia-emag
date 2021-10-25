// https://www.infoarena.ro/problema/spargere2

#include <iostream>
	
#include <fstream>
	
using namespace std;
	
#define NMAX  100005
	
int n, k;
	
long long a[NMAX], dp[NMAX];
	
 
	
ifstream in("spargere2.in");
	
ofstream out("spargere2.out");
	
 
	
int main(){
	
    in>>n>>k;
	
    for(int i = 1; i <= n; i++){
	
        in>>a[i];
	
    }
	
    for(int i = 1; i <= n; i++){
	
        if(i - k < 0)
	
            dp[i] = max(dp[i-1], a[i]);
	
        else
	
            dp[i] = max(a[i] + dp[i - k], dp[i-1]);
	
    }
	
    out<<dp[n];
	
    return 0;
	
}