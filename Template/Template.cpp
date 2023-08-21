#include <iostream>
#include <vector>
#include <cstdio>

// Template base class
class Sort {
public:
    virtual bool compare(int a, int b) = 0;
    void sort(int arr[], const unsigned &n) {
        for (unsigned i = 0; i < n - 1; i++) {
            unsigned min = i;
            for (unsigned j = i + 1; j < n; j++)
                if (compare(arr[j], arr[min]))
                    min = j;
            swap(&arr[min], &arr[i]);
        }
    }
private:
    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
};

class SortUp: public Sort {
public:
    bool compare(int a, int b) {
        return a < b;
    }
};

class SortDown: public Sort {
public:
    bool compare(int a, int b) {
        return a > b;
    }
};

void printArray(int array[], unsigned n) {
    for (unsigned i = 0; i < n; i++)
        printf("%i ", array[i]);
    printf("\n");
}

int main() {
    const int ARR_SIZE = 10;
    std::vector<Sort *> sorters = {new SortUp(), new SortDown()};
    int array[ARR_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        array[i] = rand() % 101;
    }
    printArray(array, 10);

    for (Sort *sorter : sorters) {
        sorter->sort(array, 10);
        printArray(array, 10);
    }
}