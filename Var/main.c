#include "var.h"

int main(){
	Var dynamic = {};
	str_var("foo", &dynamic);
	print_var(&dynamic);

	int_var(0xdeadbeef, &dynamic);
	print_var(&dynamic);

	uint_var(-1, &dynamic);
	print_var(&dynamic);

	char_var(0x41, &dynamic);
	print_var(&dynamic);


	free_var(&dynamic);
	print_var(&dynamic);

	return 0;
}