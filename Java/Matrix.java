/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hacktoberfest;

/**
 *
 * @author vuvie
 */
public class Matrix {
    private int [][] matrix;
    private int width = 0;
    private int height = 0;

    public int[][] getMatrix() {
        return matrix;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }
    
    public Matrix(){
        
    }
    
    public Matrix(int width, int height){
        this.width = width;
        this.height = height;
        this.matrix = new int[width][height];
    }
    
    private  void setMatrixSize(int m, int n){
        this.width = m;
        this.height = n;
        this.matrix = new int[m][n];
    }
    
    private void setMatrixCell(int i, int x, int y) {
        matrix[x][y] = i;
    }
    
    private void setMatrixRow(int [] row, int x) {
        System.arraycopy(row, 0, matrix[x], 0, row.length);
    }
    
    private void setMatrixColumn(int [] column, int y) {
        for (int i = 0; i < column.length; i++) {
            matrix[i][y] = column[i];
        }
    }
    
    public Matrix add(Matrix matrix2) {
        if(matrix2.getHeight() != height || matrix2.getWidth() != width) {
            System.out.println("Can not add 2 matrix with diffirent size");
            return null;
        }
        
        Matrix resultMatrix = new Matrix(width, height);
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                // c[i][j] = a[i][j] + b[i][j]
                resultMatrix.getMatrix()[i][j] = this.getMatrix()[i][j] 
                        + matrix2.getMatrix()[i][j];
            }
        }
        
        return resultMatrix;
    }
    
    public Matrix sub(Matrix matrix2) {
        if(matrix2.getHeight() != height || matrix2.getWidth() != width) {
            System.out.println("Can not sub 2 matrix with diffirent size");
            return null;
        }
        
        Matrix resultMatrix = new Matrix(width, height);
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                // c[i][j] = a[i][j] - b[i][j]
                resultMatrix.getMatrix()[i][j] = this.getMatrix()[i][j] 
                        - matrix2.getMatrix()[i][j];
            }
        }
        
        return resultMatrix;
    }
    
    public Matrix multiply(Matrix matrix2) {
        if(this.width != matrix2.getHeight()) {
            System.out.println("width of first matrix must match"
                    + " height of the second one");
            return null;
        }
        Matrix resultMatrix = new Matrix(height, matrix2.getWidth());
        
        for (int i = 0; i < resultMatrix.getWidth(); i++) {
            for (int j = 0; j < resultMatrix.getHeight(); j++) {
                int sum = 0;
                for (int k = 0; k < width; k++) {
                    sum += this.matrix[i][k] * matrix2.getMatrix()[k][i];
                }
                resultMatrix.getMatrix()[i][j] = sum;
            }
        }
        
        return resultMatrix;
    }
}
