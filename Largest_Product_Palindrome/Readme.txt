Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].

************************************************************************************************

Solution:

The approach to look at this problem in a O(n) way is following:
Tha maximum product for any given n-digit number is the the highest n-digit number with itself. So first we take that and check whether it is a palindrome. If not we go further.
Any product length will not be greater than 2n.
We divide our products in 2 eqaual parts-> left and right. A palindrome will be a concatenation of the left and its reversed digits. If left is greater than right, decrement left.
Create a new palindrome by the concatnation and check if its a valid product. To do so you start finding its mod with numbers starting from the highest n digit number.
If no match is found decrease the left part again, find a palindrome using the left and validate it. repeate till you find the solution,


