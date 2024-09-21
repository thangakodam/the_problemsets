// problem: https://leetcode.com/problems/find-the-difference
// time complexity  -> O(N + M)      ; N - len of string s,  M - len of string t
// space complexity -> O(1)
char findTheDifference(char* s, char* t) {
  // hold the ASCII sum of each characters
  int ascii_sum = 0;

  // calculate ACSII sum of chars in t
  for (int i = 0; i < strlen(t); i++)
    ascii_sum += t[i];
  
  // substract ASCII value of each char in s with sum
  for (int i = 0; i < strlen(s); i++) {
    ascii_sum -= s[i];
  }

  // the remaining value is the ACSII value of added char
  return (char) ascii_sum;
}
