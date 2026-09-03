#include <iostream>
using namespace std;

// merge two sorted halves and count cross inversions
int mergeAndCount(int * arr, int left, int mid, int right) {
    // sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temp arrays to hold the data
    int * leftArr = new int[n1];
    int * rightArr = new int[n2];

    // copy data to temp arrays
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int inversions = 0;

    // the real magic happens here!
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            // if left guy > right guy, it's an inversion!
            // also, ALL remaining left guys are > right guy. Math is awesome.
            arr[k++] = rightArr[j++];
            inversions += (n1 - i);
        }
    }

    // grab any leftovers from left array
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    // grab any leftovers from right array
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    // clean up memory! always free what you new
    delete[] leftArr;
    delete[] rightArr;

    return inversions;
}

// recursive function - O(n log n) baby!
int countInversions(int * arr, int left, int right) {
    int inversions = 0;

    // base case: if left >= right, array has 1 element, 0 inversions
    if (left < right) {
        int mid = left + (right - left) / 2;

        // count inversions in left half
        inversions += countInversions(arr, left, mid);

        // count inversions in right half
        inversions += countInversions(arr, mid + 1, right);

        // count the split inversions while merging
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    // test case 1 from the exam
    int n = 8;
    int arr[8] = {3, 1, 4, 2, 3, 1, 4, 2};

    // arrays go from index 0 to n-1
    int totalInversions = countInversions(arr, 0, n - 1);

    cout << "Cantidad de inversiones: " << totalInversions << endl;

    return 0;
}