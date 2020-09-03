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

int n, s[2002], ans;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	reverse(s, s + n);
	v.push_back(-INF);
	for (int i = 0; i < n; i++) {
		if (v.back() < s[i]) {
			v.push_back(s[i]);
			ans++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), s[i]);
			*it = s[i];
		}
	}
	cout << n - ans << endl;
	return 0;
}
