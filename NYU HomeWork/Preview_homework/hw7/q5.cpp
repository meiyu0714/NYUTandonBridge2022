#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void switch_number(int& a, int& b);
int main()
{
    int a[6] = {3, -1, -3, 0, 6, 4};
    int PosArrSize1;
    int *p1;
    p1 = getPosNums1(a, 6, PosArrSize1);
    cout<<"section 1"<<endl;
    cout<<"PosArrSize: "<<PosArrSize1<<endl;
    cout<<"positive numbers are: ";
    for(int i = 0; i < PosArrSize1; i++){
        cout<<p1[i]<<" ";
    }
    delete [] p1;

    int *p2;
    int PosArrSize2;
    getPosNums2(a, 6, p2, PosArrSize2);
    cout<<endl;
    cout<<"section 2"<<endl;
    cout<<"PosArrSize: "<<PosArrSize2<<endl;
    cout<<"Positive numbers are: ";
    for(int i = 0; i< PosArrSize2; i++){
        cout<<p2[i]<<" ";
    }
    delete [] p2;

    int PosArrSize3;
    int *p3;
    p3 = getPosNums3(a, 6, &PosArrSize3);
    cout<<endl;
    cout<<"section 3"<<endl;
    cout<<"PosArrSize: "<<PosArrSize3<<endl;
    cout<<"positive numbers are: ";
    for(int i = 0; i < PosArrSize3; i++){
        cout<<p3[i]<<" ";
    }
    delete [] p3;

    int *p4;
    int PosArrSize4;
    getPosNums4(a, 6, &p4, &PosArrSize4);
    cout<<endl;
    cout<<"section 4"<<endl;
    cout<<"PosArrSize: "<<PosArrSize4<<endl;
    cout<<"Positive numbers are: ";
    for(int i = 0; i< PosArrSize4; i++){
        cout<<p4[i]<<" ";
    }
    delete [] p4;

    return 0;
}
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    outPosArrSize = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            switch_number(arr[i], arr[outPosArrSize]);
            outPosArrSize ++;
        }
    } 
    //count = how many positive numbers here. 
    //count -1 = index of the last positive number
    int *p;
    p = new int [outPosArrSize];
    for(int i = 0; i < outPosArrSize ; i++){
        p[i] = arr[i];
    }
    return p;
    
}
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
   int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            switch_number(arr[i], arr[count]);
            count ++;
        }
    } 
    outPosArrSize = count;
    outPosArr = new int [count];
    for(int i = 0; i < count ; i++){
        outPosArr[i] = arr[i];
    }
}
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr){
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            switch_number(arr[i], arr[count]);
            count ++;
        }
    } 
    *outPosArrSizePtr = count;

    int *p;
    p = new int [count];
    for(int i = 0; i < count ; i++){
        p[i] = arr[i];
    }
    return p;   
}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            switch_number(arr[i], arr[count]);
            count ++;
        }
    } 
    *outPosArrSizePtr = count;
    
    int *outPosArr = new int [count];
    for(int i = 0; i < count ; i++){
        outPosArr[i] = arr[i];
    }
    *outPosArrPtr = outPosArr; 
}
void switch_number(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}