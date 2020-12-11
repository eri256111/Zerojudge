#include <iostream>
using namespace std;

#define endl '\n'

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int N,
		H1, M1, H2, M2, M3,
		T1, T2;
	cin >> N;
	while(N--){
		cin >> H1 >> M1 >> H2 >> M2 >> M3;
		T1 = H1 * 60 + M1;
		T2 = H2 * 60 + M2;
		if(T1 + M3 <= T2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	return 0;
}