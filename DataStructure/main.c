#include <stdio.h>

#include "Link_list.h"
#include "Linear_list.h"


int main() {
	double a, b;
	a = time(NULL);
    LinearList L;
    InitList(&L);
    add_num(&L, 2);
    print_list(L);
	b = time(NULL);
	
	printf("花费的时间为:%.15f", b - a);
    return 0;
}
