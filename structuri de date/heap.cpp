// https://www.infoarena.ro/problema/heapuri

#include <fstream>
	
#define NMAX 200005
	
 
	
using namespace std;
	
 
	
ifstream f("heapuri.in");
	
ofstream g("heapuri.out");
	
 
	
int heap[NMAX], pos[NMAX], v[NMAX], n = 0, nrquiz, type, value, l = 0;
	
// in heap retin pozitia unui element din vectorul de valori (v, pe care il citesc),
	
// in pos retin ordinea cronologica in care au intrat elementele in heap
	
// in v retin valorile elementelor citite
	
 
	
int left_son(int k) // determin coordonatele fiului din stanga al unui element din heap
	
{
	
    return 2*k;
	
}
	
 
	
int right_son(int k) // determin coordonatele fiului din dreapta al unui element din heap
	
{
	
    return 2*k + 1;
	
}
	
 
	
int father(int k) // determin coordonatele tatalui unui element din heap
	
{
	
    return k/2;
	
}
	
 
	
void change(int a, int b) // interschimb 2 elemente din heap (trebuie mopdificata si pozitia din vectorul cronologic)
	
{
	
    int aux;
	
    aux = heap[a];
	
    heap[a] = heap[b];
	
    heap[b] = aux;
	
    pos[heap[a]] = a;
	
    pos[heap[b]] = b;
	
}
	
 
	
void go_down(int k) // cobor un element prin heap pana cand o sa fie mai mic decat amandoi fiii sai
	
{
	
    int aux;
	
 
	
    do
	
    {
	
        aux = 0;
	
 
	
        if (left_son(k) <= n)
	
        {
	
            aux = left_son(k);
	
 
	
            if (right_son(k) <= n && v[heap[aux]] > v[heap[right_son(k)]])
	
                aux = right_son(k);
	
 
	
            if (v[heap[k]] < v[heap[left_son(k)]] && v[heap[k]] < v[heap[right_son(k)]])
	
                aux = 0;
	
 
	
            if (aux)
	
            {
	
                change(k, aux);
	
                k = aux;
	
            }
	
        }
	
    } while (aux);
	
}
	
 
	
void go_up(int k) // urc un element prin heap pana cand este mai mare decat tatal sau
	
{
	
    while (k > 1 && v[heap[k]] < v[heap[father(k)]])
	
    {
	
        change(k, father(k));
	
        k = father(k);
	
    }
	
}
	
 
	
void insert_heap(int x) // adaug un element in heap; il adaug pe ultima pozitie din heap, apoi il urc
	
{
	
    n ++;
	
    heap[n] = x;
	
    pos[x] = n;
	
    go_up(n);
	
}
	
 
	
void delete_heap(int k) // sterg un element din heap (al k-lea intrat in ordine cronologica)
	
{
	
    change(k, n);
	
    n --;
	
    go_down(k);
	
}
	
 
	
int main()
	
{
	
    f >> nrquiz;
	
 
	
    while(nrquiz)
	
    {
	
        nrquiz -- ;
	
 
	
        f >> type;
	
 
	
        if (type == 1) // adaug un elemnt in heap
	
        {
	
            f >> value;
	
            v[++l] = value;
	
            insert_heap(l);
	
        }
	
 
	
        if (type == 2) // sterg un element din heap
	
        {
	
            f >> value;
	
            delete_heap(pos[value]);
	
        }
	
 
	
        if (type == 3) // afisez minimul din heap
	
            g << v[heap[1]] << '\n';
	
    }
	
    return 0;
	
}