#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n;
string str;
vector<string> v[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v[str.size()].push_back(str);
	}
	for (int i = 1; i <= 50; i++)
		sort(v[i].begin(), v[i].end());
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j > 0) if (v[i][j] == v[i][j - 1])continue;
			cout << v[i][j] << endl;
		}
	}
	return 0;
}
