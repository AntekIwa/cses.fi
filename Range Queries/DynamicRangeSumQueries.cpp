#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)

const int base = 1 << 20;
vector<ll> tree(2*base);

void upd(int x, int val){
	x += base;
	val -= tree[x];
	while(x > 0){
		tree[x] += val;
		x/=2;
	}
}

ll query(int l, int r){
	l += base;
	r += base;
	ll sum = 0;
	while(l <= r && l != 0 && r != 0){
		if(l%2 == 1) sum += tree[l];
		if(r%2 == 0) sum += tree[r];
		l = (l+1)/2;
		r = (r-1)/2;
	}	
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin >> n >> q;
	rep(i,n){
		ll a; cin >> a;
		upd(i+1, a);
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int x, val; cin >> x >> val;
			upd(x, val);
		}
		else{
			int l, r; cin >> l >> r;
			cout << query(l,r) << "\n";	
		}
	}
	return 0;
}
