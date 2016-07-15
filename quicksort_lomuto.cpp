#include "iostream"
using namespace std;

int DoPartitionGetIndexOfPivotEle(int array[], int ibegin, int iend) {

  // Goal: Find   iPivot, return it
  //
  //  ibegin      iPivot       iend
  //        lesser      greater
  //
  //  SubGoal I:   all eles before iPivot index should be lesser or equal   than ele at iPivot
  //  SubGoal II:  all eles after  iPivot index should be greater          than ele at iPivot

  // Initially, let the Pivot be last element
  int Pivot = array[iend];

  // iPivot points to first element
  //    Finally will take the Pivot element's index
  int iPivot = ibegin;

  // for all elements expcept last ele
  for (int i = ibegin; i < iend; i++) {

    // if ele at i is less than Pivot (last ele)
    //    swap iPivot(starts from begin) element with i, and move iPivot ahead
    // this way we ensure elements before iPivot are lesser or equal (I: above)
    if (array[i] <= array[iend]) {

      // swap i with iPivot // no effect 1st time
      int temp = array[iPivot];
      array[iPivot] = array[i];
      array[i] = temp;

      iPivot++;
    }
  }

  // Now iPivot is somewhere in the middle
  //    i went till iend-1
  // And, elements before iPivot are lesser or equal
  //    => elements at & after iPivot are greater
  //
  // since i didnot touch last element at iend
  //    we did not compare iPivot to iend
  // => ele at iPivot is greater than Pivot at iend
  //  so swap iPivot & iend
  int temp = array[iPivot];
  array[iPivot] = array[iend];
  array[iend] = temp;

  // Now iPivot has Pivot value
  //  => iPivot has made required partition, eles before it are <=, eles after it are >
  // so return iPivot (since both SubGoal I && SubGoal II are satisfied)

  return iPivot;
}
void QuickSort(int array[], int ibegin, int iend) {
  if (ibegin <= iend) { // initially 0 to N-1
    int iPivot = DoPartitionGetIndexOfPivotEle(array, ibegin, iend); // get pivot position
    QuickSort(array, ibegin, iPivot - 1);  // call self, for before pivot position subarray
    QuickSort(array, iPivot + 1, iend);    // call self, for after  pivot position subarray
  }
}
void QuickSortLomuto() {
  int array[] = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 0 };
  int N = sizeof(array) / sizeof(array[0]); // count = size of all eles/ size of single ele

  int ibegin = 0;
  int iend = N - 1;

  QuickSort(array, ibegin, iend);  // send all elements

  // print sorted array
  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  // Output
  //    0 2 3 4 5 7 9 10 11 12 14
}

int main() {
  QuickSortLomuto();
  return 0;
}
