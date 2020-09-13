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

int n;
int res[1000005], cnt[1000005], w[1000005];
stack<PI> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		cnt[w[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (!i)s.push({ i,cnt[w[i]] });
		else {
			int cur = s.top().second;
			if (cur < cnt[w[i]]) {
				while (!s.empty()) {
					auto j = s.top();
					if (j.second < cnt[w[i]]) {
						res[j.first] = w[i];
						s.pop();
					}
					else break;
				}
				s.push({ i,cnt[w[i]] });
			}
			else s.push({ i,cnt[w[i]] });
		}
	}
	while (!s.empty()) {
		int cur = s.top().first;
		res[cur] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}