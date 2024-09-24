// problem: https://leetcode.com/problems/length-of-last-word
// time complexity  -> O(N)
// space complexity -> O(1)
int lengthOfLastWord(char* s) {
  int wlen = 0;                           // len of last word
  bool is_trail_space_removed = false;    // flag to remove trailing spaces if present

  for (int i = strlen(s) - 1; i >= 0; i--) {
    // if flag is set and the last characters are spaces, then ignore it
    if (!is_trail_space_removed && s[i] == ' ') 
      continue;
    else {
      // when first non-space character is detected, update the flag
      is_trail_space_removed = true;
    }

    // count until we detect space character, that marks the start of the last word
    if (s[i] != ' ')  
      wlen++;
    else  
      return wlen;
  }
  return wlen; 
}


// ALTERNATE SOLUTION (moving from start to end)
int lenghtOfLastWord(char *s) {
  int wlen = 0;

  for (int i = 1; i < strlen(s); i++) {
    if (s[i] == ' ') continue;
    if (s[i - 1] == ' ') wlen = 0;
    wlen++;
  }

  return wlen;
}
