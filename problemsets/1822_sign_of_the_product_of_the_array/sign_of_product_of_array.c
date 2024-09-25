// problem: https://leetcode.com/problems/sign-of-the-product-of-an-array
// time complexity  -> O(N)
// space complexity -> O(1)
int arraySign(int* nums, int numsSize) {
  int negative_sig = 1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0)
      return 0;

    if (nums[i] < 0)
      negative_sig *= (-1);
  }

  return negative_sig;
}
