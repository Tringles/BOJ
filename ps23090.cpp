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

ll n, ans, f, s;
priority_queue<ll> fq;
priority_queue<ll, vector<ll>, greater<ll>> sq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, x, k; i < n; i++) {
		cin >> x >> k;
		ans += abs(x);
		if (fq.empty() || fq.top() >= k) {
			fq.push(k);
			f += k;
		}
		else {
			sq.push(k);
			s += k;
		}
		if (fq.size() > sq.size() + 1) {
			s += fq.top();
			f -= fq.top();
			sq.push(fq.top());
			fq.pop();
		}
		if (sq.size() > fq.size()) {
			f += sq.top();
			s -= sq.top();
			fq.push(sq.top());
			sq.pop();
		}
		cout << fq.top() << ' ' << fq.top() * fq.size() - fq.top() * sq.size() + ans - f + s << endl;
	}
	return 0;
}