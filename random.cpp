#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int* arr, int targetnumber, int sizearr);
void SelectionSort(int* arr, int sizearr);
void  arrayscrambler(int* arr, int sizearr);
void insertionSort(int* arr, int sizearr);
// void display(int* arr(), int sizearr);

int main(){
    int given_array[5]= {2,3,7,4,1};
    int target = 4;
    int size = 5;
    SelectionSort(given_array, size);
    int printer = BinarySearch(given_array, target, size);
    cout << "The search process was successful. The result is in "<<printer<<" index."<<endl;
    cout<< "Also the sorted array using selection sort is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<given_array[i];
    }
    cout<<endl;
    cout<<"Let's scramble the array and utilise insertion sort."<<endl;
    arrayscrambler(given_array, size);
    cout<<"The sorted array is "<<endl;
    insertionSort(given_array, size);
    for(int i=0; i<size; i++){
        cout<<given_array[i];
    }
    
    return 0;
}

int BinarySearch(int *arr, int targetnumber,int sizearr){
    int first= 0;
    int last = sizearr-1;
      while(first<=last){
        int mid = (first+(-first+last)/2);
            if(arr[mid] == targetnumber){
                return mid;
            }
            else if(arr[mid]<targetnumber){
                first = mid + 1;
            }
            else if(arr[mid]>targetnumber){
                last = mid-1;
            }
      }
      return -1;
}
void SelectionSort(int* arr, int sizearr){
    int indexsmallest;
    int temp;
        for(int i=0; i<sizearr-1; i++){
            indexsmallest = i;
            for(int j=i+1; j<sizearr; ++j){
            if(arr[j]<arr[indexsmallest]){
                indexsmallest = j;
            }
        }
         temp = arr[i];
         arr[i] = arr[indexsmallest];
         arr[indexsmallest] = temp;
        }  
}

void insertionSort(int* arr, int sizearr){
   for(int i=0; i<sizearr; i++){
    int j=i;
    while(j>0 && arr[j]<arr[j-1]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        --j;
    }
   }
}

void arrayscrambler(int* arr, int sizearr){
    for(int i=0; i<sizearr; i++){
        random_device rd;
        int temp=0;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, sizearr-1);
        int random_number = dist(gen);
        arr[random_number]= temp;
        arr[random_number] = arr[i];
        arr[i] = temp;
        cout<<arr[i];
    }
}

// void display(int* arr()){
//     for(int i=0; i,)
// }



