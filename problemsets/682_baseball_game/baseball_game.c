// problem:
// time complexity  -> O(N)
// space complexity -> O(N)    ; due to usage of score array
int calPoints(char** operations, int operationsSize) {
  // Array to hold the scores and initializing it to zero
  int *score = malloc(operationsSize * sizeof(int));
  for (int i = 0; i < operationsSize; i++) score[i] = 0;

  int idx = 0;
  for (int ops = 0; ops < operationsSize; ops++) {
    if (strcmp(operations[ops], "+") == 0) {
      score[idx++] = score[idx - 1] + score[idx -2];
    }
    else if (strcmp(operations[ops], "D") == 0) {
      score[idx++] = 2 * score[idx - 1];
    }
    else if (strcmp(operations[ops], "C") == 0) {
      score[--idx] = 0;
    }
    else
      score[idx++] = atoi(operations[ops]);
  }

  // calculate the sum
  int sscore = 0;
  for (int i = 0; i < operationsSize; i++) sscore += score[i];

  return sscore;
}
