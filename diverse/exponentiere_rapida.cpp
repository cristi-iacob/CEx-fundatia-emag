// https://www.infoarena.ro/problema/lgput

#include <fstream>
	
#define mod 1999999973
	
 
	
using namespace std;
	
 
	
ifstream f("lgput.in");
	
ofstream g("lgput.out");
	
 
	
long long a, b;
	
 
	
long long putere(long long a, long long b)
	
{
	
    if (b == 0)
	
        return 1;
	
 
	
    if (b % 2 == 0)
	
        return putere((a * a) % mod, b / 2) % mod;
	
 
	
    return (a * (putere(a, b - 1) % mod)) % mod;
	
}
	
 
	
int main()
	
{
	
    f >> a >> b;
	
    g << putere(a, b) << '\n';
	
    return 0;
	
}