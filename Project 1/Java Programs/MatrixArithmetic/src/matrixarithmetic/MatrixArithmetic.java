/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matrixarithmetic;

import java.util.Scanner;

/**
 *
 * @author miche
 */
public class MatrixArithmetic {

    public static float[][] matrixAddition( float[][] m1, float[][] m2){
        float[][] result = new float[m1.length][m1[0].length];
        for(int i = 0; i < m1.length; i++){
            for(int j = 0; j < m1[0].length; j++){
                result[i][j] = m1[i][j] + m2[i][j];
            }
        }
       displayResultantMatrix(result);
       return result; 
    }
    
    public static float[][] matrixSubtraction( float[][] m1, float[][] m2){
        float[][] result = new float[m1.length][m1[0].length];
        for(int i = 0; i < m1.length; i++){
            for(int j = 0; j < m1[0].length; j++){
                result[i][j] = m1[i][j] - m2[i][j];
            }
        }
       displayResultantMatrix(result);
       return result; 
    }
    
    public static float[][] matrixMultiplication( float[][] m1, float[][] m2){
        float[][] result = new float[m1.length][m2[0].length];
        long start = System.nanoTime();
        for(int i = 0; i < m1.length; i++){
            for(int j = 0; j < m2[0].length; j++){
                for(int k = 0; k < m1[0].length; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
          }
        }
        long end = System.nanoTime();
       displayResultantMatrix(result);
       getElapsedTime(start, end);
       return result; 
    }
    
    public static void displayResultantMatrix(float[][] result) {
        System.out.println("The result is: ");
        for(float[] r : result) {
            for (float c : r) {
                System.out.print(c + "    ");
            }
            System.out.println();
        }
    }
    
    public static void getElapsedTime(long start, long end){
        System.out.println("Elapsed Time (nano seconds): "+ (end-start));
    }
    
    //-------------------------------------------MAIN--------------------------------------------------
    public static void main(String[] args) {
     
        Scanner s = new Scanner(System.in);
	int exit = 0;
        
        int i, j, r1, c1, r2, c2;
        System.out.print("\n Enter the size of Matrix 1 (3x3 --> 3 3): ");
        r1 = s.nextInt();
        c1 = s.nextInt();

        System.out.print("\n Enter the size of Matrix 2 (3x3 --> 3 3): ");
        r2 = s.nextInt();
        c2 = s.nextInt();

        //create two 2d arrays with size specified by user
        float[][] matrix1 = new float[r1][c1];
        float[][] matrix2 = new float[r2][c2];

        //get first matrix from user
        System.out.println("\n Enter the values of Matrix 1: ");
                for(i = 0; i < r1; i++) {
                        for(j = 0; j < c1; j++) {
                                matrix1[i][j] = s.nextInt();
                        }
                }
        //get second matrix from user
        System.out.println("\n Enter the values of Matrix 2: ");
                for(i = 0; i < r2; i++) {
                        for(j = 0; j < c2; j++) {
                                matrix2[i][j] = s.nextInt();
                        }		
                }
        
        while(exit==0){
                
            //ask what operation the user wants done
            System.out.println("\n Choose an operation to perform:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Add new matrices\n5.Exit");
            int op = s.nextInt();

            switch (op) {
                case 1:
                    if(matrix1.length == matrix2.length && matrix1[0].length == matrix2[0].length){
                        matrixAddition(matrix1, matrix2);
                    }else{
                        System.out.println("Matrix Addition can't be performed on matrices of different sizes");
                    }   break;
                case 2:
                    if(matrix1.length == matrix2.length && matrix1[0].length == matrix2[0].length){
                        matrixSubtraction(matrix1, matrix2);
                    }else{
                        System.out.println("Matrix Subtraction can't be performed on matrices of different sizes");
                    }   break;
                case 3:
                    if(matrix1[0].length == matrix2.length ){
                        matrixMultiplication(matrix1, matrix2);
                    }else{
                        System.out.println("Matrix multiplication can't be performed on the given matrices. Matrix 1 columns must equal Matrix 2 rows");
                    }   break;
                case 4:
                    System.out.print("\n Enter the size of Matrix 1 (3x3 --> 3 3): ");
                    r1 = s.nextInt();
                    c1 = s.nextInt();
                    System.out.print("\n Enter the size of Matrix 2 (3x3 --> 3 3): ");
                    r2 = s.nextInt();
                    c2 = s.nextInt();
                    //create two 2d arrays with size specified by user
                    matrix1 = new float[r1][c1];
                    matrix2 = new float[r2][c2];
                    //get first matrix from user
                    System.out.println("\n Enter the values of Matrix 1: ");
                    for(i = 0; i < r1; i++) {
                        for(j = 0; j < c1; j++) {
                            matrix1[i][j] = s.nextInt();
                        }
                    }
                    //get second matrix from user
                    System.out.println("\n Enter the values of Matrix 2: ");
                    for(i = 0; i < r2; i++) {
                        for(j = 0; j < c2; j++) {
                            matrix2[i][j] = s.nextInt();		
                        }
                    }
                    break;
                case 5:
                    exit=1;
                    break;
                default:
                    System.out.println("Please enter a valid operation number\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Add new matrices\n5.Exit");
                    break;
            }
        }
        
    }
    
    
    
    
}
