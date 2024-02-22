#ifndef _MATLIB_H
#define _MATLIB_H 1

#include <stdbool.h>
#include <stdio.h>

#define MAT_DATA(mat, r, c) ((mat)->data[(r) * (mat)->col + (c)])
struct matrix {
	int row;
	int col;
	// bool sparse;
	// bool triangle;
	// struct matrix *P;
	// struct matrix *Q; // 把 LU 合并在一起
	// struct matrix *L;
	// struct matrix *D;
	// struct matrix *U;
	// struct matrix *grad; // like tensor in pytorch to preserve the \partial loss / \partial w while itself is the w
	double data[];
	/*
 * NOTICE: data length must be mat->row * mat->col
 */
};

/* In order to save space, use mask instead of copying data to create minor.
 * struct minor_mask contains the absolute index of the excluded entry
 * bitmap
 */
/*
struct minor_mask {
	int len;
	int rows[];
	int cols[];

};
*/

// TODO
#define ElemType double

struct matrix *mat_create(int row, int col);
void mat_init(struct matrix *mat, double *data);
struct matrix *mat_trans(const struct matrix *mat);
void mat_row_perm(struct matrix *mat, int r1, int r2);
void mat_REF(struct matrix *mat);
int mat_rref(struct matrix *mat);
double mat_det(struct matrix *mat);
double mat_tr(struct matrix *mat);
struct matrix *mat_dot(const struct matrix *left, const struct matrix *right);
int mat_rank(struct matrix *mat);
struct matrix *mat_inverse(struct matrix *mat);
void mat_print(struct matrix *mat);
bool mat_cmp(const struct matrix *mat1, const struct matrix *mat2);
#endif /* _MATLIB_H */
