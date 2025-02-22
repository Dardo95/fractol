#include "../include/fractol.h"

void	handle_close(void *param)
{
	t_data *data;

	data = (t_data *)param;
	cleanup(data);
	exit(EXIT_SUCCESS);
}
