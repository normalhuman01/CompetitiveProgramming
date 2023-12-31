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

int add(int a, int b, int m = MOD){
	return a + b < m? a + b : a + b - m;
}

int mul(ll a, ll b, int m = MOD){
	return (a * b) % m;
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

/*
	Author: Racso Galvan

	Idea:

	- Notice that at each move we move to a rectangle with smaller dimensions,

	  so we can count the number of ways we can reduce the dimensions, which 

	  decrease independently.

	- 


*/

const int N = 1000+5;

int n, m, k;
int memo[N][N];
int prodmemo[N][N];
int sumamemo[N][N];

int main(){
	ri3(n, m, k);
	for(int i=1; i<N; i++){
		memo[i][0] = 1;
		prodmemo[i][0] = add(prodmemo[i-1][0], mul(i + 1, memo[i][0]));
		sumamemo[i][0] = add(sumamemo[i-1][0], memo[i][0]);
		for(int j=1; j<=k; j++){
			memo[i][j] = add(mul(i, sumamemo[max(i-2,0)][j-1]), MOD - prodmemo[max(0,i-2)][j-1]);
			prodmemo[i][j] = add(prodmemo[i-1][j], mul(i + 1, memo[i][j]));
			sumamemo[i][j] = add(sumamemo[i-1][j], memo[i][j]);
		}
	}
	printf("%d\n",mul(memo[n][k],memo[m][k]));
	return 0;
}
