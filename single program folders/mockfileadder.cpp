// File Name: main.cpp
// Author: Shreejal Bhattarai
// Collaborators: None
// Date: 9/10/2024
// Assignment Number: 1
// CS 2308 Fall 2024
//
// (This is a program that asks user to select one folder from a list of folders
//  and lets them to add files to them(Mock files as it just adds the file size.)




#include<iostream>
#include<iomanip>
using namespace std;

const int FOLDER_SIZE = 10;

struct Folder{
    string name;
    int quantity;
    double size;

};

// Function Prototypes
int totalFiles(Folder folderarray[]);
void showFolders(Folder folderarray[]);
int largestSize(Folder folderarray[]);
void addFile(Folder folderarray[], int folderIndex, double toaddsize);


int main(){

//The instance of Struct Folder
Folder FolderInstance[FOLDER_SIZE];
 
//Definiton of default values
string FolderNames[FOLDER_SIZE] = {"Documents", "Downloads", "Pictures", "Videos", "Projects", "Labs", "Music", "Favorites", "Contacts", "Miscellaneous"};
int NumFiles[FOLDER_SIZE] = {5,11,27,6,3,6,45,4,35,1};
double size[FOLDER_SIZE] = {12.38, 17.22, 30.26, 22.75, 7.94, 1.44, 102.73, 2.10, 3.51, 2.23};


//Assigning all the values to structure methods
for(int i=0; i<FOLDER_SIZE; i++){
 FolderInstance[i].name = FolderNames[i]; 
 FolderInstance[i].quantity = NumFiles[i];
 FolderInstance[i].size = size[i];

}
double toaddsize;
int userchoice;

do{
showFolders(FolderInstance);

cout<<"Enter the folder number (0 to quit):"<<endl;
cin>>userchoice;

if( userchoice != 0 ){ 
cout<<"Enter the file size:"<<endl;
cin>>toaddsize;

if(userchoice>FOLDER_SIZE){
    cout<<"Invalid folder number"<<endl;
}

addFile (FolderInstance, userchoice, toaddsize); 
}
else if(userchoice>FOLDER_SIZE){
    cout<<"Invalid folder number\n"<<endl;
}
}
while(userchoice !=0);
if(userchoice == 0){
cout<<"Total number of files: "<<totalFiles(FolderInstance)<<endl;
}

//Calling the function largestSize
int largestsizeval = largestSize(FolderInstance);
cout<<"Folder with the largest size value: "<< FolderNames[largestsizeval]<<endl;


return 0;

}

//***********************************************************
// function name: totalFiles ---> This function returns the total size of all the files in the folder.
//
// param-1 Folder folderarray[]
// returns: integer
//***********************************************************

int totalFiles(Folder folderarray[]){
int totalFilesize = 0;
for(int i=0; i<FOLDER_SIZE; i++){
totalFilesize = totalFilesize + folderarray[i].quantity;
}
return totalFilesize;
}

//***********************************************************
// function name: showFolders ---> Prints the folder, for the first prompt, and for subsequent prompt after it, uses loop.
// param-1 Folder folderarray[]
// returns: void
//***********************************************************

void showFolders(Folder folderarray[]){
cout << left << setw(3) << "N" << setw(15) << "Name" << setw(10) << "Num files" << setw(10) << "Size(Mb)" << setw(10) << "Average file size" << endl;
int N = 0;
cout<<fixed<<setprecision(2);
for(int i=0; i<FOLDER_SIZE; i++){
    N++;
    cout<< left << setw(3) <<  N << setw(15) << folderarray[i].name << setw(10) << folderarray[i].quantity << setw(10) << folderarray[i].size <<setw(10)<<(folderarray[i].size)/(folderarray[i].quantity) <<endl;
}
}

//***********************************************************
// function name: largestSize ---->loops through all folders to find the folder with the largest size.
// param-1 Folder folderarray[]
// returns: maxIndex(The index for the folder with maximum size)
//***********************************************************

int largestSize(Folder folderarray[]){
    double maxsize = folderarray[0].size;
    int maxIndex = 0;
 for(int i=1; i<FOLDER_SIZE; i++){
    if(folderarray[i].size>maxsize){
        maxsize = folderarray[i].size;
        maxIndex = i;
    }
 }
 return maxIndex;
}

//***********************************************************
// function name: addFile ----> the main part of the program, adds size to the designated folder.
// param-1 Folder folderarray[]
// param-2 folderIndex
// param-3 toaddsize
// returns: void
//***********************************************************

void addFile(Folder folderarray[], int folderIndex, double toaddsize){
    folderarray[folderIndex-1].size += toaddsize;  // Update the size
    folderarray[folderIndex-1].quantity += 1;
}

