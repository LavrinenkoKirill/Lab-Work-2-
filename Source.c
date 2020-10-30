#include <stdio.h>

int main()
{
	char str1[100];

	printf("Input string:\n");
	fgets(str1, 100, stdin);

	char str2[100];
	printf("Input word that we should change:");
	fgets(str2, 100, stdin);

	char str3[100];
	printf("Transform this word to ");
	fgets(str3, 100, stdin);



	int length1 = 0;
	int length2 = 0;
	int length3 = 0;

	for (int i = 0; str2[i] != '\0'; i++) length2++;
	for (int i = 0; str3[i] != '\0'; i++) length3++;

	if (str2[length2 - 1] == '\n')
	{
		str2[length2 - 1] = '\0';
		length2--;
	}





	if (str3[length3 - 1] == '\n')
	{
		str3[length3 - 1] = '\0';
		length3--;
	}



	int flag, poz;
	int x = 0;
	while (str1[x] != '\0')
	{

		length1 = 0;
		for (int i = 0; str1[i] != '\0'; i++) length1++;
		if (str1[length1 - 1] == '\n')
		{
			str1[length1 - 1] = '\0';
			length1--;
		}



		for (int j = 0; str1[j]!='\0'; j++)
		{
			flag = 1;
			for (int i = 0; i < length2; i++)
			{
				if (str1[j + i] != str2[i])
					flag = 0;
			}

			if (flag == 1)
			{
				if ((j != 0 && ((str1[j - 1] >= 'A') && (str1[j - 1] <= 'Z')) || ((str1[j - 1] >= 'a') && (str1[j - 1] <= 'z'))) || (((str1[j + length2] >= 'A') && (str1[j + length2] <= 'Z')) || ((str1[j + length2] >= 'a') && (str1[j + length2] <= 'z'))))
				{
					flag = 0;
				}
				else
				{

					flag = 1;
					poz = j; //poz-позиция,откуда начинается подстрока
					break;
				}
			}

		}






		if (flag == 1)
		{
			int poz2 = poz + length2; //poz2-позиция,где заканчивается подстрока (+1)

			if (length2 == length3)
			{
				for (int i = 0; i < length3; i++)
					str1[poz + i] = str3[i];
			}
			else
			{
				if (length2 > length3)
				{
					int na_sk = length2 - length3;

					for (int i = 0; str1[poz2 + i - 1]!='\0'; i++)
					{
						str1[poz2 - na_sk + i] = str1[poz2 + i];
					}

					for (int i = 0; i < length3; i++)
					{
						str1[poz + i] = str3[i];
					}
				}
				else
				{

					int na_sk = length3 - length2;
					int size_sdvig = length1 - poz2;/// size_sdvig-сколько символов нужно сдвинуть 

					for (int i = 0; i <= size_sdvig; i++)
					{
						str1[length1 + na_sk - i] = str1[length1 - i];
					}


					for (int i = 0; i < length3; i++)
						str1[poz + i] = str3[i];
				}
			}
		}


		x++;
	}

	printf("%s", str1);
}