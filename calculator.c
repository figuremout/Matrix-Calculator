#include <stdio.h>
#include <stdlib.h>

void transposed_matrix(int row, int col, float matrix[row][col], float matrix_result[col][row]);
void into_row_echelon_form(int row, int col, float matrix[row][col]);
void into_reduced_row_echelon_form(int row, int col, float matrix[row][col]);
float det(int n,float a[][n]);
float tr(int dimension, float matrix[dimension][dimension]);
void matrix_multiplication(int row_left, int c_r, int col_right, float matrix_left[row_left][c_r], float matrix_right[c_r][col_right], float matrix_result[row_left][col_right]);
int rank_of_matrix(int row, int col, float matrix[row][col]);

int main()
{
    for (;;){
    printf("#MATRIX CALCULATOR#\n");
    printf("\n*******************\n");
    printf("0.矩阵转置\n");
    printf("1.化为行阶梯形矩阵\n");
    printf("2.化为行最简形矩阵\n");
    printf("3.计算行列式\n");
    printf("4.计算方阵的迹\n");
    printf("5.计算矩阵乘法\n");
    printf("6.计算矩阵的秩\n");
    printf("7.计算逆矩阵\n");
    printf("8.EXIT\n");
    printf("*******************\n");

    int command;
    printf("Enter your command: ");
    scanf("%d", &command);

    system("cls");

    switch (command){
    case 0: {
            int row, col;
            printf("#矩阵转置#\n");
            printf("\nEnter the row of the matrix: ");
            scanf("%d", &row);
            printf("Enter the column of the matrix: ");
            scanf("%d", &col);
            float matrix[row][col];
            float matrix_result[col][row];

            for (int r = 0; r < row; r++){
                printf("Row %d: ",r);
                for (int c = 0; c < col; c++){
                    scanf(" %f",&matrix[r][c]);
                }
            }

            transposed_matrix(row, col, matrix, matrix_result);

            printf("\nThe transposed matrix: \n");
            for (int i = 0; i < col; i++){
                for (int j = 0; j < row; j++){
                    printf("\t%g", matrix_result[i][j]);
                }
                printf("\n");
            }
    break;}
    case 1: {
            int row, col;
            printf("#化为行阶梯形矩阵#\n");
            printf("\nEnter the row of the matrix: ");
            scanf("%d", &row);
            printf("Enter the col of the matrix: ");
            scanf("%d", &col);

            float matrix[row][col];
            for (int r = 0; r < row; r++){
                printf("Row %d: ",r);
                for (int c = 0; c < col; c++){
                    scanf(" %f",&matrix[r][c]);
                }
            }

            into_row_echelon_form(row, col, matrix);
            printf("\nThe row echelon form: \n");
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    printf("\t%g", matrix[i][j]);
                }
                printf("\n");
            }
    break;}
    case 2: {
            int row, col;
            printf("#化为行最简形矩阵#\n");
            printf("\nEnter the row of the matrix: ");
            scanf("%d", &row);
            printf("Enter the col of the matrix: ");
            scanf("%d", &col);

            float matrix[row][col];
            for (int r = 0; r < row; r++){
                printf("Row %d: ",r);
                for (int c = 0; c < col; c++){
                    scanf(" %f",&matrix[r][c]);
                }
            }
            into_reduced_row_echelon_form(row, col, matrix);
            printf("\nThe reduced row echelon form: \n");
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    printf("\t%g", matrix[i][j]);
                }
                printf("\n");
            }
    break;}
    case 3: {
            int dimension;
            printf("#计算行列式#\n");
            printf("\nEnter the dimension of a matrix: ");
            scanf("%d",&dimension);

            float matrix[dimension][dimension];

            for (int row = 0;row <= dimension - 1;row++){
                printf("Row %d: ",row);
                for (int col = 0;col <= dimension - 1;col++){
                    scanf("%f",&matrix[row][col]);
                }
            }

            printf("\ndet() = %g\n\n",det(dimension,matrix));
    break;}
    case 4: {
            int dimension;
            printf("#计算方阵的迹#\n");
            printf("\nEnter the dimension of a matrix: ");
            scanf("%d",&dimension);
            float matrix[dimension][dimension];

            for (int row = 0;row < dimension; row++){
                printf("Row %d: ",row);
                for (int col = 0;col < dimension; col++){
                    scanf("%f",&matrix[row][col]);
                }
            }

            printf("\ntr() = %g\n", tr(dimension, matrix));
    break;}
    case 5: {
            int row_left, c_r, col_right;//c_r是两个矩阵共用的维数
            printf("#计算矩阵乘法#\n");
            printf("\nEnter the row of the left matrix: ");
            scanf("%d",&row_left);
            printf("Enter the column of the left matrix(the row of the right matrix): ");
            scanf("%d",&c_r);
            printf("Enter the column of the right matrix: ");
            scanf("%d",&col_right);
            printf("\n");
        //初始化左矩阵
            float matrix_left[row_left][c_r];
            //循环读入数组每一行元素
            for (int row = 0; row < row_left; row++){
                printf("Row %d of the left matrix: ",row);
                for (int col = 0; col < c_r; col++){
                    scanf(" %f",&matrix_left[row][col]);
                }
            }
            printf("\n");

        //初始化右矩阵
            float matrix_right[c_r][col_right];
            //循环读入数组每一行元素
            for (int row = 0; row < c_r; row++){
                printf("Row %d of the right matrix: ",row);
                for (int col = 0; col < col_right; col++){
                    scanf(" %f",&matrix_right[row][col]);
                }
            }

            float matrix_result[row_left][col_right];//定义结果矩阵
            //执行计算
            matrix_multiplication(row_left, c_r, col_right, matrix_left, matrix_right, matrix_result);
        //输出结果矩阵
            printf("\nThe result of multiplication: \n");
            for (int i = 0; i < row_left; i++){
                for (int j = 0; j < col_right; j++){
                    printf("\t%g", matrix_result[i][j]);
                }
                printf("\n");
            }
    break;}
    case 6: {
            int row, col;
            printf("#计算矩阵的秩#\n");
            printf("\nEnter the row of the matrix: ");

            scanf("%d", &row);
            printf("Enter the column of the matrix: ");
            scanf("%d", &col);
            float matrix[row][col];

            for (int r = 0; r < row; r++){
                printf("Row %d: ",r);
                for (int c = 0; c < col; c++){
                    scanf(" %f",&matrix[r][c]);
                }
            }
            printf("\nThe rank: %d\n", rank_of_matrix(row, col, matrix));
    break;}
    case 7: {
            int dimension;
            printf("#计算逆矩阵#\n");
            printf("\nEnter the dimension of the square matrix: ");
            scanf("%d", &dimension);
            float matrix[dimension][dimension];
            float matrix_result[dimension][dimension];

            for (int row = 0;row < dimension; row++){
                printf("Row %d: ",row);
                for (int col = 0;col < dimension; col++){
                    scanf("%f",&matrix[row][col]);
                }
            }

            inverse_matrix(dimension, matrix, matrix_result);

            printf("\nThe inverse matrix: \n");
            for (int i = 0; i < dimension; i++){
                for (int j = 0; j < dimension; j++){
                    printf("\t%g", matrix_result[i][j]);
                }
                printf("\n");
            }
    break;}
    default:
        printf("EXIT SUCCESSFULLY!\n");
        return 0;
    }
    system("pause");
    system("cls");
    }
    return 0;
}

void transposed_matrix(int row, int col, float matrix[row][col], float matrix_result[col][row])
{
    for (int r = 0; r < col; r++){
        for (int c = 0; c < row; c++){
            matrix_result[r][c] = matrix[c][r];
        }
    }
}

void into_row_echelon_form(int row, int col, float matrix[row][col])
{
    //对每一该操作的列执行操作
    for (int c = 0; c < col && c <= row; c++){
        //检查该列该操作的元素是否为0，对不为0的行继续执行操作
        int count_changed_row = 0, kept_row = c;
        for (int r = c; r < row; r++){

            if (matrix[r][c] != 0){
                float first_element = matrix[r][c];
                for (int j = c; j < col; j++){
                    matrix[r][j] /= first_element;
                }
                //把首元化为1后，要知道有几行，再相减只留下一行，再把该行移至适当位置
                count_changed_row++;
                if (count_changed_row == 1){
                    kept_row = r;
                }
                if (count_changed_row > 1){
                    for (int j = c; j < col; j++){
                        matrix[r][j] -= matrix[kept_row][j];
                        //排除bug：有时相减后为0，但是结果却为一个数量级为1e-7的数
                        if ((matrix[r][j] > 0 ? matrix[r][j] : -matrix[r][j]) < 1e-6){
                            matrix[r][j] = 0;
                        }
                    }
                }
            }
        }
        //交换行
        float temp;
        for (int j = 0; j < col; j++){
            temp = matrix[c][j];
            matrix[c][j] = matrix[kept_row][j];
            matrix[kept_row][j] = temp;
        }
    }
}

void into_reduced_row_echelon_form(int row, int col, float matrix[row][col])
{
    into_row_echelon_form(row, col, matrix);
    //确定第一行的1在什么位置
    int first_one;
    for (int c = 0; c < col; c++){
        if (matrix[0][c] == 1){
            first_one = c;
            break;
        }
    }
    //确定列的1在哪一行
    for (int c = first_one + 1; c < col && c < row; c++){
        int row_to_be_used = -1;
        for (int r = c; r < row; r++){
            if (matrix[r][c] == 1){
                row_to_be_used = r;
            }
        }

        if (row_to_be_used == -1){
            continue;
        }
        for (int r = 0; r < row_to_be_used; r++){
            if (matrix[r][c] != 0){
                float first_element = matrix[r][c];
                for (int j = c; j < col; j++){
                    matrix[r][j] -= matrix[row_to_be_used][j] * first_element;
                    if (fabs(matrix[r][j]) < 1e-6){
                        matrix[r][j] = 0;
                    }
                }
            }
        }
    }
}

float det(int n,float a[][n])
{
    float result = 0.0f;//困扰我很久很久的bug在这！！！这个声明只能放在这个函数里，以便每次调用都会初始化为零，否则放在函数外会使余子式的计算改变了result值，而result再加上余子式的值使得重复累加

    //判断当矩阵为一阶时直接输出结果
    if (n == 1){
        return a[0][0];
    }

    //以行列式第一行展开
    for (int c = 0;c <= n - 1;c++){
        float complement_minor[n - 1][n - 1],*p = &complement_minor[0][0];

        //遍历原数组排除划掉的元素，将其他元素依次存储进余子式数组中
        for (int row = 0;row <= n - 1;row++){
            for (int col = 0;col <= n - 1;col++){
                if (row != 0 && col != c){
                    *p++ = a[row][col];
                }
            }
        }

        //累加各个代数余子式与其对应元素的积
        result += (c % 2 ? -1 : 1) * a[0][c] * det(n - 1,complement_minor);
    }
    return result;
}

float tr(int dimension, float matrix[dimension][dimension])
{
    float sum = 0;
    for (int i = 0; i < dimension; i++){
        sum += matrix[i][i];
    }
    return sum;
}

void matrix_multiplication(int row_left, int c_r, int col_right, float matrix_left[row_left][c_r], float matrix_right[c_r][col_right], float matrix_result[row_left][col_right])
{
    //遍历结果数组
    for (int i = 0; i < row_left; i++){
        for (int j = 0; j < col_right; j++){
            matrix_result[i][j] = 0;//为了节省代码量在这里顺便初始化结果矩阵,别忘了初始化！
            //遍历左矩阵i行与右矩阵j列对应元
            for (int n = 0; n < c_r; n++){
                matrix_result[i][j] += matrix_left[i][n] * matrix_right[n][j];
            }
        }
    }
}

int rank_of_matrix(int row, int col, float matrix[row][col])
{
    into_row_echelon_form(row, col, matrix);
    //从底行开始检验
    for (int r = row - 1; r >= 0; r--){
        for (int c = 0; c < col; c++){
            if (matrix[r][c] != 0){
                return (r + 1);
            }
        }
    }
    return 0;
}

void inverse_matrix(int dimension, float matrix[dimension][dimension], float matrix_result[dimension][dimension])
{
    //将整个单位矩阵拓展进原矩阵
    float augmented_matrix[dimension][dimension * 2];
    for (int r = 0; r < dimension; r++){
        for (int c = 0; c < dimension * 2; c++){
            if (c >= dimension){
                if (r == (c - dimension)){
                    augmented_matrix[r][c] = 1;
                }
                else
                    augmented_matrix[r][c] = 0;
            }
            else
                augmented_matrix[r][c] = matrix[r][c];
        }
    }
    into_reduced_row_echelon_form(dimension, dimension * 2, augmented_matrix);
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            matrix_result[i][j] = augmented_matrix[i][j + dimension];
        }
    }
    /*
    //将单位矩阵每一列依次拓展进原矩阵，看成解多元一次方程组
    for (int c = 0; c < dimension; c++){
        float augmented_matrix[dimension][dimension + 1];
        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension + 1; j++){
                if (j == dimension){
                    if (i == c){
                        augmented_matrix[i][j] = 1;
                    }
                    if (i != c){
                        augmented_matrix[i][j] = 0;
                    }
                }
                else
                    augmented_matrix[i][j] = matrix[i][j];
            }
        }
        into_reduced_row_echelon_form(dimension, dimension + 1, augmented_matrix);
        for (int r = 0; r < dimension; r++){
            matrix_result[r][c] = augmented_matrix[r][dimension];
        }
    }
    */
}
