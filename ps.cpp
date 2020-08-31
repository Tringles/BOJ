#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

ll n, k, p1, ans, cnt;
map<ll, ll> visit;
queue<pair<ll, ll>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p1;
		q.push({ p1,p1 });
		visit[p1] = 1;
	}
	while (1) {
		ll cur = q.front().first;
		ll origin = q.front().second;
		q.pop();
		ll next[] = { cur + 1,cur - 1 };
		for (int i = 0; i < 2; i++) {
			if (visit[next[i]])continue;
			visit[next[i]] = 1;
			ans += abs(next[i] - origin);
			cnt++;
			if (cnt == k)break;
			q.push({ next[i],origin });
		}
		if (cnt == k)break;
	}
	cout << ans << endl;
	return 0;
}