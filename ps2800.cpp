#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

string str, tmp;
stack<int> s;
vector<pair<int, int>> v;
vector<string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')s.push(i);
		else if (str[i] == ')') {
			v.push_back({ s.top(), i });
			s.pop();
		}
	}
	int det = 1 << v.size();
	for (int i = 1; i < det; i++) {
		tmp = str;
		for (int j = 0; j < v.size(); j++)
			if (i & (1 << j))tmp[v[j].first] = tmp[v[j].second] = 'X';
		string push;
		for (auto& j : tmp)if (j != 'X')push += j;
		ans.push_back(push);
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << endl;
	for (int i = 1; i < ans.size(); i++)
		if (ans[i - 1] != ans[i])cout << ans[i] << endl;
	return 0;
}
