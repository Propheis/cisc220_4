# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAX_INPUT_LENGTH 50

// Parses a space delimited string of ints into an array of ints
void stringToIntArray(const char* str, int *intArr, int arrSize) {
  char *input = strdup(str);
  char *token;
  token = strtok(input, " ");
  int i = 0;
  while (token != NULL) {
    intArr[i] = atoi(token);
    token = strtok(NULL, " ");
    i++;
  }
}

// Prompts the user for the dimensions of a matrix
void getMatrixDimensions(int matrixNumber, int *dimensionX, int *dimensionY) {
  printf("Insert matrix %d dimensions separated by a space: ", matrixNumber);
  
  char input[MAX_INPUT_LENGTH];
  scanf("%s", &input);

  // Get the dimensions from stdin
  int data[3];
  stringToIntArray(input, data, 2);

  *dimensionX = data[0];
  *dimensionY = data[1];
}

// Takes a 2D dimension vector of each matrix and returns 0 if you can multiply safely
char canMultiply(int m1y, int m2x) {
  if (m1y == m2x)
    return 0;
  return 1;
}

// Returns a matrix. matrixNumber is printed into the prompt
void getMatrix(int matrixNumber, size_t num_rows, size_t num_cols, int *matrix) {
  printf("Input matrix %d elements separated by spaces:", matrixNumber);
  char input[MAX_INPUT_LENGTH];
  scanf("%s", &input);

  stringToIntArray(strdup(input), matrix, num_rows*num_cols);
}

// Prints the message, than the matrix in a nice format
void printMatrix(const char **message, int num_rows, int num_cols, int matrix[]) {
  printf("%s\n", *message);

  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++)
      printf("%d\t", matrix[ (i * num_cols) + j ]);
    printf("\n");
  }
  
  printf("\n");
}

// Perform a matrix multiplication
void matrixMult(int m1X, int m1Y, int m2X, int m2Y, int *m1, int *m2, int *mResult) {
  printf("%s\n", "Multiplication Result:");

  // By Rows
  for (int i = 0; i < m1X; i++) {
    // By Columns
    for (int j = 0; j < m2Y; j++) {
  
      int result;
      printf("%s [%d, %d] = ", "Element", i+1, j+1);
      
      // Multiply m1's row by m2's column
      for (int k = 0; k < m1Y; k++ ) {
        int m1Val = m1[ (i * m2X) + k ];
        int m2Val = m2[ (k * m2Y) + j ];
        
        if (k + 1 < m2X)
          printf("%d*%d + ", m1Val, m2Val);
        else
          printf("%d*%d ", m1Val, m2Val);

        result += m1Val * m2Val;
      }

      printf("= %d\n", result);
      mResult[ (i * m2Y) + j] = result;
      result = 0;
    } // end for j = 0 .. m2Y
  } // end for i = 0 .. m1X
  printf("\n");
}


int main(int argc, char const *argv[]) {
  const char* msg1 = "Matrix 1: ";
  const char* msg2 = "Matrix 2: ";
  const char* msg3 = "Final output: ";
  const char* msg4 = "M1 * M2 * M3: ";
  // Stores the dimensions of each of the matrices
  int m1x, m1y
    , m2x, m2y
    , m3x, m3y
    , resultx, resulty;

  getMatrixDimensions(1, &m1x, &m1y);

  printf("%d %d\n", m1x, m1y);

  // getMatrixDimensions(2, &m2x, &m2y);

  // while (canMultiply(m1y, m2x) != 0) {
  //   fputs("Dimensions mismatch\n", stderr);
  //   getMatrixDimensions(2, &m2x, &m2y);
  // }

  // // Initialize resultx and resulty
  // resultx = m1x;
  // resulty = m2y;

  // // // Initialize the matrices
  // int m1[m1x][m1y]
  // ,   m2[m2x][m2y]
  // ,   m3[m3x][m3y]
  // ,   result[resultx][resulty];

  // getMatrix(1, m1x, m1y, &m1);
  // getMatrix(2, m2x, m2y, &m2);

  // printMatrix("Matrix 1:",  m1x, m1y, &m1);
  // printMatrix("Matrix 2:",  m2x, m2y, &m2);

  // matrixMult(m1x, m1y, &m1, m2x, m2y, &m2, &result);

  // printMatrix("Final output:", result, resultx, resulty);

  // do {
  //   fputs("Dimensions mismatch", stderr);
  //   getMatrixDimensions(3, &m3x, &m3y);
  // } while (canMultiply(resulty, m3x) != 0);

  // getMatrix(3, m3);

  // int finalMatrix = matrixMult(result, m3);

  // printMatrix("m1 * m2 * m3", finalMatrix);

  // return 0;
}

// int main(int argc, char const *argv[])
// {
//   const char* msg1 = "Matrix 1: ";
//   const char* msg2 = "Matrix 2: ";
//   const char* msg3 = "Final output: ";
//   // 2x3 matrix
//   int m1[6] = { 1, 2, 3, 4, 5, 6 };
//   // 3x4 matrix
//   int m2[12] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120 };
  
//   printMatrix(&msg1, 2, 3, m1);
//   printMatrix(&msg2, 3, 4, m2);

//   int m3[2*4];
//   matrixMult(2, 3, 3, 4, m1, m2, m3);

//   printMatrix(&msg3, 2, 4, m3);

//   return 0;
// }