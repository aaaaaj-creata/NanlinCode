#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
	char arr[20];
	while (scanf("%s", arr) != EOF) {
		sort(arr, arr + strlen(arr));
		printf("%s\n", arr);
	}
	return 0;
}