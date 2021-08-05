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

void func(int l, int r) {
	int cur = l;
	int next = l++;
	while (v[++next] < v[cur]);
	if (l <= next - 1)func(l, next - 1);
	if (next <= r)func(next, r);
	cout << v[cur] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) v.push_back(n);
	v.push_back(INF);
	func(0, v.size() - 2);
	return 0;
}