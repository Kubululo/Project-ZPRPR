#include <stdio.h>
#include <ctype.h>
void print_specific_lenght(int original[]);
void load(int original[]);
void edit(int original[], int edited[]);
void print_original(int original[]);
void print_edited(int edited[]);
void unencrypt(int edited[]);
void print_histogram(int edited[]);
int main()
{
	int original[1000], edited[1000], control_command, i, cyclecount = 0;
	for (i = 0; i < 1000; ++i)
	{
		original[i] = 0;
		edited[i] = 0;
	}
	do
	{
		control_command = getchar();
		switch (control_command)
		{
		case 'n':
			load(original);
			break;
		case 'v':
			print_original(original);
			break;
		case 'u':
			edit(original, edited);
			break;
		case 's':
			print_edited(edited);
			break;
		case 'd':
			print_specific_lenght(original);
			break;
		case 'h':
			print_histogram(edited);
			break;
		case 'c':
			unencrypt(edited);
			break;
		case 'k':
			break;
		default:
			break;
		}
		cyclecount++;
	} while (control_command != 'k');
	return 0;
}
void load(int original[])
{
	FILE *f;
	int c, i = 0, *original_p;
	original_p = &original[0];
	if ((f = fopen("sifra.txt", "r")) == NULL)
	{
		printf("Spravu sa nepodarilo nacitat\n");
	}
	while ((c = getc(f)) != EOF)
	{
		if (i < 1000)
		{
			*(original_p + i) = c;
			++i;
		}
		else
		{
			break;
		}
	}
	if (fclose(f) == EOF)
	{
		printf("Subor sa nepodarilo zatvorit\n");
	}
}
void edit(int original[], int edited[])
{
	int i, j = 0, *edited_p;
	edited_p = &edited[0];
	if (original == NULL)
	{
		printf("Sprava nie je nacitana\n");
	}
	else
	{
		for (i = 0; i < 1000; ++i)
		{
			if (isalpha(original[i]))
			{

				*(edited_p + j) = toupper(original[i]);

				++j;
			}
		}
	}
}
void print_original(int original[])
{
	int i;
	if (original == NULL)
	{
		printf("Sprava nie je nacitana\n");
	}
	else
	{
		for (i = 0; i < 1000; ++i)
		{
			if (original[i] != 0)
			{
				printf("%c", original[i]);
			}
		}
		printf("\n");
	}
}
void print_edited(int edited[])
{
	int i;
	if (edited == NULL)
	{
		printf("Sprava nie je nacitana\n");
	}
	else
	{
		for (i = 0; i < 1000; ++i)
		{
			if (edited[i] != 0)
			{
				printf("%c", edited[i]);
			}
		}
		printf("\n");
	}
}
void unencrypt(int edited[])
{
	int i = 0, k, *edited_p;
	edited_p = &edited[0];
	scanf("%d", &k);
	if (k < 1 || k > 25)
	{
		return;
	}
	if (edited == NULL)
	{
		printf("Nie je k dispozicii upravena sprava\n");
	}
	else
	{
		for (i = 0; i < 1000; ++i)
		{

			if (isupper(*(edited_p + i)) && isalpha(*(edited_p + i)))
			{

				*(edited_p + i) = *(edited_p + i) - k;

				if (!isalpha(*(edited_p + i)))
				{
					*(edited_p + i) = 'Z' - k + 1;
				}
				printf("%c", *(edited_p + i));
			}
		}
		printf("\n");
	}
}
void print_histogram(int edited[])
{
	int i = 0, j, counter = 0, char_number[26];
	double perc[26], max = 0;
	if (edited == NULL)
	{
		printf("Nie je k dispozicii upravena sprava\n");
	}

	for (i = 0; i < 26; ++i)
	{
		char_number[i] = 0;
	}
	i = 0;
	do
	{
		j = edited[i] - 65;
		if (isalpha(j + 65) && isupper(j + 65))
		{
			++char_number[j];
			++counter;
		}
		++i;
	} while (isalpha(edited[i]) && isupper(edited[i]));

	for (i = 0; i < 26; ++i)
	{
		perc[i] = char_number[i];
		perc[i] /= counter;
		perc[i] *= 100;
		if (perc[i] > max)
		{
			max = perc[i];
		}
	}

	if (max >= 90)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 90)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 80)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 80)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 70)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 70)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 60)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 60)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 50)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 50)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 40)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 40)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 30)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 30)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 20)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 20)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 10)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 10)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 0)
	{
		for (i = 0; i < 26; ++i)
		{
			if (perc[i] > 0)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < 26; ++i)
	{
		printf("%c ", i + 65);
	}
	printf("\n");
}
void print_specific_lenght(int original[])
{
	int i, j = 0, k, lenght = 0;
	scanf("%d", &k);
	int word[1000];
	for (i = 0; i < 1000; ++i)
	{
		word[i] = 0;
	}
	if (k < 1 || k > 100)
	{
		return;
	}
	if (original == NULL)
	{
		printf("Sprava nie je nacitana\n");
	}
	else
	{
		for (i = 0; i < 1000; ++i)
		{
			if (original[i] != ' ' && original[i] != '\0' && original[i] != 0)
			{
				word[j] = original[i];
				++j;
				++lenght;
			}
			if (original[i] == ' ' || original[i] == '\0')
			{
				if (lenght == k)
				{
					for (j = 0; j < k; ++j)
					{
						printf("%c", word[j]);
						word[j] = 0;
					}
					printf("\n");
				}
				j = 0;
				lenght = 0;
			}
		}
	}
}