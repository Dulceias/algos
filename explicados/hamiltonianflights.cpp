#include <bits/stdc++.h>
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
#define forn(i, x, n) for (int i = x; i < n; i++)
const int mod = 1e9 + 7;
 
vvl flights;
ll dp[1 << 20][20]; //lo dejamos global y solo usamos las posiciones neceariaes?¿?¿?

void solve(){
    ll n, m;
    cin >> n >> m;

    flights.assign(n + 1, vl());

    forn(i, 0, m){
        ll a = 0, b = 0;
        cin >> a >> b;
        a--; b--; //indexado en 0;
    
        flights[b].pb(a); //de fin a inicio en lugar de inicio a fin...
    }

    dp[1][0] = 1; //para llegar del nod 1 al 1 hay 1 camino. esta indexado en 0, no en 1.

    forn(k, 2, (1 << n)){ //vamos desde el nodo 2 creo???
        if((k & (1 << 0)) == 0) continue;
        //si el bit 0 no esta encendido en mi bitmask, no me interesa, entonces continue.
        if((k & (1 << (n - 1))) && (k != (1 << n) - 1)) continue; 
        //si estoy viendo la ciudad del final antes de mi final (antes de recorrer todos los nodos), entonces lo ignoro
        forn(a, 1, n){ //indexado en 1 porque el nodo 0 no nos interesa?? porque empezamos en 1..
            if((k & (1 << a)) == 0) continue;
            //si el bit qu eestamos evaluando no está encendido (la ciudad), continue pork no lo contemplo en el vuelo actual
            int prev = k - (1 << a); //restar el shift para apgar el bit
            for(auto v : flights[a]){ //kiero ver kienes van hacia a
                if(k & (1 << v)){//si mi bitmask tiene encendido el padre v
                    dp[k][a] += dp[prev][v];
                    dp[k][a] %= mod;
                    //dp cuando tomo en cuenta todo mi bitmask terminando en k
                //a mi estado actual terminando en mi nodo a le sumo la solucion de us padre v que ya tengo en mi dp, o sea, si el anterior es 1, a la actual le sumo 1
                }
            }
        }

    }
    cout << dp[(1 << n) - 1][n - 1];
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
