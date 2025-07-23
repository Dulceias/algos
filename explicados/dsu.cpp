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
 
#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define tt int t; cin >> t
#define cout(x) cout << x << endl
#define forn(i, x, n) for (int i = x; i < int(n); i++)

struct dsu{
    vl tamaño; // tamaño[i] = tamaño del set A, i pertenece a A
    vl padres; // padres[i] = padre del set A
    dsu(ll n) { // funcion constructora en c++
        tamaño.assign(n + 1, 1); // el tamaño de un set separado es 1, al principio todos los tamaños son 1 pork estan solos
        padres.resize(n + 1);
        forn(i, 0, n){
            padres[i] = i; // el padre de cada nodo es él mismo
        }
    }
    ll find(ll x){
        if(padres[x] == x) return x; // si yo mismo soy mi padre, soy el padre global (el padre del set)
        else return padres[x] = find(padres[x]); // si no soy mi propio padre, busca al padre de mi padre
        // **arriba** el padre de mi padre ahora es el padre k estoy buscando... es para optimizar y k no repita todas las
        // operaciones cada vez que se añada un nodo
    }
    bool onion(ll x, ll y){ //union es palabra reservada
        ll a = find(x); //a va a ser el padre de x
        ll b = find(y); // b padre de y
        if(a == b) return true; // si tienen el mismo padre, return algo (aca es true de que ya estan conectados)
        //para juntarlos tenemos que agarrar el padre del mayor...
        //padres[b] = a; // el padre de b va a ser hijo de a
        // grafo con padre 1, hijos 2 3 yyyy padre 4, hijos 5 6
        // padres[4] = 4, pero ahora padres[4] = 1, el padre de 5 es 4 y el padre de 4 es 1
        //small to large
        if(tamaño[b] > tamaño[a]) swap(a, b); // a = 4, b = 1, 
        padres[b] = a;
        tamaño[a] += tamaño[b]; // añade el set mas pequeño al mas grande
        return false;
    }
};
 
void solve() {
    
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    tt;
    while(t--) solve();
    return 0;
}