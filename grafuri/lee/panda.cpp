// https://infoarena.ro/problema/panda

#include <fstream>
	
#include <bitset>
	
#include <queue>
	
#define NMAX 501
	
 
	
using namespace std;
	
 
	
ifstream f("panda.in");
	
ofstream g("panda.out");
	
 
	
int mat[NMAX][NMAX], i, j, n, m, urs_int, t, xs, ys, s, cod_int, x[NMAX*NMAX], y[NMAX*NMAX], quiz, reza=0, k, rezb1=2000000000, rezb2=0;
	
const int dx[]={1,-1,0,0};
	
const int dy[]={0,0,1,-1};
	
bool ok[NMAX][NMAX];
	
 
	
bitset <35> urs, cod;
	
 
	
struct coordonate
	
{
	
    int x, y;
	
};
	
 
	
bool inside (coordonate a)
	
{
	
    if (a.x>=1 && a.x<=n && a.y>=1 && a.y<=m) return 1;
	
    return 0;
	
}
	
 
	
queue <coordonate> q;
	
 
	
void lee(int i, int j)
	
{
	
    mat[i][j]=1;
	
    coordonate coord;
	
    coord.x=i;
	
    coord.y=j;
	
    q.push(coord);
	
 
	
        while (!q.empty())
	
        {
	
            coord=q.front();
	
            q.pop();
	
            coordonate newcoord;
	
 
	
                for (int k=0; k<=3; ++k)
	
                {
	
                    newcoord.x=coord.x+dx[k];
	
                    newcoord.y=coord.y+dy[k];
	
                    if (inside(newcoord) && mat[newcoord.x][newcoord.y]==0 && ok[newcoord.x][newcoord.y]==1)
	
                    {
	
                        q.push(newcoord);
	
                        mat[newcoord.x][newcoord.y]=mat[coord.x][coord.y]+1;
	
                    }
	
                }
	
 
	
        }
	
}
	
 
	
int main()
	
{
	
    f>>quiz>>n>>m>>t>>xs>>ys>>urs_int>>s;
	
    urs=urs_int;
	
 
	
    for (i=1; i<=t; ++i)
	
        f>>x[i]>>y[i];
	
 
	
    for (i=1; i<=n; ++i)
	
        for (j=1; j<=m; ++j)
	
    {
	
        //cod.reset();
	
        f>>cod_int;
	
        cod=cod_int;
	
        bool okk=1;
	
        for (k=0; k<s; ++k)
	
            if (cod[k]==urs[k])
	
            {
	
                okk=0;
	
                break;
	
            }
	
 
	
        if (i==xs && j==ys) okk=0;
	
 
	
        if (okk)
	
            ok[i][j]=1, reza++;
	
    }
	
 
	
    if (quiz==1) g<<reza<<'\n';
	
    else
	
    {
	
        lee(xs,ys);
	
        for (i=1; i<=t; ++i)
	
            if (mat[x[i]][y[i]]!=0 && mat[x[i]][y[i]]<rezb1)
	
            rezb1=mat[x[i]][y[i]], rezb2=1;
	
        else
	
            if (mat[x[i]][y[i]]!=0 && mat[x[i]][y[i]]==rezb1)
	
            rezb2++;
	
 
	
        g<<rezb1-1<<" "<<rezb2<<'\n';
	
    }
	
    return 0;
	
}