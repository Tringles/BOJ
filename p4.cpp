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

vector<string> solution(vector<string> r) {
	vector<pair<string, int>> order;
	vector<string> ans;
	map<string, string> m;

	for (auto s : r) {
		vector<string> v;
		string token;
		stringstream str;
		str.str(s);
		while (str >> token) v.push_back(token);

		if (v[0] == "Enter") {
			m[v[1]] = v[2];
			order.push_back({ v[1], 0 });
		}
		else if (v[0] == "Change") {
			m[v[1]] = v[2];
		}
		else {
			order.push_back({ v[1], 1 });
		}
	}

	for (auto o : order) {
		string id = o.first;
		int flag = o.second;
		if (!flag) {
			string output = m[id] + "님이 들어왔습니다.";
			ans.push_back(output);
		}
		else {
			string output = m[id] + "님이 나갔습니다.";
			ans.push_back(output);
		}
	}
	return ans;
}