#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

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
	dir = opendir(strcat(cwd, "/Üniversite/"));
	while ((s_dir = readdir(dir))!= NULL)
	{
		if (!strcmp(s_dir->d_name, ".") || !strcmp(s_dir->d_name, "..") || s_dir->d_type == 8)
			continue;
		printf("d_name: %s\n", s_dir->d_name);
		dir2 = opendir(strcat(cwd, s_dir->d_name));
		while ((sdir2 = readdir(dir2)) != NULL)
		{
			if (!strcmp(s_dir->d_name, ".") || !strcmp(s_dir->d_name, "..") || s_dir->d_type == 8)
				continue;
			printf("dddddd: %s\n", sdir2->d_name);
		}
		closedir(dir2);
	}

	return (0);
}
