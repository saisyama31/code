#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n,q,m;
		cin >> n >> q >> m;
		int can_win[m + 1];
		int a[n];
		memset(can_win,0,sizeof(can_win));
		for(int i = 0;i < n;i++) cin >> a[i],a[i] = min(a[i],m + 1);
		map<pair<int,int>,int> games;
		for(int i = 0;i < q;i++){
			int l,r;
			cin >> l >> r;
			games[{a[l - 1],a[r - 1]}]++;
		}
		for(auto it = games.begin();it != games.end();it++){
			int lo = (it->first).first,hi = (it->first).second;
			int count = it->second;
			int clo = lo,chi = hi + lo - 1;
			while(clo <= m){
				can_win[clo] += count;
				if(chi + 1 <= m)
					can_win[chi + 1] -= count;
				clo += lo + hi;
				chi += lo + hi;
			}
		}
		for(int i = 1;i <= m;i++) can_win[i] += can_win[i - 1];
		int ans = 0;
		for(int i = 0;i <= m;i++) ans = max(ans,can_win[i]);
		cout << ans << "\n";
	}
	return 0;
}
