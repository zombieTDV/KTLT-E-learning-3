#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

const int n_rows = 3;
const int n_cols = 3;

void input_2D_array(int array[n_rows][n_cols]);
void output_2D_array(int array_2D[n_rows][n_cols]);
void main_diagonal(int array[n_rows][n_cols]);
int marginal_sum(int array[n_rows][n_cols]);

void input_2D_array(int array[n_rows][n_cols]){
    cout << "Nhập dữ liệu cho mảng 2 chiều " << n_rows << 'x' << n_cols << '\n';
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            cout << "array[" << i << "][" << j << "]: "; cin >> array[i][j];

        }
    }
}

void output_2D_array(int array_2D[n_rows][n_cols]){
    cout << "Dữ liệu của mảng 2 chiều: " << n_rows << 'x' << n_cols << '\n';
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            cout << "array[" << i << "][" << j << "]: " << array_2D[i][j] << '\n';

        }
    }
}

void main_diagonal(int array[n_rows][n_cols]){
    cout << "Các phần tử nằm trên đường chéo chính: ";
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            if (i == j){
                cout << array[i][j] << " ";
            }
        }
    }
}

int marginal_sum(int array[n_rows][n_cols]){
    int sum = 0;
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            if (i == 0 || i == n_rows - 1){
                sum += array[i][j];
            }
            else if (j == 0 || j == n_cols - 1){
                sum += array[i][j];
            }
        }
    }
    return sum;
}

int main(){
    int A[n_rows][n_cols];
    input_2D_array(A);

    cout <<'\n';
    output_2D_array(A);
    cout << '\n';
    main_diagonal(A);
    cout << '\n';
    cout << "Tổng các phần tử nằm trên ở 4 viền ngoài cùng: " << marginal_sum(A); 
    return 0;
}