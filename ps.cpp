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

ll n, k, ans;
stack<PL> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		PL p = { k,1 };
		while (!s.empty()) {
			auto a = s.top();
			if (a.first <= k) {
				ans += a.second;
				if (a.first == k)
					p.second += a.second;
				s.pop();
			}
			else break;
		}
		if (!s.empty())ans++;
		s.push(p);
	}
	cout << ans << endl;
	return 0;
}