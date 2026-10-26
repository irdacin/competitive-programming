#include <cstdio>

int main(){
	int n, r, k;
	scanf("%d%d%d", &n, &r, &k);
	
	int b[n];
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);

	int nilai = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		nilai += b[i] / 100 * x;
	}

	printf(nilai >= r ? "PASS" 	: "NOT PASS");
	return 0;
}