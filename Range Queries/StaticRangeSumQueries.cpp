#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)

const int MAX_N = 1e6 + 7;
vector<ll> pref(MAX_N);

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin >> n >> q;
	rep(i,n){
		cin >> pref[i+1];
		pref[i+1] += pref[i];
	}
	while(q--){
		int l, r; cin >> l >> r;
		cout << pref[r] - pref[l-1] << "\n";
	}
	return 0;
}
