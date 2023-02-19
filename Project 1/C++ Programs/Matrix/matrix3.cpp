#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Matrix{
    public:
        float **m;
        int r, c;

    public:

        Matrix() {
            r = 0;
            c = 0;
        }

        void initialize(int r, int c){

            m = new float*[r];

            this->r = r;
            this->c = c;

            for(int i = 0; i < r; i++){
                m[i] = new float[c];
            }
        }

        int getRow(){
            return r;
        }

        int getColumn(){
            return c;
        }

        friend Matrix operator + (const Matrix &matrix1, const Matrix &matrix2){
            Matrix result;
            result.initialize(matrix1.r, matrix1.c);
            for(int i = 0; i < matrix1.r; i++){
                for(int j = 0; j < matrix1.c; j++){
                    result.m[i][j] = matrix1.m[i][j] + matrix2.m[i][j];
                }
            }


            cout<<"The result of the addition is: "<<endl;
            for(int i = 0; i < matrix1.r; i++){
                for(int j = 0; j < matrix1.c; j++){
                    cout<<result.m[i][j]<<" ";
                }
            cout<<endl;
            }

            return result;
        }

        friend Matrix operator - (const Matrix &matrix1, const Matrix &matrix2){
            Matrix result;
            result.initialize(matrix1.r, matrix1.c);
            for(int i = 0; i < matrix1.r; i++){
                for(int j = 0; j < matrix1.c; j++){
                    result.m[i][j] = matrix1.m[i][j] - matrix2.m[i][j];
                    }
                }
            

            cout<<"The result of the subtraction is: "<<endl;
            for(int i = 0; i < matrix1.r; i++){
                for(int j = 0; j < matrix1.c; j++){
                    cout<<result.m[i][j]<<" ";
                }
            cout<<endl;
            }

            return result;

        }

        friend Matrix operator * (Matrix const &matrix1, Matrix const &matrix2){
            Matrix result;
            result.initialize(matrix1.r, matrix2.c);

            auto start = high_resolution_clock::now();

            for(int i = 0; i < matrix1.r; i++){
                for(int j = 0; j < matrix2.c; j++){
                    result.m[i][j] = 0;
                    for(int k = 0; k < matrix1.c; k++){
                    result.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
                    }
                }
            }
            
            auto stop = high_resolution_clock::now();

            cout<<"The result of the multiplication is: "<<endl;
            for(int i = 0; i < matrix1.r; i++){
                for(int j = 0; j < matrix2.c; j++){
                    cout<<result.m[i][j]<<" ";
                }
                cout<<endl;
            }

            auto duration = duration_cast<microseconds>(stop - start);
            cout<<"Time elapsed in microseconds: ";
            cout<<duration.count() << endl;

            return result;

        }

        


};

int main(){
    Matrix matrix1;
    Matrix matrix2;
    
    int exit = 0;
    int r1, c1, r2, c2, op;

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

    matrix1.initialize(r1,c1);
    matrix2.initialize(r2,c2);

    //getting matrix VALUES from user
    //Matrix 1
    cout<<"Enter the values of Matrix 1: "<<endl;
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cin>>matrix1.m[i][j];
        }
    }
    //Matrix 2
    cout<<"Enter the values of Matrix 2: "<<endl;
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            cin>>matrix2.m[i][j];
        }
    }


    while(exit == 0){
        cout<<"Choose an operation to perform:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Add new matrices\n5.Exit\n";
        cin>>op;

        switch(op){
            case 1:
                    if(r1 == r2 && c1 == c2){
                        matrix1 + matrix2;
                    }else{
                        cout<<"Matrix Addition can't be performed on matrices of different sizes\n";
                    }   break;
                case 2:
                    if(r1 == r2 && c1 == c2){
                        matrix1 - matrix2;
                    }else{
                        cout<<"Matrix Subtraction can't be performed on matrices of different sizes\n";
                    }   break;
                case 3:
                    if(c1 == r2 ){
                        matrix1 * matrix2;
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

                    matrix1.initialize(r1,c1);
                    matrix2.initialize(r2,c2);

                    //getting matrix VALUES from user
                    //Matrix 1
                    cout<<"Enter the values of Matrix 1: "<<endl;
                    for(int i = 0; i < r1; i++){
                        for(int j = 0; j < c1; j++){
                            cin>>matrix1.m[i][j];
                        }
                    }
                    //Matrix 2
                    cout<<"Enter the values of Matrix 2: "<<endl;
                    for(int i = 0; i < r2; i++){
                        for(int j = 0; j < c2; j++){
                            cin>>matrix2.m[i][j];
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
