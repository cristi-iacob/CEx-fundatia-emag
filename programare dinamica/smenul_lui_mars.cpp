// https://www.pbinfo.ro/?pagina=probleme&id=1268
#include <fstream>
#define NMAX 100005

using namespace std;

ifstream f("easyquery.in");
ofstream g("easyquery.out");

long long sp[NMAX], v[NMAX], i, n, type, x, y, val, nrquiz;

int main()
{
    f >> n;

    for (i = 1; i <= n; ++ i)
        f >> v[i];

    f >> nrquiz;

    while (nrquiz)
    {
        nrquiz --;

        f >> type >> x >> y >> val;

        if (type == 1)
        {
            sp[x] +=  val;
            sp[y + 1] -= val;
        }

        if (type == 2)
        {
            sp[x] -= val;
            sp[y + 1] += val;
        }
    }

    for (i = 2; i <= n; ++ i)
        sp[i] += sp[i - 1];

    for (i = 1; i <= n; ++ i)
        g << (long long) sp[i] + v[i] << " ";
    return 0;
}