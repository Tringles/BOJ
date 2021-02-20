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

int ball[101], n, m, p1, p2, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)ball[i] = ++cnt;
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		swap(ball[p1], ball[p2]);
	}
	for (int i = 1; i <= n; i++)cout << ball[i] << ' ';
	return 0;
}
