#include<bits/stdc++.h>
#include<unordered_map>
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

int t, n, p;
vector<int> v, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		ans.clear();
		for (int i = 1; i <= n; i++) {
			cin >> p;
			v.push_back(p);
			if (i % 2) {
				sort(v.begin(), v.end());
				ans.push_back(v[i / 2]);
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			if (!(i % 10) && (i / 10))cout << endl;
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
