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

vvi tree, ancestro;
vi depth, padre;
int n, q;

void dfs(int act, int parent){
    padre[act] = parent;
    depth[act] = depth[parent] + 1;

    for(auto v : tree[act]){
        if(v != parent){
            dfs(v, act);
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    for(int i = 17; i >= 0; i--){
        if(depth[a] - (1 << i) >= depth[b]){
            a = ancestro[a][i];
        }
    }

    if(a == b) return a;
    for(int i = 17; i >= 0; i--){
        if(ancestro[a][i] != ancestro[b][i]){
            a = ancestro[a][i];
            b = ancestro[b][i];
        }
    }

    return padre[a];

}

void solve() {
    cin >> n;

    tree.assign(n + 1, vi());
    padre.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    ancestro.assign(n + 1, vi(18, 0));

    forn(i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(1, 0);

    forn(i, 1, n + 1) ancestro[i][0] = padre[i];

    forn(i, 1, 18){
        forn(j, 1, n + 1){
            ancestro[j][i] = ancestro[ancestro[j][i - 1]][i - 1];
        }
    }

    cin >> q;
    
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
}
