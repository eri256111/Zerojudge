#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using pci = pair<char, int>;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vl = vector<ll>;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define Pb push_back
#define All(v) v.begin(),v.end()
#define coutv(v) for(auto i : v){\
	cout << i << ' '; \
}cout << endl;
#define _ <<' '<<

int main(){
	FAST;

	const int MAX = 100 + 5;

	int m, n,
		arr[MAX][MAX];
	cin >> m >> n;
	Fr(i,0,m){
		stack<pci> s;
		Fr(j,0,n){
			cin >> arr[i][j];
			if(arr[i][j] == 1){
				if(s.empty())
					s.push({1, j});
				else{
					Fr(k,s.top().Sd,j)
						arr[i][k] = 1;
					s.pop();
				}
			}
		}
	}
	Fr(i,0,m){
		Fr(j,0,n){
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}