// problem: https://leetcode.com/problems/check-if-it-is-a-straight-line
// time complexity  -> O(N)
// space complexity -> O(1)
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
  // if one point, can't predict if it's straight or not
  if (coordinatesSize == 1) return false;

  // if two points, then it's a straight line
  if (coordinatesSize == 2) return true;

  // use two-point formula to identify straight line
  // consider three points of a straight line (p, q), (x1, y1), (x2, y2)
  // then their slopes must be equal
  // (y1 - q) / (x1 - p) == (y2 - y1) / (x2 - x1)
  // (y1 - q)(x2 - x1) == (y2 - y1)(x1 - p)

  int x1 = coordinates[0][0];
  int y1 = coordinates[0][1];

  // calculate (x2 - x1) & (y2 - y1)
  int dx = coordinates[1][0] - x1;
  int dy = coordinates[1][1] - y1;

  for (int point = 1; point < coordinatesSize; point++) {
    int p = coordinates[point][0];
    int q = coordinates[point][1];

    // if (y1 - q)(x2 - x1) != (y2 - y1)(x1 - p) then return
    if ((y1 - q) * dx != dy * (x1 - p))
      return false;
  }

  return true;
}
