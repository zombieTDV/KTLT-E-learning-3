#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

void input_array(int array[], int size);
void output_array(int array[], int size);
void swap(int &a, int &b);
void ascent_sort(int array[], int size);
void descent_sort(int array[], int size);
bool check_ascent_sort(int array[], int size);
bool check_descent_sort(int array[], int size);
void check_sorted(int array[], int size);
void half_ascent_half_descent(int array[], int size);
void max_value_distance_in_array(int array[], int size);

void input_array(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << "Nhập dữ liệu cho A[" << i << "]: ";
        cin >> array[i];
    }
}

void output_array(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << "Dữ liệu của A[" << i << "]" << array[i] << '\n';
    }
}

void swap(int &a, int &b){
    int dummy = a;
    a = b;
    b = dummy;
}

void ascent_sort(int array[], int size){
    for (int i = 0; i < (size-1); i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] > array[j]){
                swap(array[i], array[j]);
            }
        }}
}

void descent_sort(int array[], int size){
    for (int i = 0; i < (size-1); i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] < array[j]){
                swap(array[i], array[j]);
            }
        }}
}

bool check_ascent_sort(int array[], int size){
    for (int i = 0; i < (size-1); i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] > array[j]){
                return false;
            }
        }}
    return true;
}

bool check_descent_sort(int array[], int size){
    for (int i = 0; i < (size-1); i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] < array[j]){
                return false;
            }
        }}
    return true;
}

void check_sorted(int array[], int size){
    if (check_ascent_sort(array, size)){cout << "Mảng đã được sắp xếp theo thứ tự tăng dần!\n";}
    else if (check_descent_sort(array, size)){cout << "Mảng đã được sắp xếp theo thứ tự giảm dần!\n";}
    else {cout << "Mảng chưa được sắp xếp!\n";}
}

void half_ascent_half_descent(int array[], int size){
    bool mid = false;
    int size_of_half = 0;

    if (size % 2 == 0){
        size_of_half = size / 2;
        mid = false;
    }
    else {
        size_of_half = (size - 1) / 2;
        mid = true;
    }

    for (int i = 0; i < (size); i++){
        if (i < size_of_half){
            for (int j = i + 1; j < size_of_half; j++){
                if (array[i] > array[j]){
                    swap(array[i], array[j]);
                }
            }
        }
        else if(i <= 2 * size_of_half + mid && i != size_of_half){
            for (int j = i + 1; j < size; j++){
                if (array[i] < array[j]){
                    swap(array[i], array[j]);
                }
            }
        }
    }
}

void max_value_distance_in_array(int array[], int size) {
    int first_index = 0;
    int second_index = 0;
    int max_distance = 0;
    for (int i = 0; i < (size-1); i++) {
        for (int j = i + 1; j < size; j++) {
            int current_distance = abs(array[i] - array[j]);
            if (current_distance > max_distance) {
                max_distance = current_distance;
                first_index = i;
                second_index = j;
            }
        }
    }

    cout << "Khoảng cách giá trị lớn nhất chính là phần tử có giá trị là: " << array[first_index] << " và " << array[second_index] << " ở vị trí thứ " << first_index << " và " << second_index << '\n';
}

int main(){
    int n = 5;

    cout << "Nhập số phần tử(n) của dãy số nguyên A: "; cin >> n;

    while(n <= 0){
        cout << "n không phù hợp! \n";
        cout << "Nhập số phần tử(n) của dãy số nguyên A: "; cin >> n;
    }
    int A[n];

    input_array(A, n);
    
    cout << "\nKiểm tra thứ tự sắp xếp của mảng:\n";
    check_sorted(A, n);
    
    cout << "\nTìm khoảng cách giá trị lớn nhất trong mảng:\n";
    max_value_distance_in_array(A, n);
    
    cout << "\nSắp xếp mảng theo kiểu nửa tăng nửa giảm:\n";
    half_ascent_half_descent(A, n);
    output_array(A, n);
    

    return 0;
}