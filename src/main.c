#include <stdio.h>
#include <stdint.h>

#include "main.h"

int main() {
	printf("-- Calculator --\n");

	uint32_t result = 0;
	int32_t sub_result = 0;
	float div_result = 0;

	uint32_t a = 50, b = 60;

	result = addition(a , b);
	printf("Addition of %u and %u = %u\n", a, b, result);

	sub_result = subtract(a , b);
	printf("Subraction of %u and %u = %d\n", a, b, sub_result);

	result = multiply(a , b);
	printf("Multiplication of %u and %u = %u\n", a, b, result);

	div_result = divide(a , b);
	printf("Division of %u and %u = %f\n", a, b, div_result);

	return 0;
}