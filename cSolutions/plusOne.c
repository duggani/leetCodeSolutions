#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *plusOne(int *digits, int digitsSize, int *returnSize) {
  // Allocate memory for a new array that is potentially one element larger
  int *result = malloc((digitsSize + 1) * sizeof(int));
  int carry = 1; // Start with a carry of 1 for the plus one operation

  // Loop through the digits from the end towards the beginning
  for (int i = digitsSize - 1; i >= 0; i--) {
    int sum = digits[i] + carry;
    result[i + 1] = sum % 10; // Set the current digit in the result
    carry = sum / 10;         // Update carry for the next iteration
  }

  // Handle the case where an extra digit is needed at the start (e.g., 999 + 1
  // = 1000)
  if (carry > 0) {
    result[0] = carry;
    *returnSize =
        digitsSize + 1; // The result size is one larger than the input size
  } else {
    // If no extra digit is needed, shift the result to remove the unused first
    // element
    for (int i = 0; i < digitsSize; i++) {
      result[i] = result[i + 1];
    }
    *returnSize = digitsSize; // The result size is the same as the input size
  }

  return result;
}

/*  66 PLUS ONE PROBLEM
 *
 *  You are given a large integer represented as an integer array digits,
    where each digits[i] is the ith digit of the integer. The digits are
    ordered from most significant to least significant in left-to-right order.
    The large integer does not contain any leading 0's.

    Increment the large integer by one and return the resulting array of digits.



Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].


Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/
