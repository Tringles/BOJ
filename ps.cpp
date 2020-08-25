#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)q.push(i);
	while (q.size() != 1) {
		q.pop();
		int cur = q.front();
		q.pop();
		q.push(cur);
	}
	cout << q.front() << endl;
	return 0;
}