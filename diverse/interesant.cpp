https://infoarena.ro/problema/interesant

#include <bits/stdc++.h>
	
#define NMAX 205
	
 
	
using namespace std;
	
 
	
ifstream f("interesant.in");
	
ofstream g("interesant.out");
	
 
	
string s[NMAX];
	
vector < string > ans;
	
int n, type;
	
 
	
bool cmp(string a, string b)
	
{
	
    if (a.length() == b.length()) {
	
        return a.compare(b) < 0;
	
    }
	
    return a.length() > b.length();
	
}
	
 
	
bool is_substring(string a, string b)
	
{
	
    if (a.length() > b.length()) {
	
        return false;
	
    }
	
 
	
    int idx = 0;
	
 
	
    for (int i = 0; i < a.length(); ++ i) {
	
        while (idx < b.length() && b[idx] != a[i]) {
	
            idx ++;
	
        }
	
        idx ++;
	
 
	
        if (idx > b.length()) {
	
            return false;
	
        }
	
    }
	
 
	
    return true;
	
}
	
 
	
int main()
	
{
	
    f >> type >> n;
	
 
	
    for (int i = 0; i < n ; ++ i) {
	
        f >> s[i];
	
    }
	
 
	
    if (type == 1) {
	
        sort(s, s + n, cmp);
	
        g << s[0] << '\n';
	
    } else {
	
        for (int i = 0; i < n; ++ i) {
	
            bool interesant = true;
	
            for (int j = 0; j < n; ++ j) {
	
                if (i != j && is_substring(s[i], s[j])) {
	
                    interesant = false;
	
                    break;
	
                }
	
            }
	
 
	
            if (interesant) {
	
                ans.push_back(s[i]);
	
            }
	
        }
	
 
	
        g << ans.size() << '\n';
	
        for (auto it : ans) {
	
            g << it << '\n';
	
        }
	
    }
	
    return 0;
	
}