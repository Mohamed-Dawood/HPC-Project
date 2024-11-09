#include <iostream>
#include <vector>

// Function to compare and swap elements if needed
void compareAndSwap(std::vector<int>& arr, int i, int j, bool ascending) {
    if (ascending == (arr[i] > arr[j])) {
        std::swap(arr[i], arr[j]);
    }
}

// Function to perform the bitonic merge
void bitonicMerge(std::vector<int>& arr, int low, int count, bool ascending) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; i++) {
            compareAndSwap(arr, i, i + k, ascending);
        }
        bitonicMerge(arr, low, k, ascending);
        bitonicMerge(arr, low + k, k, ascending);
    }
}

// Recursive function to generate a bitonic sequence and sort it
void bitonicSort(std::vector<int>& arr, int low, int count, bool ascending) {
    if (count > 1) {
        int k = count / 2;

        // Sort the first half in ascending order
        bitonicSort(arr, low, k, true);

        // Sort the second half in descending order
        bitonicSort(arr, low + k, k, false);

        // Merge the bitonic sequence
        bitonicMerge(arr, low, count, ascending);
    }
}

int main() {
    // Input array
    std::vector<int> arr = { 11, 29, 19, 41, 14, 26, 36, 6 };
    int n = arr.size();

    // Apply bitonic sort
    bitonicSort(arr, 0, n, true);

    // Output the sorted array
    std::cout << "Sorted Array: [";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
