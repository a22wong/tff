#include<stdio.h>
#include<stdlib.h>
//psuedo structure of the login.c file
/* 
possible errors:
	1. non-existant username
		-parses through users.txt checks input against each 'username' returns
		 error1 if no match, else returns true
	2. incorrect password
		-if username matches(username returns true)  check if passward matches
		 the username. if no match return error2, else return true

A. Unsuccessfull Login (returned error1 or error2)
display errors 1 or 2:
	i. link to login page
	ii. link to landing page
B. Successfull Login (returned no errors)
	i. generates user's dashboard page
*/

int isValidUser(char *usrname);
int passMatches(char *pass, char *validname);

int main(int argc, char *argv[]) {

	FILE *p;
	char line[2000];

	if (argc != 2) {
		printf("Usage: ./a.out filename\n");
		return 1;
	} 

	p = fopen(argv[1],"rt");
	if (p == NULL) {
		printf("Invalid filename to compile.\n");
		return 2;
	}

	myfgets(line,1999,p);
	while (!feof(p)) {
		if () {

		}
	}
	fclose(p);

	return 0;
}
