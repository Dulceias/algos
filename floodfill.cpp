#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
 
#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define cout(x) cout << x << endl
#define forn(i, x, n) for (int i = x; i < n; i++)
 
const int mod = 1e9 + 7;
const int inf = 1e18;
 
ll direccioni[4] = {-1, 1, 0, 0};
ll direccionj[4] = {0, 0, -1, 1};
vvl color;
ll n, m;

void floodfill(ll i, ll j, ll colorActual) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(color[i][j] == colorActual) return; //if(color[i][j] == obstáculo) return;
    color[i][j] = colorActual;
    forn(direccion, colorActual, 4){
        floodfill(i + direccioni[direccion], j + direccionj[direccion], colorActual);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t = 1; //cin >> t;
    while(t--) floodfill(1, 1, 1);
    return 0;
}
