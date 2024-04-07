#include <stdlib.h>
typedef struct {
  int sum;
  int index1;
  int index2;
} Pair;

int compare(const void *a, const void *b) {
  Pair *pair1 = (Pair *)a;
  Pair *pair2 = (Pair *)b;
  return pair1->sum - pair2->sum;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size,
                     int k, int *returnSize, int **returnColumnSizes) {
  *returnSize = 0;
  if (nums1Size == 0 || nums2Size == 0 || k == 0) {
    return NULL;
  }
  Pair *heap = (Pair *)malloc(sizeof(Pair) * k);
  int heapSize = 0;

  int **result = (int **)malloc(sizeof(int *) * k);
  *returnColumnSizes = (int *)malloc(sizeof(int) * k);

  for (int i = 0; i < k; i++) {
    (*returnColumnSizes)[i] = 2;
    result[i] = (int *)malloc(sizeof(int) * 2);
  }

  for (int i = 0; i < nums1Size && i < k; i++) {
    heap[heapSize++] = (Pair){nums1[i] + nums2[0], i, 0};
  }

  qsort(heap, heapSize, sizeof(Pair), compare);

  while (*returnSize < k && heapSize > 0) {
    Pair top = heap[0];
    result[*returnSize][0] = nums1[top.index1];
    result[*returnSize][1] = nums2[top.index2];
    (*returnSize)++;

    if (top.index2 + 1 < nums2Size) {
      heap[0] = (Pair){nums1[top.index1] + nums2[top.index2 + 1], top.index1,
                       top.index2 + 1};
      qsort(heap, heapSize, sizeof(Pair), compare);
    } else {
      heap[0] = heap[--heapSize];
      if (heapSize > 0) {
        qsort(heap, heapSize, sizeof(Pair), compare);
      }
    }
  }
  free(heap);
  return result;
}

// 373. Find K Pairs with Smallest Sums
// Medium
// You are given two integer arrays nums1 and nums2 sorted in non-decreasing
// order and an integer k.
//
// Define a pair (u, v) which consists of one element from the first array and
// one element from the second array.
//
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
//
//
//
// Example 1:
//
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6] Example 2:
//
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence:
// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//
// Constraints:
//
// 1 <= nums1.length, nums2.length <= 105
// -109 <= nums1[i], nums2[i] <= 109
// nums1 and nums2 both are sorted in non-decreasing order.
// 1 <= k <= 104
// k <= nums1.length * nums2.length
