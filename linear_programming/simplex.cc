#include <vector>
#include <iostream>

/**
 * @brief perform pivot 
 * express variable in pivot row and pivot column and substitute to other rows
 * ..this means value on pivot row and col is 1
 * whole pivot col is zeroed out
 * whole pivot row is scaled by value in pivot col
 * rest is adjusted by subtituting pivot variable into other row
 *
 * @param pivot_row pivot row 
 * @param pivot_column pivot column
 * @param a_matrix matrix to pivot
 */
void Pivot(int pivot_row, int pivot_column, std::vector<std::vector<float>> * a_matrix){
  int rows = a_matrix->size();
  int columns = (*a_matrix)[0].size();
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      std::cout << i << " " << j << std::endl;
      if (j != pivot_column && i != pivot_row){
        (*a_matrix)[i][j] -= (*a_matrix)[pivot_row][j]
          * (*a_matrix)[i][pivot_column]
           / (*a_matrix)[pivot_row][pivot_column];
      }
    }
  }

  for (int i = 0; i < rows; i++){
    if (i != pivot_row)
      (*a_matrix)[i][pivot_column] = 0.0;
  }

  for (int j = 0; j < columns; j++){
    if (j!= pivot_column)
      (*a_matrix)[pivot_row][j] /= (*a_matrix)[pivot_row][pivot_column];
  }
  (*a_matrix)[pivot_row][pivot_column] = 1.0;
}



/**
 * @brief find pivot column
 *
 * @param a_matrix simplex matrix
 *
 * @return index of pivot column
 */
int Bland(const std::vector<std::vector<float>> & a_matrix){
  int rows = a_matrix.size();
  int columns = a_matrix[0].size();

  for(int i = 0; i < columns; i++){
    if (a_matrix[rows - 1][i] > 0)
      return i;
  }
  return -1;
}

/**
 * @brief get pivot row
 *
 * @param a_matrix simplex matrix
 * @param pivot_column computed pivot column
 *
 * @return pivot row
 */
int PivotRow(const std::vector<std::vector<float>> & a_matrix, int pivot_column){
  int rows = a_matrix.size();
  int columns = a_matrix[0].size();
  float ratio = -1;
  int pivot_row = 0;

  for (int i = 0; i < rows-1; i++){
    if (a_matrix[i][pivot_column] <= 0)
      continue;
    float r = a_matrix[i][columns - 1] / a_matrix[i][pivot_column];
    if (ratio < 0 || r < ratio){
      ratio = r;
      pivot_row = i;
    }
  }
  return pivot_row;
}


/**
 * @brief use simplex algo to solve linear programming problem
 * example:
 * maximize 13A + 23B
 * under constraints that
 * 5A + 15B <= 480
 * 4A + 4B <= 160
 * 35A + 23B <= 1190
 * can be expressed as:
 * simplex_matrix = [[5, 15, 1, 0, 0, 480],
 *                   [4,  4,  0, 1, 0, 160],
 *                   [35, 20, 0, 0, 1, 1190],
 *                   [13, 23, 0, 0, 0, 0]]
 * results in:
 *                  [0.0, 0.0, 1.5, -10.625, 1, 210]
 *                  [0.0, 1.0, 0.1, -0.125, 0.0, 28.0] -> B = 28
 *                  [1.0, 0.0, -0.1, 0.375, 0.0, 12] -> A = 12
 *                  [0.0, 0.0, -1.0, -2.0, 0.0, -800.0] -> objective 800
 *
 * @param a_matrix simplex matrix
 */
void Simplex(std::vector<std::vector<float>> *a_matrix){
  int pivot_column = Bland(*a_matrix);
  while(pivot_column != -1){
    int pivot_row = PivotRow(*a_matrix, pivot_column);
    Pivot(pivot_row, pivot_column, a_matrix);
    pivot_column = Bland(*a_matrix);
    std::cout << pivot_column << std::endl;
    std::cout << pivot_row << std::endl;
    std::cout << (*a_matrix)[pivot_row][pivot_column] << std::endl;
  }
}

