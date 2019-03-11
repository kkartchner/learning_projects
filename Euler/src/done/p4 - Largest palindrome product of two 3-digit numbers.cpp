#include <iostream>

using namespace std;

bool isPalindrome (string);

int main (){
	int first3DigitNumber = 100;
	int second3DigitNumber = 999;
	
	int largestPalindromeProduct = 0;
	
	for (first3DigitNumber = 100; first3DigitNumber < 1000; first3DigitNumber++){
		for (second3DigitNumber = 100; second3DigitNumber < 1000; second3DigitNumber++){
				int product = first3DigitNumber * second3DigitNumber;
				if (isPalindrome(to_string(product))){
					if (product > largestPalindromeProduct){
						largestPalindromeProduct = product;
					}
					cout << product << " is a palindrome\n";
				}
		}
	}	
	
	cout << "The largest product that is a palindrome is " << largestPalindromeProduct;
	return 0;
}

bool isPalindrome(string numberToCheck){
	for (int left = 0, right = numberToCheck.size()-1; left < right; left++, right--){
		if (numberToCheck[left] != numberToCheck[right]){
			return false;
		}
	}
	return true;
}
