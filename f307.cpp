#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end();
#define _ <<' '<<

typedef long long ll;
typedef pair<int, int> pii;


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
	FAST;

	int t, n, m;
	int sx, sy, ex, ey, ix, iy;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector< vector<char> > mp(n, vector<char>(m));
		Fr(i,0,n){
			Fr(j,0,m){
				cin >> mp[i][j];
				switch(mp[i][j]){
					case 'Y':
						sx = j, sy = i;
						break;
					case 'I':
						ix = j, iy = i;
						break;
					case 'N':
						ex = j, ey = i;
						break;
				}
			}
		}
		auto bfs = [&](int xs, int ys, int xe, int ye){
			vector< vector<int> > step(n, vector<int>(m, -1));
			queue<pii> qu{};
			qu.push({xs, ys});
			step[ys][xs] = 0;
			auto valid = [&](int x, int y){
				return x >= 0 and y >= 0 and x < m and y < n;
			};
			while(qu.size() != 0){
				auto [x, y] = qu.front(); qu.pop();
				Fr(i,0,4){
					int nx = x + dx[i], ny = y + dy[i];
					if(valid(nx, ny) and mp[ny][nx] != '*' and step[ny][nx] == -1){
						qu.push({nx, ny});
						step[ny][nx] = step[y][x] + 1;
						if(nx == xe and ny == ye) break;
					}
				}
			}
			return step[ye][xe];
		};
		int Y_to_I = bfs(sx, sy, ix, iy),
			I_to_N = bfs(ix, iy, ex, ey);
		if(Y_to_I == -1 or I_to_N == -1) cout << "Impossible!" << endl;
		else cout << Y_to_I + I_to_N << endl;
	}
    return 0;
}