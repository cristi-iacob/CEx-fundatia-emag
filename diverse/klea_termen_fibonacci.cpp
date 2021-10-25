// https://www.infoarena.ro/problema/kfib

#include <fstream>
	
#include <iostream>
	
#define NMAX 4
	
#define MOD 666013
	
 
	
using namespace std;
	
 
	
ifstream f("kfib.in");
	
ofstream g("kfib.out");
	
 
	
long long fib[NMAX][NMAX], mat[NMAX][NMAX], k;
	
 
	
void inmultire(long long a[NMAX][NMAX], long long b[NMAX][NMAX])
	
{
	
    long long c[NMAX][NMAX];
	
 
	
    c[1][1] = (a[1][1] * b[1][1] % MOD + a[1][2] * b[2][1] % MOD) % MOD;
	
    c[1][2] = (a[1][1] * b[1][2] % MOD + a[1][2] * b[2][2] % MOD) % MOD;
	
    c[2][1] = (a[2][1] * b[1][1] % MOD + a[2][2] * b[2][1] % MOD) % MOD;
	
    c[2][2] = (a[2][1] * b[1][2] % MOD + a[2][2] * b[2][2] % MOD) % MOD;
	
 
	
    for (int i = 1; i <= 2; ++ i)
	
        for (int j = 1; j <= 2; ++ j)
	
            a[i][j] = c[i][j];
	
}
	
 
	
int main()
	
{
	
    f >> k;
	
    k --;
	
 
	
    fib[1][1] = 1;
	
    fib[1][2] = 1;
	
    mat[1][2] = mat[2][1] = mat[2][2] = 1;
	
    mat[1][1] = 0;
	
 
	
    while (k)
	
    {
	
        if (k % 2 == 1)
	
        {
	
            inmultire(fib, mat);
	
            k --;
	
        }
	
 
	
        inmultire(mat, mat);
	
        k /= 2;
	
    }
	
 
	
    g << fib[1][1];
	
    return 0;
	
}