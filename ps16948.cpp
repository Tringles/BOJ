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

int N, n, m, r, c, Visit[202][202];
int dy[]={-2, -2, 0, 0, 2, 2}, dx[]={-1, 1, -2, 2, -1, 1};
queue<PI> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
    cin>> n >> m >> r >> c;
    q.push({n, m});
    while (!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<6;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||ny>N-1||nx<0||nx>N-1)continue;
            if(!Visit[ny][nx]){
                if(ny==r && nx==c){
                    cout<<Visit[y][x] + 1<<endl;
                    return 0;
                }
                q.push({ny,nx});
                Visit[ny][nx]=Visit[y][x]+1;
            }
        }
    }
    cout<<-1<<endl;
	return 0;
}