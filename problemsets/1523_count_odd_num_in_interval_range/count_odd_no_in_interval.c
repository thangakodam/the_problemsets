// problem: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?
// time complexity  -> O(1)
// space complexity -> O(1)
int countOdds(int low, int high){
  // no of elements b/w low and high is high - low
  // out of which half of them will be odd and other half will be even num
  int count = (high - low) / 2;

  // if either any of the boundry value is odd, then include it too
  if (low % 2 != 0 || high % 2 != 0) count++;

  return count;
}
