#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;

void dothings(){
	printf("Now I'm here\n");
	sleep(3);
	longjmp(buf, 42);
	printf("this is never printed\n");
}

int main(){
	if(!setjmp(buf)){
		dothings();
	} else {
		printf("now I'm there\n");
	}
	return 0;
}
