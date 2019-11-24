#include <stdio.h>
#include <ctype.h>
int print_specific_lenght(int original[]);
int load();
int edit(int original[], int edited[]);
void print_original( int original[]);
void print_edited(int edited[]);
int unencrypt(int edited[]);
int print_histogram(int edited[]);
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
		case 'h': 
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
int print_histogram(int edited[]){

}
int print_specific_lenght(int original[]){

}