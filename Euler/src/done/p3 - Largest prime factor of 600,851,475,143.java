/**
 * Generates all prime numbers less than or equal to the specified number. I used this to solve problem three of Project
 * Euler and then I modified it more afterward.
 */

package projectEuler;

import java.util.ArrayList;

public class p3 {
    public static ArrayList<Integer> primeNumbers = new ArrayList<>();

    public static void main(String[] args) {
        final long numberToFactor = 600_851_475_143L;

        primeNumbers.add(2);

        for (int i = 3; i <= Math.sqrt(numberToFactor); i += 2) {
            if (isPrime(i)){
                primeNumbers.add(i);
            }
        }

        int highestPrimeFactor = 2;
        for (Integer primeInt : primeNumbers){
            if (numberToFactor % primeInt == 0){
                highestPrimeFactor = primeInt;
            }
        }

        System.out.println("There are " + primeNumbers.size() + " prime numbers that are less than or equal to " + Math.sqrt(numberToFactor));
        System.out.println("The largest prime factor of " + numberToFactor + " is " + highestPrimeFactor);
    }

    public static boolean isPrime(int numberToCheck) {
        int possibleFactor = 2, i = 1;
        while (possibleFactor <= Math.sqrt(numberToCheck)){
            if (numberToCheck % possibleFactor == 0){
                return false;
            } else if (i < primeNumbers.size()){
                possibleFactor = primeNumbers.get(i);
                i++;
            } else {
                    possibleFactor++;
            }
        }
        return true;
    }
}
