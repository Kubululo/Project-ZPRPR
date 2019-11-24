#include <stdio.h>
#include <ctype.h>
int print_specific_lenght(int original[]);
int load();
int edit(int original[], int edited[]);
void print_original( int original[]);
void print_edited(int edited[]);
int unencrypt(int edited[]);
void print_histogram(int edited[]);
void main(){
    int original[1000],edited[1000],control_command,i;
    for(i=0;i<1000;++i){
        original[i]=0;
        edited[i]=0;
    }
    do {
		control_command = getchar();
		switch (control_command) {
		case 'n': original = load();
			break;
		case 'v': print_original(original);
			break;
		case 'u': edited = edit(original);
			break;
		case 's': print_edited(edited);
			break;
		case 'd':
			break;
		case 'h': print_histogram(edited);
			break;
		case 'c': edited = unencrypt(edited);
			break;
		case 'k': break;
		default: break;
		}
	} while (control_command != 'k');
}
int load(){
	FILE* f;
	int c, i = 0,original[1000];
	if ((f = fopen("sifra.txt", "r")) == NULL) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}

	while ((c = getc(f)) != EOF) {
		if (i < 1000) {
			original[i] = c;
			++i;
		}
		else {
			break;
		}
	}
	if (fclose(f) == EOF) {
		printf("Subor sa nepodarilo zatvorit\n");
	}

	return original;
}
int edit(int original[]){
	int i, j = 0,edited[1000];
	if (original == NULL) {
		printf("Sprava nie je nacitana\n");
	}
	else {
		for (i = 0; i < 1000; ++i) 
		{
			if (isalpha(original[i])) 
			{
				
				edited[j] = toupper(original[i]);
				
				++j;
			}
		}
	}

	return edited;
}
void print_original( int original[]){
	int i;
	if (original == NULL) {
		printf("Sprava nie je nacitana\n");
	}
	else {
		for (i = 0; i < 1000; ++i) {
			if(original[i] != 0){
				printf("%c", original[i]);
			}
		}
		printf("\n");
	}
}
void print_edited(int edited[]){
	int i;
	if (edited == NULL) {
		printf("Sprava nie je nacitana\n");
	}
	else {
		for (i = 0; i < 1000; ++i) {
			if(edited[i] != 0){
				printf("%c", edited[i]);
			}
		}
		printf("\n");
	}
}
int unencrypt(int edited[]){
	int j = 0, k;
	scanf("%d", &k);
	if (k < 1 || k > 25) {
		return 0;
	}

	if (edited == NULL) {
		printf("Nie je k dispozicii upravena sprava\n");
	}
	else {
		for (j = 0; j < 1000; ++j) 
		{
			
			if (isupper(edited[j] && isalpha(edited[j]))) {
				
				edited[j] = edited[j] - k;
				
				if (!isalpha(edited[j])) {
					edited[j] = 'Z' - k + 1;
				}
				printf("%c", edited[j]);
			}
		}
		printf("\n");
	}
	return edited;
}
void print_histogram(int edited[]){
	int i = 0, j, counter = 0, char_number[26];
	double perc[26], max = 0;
	if (edited == NULL) {
		printf("Nie je k dispozicii upravena sprava\n");
		return 0;
	}

	for (i = 0; i < 26; ++i) {
		char_number[i] = 0;
	}
	i = 0;
	do {
		j = edited[i] - 65;
		if (isalpha(j + 65) && isupper(j + 65)) {
			++char_number[j];
			++counter;
		}
		++i;
	} while (isalpha(edited[i]) && isupper(edited[i]));

	for (i = 0; i < 26; ++i) {
		perc[i] = char_number[i];
		perc[i] /= counter;
		perc[i] *= 100;
		if (perc[i] > max) {
			max = perc[i];
		}

	}
	
	if (max >= 90) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 90) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 80) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 80) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 70) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 70) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 60) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 60) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 50) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 50) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 40) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 40) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

	if (max >= 30) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 30) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}if (max >= 20) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 20) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	
	if (max >= 10) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 10) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	if (max >= 0) {
		for (i = 0; i < 26; ++i) {
			if (perc[i] > 0) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < 26; ++i) {
		printf("%c ", i + 65);
	}
	printf("\n");

	return 0;
}
int print_specific_lenght(int original[]){

}