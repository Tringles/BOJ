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

ll n, ans;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, p1;i < n;i++) {
		cin >> p1;
		q.push(p1);
	}
	while (q.size() > 1) {
		int f = q.top();q.pop();
		int s = q.top();q.pop();
		ans += f + s;
		q.push(f + s);
	}
	cout << ans << endl;
	return 0;
}