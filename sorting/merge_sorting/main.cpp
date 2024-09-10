#include <iostream>
#include <windows.h>
using namespace std;

// Function to merge the sub-arrays.
void merge(int * arr, int low, int mid, int high) {
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;
    // Creating two temp arrays to store left and right sub-arrays.
    int arrLeft[lengthLeft], arrRight[lengthRight];

    // Copying the data from the actual array to left and right temp arrays.
    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = arr[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = arr[mid + 1 + a];
    }

    // Merging the temp arrays back into the actual array.
    i = 0; // Starting index of arrLeft[].
    j = 0; // Staring index of arrRight[].
    k = low; // Starting index of merged subarray.
    while (i < lengthLeft && j < lengthRight) {
        // Checking and placing the smaller number of
        // both temp arrays into the main array.
        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }
    // After the successful execution of the above loop
    // copying the remaining elements of the left subarray (if remaining).
    while (i < lengthLeft) {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }
    // Copying the remaining elements of the right sub array (if remaining).
    while (j < lengthRight) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}


void merge_sort(int* arr, int size){
    for (int i = 1; i <= size - 1; i = 2 * i) {
        for (int j = 0; j < size - 1; j += 2 * i) {
            int mid = min(j + i - 1, size - 1);
            int high = min(j + 2 * i - 1, size - 1);
            merge(arr, j, mid, high);
        }
    }
}

// Function to print the array.
void printArray(int * arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}


int main() {
//    cout << "Hello World!" << endl;
    setlocale(LC_ALL, "ru-RU");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int arr1[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27,
                28, 89, 2, 25, 74};
    int arr3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59,
                0, 7, 59, 90, 84, 60, 95, 62};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Исходный массив:        ";
    printArray(arr1, size1);
    merge_sort(arr1, size1);
    cout << "Отсортированный массив: ";
    printArray(arr1, size1);
    cout << endl;


    cout << "Исходный массив:        ";
    printArray(arr2, size2);
    merge_sort(arr2, size2);
    cout << "Отсортированный массив: ";
    printArray(arr2, size2);
    cout << endl;


    cout << "Исходный массив:        ";
    printArray(arr3, size3);
    merge_sort(arr3, size3);
    cout << "Отсортированный массив: ";
    printArray(arr3, size3);
    cout << endl;

    return 0;
}
