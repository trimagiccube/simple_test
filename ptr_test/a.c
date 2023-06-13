#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum id {
	ID_0,
	ID_1,
	ID_2,
	ID_3,
	ID_4,
	ID_5,
};

#define ID_X(b) ID##b
struct my_struct {
	int id;
	int a;
	int b;
};

struct my_struct test_array[6] = {
	[0 ... 3] = {.a = 2, .b = 1, },
	{2, 2},
	{3, 3},
};

void printf_array(struct my_struct *test_ray, int ray_size)
{
	int i;
	printf("%d\n", INT_MIN);
	printf("%lx\n", (unsigned long)-1);
	for (i = 0; i < ray_size; i++)
		printf("element %d, a = %d, b = %d\n", i, test_ray[i].a, test_ray[i].b);
	printf("\n");
}

void array_init(struct my_struct (*src)[6], struct my_struct (**dst)[6])
{
	*dst = malloc(sizeof(struct my_struct) * 6);
	memcpy((void *)*dst, (void *)src, sizeof(struct my_struct) * 6);
}
int main()
{
	struct my_struct (*ptr_array)[6];
	array_init(&test_array, &ptr_array);
	printf_array(ptr_array, 6);
	return 0;
}
