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
	
	printf("���ѵ�ʱ��Ϊ:%.15f", b - a);
    return 0;
}
