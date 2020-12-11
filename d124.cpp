#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	string str;
	while(cin >> str){
		int sum = 0;
		for(int i = 0 ; i < str.size() ; i++){
			if(str[i] == '-')
				continue;
			sum += str[i] - '0';
		}
		if(sum % 3 == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}