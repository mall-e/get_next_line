#include "prolab.h"

void	update_label()
{
	int	fd;
	int	i;
	char *row;
	char cwd[256];
	char cwd2[256];
	struct dirent *s_dir;
	struct dirent *sdir2;
	DIR *dir;
	DIR *dir2;
	char	uword[20];

	printf("Güncellenecek etiketi giriniz: \n");
	fflush(stdin);
	scanf("%[^\n]s", uword);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		(write(1, "Error\n", 6));
	//else
	//	printf("current working directory: %s\n", cwd);
	chdir(strcat(cwd, "/Üniversite/"));
	//printf("cwd      %s\n",cwd);
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
				if (txtcmp(uword, sdir2->d_name))
				{
				}
				if (wordcmp(uword, row, sdir2->d_name) == 1)
				{
					printf("Aha buldum \n%s isimli dosyada %d satırda aradığınız kelime bulunmakta\n", sdir2->d_name, i);
					//usleep(2000000);
				}
				if (wordcmp(uword, row, sdir2->d_name) == 2)
				{
					printf("Aha buldum \n%s isimli dosyada %d satırda aradığınız etiket bulunmakta\n", sdir2->d_name, i);
					//usleep(2000000);
				}
				else if (wordcmp(uword, row, sdir2->d_name) == 3)
				{
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
	closedir(dir);
	chdir(go_back(cwd));
}
