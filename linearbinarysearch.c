// Online C compiler to run C program online
#include <stdio.h>

int linearSearch(int arr[], int size, int e) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int e) {
    int h = size -1, l = 0;
    int mid;
    while (l <= h) {
        mid = (h+l)/2;
        if (arr[mid] == e) {
            return mid;
        } else if (arr[mid] > e) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int e) {
    int mid = (low + high) / 2;
    if (low > high) {
        return -1;
    } else if (arr[mid] == e) {
        return mid;
    } else if (arr[mid] < e) {
       return recursiveBinarySearch(arr, mid + 1, high, e);
    } else {
       return recursiveBinarySearch(arr, low, mid - 1, e);
    }
}

int main() {
    int arr[] = {2,3,4,5,71,78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int e;
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("Enter element: ");
    scanf("%d", &e);
    // int ans = linearSearch(arr, size, e);
    int ans = recursiveBinarySearch(arr, 0, size-1, e);
    if (ans == -1) {
        printf("Not found.\n");
    } else {
        printf("%d was found at index %d.\n", e, ans);
    }
    return 0;
}