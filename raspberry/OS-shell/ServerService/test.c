#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	enum {T0, T1, T2};
	enum day {cn, t1, t2, t3, t4, t5, t6, t7} n1;
	enum day n2;
	int i, j=2000,  k =  T2;
	i = t7;
	//n1 = -1000;
	n2 = j;
	printf("\nn1 = %d n2 = %d i = %d\n", n1, n2, i);
	printf("\n k = %d T1 = %d\n", k, T1);
}