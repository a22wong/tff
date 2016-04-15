#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA "../users.txt"

int main(int argc, char *argv[]) {
	/* begin html page */
	printf("Content-Type: text/html\n\n"
	"<html><body>");	

	int counter;
	double *ptr_d;
	FILE *ptr_fp;

	/* temporary user registration values */
	char *username = "2nasty";
	char *password = "2milkmilk";
	char *job = "2a description";
	char *fullname = "2nastia brunette";

	/* allocate memory */
	ptr_d = (double *)malloc(10*sizeof(double));
	if (!ptr_d) { printf("(1) MEMORY ALLOCATION ERROR<br>"); return 1; }	
	else { printf("MEMORY ALLOCATION SUCCESSFULL<br>"); };

	/* open file for reading */
	if ((ptr_fp = fopen(DATA,"r")) == NULL) {
		printf("(2) UNABLE TO OPEN FILE<br>"); return 2;
	} else {
		printf("FILE OPENED SUCCESFULLY FOR READING...<BR>");
	}

	/* read file */
	if (fread(ptr_d,10 *sizeof(double), 1, ptr_fp) != 1) {
		printf("(3) READ ERROR<br>");
		return 3;
	} else {
		printf("READING %s...<br>", DATA);
	}
	fclose(ptr_fp);
	free(ptr_d);

	/* open file for writing */
	ptr_d = (double *)malloc(10*sizeof(double));
	if (!ptr_d) { printf("(4) MEMORY ALLOCATION ERROR<br>"); return 4; }
	else { printf("MEMORY ALLOCATION SUCCESSFUL<br>"); }

	if ((ptr_fp = fopen(DATA,"a")) == NULL) {
		printf("(5) ERROR UNABLE TO OPEN FILE FOR WRITING<br>");
		return 5;
	} else {
		printf("FILE OPENED SUCCESSFULLY FOR WRITING...<br>");
		fprintf(ptr_fp,"%s\n", username);
		fprintf(ptr_fp,"%s\n", password);
		fprintf(ptr_fp,"%s\n",fullname);
		fprintf(ptr_fp,"%s\n",job);
	}

	if (fwrite(ptr_d, 10*sizeof(double), 1, ptr_fp) != 1) {
		printf("(6) WRITE ERROR<br>"); 
		return 6;
	} else {
		printf("WRITE WAS SUCCESFULL<br>");
	}
	fclose(ptr_fp);

	/* free memory */
	free(ptr_d);
	
	/* close html page */
	printf("</body><html>");
	return 0;
}
