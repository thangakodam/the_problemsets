// problem: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
// time complexity  -> O(N)
// space complexity -> O(1)
double average(int* salary, int salarySize) {
  int max = salary[0], min = salary[0];
  double avg = 0;

  for (int emp = 0; emp < salarySize; emp++) {
    avg += salary[emp];

    // update the max and min
    max = salary[emp] > max ? salary[emp] : max;
    min = salary[emp] < min ? salary[emp] : min;
  }

  return (avg - max - min) / (salarySize - 2);   
}
