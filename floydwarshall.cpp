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
const ll inf = 1e18;
 
void solve() {
    ll n, m, w;
    cin >> n >> m;

    ll a[n + 5][n + 5];

    forn(i, 1, n + 1){
        forn(j, 1, n + 1){
            if(i == j) a[i][j] = 0;
            else a[i][j] = inf;
        }
    }

    forn(i, 0, m){
        int s, f, w;
        cin >> s >> f >> w;
        a[s][f] = w;
    }

    forn(k, 1, n + 1){
        forn(i, 1, n + 1){
            forn(j, 1, n + 1){
                a[i][j] = min(a[i][j], a[k][j] + a[i][k]);
                //cout << a[i][j] << " a[i][j]" << "    ";
            }
            //cout << endl;
        }
    }

    cout << endl;

    forn(i, 1, n + 1){
        forn(j, 1, n + 1){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}

/*
4 7
1 4 7
4 1 2
3 1 5
2 1 8
2 3 2
3 4 1
1 2 3
*/
