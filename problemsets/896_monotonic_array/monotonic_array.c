// problem: https://leetcode.com/problems/monotonic-array
// time complexity  -> O(N)
// space complexity -> O(1)
bool isMonotonic(int* nums, int numsSize) {
  if (numsSize == 1)
    return true;
  
  // var to track the array is increasing or decreasing
  // '+' - ascending order, '-' - descending order
  char indec = '\0';

  for (int i = 0; i < numsSize - 1; i++) {
    if (nums[i] == nums[i + 1])
      continue;

    if (nums[i] > nums[i + 1]) {
      // if indec is not set
      indec = indec == '\0' ? '-' : indec;

      if (indec != '-') return false;
    }
    else {
      // if indec is not set
      indec = indec == '\0' ? '+' : indec;

      if (indec != '+') return false;
    }
  }

  return true;   
}
