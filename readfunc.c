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

char *go_back(char *s)
{
	int	len;

	len = strlen(s);
	len--;
	while (s[len] != '/')
	{
		s[len] = '\0';
		len--;
	}
	s[len] = '\0';
	return (s);
}

int	wordcmp(char *word, char *row, char *fname)
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

int txtcmp(char *word, char *txt)
{
	int	i;
	int	j;
	int	tmp;
	char *str;

	i = 0;
	str = dlt_ext(txt);
	if (strcmp(str, word))
	{
		//printf("str: %s word: %s \n", str ,word);
		return (0);
	}
	else
	{

		//printf("str: %s word: %s \n", str ,word);
		return (1);
	}
}

void	find_word(prolab *pro)
{
	int	i;
	int	fd;
	char *row;
	char cwd[256];
	char cwd2[256];
	char word[20];
	struct dirent *s_dir;
	struct dirent *sdir2;
	DIR *dir;
	DIR *dir2;
	int	ytm_control;
	int	ist_control;
	int	ist_control2;
	int	etk_control;


	i = 1;
	ytm_control = 0;
	ist_control = 0;
	ist_control2 = 0;
	etk_control = 0;
	printf("Aranacak kelimeyi giriniz: \n");
	fflush(stdin);
	scanf("%[^\n]s", word);
	//fgets(word, 20, stdin);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		(write(1, "Error\n", 6));
	else
		printf("current working directory: %s\n", cwd);
	chdir(strcat(cwd, "/Üniversite/"));
	printf("cwd      %s\n",cwd);
	dir = opendir(".");
	while ((s_dir = readdir(dir))!= NULL)
	{
		if (!strcmp(s_dir->d_name, ".") || !strcmp(s_dir->d_name, "..") || s_dir->d_type == 8)
			continue;
		//printf("içerdeki cwd : %s\n", cwd);
		chdir(strcat(cwd, "/"));
		dir2 = opendir(strcat(cwd, s_dir->d_name));
		//printf("degisen: %s\n", cwd);
		while ((sdir2 = readdir(dir2)) != NULL)
		{
			if (!strcmp(sdir2->d_name, ".") || !strcmp(sdir2->d_name, "..") || !find_txt(sdir2->d_name))
				continue;
			chdir(strcat(cwd, "/"));
			fd = open(sdir2->d_name, O_RDONLY);
			//printf("Dosya: %s\n", sdir2->d_name);
			i = 1;
			while ((row = get_next_line(fd)) != NULL)
			{
				if (txtcmp(word, sdir2->d_name))
				{
					ytm_control++;
				}
				if (wordcmp(word, row, sdir2->d_name) == 1)
				{
					printf("Aha buldum \n%s isimli dosyada %d satırda aradığınız kelime bulunmakta\n", sdir2->d_name, i);
					etk_control = 0;
					//usleep(2000000);
				}
				if (wordcmp(word, row, sdir2->d_name) == 2)
				{
					printf("Aha buldum \n%s isimli dosyada %d satırda aradığınız etiket bulunmakta\n", sdir2->d_name, i);
					ist_control2++;
					etk_control++;
					//usleep(2000000);
				}
				else if (wordcmp(word, row, sdir2->d_name) == 3)
				{
					ist_control++;
					//printf("%d\n", ist_control);
					//usleep(2000000);
				}
				// else
				// {
				// 	printf("Hmm... bu dosyada yok (%s)\n", sdir2->d_name);
				// 	//usleep(100000);
				// }
				//printf("Satir %d: \n%s\n", i,row);
				//printf("dname: %s word: %s mcmp(): %d strlenword: %lu strlendname: %lu\n", dlt_ext(sdir2->d_name), word, mcmp(dlt_ext(sdir2->d_name), word), strlen(word), strlen(dlt_ext(sdir2->d_name)));
				i++;
			}
			close(fd);

		}
		getcwd(cwd, sizeof(cwd));
		chdir(go_back(cwd));
		closedir(dir2);

	}
	if (ytm_control == 0 && ist_control == 0 && etk_control != 0)
	{
		printf("\n\n*--------------------------------------*\n");
		printf("|                                      |\n");
		printf("|  Aradığını etiket yetim bir etiket!  |\n");
		printf("|                                      |\n");
		printf("*--------------------------------------*\n\n\n");
	}
	if (ist_control != 0 && ist_control2 == 0)
	{
		printf("\n\n*----------------------------------------*\n");
		printf("|                                        |\n");
		printf("|  Aradığını etiket istenen bir etiket!  |\n");
		printf("|                                        |\n");
		printf("*----------------------------------------*\n\n\n");
	}
	closedir(dir);
	chdir(go_back(cwd));
}
