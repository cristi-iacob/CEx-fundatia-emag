// https://www.infoarena.ro/problema/graf

#include <fstream>
	
#include <queue>
	
#include <algorithm>
	
#define NMAX 7502
	
 
	
using namespace std;
	
 
	
ifstream f("graf.in");
	
ofstream g("graf.out");
	
 
	
int i, n, m, start, finish, x, y, distX[NMAX], distY[NMAX], viz[NMAX], distXY, cont=0, sol[NMAX], j, cont2, father[NMAX], ans[NMAX];
	
queue <int> q;
	
 
	
struct node
	
{
	
    int value;
	
    node *next;
	
};
	
node *v[NMAX];
	
 
	
void initialize(int viz[], int x)
	
{
	
    for (int i=1; i<=n; ++i)
	
        viz[i] = -1;
	
    viz[x] = 0;
	
}
	
 
	
void add(node *&father, int data)
	
{
	
    node *NewNode = new node;
	
    NewNode -> value = data;
	
    NewNode -> next = father;
	
    father = NewNode;
	
}
	
 
	
void read()
	
{
	
    f>>n>>m>>start>>finish;
	
 
	
    for (int i=1; i<=m; ++i)
	
    {
	
        f>>x>>y;
	
        add(v[x],y);
	
        add(v[y],x);
	
    }
	
}
	
 
	
int BFSX()
	
{
	
    q.push(start);
	
    initialize(distX, start);
	
    father[start] = -1;
	
 
	
    while (!q.empty())
	
    {
	
        int a = q.front();
	
        q.pop();
	
 
	
        node *Node;
	
 
	
        for (Node = v[a]; Node != NULL; Node = Node -> next)
	
            if (distX[Node -> value] == -1)
	
            {
	
                distX[Node -> value] = distX[a] + 1;
	
                father[Node -> value] = a;
	
                q.push(Node -> value);
	
            }
	
    }
	
}
	
 
	
void BFSY()
	
{
	
    q.push(finish);
	
    initialize(distY, finish);
	
 
	
    while (!q.empty())
	
    {
	
        int a = q.front();
	
        q.pop();
	
 
	
        node *Node;
	
 
	
        for (Node = v[a]; Node != NULL; Node = Node -> next)
	
            if (distY[Node -> value] == -1)
	
        {
	
            distY[Node -> value] = distY[a] + 1;
	
            q.push(Node -> value);
	
        }
	
    }
	
}
	
 
	
int main()
	
{
	
    read();
	
    BFSX();
	
    BFSY();
	
 
	
  /*  for (i=1; i<=n; ++i) g<<distX[i]<<" ";
	
    g<<'\n';
	
    for (i=1; i<=n; ++i) g<<distY[i]<<" ";
	
    g<<'\n';*/
	
 
	
    distXY = distX[finish];
	
 
	
    int aux = finish;
	
    for (i=1; i<=n; ++i)
	
        if (distX[i] + distY[i] == distXY) sol[++cont] = i;
	
 
	
    sort(sol+1, sol+cont+1);
	
  //  for (i=1; i<=cont; ++i) g<<sol[i]<<" ";g<<'\n';
	
 
	
    cont2 = 0;
	
 
	
    for (i=1; i<=cont; ++i)
	
    {
	
        bool ok = 1;
	
        if (sol[i] == start || sol[i] == finish) ok = 1;
	
        else
	
            for (j=1; j<=cont; ++j)
	
            if (i != j && distX[sol[i]] == distX[sol[j]])
	
        {
	
            ok = 0;
	
            break;
	
        }
	
 
	
        if (ok) ans[++cont2] = sol[i];
	
    }
	
 
	
    g<<cont2<<'\n';
	
    for (i=1; i<=cont2; ++i) g<<ans[i]<<" ";
	
 
	
    return 0;
	
}