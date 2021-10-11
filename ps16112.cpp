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

int n, k;
ll ans;
vector<ll> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0, p1; i < n;i++) {
		cin >> p1;
		v.push_back(p1);
	}
	sort(v.begin(), v.end());
	for (int i = 1;i < n;i++)
		ans += v[i] * min(i, k);
	cout << ans << endl;
	return 0;
}