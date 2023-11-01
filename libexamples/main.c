#include <stdio.h>
#include "arithmetic.h"

int main(){
	int a = 3, b = 6;

	printf("add(%d, %d) = %d\n", a, b, add(a, b));
	printf("sub(%d, %d) = %d\n", a, b, sub(a, b));
	printf("mul(%d, %d) = %d\n", a, b, mul(a, b));
	printf("div(%d, %d) = %f\n", a, b, div(a, b));

	return 0;
}
