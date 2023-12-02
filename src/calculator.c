#include <stdio.h>
#include <stdint.h>

#include "calculator.h"

#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

/* function to add two numbers */
uint32_t calc_add(uint32_t a, uint32_t b) {
	return addition(a,b);
}

/* function to subtract two numbers */
uint32_t calc_sub(uint32_t a, uint32_t b) {
	return subtract(a,b);
}

/* function to multiply two numbers */
uint32_t calc_mul(uint32_t a, uint32_t b) {
	return multiply(a,b);
}

/* function to divide two numbers */
float calc_div(uint32_t a, uint32_t b) {
	return divide(a,b);
}