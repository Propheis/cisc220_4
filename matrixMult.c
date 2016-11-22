# include <stdio.h>

int main(int argc, char *argv[]) {
  int[] matrix1Dimensions
      , matrix2Dimensions
      , matrix3Dimensions
      , resultDimensions;
  
  matrix1Dimensions = getMatrixDimensions(1);

  do {
    fputs("Dimensions mismatch", stderr);
    matrix2Dimensions = getMatrixDimensions(2);
  } while (canMultiply(matrix1Dimensions, matrix2Dimensions) == false)

  int[][] m1, m2, m3, result;

  m1 = getMatrix(1);
  m2 = getMatrix(2);

  printMatrix("Matrix 1:", m1);
  printMatrix("Matrix 2:", m2);

  result = matrixMult(m1, m2);

  printMatrix("Final output:", result);

  do {
    fputs("Dimensions mismatch", stderr);
    matrix3Dimensions = getMatrixDimensions(3);
  } while (canMultiply(resultDimensions, matrix3Dimensions) == false);

  int[][] finalMatrix = matrixMult(result, m3);

  printMatrix("m1 * m2 * m3", finalMatrix);

  return 0;
  
}
