#include <stdio.h>
#include "parse.h"

int main(int argc, char *argv[])
{
	t_data *data = run_parse(argc, argv);
	printf("NO : %s\n", data->north);
	printf("SO : %s\n", data->south);
	printf("WE : %s\n", data->west);
	printf("EA : %s\n", data->east);
	printf("Floor : %d, %d, %d\n", data->floor->red, data->floor->green, data->floor->blue);
	printf("Ceiling: %d, %d, %d\n", data->ceiling->red, data->ceiling->green, data->ceiling->blue);
	//map check, but map parse should be changed.
}
