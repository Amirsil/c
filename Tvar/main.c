#include "var.c"

int main(){
	int num = 0xf00;
	char *str = "bar";
	unsigned int address = 0xdeadbeef;

	var dynamicly_typed = (var){STRING, &str};
	PrintVar(&dynamicly_typed);

	dynamicly_typed = (var){INTEGER, &num};
	PrintVar(&dynamicly_typed);

	dynamicly_typed = (var){UINTEGER, &address};
	PrintVar(&dynamicly_typed);


	return 0;
}