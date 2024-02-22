#include "matlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/*
	 * 0,0,0,0
	 *
	 * 0, 0, 2, 3
	 * 0, 5, 6, 7,
	 * 0, 9, 10, 11,
	 * 0, 12, 13, 14,
	 *
	 *
	 */
	struct matrix *left = mat_create(4, 4);
	mat_init(left, (double[]){
			      // 0,
				  2, 2, 3, 4,
			      0, 0, 2, 3,
			      0, 5, 6, 7,
			      0, 9, 10, 11,
			      // 0, 12, 13, 14,
		      });
	// mat_swap_row(left, 0, 1);

	// struct matrix *right = mat_create(2, 1);
	// mat_init(right, (double[]){
	// 		       1,
	// 		       2,
	// 	       });
	// struct matrix *new = mat_trans_new(mat);
	// printf("%d\n", mat_cmp(left, right));

	printf("rank=%d\n", mat_rref(left));
	mat_print(left);
	// mat_print(left);
	// mat_print(right);
	// printf("tr = %.2lf\n", mat_tr(left));
	// mat_RREF(left);
	// printf("det = %.2lf\n", mat_det(left));
	// struct matrix *mul_res = mat_mul(left, right);
	// mat_print(mul_res);
	free(left);
	// free(right);
}
