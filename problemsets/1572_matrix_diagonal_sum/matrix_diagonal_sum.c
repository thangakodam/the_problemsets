// problem: https://leetcode.com/problems/matrix-diagonal-sum
// time complexity  -> O(N)  ; size of matrix row
// space complexity -> O(1)
int diagonalSum(int** mat, int matSize, int* matColSize) {
  int diag_sum = 0;

  for (int r = 0, c = 0; r < matSize; r++, c++) {
    // calculate primary diagonal
    diag_sum += mat[r][c];

    // calculate the secondary diagonal
    diag_sum += mat[r][matSize - 1 - c];
  }

  // if matrix is of odd size, the the middle element was added twice
  if (matSize % 2 != 0) {
    int idx = matSize / 2;
    diag_sum -= mat[idx][idx];
  }

  return diag_sum;
}
