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

int n, cnt;
PI p[70];

bool comp(const PI& a, const PI& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p, p + n, comp);
	for (int i = 5; i < n; i++) {
		if (p[i].first != p[4].first)break;
		else cnt++;
	}
	cout << cnt << endl;
	return 0;
}