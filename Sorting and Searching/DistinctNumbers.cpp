#include <bits/stdc++.h>
 
using namespace std;

set<int> num;
 
int main(){
//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	while(n--){
		int a; cin >> a;
		num.insert(a);
	}
	cout << num.size();
	return 0;
}
