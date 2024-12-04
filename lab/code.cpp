#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Function to divide a matrix into submatrices
Matrix strassenMultiply(const Matrix &A, const Matrix &B);

// Function to split matrix into quadrants
void split(const Matrix &M, Matrix &A, Matrix &B, Matrix &C, Matrix &D) {
    int n = M.size() / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = M[i][j];
            B[i][j] = M[i][j + n];
            C[i][j] = M[i + n][j];
            D[i][j] = M[i + n][j + n];
        }
    }
}

// Function to join quadrants back into a matrix
void join(Matrix &C, const Matrix &A, const Matrix &B, const Matrix &C1, const Matrix &D) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j];
            C[i][j + n] = B[i][j];
            C[i + n][j] = C1[i][j];
            C[i + n][j + n] = D[i][j];
        }
    }
}

// Recursive Strassen's algorithm
Matrix strassenMultiply(const Matrix &A, const Matrix &B) {
    int n = A.size();

    // Base case when matrix size is 1x1
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Split matrices into quadrants
    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    // Compute the 7 products using the Strassen's formula
    Matrix M1 = strassenMultiply(add(A11, A22), add(B11, B22));
    Matrix M2 = strassenMultiply(add(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subtract(B12, B22));
    Matrix M4 = strassenMultiply(A22, subtract(B21, B11));
    Matrix M5 = strassenMultiply(add(A11, A12), B22);
    Matrix M6 = strassenMultiply(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassenMultiply(subtract(A12, A22), add(B21, B22));

    // Calculate the quadrants of the result matrix C
    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    // Join the quadrants into a single result matrix
    Matrix C(n, vector<int>(n));
    join(C, C11, C12, C21, C22);

    return C;
}

// print function to print the matrix
void printMatrix(const Matrix &M) {
    for (int i = 0; i < M.size(); ++i) {        
        for (int j = 0; j < M[i].size(); ++j) { 
            cout << M[i][j] << " ";
        }
        cout << endl;  
    }
}

int main() {
    // Sample matrices A and B of 4 x 4
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B = {
        {7, 8, 9, 2},
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 3, 1, 2}
    };

    Matrix C = strassenMultiply(A, B); // Calculating Resultant Matrix

    cout << "Resultant Matrix:" << endl;
    printMatrix(C);

    return 0;
}
