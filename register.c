#include<stdio.h>
#include<stdlib.h>
//psuedo structure of registration page
/* 

A. validate username -- isUnique()
	- if no unique: error1 displays links to landing and login pages
	  else append username and profile info to users.txt file and display success page
*/

int isUnique(char *username);
void addProfile();


//this largely copies the third assignment, will modify to fit this assignment later on
int main(int argc, char *argv[]) {
	
	FILE *p;
	char line[2000];

	if (argc != 2) {
		printf("Wrong syntax: ./a.out filename\n");
		return 1;
	}

	p = fopen(argv[1], "rt");
	if (p == NULL) {
		printf("Invalid filename to compile.\n");
		return 2;
	}

	fgets(line, 1999, p);
	while (!feof(p)) {
		
	}
	fclose(p);
	return 0;
}
