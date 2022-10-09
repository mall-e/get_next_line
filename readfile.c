// #include <unistd.h>
// #include <stdio.h>
// #include <dirent.h>
// #include <string.h>

// int	main(void)
// {
// 	char cwd[256];
// 	char cwd2[256];
// 	struct dirent *s_dir;
// 	struct dirent *sdir2;
// 	DIR *dir;
// 	DIR *dir2;

// 	if (getcwd(cwd, sizeof(cwd)) == NULL)
// 		return (write(1, "Error\n", 6));
// 	else
// 		printf("current working directory: %s\n", cwd);
// 	getcwd(cwd2, sizeof(cwd2));
// 	chdir(strcat(cwd2, "/Üniversite/"));
// 	printf("cwd2: %s \n", cwd2);
// 	dir = opendir(strcat(cwd, "/Üniversite/"));
// 	while ((s_dir = readdir(dir))!= NULL)
// 	{
// 		if (!strcmp(s_dir->d_name, ".") || !strcmp(s_dir->d_name, "..") || s_dir->d_type == 8)
// 			continue;
// 		dir2 = opendir(strcat(cwd2, s_dir->d_name));
// 		printf("d_name: %s\n", s_dir->d_name);
// 		while ((sdir2 = readdir(dir2)) != NULL)
// 		{
// 			printf("denem");
// 			if (!strcmp(sdir2->d_name, ".") || !strcmp(sdir2->d_name, "..") || sdir2->d_type != 8)
// 				continue;
// 			printf("%s: %s\n", cwd2,sdir2->d_name);
// 		}
// 	}

// 	return (0);
// }
