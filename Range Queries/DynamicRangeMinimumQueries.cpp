#include <bits/stdc++.h>

using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)

const int base = 1 << 20;
const int inf = 1e9 + 7;
vector<int> tree(2*base, inf);

void upd(int x, int val){
	x += base;
	tree[x] = val;
	x /= 2;
	while(x > 0){
		tree[x] = min(tree[x*2], tree[x*2 + 1]);
		x/=2;
	}
}

int query(int l, int r){
	l += base;
	r += base;
	int mini = inf;
	while(l <= r && l != 0 && r != 0){
		if(l%2 == 1) mini = min(tree[l],mini);
		if(r%2 == 0) mini = min(tree[r],mini);
		l = (l+1)/2;
		r = (r-1)/2;
	}	
	return mini;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin >> n >> q;
	rep(i,n){
		int a; cin >> a;
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
