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

int a, b;
map<int, int> m1, m2;
queue<int> q1, q2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        m1[a]++, m2[b]++;
        q1.push(a);
        q2.push(b);
    }
    while(!q1.empty()){
        int cur = q1.front();
        q1.pop();
        if(m1[cur] == 1){
            cout << cur << ' ';
            break;
        }
    }
    while(!q2.empty()){
        int cur = q2.front();
        q2.pop();
        if(m2[cur] == 1){
            cout << cur << endl;
            return 0;
        }
    }
}
