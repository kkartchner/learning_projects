/**
* Finds the 10,001st prime number and prints it to the screen.
*/

#define NUMBER_OF_PRIMES 10001

#include <stdio.h>
#include <math.h>

int isPrime(int);

int prime_numbers[NUMBER_OF_PRIMES];

int main () {
	int prime_count = 1, number_to_check = 3;
	
	prime_numbers[0] = 2;
	
	while (prime_count < NUMBER_OF_PRIMES){
		if (isPrime(number_to_check)){		// Find the next prime		
			prime_numbers[prime_count] = number_to_check;
			prime_count++;
		}
		number_to_check++;
	}
	
	
	printf("The 10,001st prime number is %d", prime_numbers[NUMBER_OF_PRIMES-1]);
	
	return 0;
}

int isPrime(int number_to_check) {
        int possible_factor = 2, i = 1;
        while (possible_factor <= sqrt(number_to_check)){
            if (number_to_check % possible_factor == 0){
                return 0;
			} else if (prime_numbers[i] != 0){
                possible_factor = prime_numbers[i];
                i++;
            } else {
                    possible_factor++;
            }
        }
        return 1;
}