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
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, p1;i < n * 3;i++) {
		cin >> p1;
		v.push_back(p1);
	}
	sort(v.begin(), v.end());
	int a = 0, b = INF;
	for (int i = n;i < n + n;i++) {
		a = max(a, v[i]);
		b = min(b, v[i]);
	}
	cout << a - b << endl;
	return 0;
}