=begin
Problem 16:

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?

https://projecteuler.net/problem=16
=end
puts "Welcome to PowerDigitSum!"
puts "The sum of the digits of 2^1000 is:"
digits = (2**1000).to_s

digit_sum = 0
digits.each_char do |c|
  digit_sum += c.to_i
end

puts "#{digit_sum}"
