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

vector<int> solution(vector<int> n, vector<int> m) {
	vector<int> ans;
	int cnt = 0;
	int rank = 0;

	sort(n.begin(), n.end());
	sort(m.begin(), m.end());

	for (auto i : n)
		if (i == 0)cnt++;

	for (auto i : n) {
		for (auto j : m) {
			if (i == j) {
				rank++;
				break;
			}
		}
	}
	rank = 7 - rank;
	if (rank == 7)rank = 6;

	int nrank = rank - cnt;
	if (!nrank) nrank = 1;

	ans.push_back(nrank);
	ans.push_back(rank);

	return ans;
}