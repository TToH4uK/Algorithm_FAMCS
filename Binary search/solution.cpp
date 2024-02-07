#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int x, int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int k = (l + r) / 2;
        if (x == arr[k]) {
            return true;
        }
        else if (x < arr[k]) {
            r = k;
        }
        else if (x > arr[k]) {
            l = k + 1;
        }
    }
    return false;
}



int ForLeft(int arr[], int x, int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int k = (l + r) / 2;
        if (x <= arr[k]) {
            r = k;
        }
        else if (x > arr[k]) {
            l = k + 1;
        }
    }
    return l;
}



int ForRight(int arr[], int x, int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int k = (l + r) / 2;
        if (x < arr[k]) {
            r = k;
        }
        else if (x >= arr[k]) {
            l = k + 1;
        }
    }
    return l;
}
int main()
{
    int NumberOfArray1;
    cin >> NumberOfArray1;
    int* arr = new int[NumberOfArray1];
    for (int i = 0; i < NumberOfArray1; i++)
    {
        cin >> arr[i];
    }


    int NumberOfArray2;
    cin >> NumberOfArray2;
    int* arr1 = new int[NumberOfArray2];
    for (int j = 0; j < NumberOfArray2; j++)
    {
        cin >> arr1[j];
    }


    for (int j = 0; j < NumberOfArray2; j++) {
        if (BinarySearch(arr, arr1[j], NumberOfArray1) == true) {
            cout << "1" << " " << ForLeft(arr, arr1[j], NumberOfArray1) << " " << ForRight(arr, arr1[j], NumberOfArray1) << endl;

        }
        else cout << "0" << " " << ForLeft(arr, arr1[j], NumberOfArray1) << " " << ForRight(arr, arr1[j], NumberOfArray1) << endl;
    }
}
