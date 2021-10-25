// https://www.pbinfo.ro/probleme/588/dijkstra

#include <fstream>
#include <vector>
#include <queue>
#define NMAX 50005
#define inf (1 << 30)

using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

int i, n, m, a, b, c, d[NMAX], start;
vector < pair < int, int > > v[NMAX];
bool visited[NMAX];

struct compare
{
    bool operator () (pair < int, int > &a, pair < int, int > &b)
    {
        return a.second > b.second;
    }
};

priority_queue < pair < int, int >, vector < pair < int, int > >, compare > pq;

void read()
{
    f >> n >> start;

    while (f >> a >> b >> c)
    {
        v[a].push_back(make_pair(b, c));
    }
}

void initialize()
{
    for (i = 1; i <= n; ++ i)
    {
        d[i] = inf;
        visited[i] = 0;
    }
}

void dijkstra()
{
    pq.push(make_pair(start, 0));
    d[start] = 0;

    while (!pq.empty())
    {
        int current = pq.top().first;
        pq.pop();

        if (!visited[current])
        {
            visited[current] = 1;

            for (auto &it : v[current])
                if (d[it.first] > d[current] + it.second)
            {
                d[it.first] = d[current] + it.second;
                pq.push(make_pair(it.first, d[it.first]));
            }
        }
    }
}

int main()
{
    read();
    initialize();
    dijkstra();

    for (i = 1; i <= n; ++ i)
        if (d[i] == inf)
        g << "-1 ";
    else
        g << d[i] << " ";

    return 0;
}
