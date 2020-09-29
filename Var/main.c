#include "var.h"

int main(){
	Var dynamic = {};
	new_var(STRING, strptr("foo"), &dynamic);
	print_var(&dynamic);

	new_var(INTEGER, intptr(0xdeadbeef), &dynamic);
	print_var(&dynamic);

	new_var(UINTEGER, uintptr(-1), &dynamic);
	print_var(&dynamic);

	new_var(CHARACTER, charptr(0x41), &dynamic);
	print_var(&dynamic);


	free_var(&dynamic);
	print_var(&dynamic);
	return 0;
}