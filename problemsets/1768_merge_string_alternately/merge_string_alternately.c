// problem: https://leetcode.com/problems/merge-strings-alternately
// time complexity  -> O(N + M)    ; N - size of word1, M - size of word2
// space complexity -> O(1)
char * mergeAlternately(char * word1, char * word2){
  // get the string length
  int w1_len = strlen(word1);
  int w2_len = strlen(word2);

  // allocate memory for merged string (+1 is to add null character)
  char *merged = malloc(sizeof(char) * (w1_len + w2_len + 1));

  int mer_len = 0;
  for (int idx = 0; idx < (w1_len + w2_len); idx++){
    if (idx < w1_len)
      merged[mer_len++] = word1[idx];

    if (idx < w2_len)
      merged[mer_len++] = word2[idx];
  }

  // adding null character to mark the end of string
  merged[mer_len] = '\0';

  return merged;
}
