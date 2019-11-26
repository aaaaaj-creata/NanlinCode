#include<stdio.h>
int main() {
	int N, M, a, sum = 0, i;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &M);
		for (i = 1; i <= M; i++) {
			scanf("%d", &a);
			sum += a;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}

