// https://www.pbinfo.ro/probleme/402/bete

#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 105

using namespace std;

ifstream f("bete.in");
ofstream g("bete.out");

int i, j, n, s, sol[NMAX], cont = 0;
bool ok[2 * NMAX * NMAX];

struct bete
{
    int val, poz;
};
bete v[NMAX];

bool cmp(bete a, bete b)
{
    if (a.val == b.val)
        return a.poz > b.poz;
    return a.val < b.val;
}

int main()
{
    f >> n >> s;

    for (i = 1; i <= n; ++ i)
        f >> v[i].val, v[i].poz = i;

    sort(v + 1, v + n + 1, cmp);

    ok[0] = 1;
    for (i = 1; i <= n; ++ i)
        for (j = s; j >= 0; -- j)
        if (ok[j])
            ok[j + v[i].val] = 1;

    if (ok[s])
    {
        g << "DA" << '\n';

        i = n;

        while (s)
        {
            if (ok[s - v[i].val])
            {
                sol[++ cont] = v[i].poz;
                s -= v[i].val;
            }
            i --;
        }

        g << cont << '\n';

        for (i = 1; i <= cont; ++ i)
            g << sol[i] << " ";
        return 0;
    }

    g << "NU" << '\n';

    return 0;
}
