#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

float** matrixAddition(float matrix1[100][100], float matrix2[100][100], int r1, int c1, int r2, int c2){
    float** result;
    result = new float*[r1];
    for(int i = 0; i < r1; i++){
        result[i] = new float[c1];
        for(int j = 0; j < c1; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout<<"The result of the subtraction is: "<<endl;
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return result;
}

float** matrixSubtraction(float matrix1[100][100], float matrix2[100][100], int r1, int c1, int r2, int c2){
    float** result;
    result = new float*[r1];
    for(int i = 0; i < r1; i++){
        result[i] = new float[c1];
        for(int j = 0; j < c1; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

        cout<<"The result of the subtraction is: "<<endl;
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cout<<result[i][j]<<" ";
        }
    cout<<endl;
    }

    return result;
}

float** matrixMultiplication(float matrix1[100][100], float matrix2[100][100], int r1, int c1, int r2, int c2){
    float** result;
    result = new float*[r1];

    auto start = high_resolution_clock::now();

    for(int i = 0; i < r1; i++){
        result[i] = new float[c2];
        for(int j = 0; j < c2; j++){
            result[i][j] = 0;
            for(int k = 0; k < c1; k++){
            result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    auto stop = high_resolution_clock::now();

    cout<<"The result of the multiplication is: "<<endl;
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time elapsed in microseconds: ";
    cout<<duration.count() << endl;

    return result;
}

int main() {
    float matrix1[100][100], matrix2[100][100];

    int r1, c1, r2, c2, op;
    int exit = 0;

    //getting matrix SIZES from user
    //MAtrix 1
    cout<<"Enter the rows for Matrix 1: ";
    cin>>r1;
    cout<<"Enter the columns for Matrix 1: ";
    cin>>c1;
    //Matrix 2
    cout<<"Enter the rows for Matrix 2: ";
    cin>>r2;
    cout<<"Enter the columns for Matrix 2: ";
    cin>>c2;

    //getting matrix VALUES from user
    //Matrix 1
    cout<<"Enter the values of Matrix 1: "<<endl;
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cin>>matrix1[i][j];
        }
    }
    //Matrix 2
    cout<<"Enter the values of Matrix 2: "<<endl;
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            cin>>matrix2[i][j];
        }
    }

    while(exit == 0){
        cout<<"Choose an operation to perform:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Add new matrices\n5.Exit\n";
        cin>>op;

        switch(op){
            case 1:
                    if(r1 == r2 && c1 == c2){
                        matrixAddition(matrix1, matrix2, r1, c1, r2, c2);
                    }else{
                        cout<<"Matrix Addition can't be performed on matrices of different sizes\n";
                    }   break;
                case 2:
                    if(r1 == r2 && c1 == c2){
                        matrixSubtraction(matrix1, matrix2, r1, c1, r2, c2);
                    }else{
                        cout<<"Matrix Subtraction can't be performed on matrices of different sizes\n";
                    }   break;
                case 3:
                    if(c1 == r2 ){
                        matrixMultiplication(matrix1, matrix2, r1, c1, r2, c2);
                    }else{
                        cout<<"Matrix multiplication can't be performed on the given matrices. Matrix 1 columns must equal Matrix 2 rows\n";
                    }   break;
                case 4:
                    //getting matrix SIZES from user
                    //MAtrix 1
                    cout<<"Enter the rows for Matrix 1: ";
                    cin>>r1;
                    cout<<"Enter the columns for Matrix 1: ";
                    cin>>c1;
                    //Matrix 2
                    cout<<"Enter the rows for Matrix 2: ";
                    cin>>r2;
                    cout<<"Enter the columns for Matrix 2: ";
                    cin>>c2;

                    //getting matrix VALUES from user
                    //Matrix 1
                    cout<<"Enter the values of Matrix 1: "<<endl;
                    for(int i = 0; i < r1; i++){
                        for(int j = 0; j < c1; j++){
                            cin>>matrix1[i][j];
                        }
                    }
                    //Matrix 2
                    cout<<"Enter the values of Matrix 2: "<<endl;
                    for(int i = 0; i < r2; i++){
                        for(int j = 0; j < c2; j++){
                            cin>>matrix2[i][j];
                        }
                    }
                    break;
                case 5:
                    exit=1;
                    break;
                default:
                    cout<<"Please enter a valid operation number\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Add new matrices\n5.Exit\n";
                    break;
        }

    }
}
