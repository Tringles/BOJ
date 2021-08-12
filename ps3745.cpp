#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		vector<int> v;
		int ans = 0;
		v.push_back(-INF);
		for (int i = 0;i < n;i++) {
			cin >> s;
			if (v.back() < s) {
				v.push_back(s);
				ans++;
			}
			else {
				auto it = lower_bound(v.begin(), v.end(), s);
				*it = s;
			}
		}
		cout << ans << endl;
	}
	return 0;
}