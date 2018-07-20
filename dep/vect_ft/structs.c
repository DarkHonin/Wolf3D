#include "vect_ft.h"
#include <stdio.h>

int check_vector(vector e, int *data)
{
	for (int x =0; x < (e->buff_size/e->meta); x++)
	{
		if (((int *)e->data)[x] == data[x])
			ft_putstr("[OK]");
		else
			ft_putstr("[NOK]");
	}
	ft_putendl("");
}


int main(void)
{
	ft_putendl("Vect test: Structs");
	ft_putendl("+===========+");
	int qq[6] = {16, 45, 88, 98, 774, 663};
	int qq2[6] = {116, 145, 188, 198, 1774, 1663};
	vector v = MAKE_VECT(sizeof(t_buff));
	vector v2 = MAKE_VECT(sizeof(int));
	vector v3 = MAKE_VECT(sizeof(int));
	vect_push(v2, &qq[0]);
	vect_push(v2, &qq[1]);
	vect_push(v2, &qq[2]);
	vect_push(v2, &qq[3]);
	vect_push(v2, &qq[4]);
	vect_push(v2, &qq[5]);

	vect_push(v3, &qq2[0]);
	vect_push(v3, &qq2[1]);
	vect_push(v3, &qq2[2]);
	vect_push(v3, &qq2[3]);
	vect_push(v3, &qq2[4]);
	vect_push(v3, &qq2[5]);
	
	ft_putstr("Checking sub vec 1: ");
	check_vector(v2, qq);
	vect_dump(v2);
	ft_putstr("Checking sub vec 2: ");
	check_vector(v3, qq2);

	vect_push(v, v2);
	vect_push(v, v3);
	
	vector out = vect_get(v, 0);
	vect_dump(out);
	ft_putstr("Checking sub vec 2 out: ");
	check_vector(out, qq);
}