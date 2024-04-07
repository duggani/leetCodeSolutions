
#include <stdbool.h>
#include <stdlib.h>

// helper function to setup qsort
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool containsDuplicate(int *nums, int numsSize) {
  // sort the array before checking for duplicates
  qsort(nums, numsSize, sizeof(int), compare);

  for (int i = 0; i < numsSize - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      return true;
    }
  }
  return false;
}

// 217. Contains Duplicate
// Easy
//
// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: true
// Example 2:
//
// Input: nums = [1,2,3,4]
// Output: false
// Example 3:
//
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true
//
//
// Constraints:
//
// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
