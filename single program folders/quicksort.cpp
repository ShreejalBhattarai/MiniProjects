#include<iostream>
#include<vector>
#include<string>
using namespace std;

int partition(vector<int> arr, int start, int end) {
    int index = start - 1;
    int pivot = arr[end];

    for (int j=start; j<end; j++) {
        if (arr[j]<pivot){
            index ++;
            swap(arr[j], arr[index]);
        }
    }
        index++;
        swap(arr[end],arr[index]);
    return index;
}

void quicksort(vector<int> arr, int start, int end) {
    if(start<end) {
        int pivotindex = partition(arr, start, end);
        quicksort(arr, start, pivotindex-1);
        quicksort(arr, pivotindex+1, end);
    }
}

int main(){
    vector<int> given_array = {2,3,5,6,1,2,10,0,-5};
    quicksort(given_array, 0, given_array.size()-1);
    for(int i=0; i<given_array.size(); i++){
        cout<<given_array[i]<<" ";
    }
    cout<<"\n";
    return 0;
}