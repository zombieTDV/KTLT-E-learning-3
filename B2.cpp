#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

void output_array(int array[], int size);
void array_merge(int A[], int B[], int C[], int sizeA, int sizeB, int sizeC);

void output_array(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << "Dữ liệu của A[" << i << "]" << array[i] << '\n';
    }
}

void array_merge(int A[], int B[], int C[], int sizeA, int sizeB, int sizeC){
    int cur_index_A = 0;
    int cur_index_B = 0;
    for (int i = 0; i < sizeC; i++){
        if (A[cur_index_A] < B[cur_index_B]){
            C[i] = A[cur_index_A];
            cur_index_A += 1;
        }
        else {
            C[i] = B[cur_index_B];
            cur_index_B += 1;
        }
    }
}
int main(){
    int A[3] = {1, 3, 5};
    int B[3] = {0, 2, 6};
    int C[6];

    array_merge(A, B, C, 3, 3, 6);
    output_array(C, 6);
    return 0;
}