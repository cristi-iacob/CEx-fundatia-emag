// https://www.pbinfo.ro/probleme/396/sclm

#include <fstream>

using namespace std;

ifstream  f("sclm.in");
ofstream g("sclm.out");

int v[1002],i,n,l[1002],j,max1,tati[1002],maxim=-1,pozmax,x,cont=0;

int main ()
{
    f>>n;
    for (i=1; i<=n; i++)
    f>>v[i];


    l[n]=1; tati[n]=0;
    for (i=n-1; i>=1; i--)
    {
       max1=-1;
    for (j=i+1; j<=n; j++)
    if (l[j]>max1 && v[i]<v[j] )
    { max1=l[j];
        tati[i]=j;
    }


    l[i]=max1+1;
    }

    for (i=1; i<=n; i++)
    if (l[i]>maxim)
    {
        maxim=l[i];
        pozmax=i;
    }

x=pozmax;
    do
    {

        x=tati[x];
        cont++;
    }
    while ( x!= 0) ;
    g<<cont<<'\n';
    x=pozmax;
    do
    {
        g<<x<<" ";
        x=tati[x];

    }
    while ( x!= 0) ;


   // for (i=1; i<=n; i++)
   // g<<l[i]<<" ";
   // g<<'\n';
   // for (i=1; i<=n; i++)
   // g<<tati[i]<<" ";
    return 0;

}