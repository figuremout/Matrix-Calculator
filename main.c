#include <stdio.h>
#include <stdlib.h>

void transposed_matrix(int row, int col, float matrix[row][col], float matrix_result[col][row]);
void into_row_echelon_form(int row, int col, float matrix[row][col]);
void into_reduced_row_echelon_form(int row, int col, float matrix[row][col]);
float det(int n,float a[][n]);
float tr(int dimension, float matrix[dimension][dimension]);
void matrix_multiplication(int row_left, int c_r, int col_right, float matrix_left[row_left][c_r], float matrix_right[c_r][col_right], float matrix_result[row_left][col_right]);
int rank_of_matrix(int row, int col, float matrix[row][col]);
void inverse_matrix(int dimension, float matrix[dimension][dimension], float matrix_result[dimension][dimension]);

int main()
{
    for (;;){
    printf("#MATRIX CALCULATOR#\n");
    printf("\n*******************\n");
    printf("0.����ת��\n");
    printf("1.��Ϊ�н����ξ���\n");
    printf("2.��Ϊ������ξ���\n");
    printf("3.��������ʽ\n");
    printf("4.���㷽��ļ�\n");
    printf("5.�������˷�\n");
    printf("6.����������\n");
    printf("7.���������\n");
    printf("8.EXIT\n");
    printf("*******************\n");

    int command;
    printf("Enter your command: ");
    scanf("%d", &command);

    system("cls");

    switch (command){
    case 0: {
            int row, col;
            printf("#����ת��#\n");
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
            printf("\n");
    break;}
    case 1: {
            int row, col;
            printf("#��Ϊ�н����ξ���#\n");
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
            printf("\n");
    break;}
    case 2: {
            int row, col;
            printf("#��Ϊ������ξ���#\n");
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
            printf("\n");
    break;}
    case 3: {
            int dimension;
            printf("#��������ʽ#\n");
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
            printf("#���㷽��ļ�#\n");
            printf("\nEnter the dimension of a matrix: ");
            scanf("%d",&dimension);
            float matrix[dimension][dimension];

            for (int row = 0;row < dimension; row++){
                printf("Row %d: ",row);
                for (int col = 0;col < dimension; col++){
                    scanf("%f",&matrix[row][col]);
                }
            }

            printf("\ntr() = %g\n\n", tr(dimension, matrix));
    break;}
    case 5: {
            int row_left, c_r, col_right;//c_r�����������õ�ά��
            printf("#�������˷�#\n");
            printf("\nEnter the row of the left matrix: ");
            scanf("%d",&row_left);
            printf("Enter the column of the left matrix(the row of the right matrix): ");
            scanf("%d",&c_r);
            printf("Enter the column of the right matrix: ");
            scanf("%d",&col_right);
            printf("\n");
        //��ʼ�������
            float matrix_left[row_left][c_r];
            //ѭ����������ÿһ��Ԫ��
            for (int row = 0; row < row_left; row++){
                printf("Row %d of the left matrix: ",row);
                for (int col = 0; col < c_r; col++){
                    scanf(" %f",&matrix_left[row][col]);
                }
            }
            printf("\n");

        //��ʼ���Ҿ���
            float matrix_right[c_r][col_right];
            //ѭ����������ÿһ��Ԫ��
            for (int row = 0; row < c_r; row++){
                printf("Row %d of the right matrix: ",row);
                for (int col = 0; col < col_right; col++){
                    scanf(" %f",&matrix_right[row][col]);
                }
            }

            float matrix_result[row_left][col_right];//����������
            //ִ�м���
            matrix_multiplication(row_left, c_r, col_right, matrix_left, matrix_right, matrix_result);
        //����������
            printf("\nThe result of multiplication: \n");
            for (int i = 0; i < row_left; i++){
                for (int j = 0; j < col_right; j++){
                    printf("\t%g", matrix_result[i][j]);
                }
                printf("\n");
            }
            printf("\n");
    break;}
    case 6: {
            int row, col;
            printf("#����������#\n");
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
            printf("\nThe rank: %d\n\n", rank_of_matrix(row, col, matrix));
    break;}
    case 7: {
            int dimension;
            printf("#���������#\n");
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

            //�����Ƿ����
            float matrix_copy[dimension][dimension];
            for (int r = 0; r < dimension; r++){
                for (int c = 0; c < dimension; c++){
                    matrix_copy[r][c] = matrix[r][c];
                }
            }
            if (rank_of_matrix(dimension, dimension, matrix_copy) != dimension){
                printf("\nThe matrix is not invertible.\n\n");
                break;
            }

            inverse_matrix(dimension, matrix, matrix_result);

            printf("\nThe inverse matrix: \n");
            for (int i = 0; i < dimension; i++){
                for (int j = 0; j < dimension; j++){
                    printf("\t%g", matrix_result[i][j]);
                }
                printf("\n");
            }
            printf("\n");
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
    //��ÿһ�ò�������ִ�в���
    for (int c = 0; c < col && c <= row; c++){
        //�����иò�����Ԫ���Ƿ�Ϊ0���Բ�Ϊ0���м���ִ�в���
        int count_changed_row = 0, kept_row = c;
        for (int r = c; r < row; r++){

            if (matrix[r][c] != 0){
                float first_element = matrix[r][c];
                for (int j = c; j < col; j++){
                    matrix[r][j] /= first_element;
                }
                //����Ԫ��Ϊ1��Ҫ֪���м��У������ֻ����һ�У��ٰѸ��������ʵ�λ��
                count_changed_row++;
                if (count_changed_row == 1){
                    kept_row = r;
                }
                if (count_changed_row > 1){
                    for (int j = c; j < col; j++){
                        matrix[r][j] -= matrix[kept_row][j];
                        //�ų�bug����ʱ�����Ϊ0�����ǽ��ȴΪһ��������Ϊ1e-7����
                        if ((matrix[r][j] > 0 ? matrix[r][j] : -matrix[r][j]) < 1e-6){
                            matrix[r][j] = 0;
                        }
                    }
                }
            }
        }
        //������
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
    //ȷ����һ�е�1��ʲôλ��
    int first_one;
    for (int c = 0; c < col; c++){
        if (matrix[0][c] == 1){
            first_one = c;
            break;
        }
    }
    //ȷ���е�1����һ��
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
    float result = 0.0f;//�����Һܾúܾõ�bug���⣡�����������ֻ�ܷ������������Ա�ÿ�ε��ö����ʼ��Ϊ�㣬������ں������ʹ����ʽ�ļ���ı���resultֵ����result�ټ�������ʽ��ֵʹ���ظ��ۼ�

    //�жϵ�����Ϊһ��ʱֱ��������
    if (n == 1){
        return a[0][0];
    }

    //������ʽ��һ��չ��
    for (int c = 0;c <= n - 1;c++){
        float complement_minor[n - 1][n - 1],*p = &complement_minor[0][0];

        //����ԭ�����ų�������Ԫ�أ�������Ԫ�����δ洢������ʽ������
        for (int row = 0;row <= n - 1;row++){
            for (int col = 0;col <= n - 1;col++){
                if (row != 0 && col != c){
                    *p++ = a[row][col];
                }
            }
        }

        //�ۼӸ�����������ʽ�����ӦԪ�صĻ�
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
    //�����������
    for (int i = 0; i < row_left; i++){
        for (int j = 0; j < col_right; j++){
            matrix_result[i][j] = 0;//Ϊ�˽�ʡ������������˳���ʼ���������,�����˳�ʼ����
            //���������i�����Ҿ���j�ж�ӦԪ
            for (int n = 0; n < c_r; n++){
                matrix_result[i][j] += matrix_left[i][n] * matrix_right[n][j];
            }
        }
    }
}

int rank_of_matrix(int row, int col, float matrix[row][col])
{
    into_row_echelon_form(row, col, matrix);
    //�ӵ��п�ʼ����
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
    //��������λ������չ��ԭ�����Ϊ�������
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
    //��һ�׿����㷨������λ����ÿһ��������չ��ԭ���󣬿��ɽ��Ԫһ�η�����
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
