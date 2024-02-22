#include "matlib.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

// TODO what if row col below zero
struct matrix *mat_create(int row, int col)
{
	struct matrix *mat =
		malloc(sizeof(struct matrix) + row * col * sizeof(double));
	mat->row = row;
	mat->col = col;
	return mat;
}

/*
 * NOTICE: data length must be mat->row * mat->col
 */
void mat_init(struct matrix *mat, double *data)
{
	int total = mat->row * mat->col;
	for (int i = 0; i < total; i++) {
		mat->data[i] = *data++;
	}
	return;
}

// trans: transpose
struct matrix *mat_trans(const struct matrix *mat)
{
	struct matrix *trans_mat = mat_create(mat->col, mat->row);
	for (int r = 0; r < trans_mat->row; r++) {
		for (int c = 0; c < trans_mat->col; c++) {
			MAT_DATA(trans_mat, r, c) = MAT_DATA(mat, c, r);
		}
	}

	return trans_mat;
}

// permutation matrix: exchange rows
// elimination matrix: eliminate by pivots
// LU

// It is faster than multiplying permutaion matrix
// Pi,j
void mat_row_swap(struct matrix *mat, int r1, int r2)
{
#ifdef DEBUG
	printf("E%d,%d * mat\n", r1, r2);
#endif
	size_t size = sizeof(double) * mat->col;
	double *temp = malloc(size);
	memcpy(temp, &MAT_DATA(mat, r1, 0), size);
	memcpy(&MAT_DATA(mat, r1, 0), &MAT_DATA(mat, r2, 0), size);
	memcpy(&MAT_DATA(mat, r2, 0), temp, size);
	free(temp);
	return;
}

// scalar multiplication
// Ei(c)
void mat_row_scale(struct matrix *mat, int row, double scalar)
{
#ifdef DEBUG
	printf("E%d(%.2lf) * mat\n", row, scalar);
#endif
	for (int i = 0; i < mat->col; i++) {
		MAT_DATA(mat, row, i) *= scalar;
	}
	return;
}

// subtract l times one row from another
// Ei,j(c)
void mat_row_sub(struct matrix *mat, int r1, int r2, double multiplier)
{
#ifdef DEBUG
	printf("E%d,%d(%.2lf) * mat\n", r1, r2, multiplier);
#endif
	for (int i = 0; i < mat->col; i++) {
		MAT_DATA(mat, r1, i) -= multiplier * MAT_DATA(mat, r2, i);
	}
	return;
}

// eliminate pivot
void mat_row_elim(struct matrix *mat, int pivot_r, int pivot_c)
{
#ifdef DEBUG
	printf("eliminating column %d base on pivot (%d, %d)\n", pivot_c, pivot_r, pivot_c);
#endif
	double ratio;
	for (int i = 0; i < mat->row; i++) {
		if (i == pivot_r)
			continue;
		ratio = MAT_DATA(mat, i, pivot_c) / MAT_DATA(mat, pivot_r, pivot_c);
		mat_row_sub(mat, i, pivot_r, ratio);
	}
}

// TODO solve equations system. first get coeffient matrix
// Direct elimination solution
// 1. get coeffient matrix
// 2. forward elimination
// 3. back substitution

// return rank of the matrix
// DEBUG show every change
// TODO find the largest pivot
// Gauss-Jordan elimination

// Gaussian Elimination / Gauss-Jordan Elimination Partial Pivoting
int mat_gepp(struct matrix *mat, bool jordan,
			 struct matrix *L, struct matrix *U)
{
	double ratio = 0.0;
	int rank = 0;
	for (int pivot_c = 0; pivot_c < mat->col; pivot_c++) {
		if (rank == mat->row)
			break;
		int pivot_r = -1;
		for (int r = rank; r < mat->row; r++) {
			if (MAT_DATA(mat, r, pivot_c) == 0)
				continue;
			if (pivot_r < 0) { // pivot found
				rank++;
				pivot_r = r;
				// mat_row_scale(mat, pivot_r, 1 / MAT_DATA(mat, pivot_r, pivot_c));
				mat_row_elim(mat, pivot_r, pivot_c); // REF not need elim the upper rows
				break;
			}
		}
		if (pivot_r != -1 && pivot_r != (rank - 1))
			mat_row_swap(mat, pivot_r, rank - 1);
#ifdef DEBUG
		if (pivot_r != -1) {
			mat_print(mat);
			printf("\n");
		}
#endif
	}
	return rank;
}

// int mat_lu()
// {
// 	return 0;
// }

int mat_ref()
{
	return 0;
}

// Reduced Row Echelon Form
int mat_rref(struct matrix *mat)
{
	double ratio = 0.0;
	int rank = 0;
	for (int pivot_c = 0; pivot_c < mat->col; pivot_c++) {
		if (rank == mat->row)
			break;
		int pivot_r = -1;
		for (int r = rank; r < mat->row; r++) {
			if (MAT_DATA(mat, r, pivot_c) == 0)
				continue;
			if (pivot_r < 0) { // pivot found
				rank++;
				pivot_r = r;
				// mat_row_scale(mat, pivot_r, 1 / MAT_DATA(mat, pivot_r, pivot_c));
				mat_row_elim(mat, pivot_r, pivot_c); // REF not need elim the upper rows
				break;
			}
		}
		if (pivot_r != -1 && pivot_r != (rank - 1))
			mat_row_swap(mat, pivot_r, rank - 1);
#ifdef DEBUG
		if (pivot_r != -1) {
			mat_print(mat);
			printf("\n");
		}
#endif
	}
	return rank;
}

// TODO what if it is not square matrix?
// Laplace expansion
double mat_det(struct matrix *mat)
{
	double res = 0.0;
	struct matrix *minor = mat_create(mat->row - 1, mat->col - 1);
	if (mat->col == 1)
		return mat->data[0];

	for (int c = 0; c <= (mat->col - 1); c++) {
		double *ptr = minor->data;
		for (int row = 0; row <= (mat->row - 1); row++) {
			for (int col = 0; col <= (mat->col - 1); col++) {
				if (row != 0 && col != c)
					*ptr++ = MAT_DATA(mat, row, col);
			}
		}
		res += (c % 2 ? -1 : 1) * MAT_DATA(mat, 0, c) * mat_det(minor);
	}
	free(minor);
	return res;
}

// TODO what if it is not square matrix?
double mat_tr(struct matrix *mat)
{
	double sum = 0.0;
	for (int i = 0; i < mat->row; i++) {
		sum += MAT_DATA(mat, i, i);
	}
	return sum;
}

struct matrix *mat_dot(const struct matrix *left, const struct matrix *right)
{
	if (left->col != right->row)
		return NULL;
	struct matrix *res = mat_create(left->row, right->col);
	for (int i = 0; i < res->row; i++) {
		for (int j = 0; j < res->col; j++) {
			MAT_DATA(res, i, j) = 0;
			for (int n = 0; n < left->col; n++)
				MAT_DATA(res, i, j) += MAT_DATA(left, i, n) * MAT_DATA(right, n, j);
		}
	}
	return res;
}

struct matrix *mat_sum(const struct matrix *mat1, const struct matrix *mat2)
{
	if (mat1->row != mat2->row || mat1->col != mat2->col)
		return NULL;
	struct matrix *res = mat_create(mat1->row, mat1->col);
	int count = mat1->row * mat1->col;
	for (int i = 0; i < count; i++) {
		res->data[i] = mat1->data[i] + mat2->data[i];
	}
	return res;
}

// TODO
// Based on Gauss-Jordan elimination
struct matrix *mat_inv(struct matrix *mat)
{
	if (mat->row != mat->col)
		return NULL;
	struct matrix *augmented_mat = mat_create(mat->row, mat->col * 2);
	return NULL;
}

// TODO 给 struct matrix 加一个 enum 标志位，表示存储方式，比如稀疏矩阵、三角矩阵的存储
// LU factorization
// PA = LDU
struct lu {
	struct matrix *L;
	struct matrix *U;
};
void mat_splu()
{
}
struct LU *mat_lu(struct matrix *P, struct matrix *A, struct matrix *L, struct matrix *D, struct matrix *U)
{
	return NULL;
}

void mat_print(struct matrix *mat)
{
	for (int r = 0; r < mat->row; r++) {
		for (int c = 0; c < mat->col; c++) {
			printf("%.2lf\t", MAT_DATA(mat, r, c));
		}
		printf("\n");
	}
	return;
}

bool mat_cmp(const struct matrix *mat1, const struct matrix *mat2)
{
	if (mat1->row != mat2->row || mat1->col != mat2->col)
		return false;
	size_t size = sizeof(struct matrix) + sizeof(double) * mat1->row * mat2->col;
	if (memcmp(mat1, mat2, size))
		return false;
	return true; // same
}
