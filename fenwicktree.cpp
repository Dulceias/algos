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

#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define tt int t; cin >> t
#define cout(x) cout << x << endl
#define forn(i, x, n) for (int i = x; i < int(n); i++)

ll n;
vl ft, a;

void upd(ll i, ll x){
    while(i < n){
        ft[i] += x;
        i += (i & (-i));
    }
}

ll sum(ll i){
    ll s = 0;
    while(i > 0){
        s += ft[i];
        i -= (i & (-i));
    }
    return s;
}

void solve(){
    ll q;
    cin >> n >> q;

    ft.assign(n + 1, 0);
    a.assign(n + 1, 0);

    forn(i, 0, n) cin >> a[i];

    forn(i, 0, n) upd(i + 1, a[i]);

    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << sum(r) - sum(l - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}