#include<stdio.h>
#include<stdlib.h>
//psuedo structure of registration page
/* 

A. validate username -- isUnique()
	- if no unique: error1 displays links to landing and login pages
	  else append username and profile info to users.txt file and display success page
*/

/* is basically a string compare method */
int isUniqueUser(char *username, char *line) {
	for ( ; ; username++, line++) {
		int d = *username - *line;
		/* if d is not 0 or we have hit the end of 'username', then username is unique */
		if (d != 0 || !*username) return d;
	}
	/* username is not unique if d == 0 */
}

//void addProfile();

void myfgets(char *array, int limit, FILE *p) {
	int i=0,c;
	if (p == NULL) { array[0]='\0'; return; }
	
	c = fgetc(p);
	while((!feof(p)) && (c != '\n') && (i < limit)) {
		array[i]=toupper(c); i++;
		c=fgetc(p);
	}
	if (i < limit) 
		array[i]='\0';
	else 
		array[limit-1]= '\0';
	
}

//this largely copies the third assignment, will modify to fit this assignment later on
int main(int argc, char *argv[]) {
	
	
	FILE *p;
	char *line;
	line = (char *)malloc(sizeof(char)*100);

	
	/* validate username by checking it against previous usernames */
	p = fopen("./users.txt", "rt");
	if (p == NULL) {
		printf("users.txt does not exist"); 
		//in which case is fine just add the username (will b the first user)
		return 2; 
	} else printf("users.txt opened successfully"); 
	
	myfgets(line,99,p);
	while (!feof(p)) {
		if (!isUniqueUser(line, p)) {
			printf("Username is not unique.\n");
			//return 1;
		} else {
			printf("Username is unique.\n");
		}
		myfgets(line,99,p);
	}
	fclose(p);
	printf("checked user uniqueness.\n");
	return 0;
}
