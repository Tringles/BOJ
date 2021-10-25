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

struct point { int x, y, idx; };

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int n;
		vector<point> v;
		cin >> n;
		for (int i = 0, p1, p2;i < n;i++) {
			cin >> p1 >> p2;
			v.push_back({ p1,p2,i });
		}
		sort(v.begin(), v.end(), [](point& a, point& b) {
			if (a.x != b.x)return a.x < b.x;
			return a.y < b.y;
			});
		for (int i = 1;i < n;i++) {
			v[i].x -= v[0].x;
			v[i].y -= v[0].y;
		}
		v[0].x = v[0].y = 0;
		sort(v.begin() + 1, v.end(), [](point& a, point& b) {
			if (a.y * b.x != a.x * b.y)return a.y * b.x < a.x* b.y;
			if (a.x != b.x)return a.x < b.x;
			return a.y < b.y;
			});
		for (int i = n - 1;i > 0;i--) {
			if (v[i].x * v[i - 1].y != v[i].y * v[i - 1].x) {
				reverse(v.begin() + i, v.end());
				break;
			}
		}
		for (int i = 0;i < n;i++)cout << v[i].idx << ' ';
		cout << endl;
	}
	return 0;
}