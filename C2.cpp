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

const int K = 100+5;

int n,k,p;
ll C[K][K][K];
ll F[K][K]; // F[i][m] has the value of F_{i} mod (pm)

void init(){
	for(int m=1; m<=k+1; m++){
		ll R = 1LL*p*m;
		for(int i=1; i<K; i++){
			C[i][0][m] = 1;
			C[i][i][m] = 1;
			for(int j=1; j<i; j++){
				C[i][j][m] = add(C[i-1][j-1][m],C[i-1][j][m],R);
			}
		}
	}
}

int main(){
	int t;
	ri(t);
	while(t--){
		ri3(n,k,p);
		if(p == 1){
			puts("0");
			continue;
		}
		else{
			init();
			for(int i=1; i<=k+1; i++){
				ll R = 1LL*p*i;
				F[0][i] = n%R;
				ll m = 1LL*n*(n+1)/2LL;
				F[1][i] = add(m,0,R);
			}
			for(int i=2; i<=k; i++){
				for(int m=k+1; m>=2; m--){
					ll R = 1LL*p*m;
					F[i][m] = pow_mod(n+1,i+1,R);
					F[i][m] = add(F[i][m],R-1-n,R);
					for(int j=1; j<=i-1; j++){
						
						ll take_off = modInverso(i+1,p)==-1?mul(C[i+1][j][m],F[j][m]/(i+1),R):mul(C[i+1][j][m],mul(F[j][m],modInverso(i+1,p)),R);
						F[i][m] = add(F[i][m],R-take_off,R);
					}
				}
			}
			for(int i=2; i<=k; i++){
				F[i][1] = add(F[i][i+1] / (i+1),0,p);
			}
			printf("%lld\n",F[k][1]);
		}
	}
	return 0;
}
