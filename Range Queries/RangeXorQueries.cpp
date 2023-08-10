#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int base = 1 << 20;
vector<int> tree(2*base);

void upd(int x, int val){
	x += base;
	tree[x] = val;
	x /= 2;
	while(x > 0){
		tree[x] =tree[x*2] ^ tree[x*2 + 1];
		x/=2;
	}
}

ll query(int l, int r){
	l += base;
	r += base;
	int res = 0;
	while(l <= r && l != 0 && r != 0){
		if(l%2 == 1) res ^= tree[l];
		if(r%2 == 0) res ^= tree[r];
		l = (l+1)/2;
		r = (r-1)/2;
	}	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin >> n >> q;
	rep(i,n){
		ll a; cin >> a;
		upd(i+1, a);
	}
	while(q--){
		int l, r; cin >> l >> r;
		cout << query(l,r) << "\n";	
	}
	return 0;
}
