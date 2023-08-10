#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

const int MAX_N = 1007;
int pref[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin >> n >> q;
	rep(i,n){
		rep(j,n){
			char sign; cin >> sign;
			pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j];
			if(sign == '*') pref[i+1][j+1]++;
		}
	}
	while(q--){
		int x1,y1,x2,y2; cin >> y1 >> x1 >> y2 >> x2;
		cout << pref[y2][x2] - pref[y1-1][x2] - pref[y2][x1-1] + pref[y1-1][x1-1] << "\n";
	}
	return 0;
}
