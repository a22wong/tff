#include<stdio.h>
#include<stdlib.h>

#define FDATA "./users.txt"
#define MAX 250
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

//int isValidUser(char *usrname);
//int passMatches(char *pass, char *validname);

int main(int argc, char *argv[]) {

	printf("Content-Type: text/html\n\n"
	"<html><head><title> Login </title></head>"
	"<body>");
	
//	int i;	
//	FILE *p;
//	char *fline;
//	fline = (char *)malloc(sizeof(char)*MAX);
//	char *input;
//	input = getenv("QUERY_STRING");
//
//	p = fopen(FDATA,"r");
//	if (p == NULL) {
//		printf("ERROR: Unable to open file\n");
//		return 2;
//	}

//	for (i=0;i<3;i++) { myfgets(fline,MAX-1,p); }
//	while (!feof(p)) {
//		/* parse through the file to check that username exists */
//		if (  ) {
//			return 1;
//		} else {
//			/* read the next line to check if password matches that users password */
//			if (/* if inputpassword doesn't match filepassword  */) {
//				return 2;
//			} else {
//				/* login successful: printf html login page. */
//				printf("login successfull\n");
//			}
//		}
//	}
//	fclose(p);

	printf("<a href='./dashboard.py'>text</a> ");
	printf("</body></html>");

	return 0;
}
