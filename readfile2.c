#include "prolab.h"

int	main(void)
{
	char cwd[256];
	char cwd2[256];
	struct dirent *s_dir;
	struct dirent *sdir2;
	DIR *dir;
	DIR *dir2;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (write(1, "Error\n", 6));
	else
		printf("current working directory: %s\n", cwd);
	chdir(strcat(cwd, "/Üniversite/"));
	dir = opendir(".");
	while ((s_dir = readdir(dir))!= NULL)
	{
		if (!strcmp(s_dir->d_name, ".") || !strcmp(s_dir->d_name, "..") || s_dir->d_type == 8)
			continue;
		//printf("içerdeki cwd : %s\n", cwd);
		dir2 = opendir(strcat(cwd, s_dir->d_name));
		printf("d_name: %s\n", s_dir->d_name);
		//printf("degisen: %s\n", cwd);
		while ((sdir2 = readdir(dir2)) != NULL)
		{
			if (!strcmp(sdir2->d_name, ".") || !strcmp(sdir2->d_name, "..") || !find_txt(sdir2->d_name))
				continue;
			printf("txt files: %s\n", sdir2->d_name);
		}
		getcwd(cwd, sizeof(cwd));
		chdir(strcat(cwd, "/"));
		closedir(dir2);
	}
	return (0);
}
