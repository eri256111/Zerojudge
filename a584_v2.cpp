#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end()
#define Pb push_back
#define _ <<' '<<

class Family{
private:
	map<string, vector<string> > G;
	map<string, string> pa;
	map<string, int> dep;
public:
	string start, end, ancestor;
	void Read(int n){
		Fr(i,0,n){
			string in; getline(cin, in);
			stringstream ss(in);
			string parent; ss >> parent;
			while(ss >> in){
				pa[in] = parent;
				G[parent].push_back(in);
			}
		}
		cin >> start >> end;
	}
	void Find_Ancestor(){
		for(auto i : G){
			if(!pa.count(i.Ft)){
				ancestor = i.Ft;
				break;
			}
		}
	}
	void DFS(string cur, int d = 0){
		for(auto i : G[cur])
			DFS(i, d + 1);
		dep[cur] = d;
	}
	string LCA(string a, string b){
		if(dep[a] < dep[b])swap(a, b);
		while(dep[b] > dep[a])b = pa[b];
		while(a != b)a = pa[a], b = pa[b];
		return a;
	}
	int ANS(){
		Find_Ancestor();
		DFS(ancestor);
		return dep[start] + dep[end] - dep[LCA(start, end)] * 2;
	}
};

int main(){
	FAST;

	int n; 
	cin >> n; cin.ignore();
	Family family;
	family.Read(n);
	cout << family.ANS() << endl;
	return 0;
}