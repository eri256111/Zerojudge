#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end()
#define _ <<' '<<

typedef long long ll;
typedef pair<int, int> pii;

class Family{
private:
	const int MAX = 25000,
		 	  MUL = 31;
	struct Node{
		int parent, level = 0;
		vector<int> child;
	};
	vector<Node> v;
public:
	int start, end;
	int hash_to_int(string str){
		int hash = 0;
		for(auto i : str)
			hash = (hash * MUL + int(i - 'A'));
		return hash;
	}
	void update(int n){
		v.resize(MAX);
		Fr(i,0,n){
			string in; getline(cin, in);
			stringstream ss(in);
			ss >> in;
			int a = hash_to_int(in), b;
			while(ss >> in){
				b = hash_to_int(in);
				v[b].parent = a;
				v[a].child.push_back(b);
			}
		}
		string s, e; cin >> s >> e;
		start = hash_to_int(s),
		end = hash_to_int(e);
	}
	int bfs(){
		queue<int> qu;
		qu.push(start);
		while(qu.size()){
			int cur = qu.front(); qu.pop();
			if(cur == end)
				return v[end].level;
			for(auto i : v[cur].child){
				if(v[i].level == 0){
					qu.push(i);
					v[i].level = v[cur].level + 1;
				}
			}
			if(v[v[cur].parent].level == 0){
				qu.push(v[cur].parent);
				v[v[cur].parent].level = v[cur].level + 1;
			}
		}
		return 0;
	}
};

int main(){
	FAST;

	int n;
	cin >> n; cin.ignore();
	Family family;
	family.update(n);
	cout << family.bfs() << endl;
	return 0;
}