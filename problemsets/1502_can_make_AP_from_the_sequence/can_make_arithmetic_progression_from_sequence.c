// problem: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence
// time complexity  -> O(N * log(N))   ; quick sort's complexity
// space complexity -> O(1)

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
  // sort the array (quick sort algorithm)
  qsort(arr, arrSize, sizeof(int), compare);

  // calculate the difference
  int diff = arr[0] - arr[1];

  for (int i = 1; i < arrSize-1; i++) {
    // calcuate the temp diff
    int tdiff = arr[i] - arr[i + 1];

    if (tdiff != diff) return false;
  }
  return true;
}
