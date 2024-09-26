// problem: https://leetcode.com/problems/multiply-strings/
// time complexity  -> O(N * M)  ; N - len of num1, M - len of num2
// space complexity -> O(1)
char* multiply(char* num1, char* num2) {
  // if any of str is 0, then just return 0
  if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) return "0";

  // size of array needed = len of num1 + len of 
  int res_len = strlen(num1) + strlen(num2);
  int res[res_len];

  // initialize elements to zero;
  for (int i = 0; i < res_len; i++) res[i] = 0;

  // calculate the product
  for (int i = strlen(num1) - 1; i >= 0; i--) {
    for (int j = strlen(num2) - 1; j >= 0; j--) {
      // get the product
      res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');

      // if the product has carry then add it to the previous element & factor it our
      res[i + j] += res[i + j + 1] / 10;
      res[i + j + 1] %= 10;
    }
  }

  // get how many leading zeros are present
  int ledzero = 0;
  while (ledzero < res_len && res[ledzero] == 0) ledzero++;

  // convert the int array to array of char (string)
  int str_len = res_len - ledzero + 1;             // +1 for adding null character
  char *rprod = malloc(sizeof(char) * str_len);

  for (int i = 0, j = ledzero; j < res_len; i++, j++)
    rprod[i] = res[j] + '0';

  rprod[str_len - 1] = '\0';                       // mark the end of the string
  return rprod;
}
