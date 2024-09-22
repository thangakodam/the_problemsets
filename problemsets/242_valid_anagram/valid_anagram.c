// problem: https://leetcode.com/problems/valid-anagram
// time complexity  -> O(N)   ; N - size of string s or t
// space complexity -> O(1)
bool isAnagram(char* s, char* t) {
  // array to hold frequency of 26 alphabets
  int freq[26] = {0};

  // if two strings are not of same len, then it can't be anagram
  if (strlen(s) != strlen(t))
    return false;

  // update the frequency of each str
  // increment for chars in s & decrement for chars in t
  for (int i = 0; i < strlen(t); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }

  // freq of each char has to be 0 for perfect match
  for (int i = 0; i < 26; i++) {
    if (freq[i] != 0)
      return false;
  }

  return true;    
}
