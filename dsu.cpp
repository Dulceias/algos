#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
#define tt int t; cin >> t
#define cout(x) cout << x << endl
#define forn(i, x, n) for (int i = x; i < int(n); i++)

vl tamaño;
vl parents;

struct dsu{
    dsu(ll n){
        tamaño.assign(n + 1, 1);
        parents.resize(n + 1);
        forn(i, 0, n){
            parents[i] = i;
        }
    }

    ll find(ll x){
        if(parents[x] == x) return x;
        else return parents[x] = find(parents[x]);
    }

    ll onion(ll x, ll y){
        ll a = find(x);
        ll b = find(y);

        if(a == b) return true;

        if(tamaño[b] > tamaño[a]) swap(a, b);

        parents[b] = a;
        tamaño[a] += tamaño[b];

        return false;
    }
};
 
void solve() {
    ll n, m;
    cin >> n >> m;

    dsu estruct(n);

    forn(i, 0, m){
        ll u, v;
        cin >> u >> v;
        //hacer algo ns
    }
    
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
