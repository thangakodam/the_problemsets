// problem: https://leetcode.com/problems/to-lower-case/
// time complexity  -> O(N)
// space complexity -> O(1)
char* toLowerCase(char* s) {
  for (int i = 0; i < strlen(s); i++) {
    // check for upper case letters
    if (s[i] >= 'A' && s[i] <= 'Z') {
      // s[i] - 'A' - make the value b/w 0 to 25
      // adding 'a' to the above value returns the equivalent lower case
      s[i] = (char) ('a' + s[i] - 'A');
    }
  }

  return s;    
}
