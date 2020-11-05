#include <stdio.h>

int my_isalpha(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return 1;
	else  return 0;
}

int count_length(char* str)
{
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++) length++;

	if (str[length - 1] == '\n')
	{
		str[length - 1] = '\0';
		length--;
	}
	return length;
}

void change_word(int poz, int length, char* str1, char* str3)
{
	for (int i = 0; i < length; i++)
		str1[poz + i] = str3[i];
}

int isword(char* str)
{
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
		if (my_isalpha(str[i]) == 0) return 0;
	return 1;
}


int main()
{
	char str1[1000];
	char str2[1000];
	char str3[1000];

	int length2;
	int length3;


	printf("Input string:\n");
	fgets(str1, 1000, stdin);

	
    printf("Input word that we should change:");
	fgets(str2, 1000, stdin);
	if (isword(str2) == 0)
	{
		printf("Incorrect input.You should type a word");
		return 0;
	}
		
	


	printf("Transform this word to ");
	fgets(str3, 1000, stdin);
	if (isword(str3) == 0)
	{
		printf("Incorrect input.You should type a word");
		return 0;
	}
	


	length2 = count_length(str2);
	length3 = count_length(str3);


	int flag, poz;
	int x = 0;
	while (str1[x] != '\0')
	{
		int length1 = count_length(str1);

		for (int j = 0; str1[j]; j++)
		{
			flag = 1;
			for (int i = 0; i < length2; i++) //нахождение подстроки
			{
				if (str1[j + i] != str2[i])
					flag = 0;
			}

			if (flag == 1) //проверка на то,является ли подстрока словом
			{
				if ((j != 0 && my_isalpha(str1[j - 1]) || my_isalpha(str1[j + length2])))
				{
					flag = 0;
				}
				else
				{
					poz = j;
					break;
				}
			}

		}

		if (flag == 1)
		{
			if (length2 == length3) change_word(poz, length3, str1, str3);

			else
			{
				int end_word = poz + length2;

				if (length2 > length3)
				{
					int na_sk = length2 - length3;

					for (int i = 0; str1[end_word + i - 1] != '\0'; i++)
					{
						str1[end_word - na_sk + i] = str1[end_word + i]; //сужение строки
					}

					change_word(poz, length3, str1, str3);

				}
				if (length2 < length3)
				{

					int na_sk = length3 - length2;
					int size_of_sdvig = length1 - end_word; //сколько символов нужно сдвинуть

					for (int i = 0; i <= size_of_sdvig; i++)
					{
						str1[length1 + na_sk - i] = str1[length1 - i];//расширение строки
					}

					change_word(poz, length3, str1, str3);

				}
			}
		}

		x++;
	}

	printf("%s", str1);
}