// https://www.infoarena.ro/problema/hashuri

#include <fstream>
	
#include <unordered_set>
	
 
	
using namespace std;
	
 
	
ifstream f("hashuri.in");
	
ofstream g("hashuri.out");
	
 
	
int x, nrquiz, type;
	
unordered_set < int > s;
	
 
	
int main()
	
{
	
    f >> nrquiz;
	
 
	
    while (nrquiz)
	
    {
	
        nrquiz --;
	
 
	
        f >> type >> x;
	
 
	
        if (type == 1)
	
            s.insert(x);
	
 
	
        if (type == 2)
	
            s.erase(x);
	
 
	
        if (type == 3)
	
            g << (s.find(x) != s.end()) << '\n';
	
    }
	
    return 0;
	
}