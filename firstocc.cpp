#include 
using namespace std;

int findValueIndex(int arr[], int size, int i, int val) {
    if (i == size) {
        return -1;  // Return -1 to indicate that the value was not found in the array
    }

    if (arr[i] == val) {
        return i;  // Return the index if the value is found at this position
    }

    return findValueIndex(arr, size, i + 1, val);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int val;

    std::cout << "Enter the value to find: ";
    std::cin >> val;

    int index = findValueIndex(arr, size, 0, val);

    if (index != -1) {
        cout << "The value " << val << " is found at index " << index << "." << endl;
    } else {
        cout << "The value " << val << " is not in the array." << endl;
    }

    return 0;
}

