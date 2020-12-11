#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 0)
			puts("No");
		else if((n & (n-1)) == 0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}