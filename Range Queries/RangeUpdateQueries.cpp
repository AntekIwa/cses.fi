#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)


const int base = 1 << 20;
vector<ll> tree(2*base);

ll query(int x){
	x += base;
	ll sum = 0;
	while(x > 0){
		sum += tree[x];
		x/=2;
	}
	return sum;
}

void upd(int l, int r, int val){
	l += base;
	r += base;
	while(l <= r && l != 0 && r != 0){
		if(l%2 == 1) tree[l] += val;
		if(r%2 == 0) tree[r] += val;
		l = (l+1)/2;
		r = (r-1)/2;
	}	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin >> n >> q;
	rep(i,n){
		ll a; cin >> a;
		upd(i+1, i+1, a);
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r, val; cin >> l >> r >> val;
			upd(l, r, val);		
		}
		else{
			int x; cin >> x;
			cout << query(x) << "\n";
		}
	}
	return 0;
}
