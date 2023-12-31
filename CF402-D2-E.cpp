#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define gc(x) ((x) = getchar())
using namespace::std;

const long double PI = acos(-1);
const long long MOD = 1000000000 +7;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}

ll add(ll a, ll b, ll m = MOD){ return (a%m + b%m+2*m)%m;}

ll mul(ll a, ll b, ll m = MOD){ return ((a%m+m)*(b%m+m))%m;}

ll pow_mod(ll a, ll b, ll m = MOD){
	ll res = 1LL;
	a = a%m;
	while(b){
		if(b&1) res = mul(res,a,m);
		b >>= 1;
		a = mul(a,a,m);
	}
	return res;
}

ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}

int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}

/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/

const int N = 2000+5;

int n;
vi G[3][N];
bool vis[N];
stack<int> S;

void DFS(int u, int id){
	vis[u] = true;
	for(int i=0; i<G[id][u].size(); i++){
		int v = G[id][u][i];
		if(!vis[v]){
			DFS(v,id);
		}
	}
	if(id == 0){
		S.push(u);
	}
}

int SCC(){
	int C = 0;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			DFS(i,0);
			C++;
		}
	}
	if(C > 1) return 2;
	for(int i=0; i<n; i++) vis[i] = false;
	int colors = 0;
	while(!S.empty()){
		if(!vis[S.top()]){
			DFS(S.top(),1);
			colors++;
		}
		S.pop();
	}
	return colors;
}

int main(){
	ri(n);
	int x;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ri(x);
			if(x > 0){
				G[0][i].pb(j);
				G[1][j].pb(i);
			}
		}
	}
	if(SCC() > 1) puts("NO");
	else puts("YES");
	return 0;
}
