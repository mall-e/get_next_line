#include "prolab.h"

int	find_txt(char *fname)
{
	int len;

	len = strlen(fname);
	len--;
	if(fname[len] == 't' && fname[len - 1] == 'x'
		&& fname[len - 2] == 't' && fname[len - 3] == '.')
		return (1);
	else
		return(0);
}
