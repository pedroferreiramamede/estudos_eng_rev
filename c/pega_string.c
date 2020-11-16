#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]){
	unsigned char byte;
	int is_string = 0;	

	//printf("Arg count: %d\n", argc);
	//printf("Argumento: %s\n\n", argv[1]);

	FILE *fp;
	fp = fopen(argv[1], "r");

	if(fp == NULL){
		printf("File not ok, errno:%d\n", errno);
		return 1;
	} else {
		//printf("File ok\n\n");

		while(fread(&byte, sizeof(byte), 1, fp)){			
			if(byte >= 0x20 && byte <= 0x7e){
				printf("%c", byte);
				is_string = 1;		
			} else {
				if(is_string){
					printf("\n");
					is_string--;
				}
			}
		
		}

		fclose(fp);
		return 0;
	}	
}
