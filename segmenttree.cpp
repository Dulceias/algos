#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;

#define mod 1000000007
#define inf 10000000000000
#define F first
#define S second
#define nd '\n'
#define forn(i, x, n) for (ll i = x; i < ll(n); i++)
#define fornl(i, x, n) for(ll i = x; i >= ll(n); i--)
#define cina(x) for(auto &c : x) cin >> c;
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define debug(x) cout << #x << " = " << x << nd;
#define debugv(x, s) cout << #x << " = "; forn(i, 0, s) cout << x[i] << " "; cout << nd;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define yes cout << "YES" << nd
#define no cout << "NO" << nd
#define pb push_back
#define all(x) x.begin(), x.end()

ll st[900000], a[200005];

void build(ll nivel, ll l, ll r){
    if(l == r){
        st[nivel] = a[l];
        return;
    }

    ll m = (l + r) / 2, news = nivel * 2;
    build(news, l, m);
    build(news + 1, m + 1, r);
    st[nivel] = st[news] + st[news + 1];
}

void upd(ll nivel, ll x, ll v, ll l, ll r){
    if(l == r){
        st[nivel] = v;
        return;
    }

    ll m = (l + r) / 2, news = nivel * 2;
    if(x <= m) upd(news, x, v, l, m);
    else upd(news + 1, x, v, m + 1, r);

    st[nivel] = st[news] + st[news + 1];
}

ll query(ll nivel, ll x, ll y, ll l, ll r){
    if(x <= l && y >= r) return st[nivel];
    if(x > r || y < l) return 0;

    ll m = (l + r) / 2, news = nivel * 2;
    ll izq = query(news, x, y, l, m);
    ll der = query(news + 1, x, y, m + 1, r);

    return izq + der;
}

void solve() {
    ll n, q; cin >> n >> q;
    forn(i, 1, n + 1) cin >> a[i];
 
    build(1, 1, n);
 
    while(q--){
        ll c, a, b; cin >> c >> a >> b;
        if(c == 2) cout << query(1, a, b, 1, n) << nd;
        else upd(1, a, b, 1, n);
    }
}

int main() {
    fastio;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
