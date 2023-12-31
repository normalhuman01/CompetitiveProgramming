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

/*
	Author: Racso Galvan

	Idea:
	
	- Greedy & simulation problem.

	- A simpler solution is to verify that |A - B| = 1, where A and B are the frequency

	  of As and Bs respectively.

	- This solution simulates the fusion of the letters according to the process

	  using a stack and always merging as long as it's possible.

	- Complexity: O(n) per testcase

*/

const int N = 99999 + 5;

int n;
char s[N];

bool valid(char a, char b, char c){
	if(a < b) swap(a, b);
	if(a < c) swap(a, c);
	if(b < c) swap(b, c);
	return a != c;
}

int main(){
	int t;
	ri(t);
	for(int caso = 1; caso <= t; caso++){
		ri(n);
		scanf("%s", s);
		bool can = true;
		vector<int> st;
		int len = 0;
		for(int i = 0; i < n; i++){
			st.emplace_back(s[i]);
			len += 1;
			while(len >= 3 and valid(st[len - 3], st[len - 2], st[len - 1])){
				char a = st[len - 3];
				char b = st[len - 2];
				char c = st[len - 1];
				st.pop_back();
				st.pop_back();
				st.pop_back();
				len -= 3;
				if(a < b) swap(a, b);
				if(a < c) swap(a, c);
				if(b < c) swap(b, c);
				st.emplace_back(b);
				len += 1;
			}
		}
		printf("Case #%d: %c\n", caso, (st.size() == 1? 'Y': 'N'));
	}
	return 0;
}
