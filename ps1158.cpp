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

int k, n;
queue<int> q, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n;
	for (int i = 1; i <= k; i++)q.push(i);
	int cnt = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cnt == n) {
			ans.push(cur);
			cnt = 1;
		}
		else {
			cnt++;
			q.push(cur);
		}
	}
	cout << '<';
	while (!ans.empty()) {
		int cur = ans.front();
		ans.pop();
		cout << cur;
		if (!ans.empty())cout << ", ";
	}
	cout << '>' << endl;
	return 0;
}
