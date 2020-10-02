#include "var.h"

int main(){
	Var dynamics[10] = {0};
	size_t length = sizeof(dynamics)/sizeof(*dynamics);

	for (int i = length + 'A'; i --> 'A';) char_var(i, dynamics + i - 'A');
	for (int i = length; i --> 0 ;) print_var(dynamics + i);

	char str[80] = {0};
	for (int i = length; i --> 0 ;){
		strcat(str, "A");
		str_var(str, dynamics + i);
	}

	for (int i = length; i --> 0 ;) print_var(dynamics + i);

	for (int i = length; i --> 0 ;) free_var(dynamics + i);
	
	// puts("");

	// Var dynamic = {0};
	// str_var("foo", &dynamic);
	// print_var(&dynamic);

	// uint_var(-1, &dynamic);
	// print_var(&dynamic);

	// free_var(&dynamic);
	// print_var(&dynamic);
	// free_var(&dynamic);

	// char_var(0x41, &dynamic);
	// print_var(&dynamic);
	// free_var(&dynamic);
	
	return 0;
}