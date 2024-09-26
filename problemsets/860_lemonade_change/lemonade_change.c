// problem: https://leetcode.com/problems/lemonade-change/
// time complexity  -> O(N)
// space complexity -> O(1)
bool lemonadeChange(int* bills, int billsSize) {
  // keep track of bills count
  int bills_5 = 0, bills_10 = 0;

  for (int i = 0; i < billsSize; i++) {
    switch (bills[i]) {
      case 5:
        bills_5++;
        break;
      
      case 10:
        if (bills_5 < 1) return false;
        bills_10++;
        bills_5--;
        break;
      
      case 20:
        // if we don't have 10$ bills, then we need 5 5$ bills
        if (bills_10 < 1) {
          if (bills_5 < 3) return false;
          bills_5 -= 3;
        }
        else {
          if (bills_5 < 1) return false;
          bills_5--;
          bills_10--;
        }
    }
  }
  return true;
    
}
