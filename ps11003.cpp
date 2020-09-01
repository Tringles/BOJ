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

int n, l, p;
deque<pair<int, int>>q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		while (!q.empty() && q.front().second <= i - l)q.pop_front();
		cin >> p;
		while (!q.empty() && q.back().first >= p)q.pop_back();
		q.push_back({ p,i });
		cout << q.front().first << ' ';
	}
	cout << endl;
	return 0;
}
