#include <iostream>
#include <vector>

int getMax(std::vector<int>& arr) {
    int maxElement = arr[0];
    for (int num : arr) {
        if (num > maxElement) {
            maxElement = num;
        }
    }
    return maxElement;
}

void countingSort(std::vector<int>& arr, int exp) {
    int size = arr.size();
    std::vector<int> output(size);
    int count[10] = {0};

    for (int i = 0; i < size; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int maxElement = getMax(arr);
    for (int exp = 1; maxElement / exp > 0; exp = exp * 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
    radixSort(arr);
    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
