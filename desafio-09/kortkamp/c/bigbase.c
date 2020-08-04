#include <stdlib.h>
#include <stdio.h>
	
int convert(int input_base,int output_base,char *input, char *output){
	printf("%d,%d,%s\n", input_base, output_base, input);
	return(0);
}

int main(int argc, char *argv[]){
	FILE *pf;
	int input_base;
	int output_base;
	char input[1000];	
       	char output[1000];
	if(argc < 2){
	       	printf("Usage: %s filename\n",argv[0]);
		return(0);
	}
	pf = fopen(argv[1], "r");	
	if(pf == NULL){
		fprintf(stderr,"Error opening file %s",argv[1] );
		return(-1);
	}
	while( fscanf(pf,"%d %d %s",&input_base,&output_base,input) != EOF){
		if(ferror(pf)){
			perror("Erro lendo o arquivo");
			return(-1);
		}
		convert(input_base, output_base,input, output);
		printf("%s\n",output);
	}

	fclose(pf);
	return(0);
}
