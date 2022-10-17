#include "prolab.h"

void	definitions(prolab *pro)
{
	char	cwd[256];

	pro->cwd = getcwd(cwd, sizeof(cwd));
	printf("procwd: %s\n", pro->cwd);
}

char	*dlt_ext(char *txtfile)
{
	int	i;
	int	len;
	char *str;

	len = 0;
	i = 0;
	len = strlen(txtfile);
	str = malloc(sizeof(char) * (len - 3));
	while (txtfile[i] != '.')
	{
		str[i] = txtfile[i];
		i++;
	}
	str[i] = '\0';
	//printf("dlt_ext: %s\n", str);
	return (str);
}

int	mcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0') && (s1[i] != '\n' || s2[i] != '\n'))
	{
		i++;
	}
	printf("s1 - s2 = %d\n s1: %d, s2: %d\n", s1[i]-s2[i], s1[i],s2[i]);
	return (s1[i] - s2[i]);
}

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
