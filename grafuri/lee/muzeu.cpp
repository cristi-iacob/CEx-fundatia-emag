// https://www.infoarena.ro/problema/muzeu

#include <fstream>
	
#include <queue>
	
const int dx[]={1,-1,0,0};
	
const int dy[]={0,0,1,-1};
	
using namespace std;
	
 
	
 
	
char mat[252][252];
	
int viz[252][252],i,n,j,nr=0;
	
ifstream f("muzeu.in");
	
ofstream g("muzeu.out");
	
 
	
struct muzeu {
	
int x;
	
int y;
	
};
	
 
	
   queue<muzeu> q;
	
bool inside (int x, int y){
	
if (x>=1 && x<=n && y>=1 && y<=n)
	
    return 1;
	
    else
	
    return 0;
	
    }
	
 
	
muzeu p;
	
    void solve (){
	
    q.push(p);
	
    while (! q.empty())
	
    {
	
         muzeu coord=q.front();
	
        q.pop();
	
        for (i=0; i<=3; i++)
	
        {
	
            muzeu newcoord;
	
            newcoord.x=coord.x+dx[i];
	
            newcoord.y=coord.y+dy[i];
	
 
	
            if (viz[newcoord.x][newcoord.y]==-1 && inside(newcoord.x,newcoord.y)==1 && viz[newcoord.x][newcoord.y]!=-2){
	
           viz[newcoord.x][newcoord.y]=viz[coord.x][coord.y]+1;
	
           q.push(newcoord);
	
            }
	
        }
	
 
	
    }
	
    }
	
 
	
    int main()
	
    {
	
        f>>n;
	
 
	
        for(i=1; i<=n; i++)
	
        for (j=1; j<=n; j++)
	
        {
	
            f>>mat[i][j];
	
            if (mat[i][j]=='.') viz[i][j]=-1;
	
            if (mat[i][j]=='#') viz[i][j]=-2;
	
            if (mat[i][j]=='P'){
	
            viz[i][j]=0;
	
            nr++;
	
            p.x=i;
	
            p.y=j;
	
            q.push(p);
	
            }
	
        }
	
 
	
        solve();
	
 
	
        for (i=1; i<=n; i++)
	
        {
	
            for (j=1; j<=n; j++)
	
            {
	
 
	
                g<<viz[i][j]<<" ";
	
            }
	
            g<<'\n';
	
        }
	
        return 0;
	
    }