// https://www.pbinfo.ro/probleme/610/spion

#include <fstream>
#include <cstring>
#include <bitset>
using namespace std;

ifstream f("spion.in");
ofstream g("spion.out");

/*

#include <bitset>
bitset<10> v;

cin>>v;
cout<<v;;

v.size() //dimensiunea
v.count() //cati 1
v.size()-v.count() //cati 0

v.set(); //toti 1
v.set(2,0) //v[2]=0;
v.set(2) //v[2]=1;

v.flip() //0->1  1->0
v.reset() //tot 0;

v.any() //true daca exista cel putin un 1, false daca nu exista 1
v.none() //true daca toti is 1, false daca nu

v.to_ulong() //transforma din baza 2 in baza 10


*/

bitset <50000002> ok;
int i,n,rez=0,x,s,d;

int main()
{
    f>>n;
  //  memset(ok,0,n);
    for (i=1; i<=n; ++i)
    {
        f>>x>>s>>d;
        if (ok[s]==0 && ok[d]==0 && ok[x]==0) rez++;
        else
            if (ok[s]==1 && ok[d]==1  )    rez--;


        ok[x]=1;
        g<<rez<<'\n';
    }

    return 0;
}