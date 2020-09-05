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

int n, q, p1, p2, sz, ans, ctr;
int result[100005], cnt[200005], s[100005], cnt2[200005];

struct make_dcmp {
	int lo, hi, id;
	bool operator<(const make_dcmp& d) {
		if (lo / sz != d.lo / sz)return (lo / sz < d.lo / sz);
		else return hi < d.hi;
	}
};
make_dcmp dcmp[100005];

void add(int x) {
	x = s[x];
	if (cnt[x])
		cnt2[cnt[x]]--;
	cnt[x]++;
	cnt2[cnt[x]]++;
	ans = max(ans, cnt[x]);
}
void erase(int x) {
	x = s[x];
	cnt2[cnt[x]]--;
	if (cnt[x] == ans && !cnt2[cnt[x]])
		ans--;
	cnt[x]--;
	cnt2[cnt[x]]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i] += 100000;
	}
	sz = sqrt(n);
	for (int i = 0; i < q; i++) {
		cin >> p1 >> p2;
		--p1, --p2;
		dcmp[i].lo = p1, dcmp[i].hi = p2, dcmp[i].id = i;
	}
	sort(dcmp, dcmp + q);
	int x = 0, y = 0;
	for (int i = 0; i < q; i++) {
		int lo = dcmp[i].lo, hi = dcmp[i].hi, idx = dcmp[i].id;
		if (!i) {
			for (int j = lo; j < hi + 1; j++)add(j);
			result[idx] = ans, x = lo, y = hi;
			continue;
		}
		while (x < lo)erase(x++);
		while (lo < x)add(--x);
		while (hi < y)erase(y--);
		while (y < hi)add(++y);
		result[idx] = ans, x = lo, y = hi;
	}
	for (int i = 0; i < q; i++)
		cout << result[i] << endl;
	return 0;
}