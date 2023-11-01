#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define my_assert(s) _assert(#s, s)

void _assert(char *s, int f){
	if (f == 0){
		fprintf(stderr, "%s: %s:%d: %s: Assertion `%s` failed.\n", __FILE__, __FILE__, __LINE__, __func__, s);	
		abort();
	}
}
void foo(int num){
	my_assert( ((num >= 0) && (num <= 100)) );
	printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]){
	int num;

	if (argc < 2) {
		fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
		exit(1);
	}

	num = atoi(argv[1]);
	foo(num);
}
