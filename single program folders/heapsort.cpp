#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void heapify(vector <int>& arr, int size, int root_index ) {
int largest = root_index;
int left_child = 2 * root_index + 1;
int right_child = 2 * root_index + 2;

if (largest<size && arr[left_child]>arr[largest]) {
   largest = left_child;
}

if (largest<size && arr[right_child]>arr[largest]) {
   largest = right_child;
}

if (root_index != largest) {
   swap(arr[root_index], arr[largest]);
   heapify(arr, size, largest);
}
}

void heapsort(vector <int>& arr) {
   int size = arr.size();
   for (int i = size/2 -1; i>= 0; i--) {
      heapify(arr, size, i);
   }
   for (int i = size-1; i<0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr,i,0);
   }
}

void printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {
   vector<int> arr = {9, 4, 3, 8, 10, 2, 5};
   heapsort(arr);
   printArray(arr);
}