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

int n, m, p1, p2, p3;
int p[100005], depth[100005], visit[100005], cnt[100005];
PI inq[100005], q[100005];
map<PI, int> edge_life;
vector<int> ans;
vector<PI> seg[100002 * 4];
stack<PII> s;

struct life { int lo, hi, x, y; };
vector<life> v;

int find(int x) {
	if (p[x] == x)return x;
	return find(p[x]);
}
int merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return 0;
	if (depth[x] < depth[y])swap(x, y);
	p[y] = x;
	if (depth[x] == depth[y]) {
		depth[x]++;
		s.push({ x,{y,1} });
	}
	else s.push({ x,{y,0} });
	return 1;
}

void update(int lo, int hi, PI val, int node, int x, int y) {
	if (hi < x || y < lo)return;
	if (lo <= x && y <= hi) {
		seg[node].push_back(val);
		return;
	}
	int mid = (x + y) >> 1;
	update(lo, hi, val, node * 2, x, mid);
	update(lo, hi, val, node * 2 + 1, mid + 1, y);
}
void rollback(int y) {
	for (int i = 1; i <= y; i++) {
		auto& x = s.top();
		s.pop();
		p[x.second.first] = x.second.first;
		if (x.second.second)depth[x.first]--;
	}
}
void query(int x, int y, int node) {
	int cntt = 0;
	for (auto& i : seg[node])
		cntt += merge(i.first, i.second);
	if (x == y) {
		cout << (find(q[x].first) == find(q[x].second)) << endl;
		rollback(cntt);
		return;
	}
	int mid = (x + y) >> 1;
	query(x, mid, node * 2);
	query(mid + 1, y, node * 2 + 1);
	rollback(cntt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)p[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> p1 >> p2 >> p3;
		if (p2 > p3)swap(p2, p3);
		if (p1 == 1) {
			visit[i] = 1;
			edge_life[{p2, p3}] = i;
			inq[i] = { p2,p3 };
		}
		else if (p1 == 2) {
			visit[edge_life[{p2, p3}]] = 0;
			v.push_back({ cnt[edge_life[{p2,p3}]] + 1,cnt[i - 1],p2,p3 });
		}
		else {
			q[cnt[i - 1] + 1] = { p2,p3 };
			cnt[i] = 1;
		}
		cnt[i] += cnt[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		if (visit[i])
			v.push_back({ cnt[i] + 1,cnt[m],inq[i].first,inq[i].second });
	}
	for (life& i : v)
		update(i.lo, i.hi, { i.x,i.y }, 1, 1, cnt[m]);
	query(1, cnt[m], 1);
	return 0;
}
