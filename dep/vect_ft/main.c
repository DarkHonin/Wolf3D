#include "vect_ft.h"
#include <libtest.h>
#include <stdio.h>

int main(void)
{
	vector vect;

	ft_putendl("Vect test: INT");
	ft_putendl("+=================+");
	vect = MAKE_VECT(sizeof(int));
	int count = 0;
	int ints[6] = {24, 44, 963, 789, 22, 71};
	ft_putstr("Running push test: ");
	while (count < 6)
		vect_push(vect, &ints[count++]);
	int *ref = vect->data;
	count = 0;
	while (count < 6)
	{
		if (ref[count] != ints[count])
		{
			ft_putendl("[NOK]");
			exit(-1);
		}
		count++;
	}
	ft_putendl("[OK]");
	ft_putstr("Running pop test: ");
	count = 5;
	int *hold;
	while((hold = vect_pop(vect)))
	{
		if (*hold != ints[count])
		{
			ft_putendl("[NOK]");
			exit(-1);
		}
		count--;
	}
	ft_putendl("[OK]");
	count = 0;
	while (count < 6)
		vect_push(vect, &ints[count++]);
	ft_putstr("Running pull test: ");
	count = 0;
	while((hold = vect_pull(vect)))
	{
		if (*hold != ints[count])
		{
			ft_putstr("[NOK]");
			exit(-1);
		}else
			ft_putstr("[OK]");
		count++;
	}
	ft_putendl("");

	ft_putstr("Running insert test: ");
	vect_insert(vect, &ints[0], 0);
	if (((int *)vect->data)[0] != ints[0])
		ft_putstr("[NOK]");
	else
		ft_putstr("[OK]");

	vect_insert(vect, &ints[1], 0);
	if (((int *)vect->data)[0] != ints[1])
		ft_putstr("[NOK]");
	else
		ft_putstr("[OK]");

	vect_insert(vect, &ints[2], 1);
	if (((int *)vect->data)[1] != ints[2])
		ft_putendl("[NOK]");
	else
		ft_putendl("[OK]");

	hold = vect_slice(vect, 1);
	if (*hold == ints[2])
		ft_putendl("OK");
	return (0);
}