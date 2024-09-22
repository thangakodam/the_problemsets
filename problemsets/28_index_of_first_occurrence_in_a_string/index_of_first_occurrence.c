// problem: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// time complexity  -> O(M * N)    ; M - size of haystack, N - size of needle
// space complexity -> O(1)
int strStr(char* haystack, char* needle) {
  int hp = 0, np = 0;       // two pointers to track the string
  int idx = -1;             // position of start of substring

  while (haystack[hp]) {
    if (haystack[hp] == needle[np]) {
      // update the index
      idx = idx == -1 ? hp : idx;
      
      // update needle pointer
      np++;  

      // check if the end of needle is reached
      if (!needle[np]) return idx;
    }
    else {
      // reset the hp back to idx if idx is not -1
      hp = idx != -1 ? idx : hp;

      idx = -1;  // reset idx
      np = 0;    // reset the np counter to start
    }

    hp++; 
  }

  return -1;    
}
