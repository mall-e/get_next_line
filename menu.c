#include "prolab.h"

int	main(void)
{
	int	i;
	char *word;
	prolab *pro;

	pro = malloc(sizeof(pro));
	definitions(pro);
	printf("Hoşgeldiniz!\nYapmak istediğiniz işlemi seçiniz\n");
	while (1)
	{
		printf("1) Arama\n");
		printf("2) Güncelleme\n");
		printf("3) Dosyaya yazma\n");
		printf("4) Çıkış\n");
		printf("İşlem no: ");
		scanf("%d", &i);
		if (i > 4)
			printf("Yanlış seçim!\n");
		else if (i == 1)
		{
			find_word(pro);
		}
		else if (i == 2)
		{
			update_label();
		}

		else if (i == 4)
		{
			printf("Çıkış yapıldı!\n");
			return (0);
		}


	}



}
