#include <stdio.h>

void afficher(int a) {
	printf("%d", a);
}

void afficher(double a) {
	printf("%f", a);
}

int main(int, char **) {
	afficher(1);
	afficher(2.0);

	return 0;
}