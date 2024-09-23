// problem: https://leetcode.com/problems/move-zeroes
// time complexity  -> O(N)
// space complexity -> O(1)
void moveZeroes(int* nums, int numsSize) {
  // two pointers - zero pointer and swap pointer
  int zptr = 0, sptr = 1;

  while (sptr < numsSize && zptr < numsSize) {
    // if zptr points to zero, then we need to swap with sptr
    if (nums[zptr] == 0) {
      // take me to the non-zero element next to zptr for swapping
      while (sptr < numsSize-1 && nums[sptr] == 0) sptr++;

      // do the swap
      int tmp = nums[zptr];
      nums[zptr] = nums[sptr];
      nums[sptr] = tmp;
    }
    
    // move to the next positon
    zptr++;
    sptr++;
  }
}
