#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
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

vector<vpl> graph;
vl dist;
ll inf = 1e18;
 
void solve(int u) {
    priority_queue<pair<ll, ll> > pq;
    pq.push({0, u});
    dist[u] = 0;

    while(!pq.empty()){
        ll v = pq.top().S;
        ll d = -pq.top().F;
        pq.pop();

        if(dist[v] != d) continue;
        for(auto x : graph[v]){
            if(dist[v] + x.S < dist[x.F]){
                dist[x.F] = dist[v] + x.S;
                pq.push({-dist[x.F], x.F});
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;

    graph.assign(n + 1, vpl());
    dist.assign(n + 1, inf);

    forn(i, 0, m){
        int u, v, x;
        cin >> u >> v >> x;
        graph[u].pb({v, x});
        graph[v].pb({u, x});
    }

    solve(0);

    forn(i, 0, n){
        cout << dist[i] << " ";
    }
    return 0;
}
