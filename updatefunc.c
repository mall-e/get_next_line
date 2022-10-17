#include "prolab.h"

int	file_lenght(int fd, int *len, char *row)
{
	char	*str;
	*len += strlen(row);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("satır: %s uzunluğu : %lu\n", str, strlen(str));
		*len += strlen(str);
	}
	return (*len);
}

int	uwordcmp(char *word, char *row, char *fname)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	//printf("word: %s  row: %s\n", word, row);
	while (row[i])
	{
		j = 0;
		tmp = i;
		count = 0;
		while(word[j])
		{
			if (row[tmp] == word[j])
			{
				tmp++;
				j++;
				count++;
			}
			else
				break ;
		}
		//printf("word %s dlt_extfname : %s \n", word, dlt_ext(fname));
		//usleep(1000000);
		if (strlen(word) == count && (row[tmp] == ' ' || row[tmp] == ',' || row[tmp] == '.' || row[tmp] == '\n' || row[tmp] == '\0'))
			return (1);
		else if (strlen(word) == count
			&& (row[tmp] == ']' && row[tmp + 1] == ']'
			&&	row[tmp - count - 1] == '[' && row[tmp - count  - 2] == '['))
			return (2);
		else if (!strcmp(word, dlt_ext(fname)))
		{
			return (3);
		}

		i++;
	}
	return (0);
}
