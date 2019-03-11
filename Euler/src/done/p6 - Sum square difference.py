sum_of_squares = 0
square_of_sums = 0

for i in range(1, 101):
	sum_of_squares += (i * i)
	square_of_sums += i
	
square_of_sums *= square_of_sums;

print("sum_of_squares:", sum_of_squares)
print("square_of_sums:", square_of_sums)

print("Difference:", square_of_sums - sum_of_squares)

input("\nPress any key to exit")