// https://infoarena.ro/problema/alee

#include <fstream>
	
#include <queue>
	
#define NMAX 180
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("alee.in");
	
ofstream g("alee.out");
	
 
	
int i, n, m, j, mat[NMAX][NMAX], x, y, stx, sty, fix, fiy;
	
const int dx[] = {1, -1, 0, 0};
	
const int dy[] = {0, 0, 1, -1};
	
queue < pair < int, int > > q;
	
 
	
bool inside(int x, int y)
	
{
	
    if (x >= 1 && x <= n && y >= 1 && y <= n)
	
        return 1;
	
    return 0;
	
}
	
 
	
void lee()
	
{
	
    q.push({stx, sty});
	
    mat[stx][sty] = 1;
	
 
	
    while (!q.empty())
	
    {
	
        pair < int, int > curr = q.front();
	
        q.pop();
	
 
	
        for (int k = 0; k <= 3; ++ k)
	
        {
	
            int newx = curr.first + dx[k];
	
            int newy = curr.second + dy[k];
	
 
	
            if (inside(newx, newy) && mat[newx][newy] > mat[curr.first][curr.second] + 1 && mat[newx][newy] != -1)
	
            {
	
                q.push({newx, newy});
	
                mat[newx][newy] = mat[curr.first][curr.second] + 1;
	
            }
	
        }
	
    }
	
}
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        for (j = 1; j <= n; ++ j)
	
            mat[i][j] = inf;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> x >> y;
	
        mat[x][y] = -1;
	
    }
	
 
	
    f >> stx >> sty >> fix >> fiy;
	
 
	
    lee();
	
 
	
    g << mat[fix][fiy] << '\n';
	
    return 0;
	
}