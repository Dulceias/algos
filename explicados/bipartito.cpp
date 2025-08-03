#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
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
#define forn(i, x, n) for (ll i = x; i < n; i++)
#define mod 1e9 + 7
#define inf 1e18

vvl graph;
vl color;
bool pos = 1;

void dfs(int u, int c){
    color[u] = c;
    for(auto v : graph[u]){
        if(color[v] == -1) dfs(v, 1 - c);
        //1 - c pork 1 - 0 = 1 y 1 - 1 = 0;
        if(color[v] == c) pos = 0; //o return false;
    }
}

bool bfs(int start, int c){
    queue<int> q;
    q.push(start);
    color[start] = c;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(auto v : graph[top]){
            if(color[v] == -1){
                q.push(v);
                color[v] = 1 - color[top];
            }
            if(color[v] == color[top]) return false; //ya se fregó....
            //tienen el mismo color (no es bipartito)
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
