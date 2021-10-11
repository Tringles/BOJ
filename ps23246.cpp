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

	bool operator<(const S& s) {
		if (a != s.a)return a < s.a;
		if (b != s.b)return b < s.b;
		if (c != s.c)return c < s.c;
	}
};

int n;
vector<S> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	S p;
	for (int i = 0, p1, p2, p3, p4;i < n;i++) {
		cin >> p1 >> p2 >> p3 >> p4;
		p.a = p2 * p3 * p4;
		p.b = p2 + p3 + p4;
		p.c = p1;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	cout << v[0].c << ' ' << v[1].c << ' ' << v[2].c << endl;
	return 0;
}