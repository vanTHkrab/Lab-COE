#include <stdio.h>

int main(void)
{
	int count = 0, a[100000];
	do {
		scanf("%d", &a[count++]);
	} while (getchar() != '\n' && count < 100);
	a[count];
	for (int i = 0; i < count; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
