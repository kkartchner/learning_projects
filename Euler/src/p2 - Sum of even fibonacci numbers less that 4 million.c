#include <stdio.h>

int main(){
	int fib_numbers[10000] = {0};
	
	fib_numbers[0] = 1;
	fib_numbers[1] = 2;
	
	int highest_fib_number = 2;
	int even_fib_sum = 2;
	
	for (int i = 2; highest_fib_number < 4000000; i++){
		fib_numbers[i] = fib_numbers[i-2] + fib_numbers[i-1];
		if (fib_numbers[i] % 2 == 0){
			even_fib_sum += fib_numbers[i];
		}
		highest_fib_number = fib_numbers[i];
	}
	
	printf("The sum of all even fibonacci numbers less than 4 million is: %d", even_fib_sum);
	
	return 0;
}