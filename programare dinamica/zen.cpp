// https://www.pbinfo.ro/probleme/1930/zen

#include <fstream>
#include <deque>
#define NMAX 1000005
#define intt long long

using namespace std;

ifstream f("zen.in");
ofstream g("zen.out");

intt i, n, x, k, curr;
deque < pair < intt, intt > > d;

int main()
{
    f >> n >> k;

    for (i = 1; i <= n; ++ i)
    {
        f >> x;

        if (i <= k)
        {
            while (!d.empty() && d.back().first > x)
                d.pop_back();
            d.push_back({x, i});

            if (i == n)
            {
                g << x;
                return 0;
            }

            continue;
        }

        if (d.size() > 0 && d.front().second == i - k - 1)
            d.pop_front();

        curr = d.front().first + x;

        while (!d.empty() && d.back().first > curr)
            d.pop_back();
        d.push_back({curr, i});
    }

  //  g << sizeof(dp) << " " ;

    g << curr << '\n';
    return 0;
}
