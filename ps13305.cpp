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

ll n, dist[100005], c[100005], ans, s, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n - 1;i++)cin >> dist[i];
	for (int i = 0;i < n;i++)cin >> c[i];
	s = c[0], sum = dist[0];
	for (int i = 1;i < n - 1;i++) {
		if (c[i] < s) {
			ans += s * sum;
			s = c[i];
			sum = 0;
		}
		sum += dist[i];
	}
	ans += s * sum;
	cout << ans << endl;
	return 0;
}