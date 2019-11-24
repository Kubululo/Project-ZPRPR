#include <stdio.h>
int print_specific_lenght(int original[]);
int load();
int edit(int original[], int edited[]);
int print_original( int original[]);
int print_edited(int edited[]);
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
		case 'n': 
			break;
		case 'v': 
			break;
		case 'u': 
			break;
		case 's': 
			break;
		case 'd':
			break;
		case 'h': 
			break;
		case 'c': 
			break;
		case 'k': break;
		default: break;
		}
	} while (control_command != 'k');
}
int load(){

}
int edit(int original[], int edited[]){

}
int print_original( int original[]){

}
int print_edited(int edited[]){

}
int unencrypt(int edited[]){

}
int print_histogram(int edited[]){

}
int print_specific_lenght(int original[]){

}