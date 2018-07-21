#include "matrix_ft.h"

int main(void)
{
	t_matrix *mtr;
	t_matrix *mtr2;
	t_matrix *mtrt;

	mtr = new_matrix(1, 3);
	mtr2 = new_matrix(3, 3);
	print_matrix(mtr);
	float *r0 = get_row(mtr, 0);
	float *r20 = get_row(mtr2, 0);
	r0[0] = 20;
	r0[1] = 3;
	r0[2] = 10;
	print_matrix(mtr);
	r20[0] = 15;
	r20[1] = 6;
	r20[2] = 9;
	print_matrix(mtr2);
	mtrt = matrix_prod(mtr, mtr2);
	print_matrix(mtrt);

}