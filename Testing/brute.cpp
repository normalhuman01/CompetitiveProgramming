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

ll add(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a+b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

ll mul(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a*b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

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

const int N = 15;

int n;
int a[N];

int solve(vi &vis, int turn, int cnt){
	if(cnt == 0){
		return 0;
	}
	int ans = turn == 1? 0 : 2e9;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		int nxt = add(i, 1, n);
		int prv = add(i, n - 1, n);
		if(vis[nxt] == turn or vis[prv] == turn){
			vis[i] = turn;
			if(turn == 1){
				ans = max(ans, a[i] + solve(vis, 3^turn, cnt - 1));
			}
			else{
				ans = min(ans, solve(vis, 3^turn, cnt - 1));
			}
			vis[i] = 0;
		}
	}
	return ans;
}

int main(){
	ri(n);
	for(int i = 0; i < n; i++){
		ri(a[i]);
	}
	int ans = 0;
	vector<int> vis(n, 0);
	for(int i = 0; i < n; i++){
		vis[i] = 1;
		int res = a[i];
		int best_machine = 2e9;
		for(int j = 0; j < n; j++){
			if(vis[j]) continue;
			vis[j] = 2;
			best_machine = min(best_machine, solve(vis, 1, n - 2));
			vis[j] = 0;
		}
		res += best_machine;
		ans = max(ans, res);
		vis[i] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
