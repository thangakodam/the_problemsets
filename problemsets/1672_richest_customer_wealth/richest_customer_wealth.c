// problem: https://leetcode.com/problems/richest-customer-wealth/
// time complexity  -> O(M * N)  ; M,N - size of row and column of matrix
// space complexity -> O(1)
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
  int max_wealth = 0;

  for (int customer = 0; customer < accountsSize; customer++) {
    int total_wealth = 0;

    for (int bank = 0; bank < *accountsColSize; bank++)
      total_wealth += accounts[customer][bank];

    // update the max_wealth
    max_wealth = total_wealth > max_wealth ? total_wealth : max_wealth;
  }

  return max_wealth;    
}
