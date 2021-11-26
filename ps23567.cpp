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

const int sz = 1 << 20;

ll bit[sz], n, m;
vector<ll> a, b, compa, compb, ans, l, r, fail;

void update(int x, ll val) {
	for (x++;x < sz;x += x & -x)bit[x] += val;
}
ll sum(int x) {
	ll ret = 0;
	for (x++;x;x ^= x & -x)
		ret += bit[x];
	return ret;
}
ll query(int lo, int hi) {
	return sum(hi) - sum(lo - 1);
}

bool check(int i, int j, int w) {
	if (w & 1)return l[j] == query(1, a[i] - 1) && r[j] == query(a[i] + 1, m);
	else return l[j] == query(1, b[i] - 1) && r[j] == query(b[i] + 1, m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		compa.push_back(a[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		compb.push_back(b[i]);
	}
	sort(compa.begin(), compa.end());
	sort(compb.begin(), compb.end());
	compa.erase(unique(compa.begin(), compa.end()), compa.end());
	compb.erase(unique(compb.begin(), compb.end()), compb.end());
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(compa.begin(), compa.end(), a[i]) - compa.begin() + 1;
	for (int i = 0; i < m; i++)
		b[i] = lower_bound(compb.begin(), compb.end(), b[i]) - compb.begin() + 1;

	fail.resize(n);
	l.resize(n);
	r.resize(n);
	for (int i = 0; i < a.size(); i++) {
		update(a[i], 1);
		l[i] = query(1, a[i] - 1);
		r[i] = query(a[i] + 1, n);
	}
	memset(bit, 0, sizeof(bit));
	for (int i = 1, j = 0; i < a.size(); i++) {
		while (j > 0 && !check(i, j, 1)) {
			for (int k = i - j; k < i - fail[j - 1]; k++)update(a[k], -1);
			j = fail[j - 1];
		}
		if (check(i, j, 1)) {
			update(a[i], 1);
			fail[i] = ++j;
		}
	}
	memset(bit, 0, sizeof(bit));
	for (int i = 0, j = 0; i < b.size(); i++) {
		while (j > 0 && !check(i, j, 0)) {
			for (int k = i - j; k < i - fail[j - 1]; k++)update(b[k], -1);
			j = fail[j - 1];
		}
		if (check(i, j, 0)) {
			if (j == a.size() - 1) {
				ans.push_back(i - j);
				for (int k = i - j; k < i - fail[j] + 1; k++)update(b[k], -1);
				j = fail[j];
			}
			else j++;
			update(b[i], 1);
		}
	}
	if (ans.empty())cout << 0;
	else for (auto i : ans)cout << i + 1 << ' ';
	return 0;
}