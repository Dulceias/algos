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
 
#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define tt int t; cin >> t
#define cout(x) cout << x << endl
#define forn(x, n) for (int i = x; i < int(n); i++)

vvi grafo;
vb visited;

void dfs(int x){
    visited[x] = true;
    for(auto v : grafo[x]){
        if(!visited[x]) dfs(x);
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : grafo[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }

}

void solve() {
    int n;
    cin >> n;

    grafo.assign(n, vi());
    visited.assign(n, false);
    bfs(0);
    dfs(0);
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    tt;
    while(t--) solve();
    return 0;
}