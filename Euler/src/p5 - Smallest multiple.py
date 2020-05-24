def divides_evenly(number):
        for i in range(2, 21):
            if not number % i == 0:
                return False

        return True


smallest_number = 9_699_690    # Smallest possible number that divide evenly is the product of the primes less than 20
break_point = 100_000_000
while not divides_evenly(smallest_number):
    smallest_number += 9_699_690  # The smallest number will be a multiple of the product of the primes
    if smallest_number >= break_point:
        print(smallest_number)
        break_point += 100_000_000


print("The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is:", smallest_number)
input()
