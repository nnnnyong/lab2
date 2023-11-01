#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
	void *handle;
	int (*add)(int, int), (*sub)(int, int), (*mul)(int, int);
        double (*div)(double, double);
	char *error;

	int a = 3, b = 6;

	handle = dlopen("./lib/libshared.so", RTLD_LAZY);
	if (!handle){
		fputs(dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}

	sub = dlsym(handle, "sub");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	mul = dlsym(handle, "mul");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	div = dlsym(handle, "div");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}

	printf("add(%d, %d) = %d\n", a, b, add(a, b));
	printf("sub(%d, %d) = %d\n", a, b, sub(a, b));
	printf("mul(%d, %d) = %d\n", a, b, mul(a, b));
	printf("div(%d, %d) = %f\n", a, b, div(a, b));

	return 0;
}

