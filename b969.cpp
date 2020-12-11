#include <iostream>
#include <sstream>
using namespace std;

#define endl '\n'

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	string name, str;
	getline(cin, name);
	getline(cin, str);
	stringstream ss(name);
	while(ss >> name){
		cout << str << ", " << name << endl;
	}
	return 0;
}