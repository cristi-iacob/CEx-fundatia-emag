// https://infoarena.ro/problema/disjoint

#include <fstream>
	
#define NMAX 100005
	
 
	
using namespace std;
	
 
	
ifstream f("disjoint.in");
	
ofstream g("disjoint.out");
	
 
	
int i, n, nrquiz, type, a, b, color[NMAX];
	
 
	
int get_color(int node)
	
{
	
    if (node != color[node])
	
        color[node] = get_color(color[node]);
	
    return color[node];
	
}
	
 
	
void unite(int a, int b)
	
{
	
    color[get_color(a)] = get_color(b);
	
}
	
 
	
int main()
	
{
	
    f >> n >> nrquiz;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        color[i] = i;
	
 
	
    while (nrquiz)
	
    {
	
        nrquiz --;
	
        f >> type >> a >> b;
	
 
	
        if (type == 1)
	
            unite(a, b);
	
        else
	
        {
	
            if (get_color(a) == get_color(b))
	
                g << "DA" << '\n';
	
            else
	
                g << "NU" << '\n';
	
        }
	
    }
	
    return 0;
	
}