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

int n, s;
vector<int> v;
vector<PI> t;
stack<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	v.push_back(-INF);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (v.back() < s) {
			v.push_back(s);
			t.push_back({ v.size() - 1,s });
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), s);
			*it = s;
			t.push_back({ it - v.begin(),s });
		}
	}
	cout << v.size() - 1 << endl;
	int ctr = v.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (t[i].first == ctr) {
			ans.push(t[i].second);
			ctr--;
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << endl;
	return 0;
}
