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

const int N = 30+5;

int n,w,k;
int a[N];
int t[N];

int main(){
	ri3(n,w,k);
	for(int i=0; i<n; i++){
		ri(a[i]);
	}
	for(int i=0; i<n; i++){
		ri(t[i]);
	}
	int solver = 0;
	int ans = 0;
	for(int mask=1; mask<1<<n; mask++){
		vii values;
		for(int i=0; i<n; i++){
			if((mask>>i)&1){
				values.pb(mp(t[i],a[i]));
			}
		}
		sort(all(values));
		int left = k;
		int pos = values.size()-1;
		int act = 0;
		for(int i=0; i<w; i++){
			act += values[pos].second;
			left -= (values[pos].first+1)/2;
			pos--;
		}
		while(pos >= 0){
			act += values[pos].second;
			left -= values[pos].first;
			pos--;
		}
		if(left >= 0){
			cout << left << endl;
			for(int i=0; i<n; i++){
				if((mask>>i)&1){
					cout << a[i] << " " << t[i] << endl;
				}
			}
			puts("");
			if(ans < act){
				ans = act;
				solver = mask;
			}
		}
	}
	for(int i=0; i<n; i++){
		if((solver>>i)&1){
			cout << a[i] << " " << t[i] << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
