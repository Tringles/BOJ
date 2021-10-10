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

struct S {
	int a, b, c;
	string s;

	bool operator<(const S& o) {
		if (a != o.a)return a > o.a;
		if (b != o.b)return b < o.b;
		if (c != o.c)return c > o.c;
		return s < o.s;
	}
};

int n;
S s;
vector<S> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> s.s >> s.a >> s.b >> s.c;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (auto& [a, b, c, d] : v)
		cout << d << endl;
	return 0;
}