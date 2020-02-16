#include <iostream>
#include <string>
using namespace std;

const int ROWS = 4, COLS = 5;

//Comment
int getTotal (int arr[ROWS][COLS]) {
  int sum = 0;
  for (int r = 0; r < ROWS; r++)
    for (int c = 0; c < COLS; c++)
      sum += arr[r][c];
  return sum;
}

//Comment
double getAverage (int arr[ROWS][COLS]) {
  return static_cast<double>(getTotal(arr)) / ROWS / COLS; 
}

//Comment
int getRowTotal (int arr[ROWS][COLS], int r) {
  int sum = 0;
  for (int c = 0; c < COLS; c++)
    sum += arr[r][c];
  return sum;
}

//Comment
int getHighestInRow (int arr[ROWS][COLS], int r) {
  int max = arr[r][0];
  for (int c = 1; c < COLS; c++)
    if (arr[r][c] > max)
      max = arr[r][c];
  return max;
}

//Comment
int getLowestInRow (int arr[ROWS][COLS], int r) {
  int min = arr[r][0];
  for (int c = 1; c < COLS; c++)
    if (arr[r][c] < min)
      min = arr[r][c];
  return min;
}

//Comment
int main () {
  int testArr[ROWS][COLS] = {{1, 2, 3, 4, 5}, 
                            {6, 7, 8, 9, 10}, 
                            {11, 12, 13, 14, 15}, 
                            {16, 17, 18, 19, 20}};
  cout << "Total of array: " << getTotal(testArr) << endl;
  cout << "Average of array: " << getAverage(testArr) << endl;
  cout << "Total of row0: " << getRowTotal(testArr, 0) << endl;
  cout << "Highest of row2: " << getHighestInRow(testArr, 2) << endl;
  cout << "Lowest of row2: " << getLowestInRow(testArr, 2) << endl;
  return 0;
}