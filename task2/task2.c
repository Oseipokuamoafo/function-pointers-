#include <stdio.h>
#include <stdlib.h>

static int a = 6, b = 3;

static void add(void)      { printf("Adding 'a' and 'b'\n");       printf("x = %d\n", a + b); }
static void subtract(void) { printf("Subtracting 'b' from 'a'\n"); printf("x = %d\n", a - b); }
static void multiply(void) { printf("Multiplying 'a' and 'b'\n");  printf("x = %d\n", a * b); }
static void divide(void)   { printf("Dividing 'a' by 'b'\n");      printf("x = %d\n", a / b); }
static void quit(void)     { exit(0); }

int main(void)
{
	/* Indexed by the input character itself. Every slot defaults to quit,
	 * so '4' and any unexpected character exit. No if/switch/goto needed. */
	void (*ops[256])(void);
	for (int i = 0; i < 256; i++)
		ops[i] = quit;
	ops['0'] = add;
	ops['1'] = subtract;
	ops['2'] = multiply;
	ops['3'] = divide;

	char c = '4';

	printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
	printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
	c = (char)getchar();

	ops[(unsigned char)c]();
	return 0;
}