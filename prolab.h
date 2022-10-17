#ifndef PROLAB_H
#define PROLAB_H

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct prolab
{
	char *cwd;
}				prolab;


int		find_txt(char *fname);
int		mcmp(char *s1, char *s2);
void	find_word(prolab *pro);
void	definitions(prolab *pro);
void	update_label();
char	*dlt_ext(char *txtfile);

#endif
