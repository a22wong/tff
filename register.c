#include<stdio.h>
#include<stdlib.h>

#define FDATA "./users.txt"
#define MAX 250
//psuedo structure of registration page
/* 
A. validate username -- isUnique()
	- if no unique: error1 displays links to landing and login pages
	  else append username and profile info to users.txt file and display success page
*/

/* is basically a string compare method */
int isUnique(char *username, char *line) {
	for ( ; ; username++, line++) {
		int d = *username - *line;
		/* if d is not 0 or we have hit the end of 'username', then username is unique */
		if (d != 0 || !*username) return d;
	}
	/* username is not unique if d == 0 */
}

void myfgets(char *array, int limit, FILE *p) {
	int i=0, c;
	if (p == NULL) { array[0]='\0'; return; }
	c = fgetc(p);
	while(!feof(p) && c != '\n' && i < limit) {
		array[i]=c; i++;
		c=fgetc(p);
	}
	if (i < limit) array[i]='\0';
	else array[limit-1]= '\0';
	
}

int isValidUser(char *uname, FILE *p);
void printSuccess() {
	printf("Content-Type: text/html; charset:iso-8859-1\n\n"
	"<html>"
	"<head><title> Registration Success </title></head>"
	"<body>"
	"\n Registration was a success >> link to dashboard page \n"
	"</body>"
	"</html>"
	);
}
void printFailure() {
	printf("Content-Type: text/html; charset:iso-8859-1\n\n"
	"<html><head><title> Registration Failure </title></head>"
	"<body>"
	"\nregistration failed >> link to login page or welcome page\n"
	"</body></html>");
}


void printTop() {
	printf("<!DOCTYPE HTML>\n\n"
	"<html lang='en'>"
            "<head>"
                "<meta name='author' content='Annastasia Stathakos'>"
                "<meta name='description' content='success page for registration'>"
                "<meta charset='UTF-8'>"
                "<title> Registration Page </title>"

                "<!-- will make a style sheet that matches whatever ethan designs -->"
                "<link rel='stylesheet' type='text/css' href='style.css'>"
            "</head>"
	"</body>");
}

void printTail() {
	printf("</body></html>");
}

int main(void) {
        /* pretending to read from html form */
        char *uName = "Username";
        char *uname = "username";
	char *data;

	data = getenv("QUERY_STRING");
	if (data == NULL) {
		printf("<p>Error! Error in passing data from form to script.\n");
	} else {
		/* i wanna see what the query string looks like so:  */
		printf("%s\n", data);
	}

        FILE *p = fopen(FDATA, "rw");
        char *line;
        int r_status;
        line = (char *)malloc(sizeof(char)*100);

        if (p == NULL) {
                printf("Congrats you're our first subscriber!\n");
	/* write data into new users.txt file */
		FILE *users;
		users = fopen("users.txt", "w");
		if (users == NULL) {
			printf("ERROR: Cannot open users.txt.\n");
			return EXIT_FAILURE;
		} 
//		fprintf(fp, "%s", data);
		fprintf(users,"%s","FULLNAME\nJOB DESCRIPTION\nUSERNAME\nPASSWORD\n");		
                return 0;
        }

        myfgets(line,MAX-1,p);
	myfgets(line,MAX-1,p);
	myfgets(line,MAX-1,p);
        while(!feof(p)) {
                printf("comparing ... %s to %s\n", uName, line);
                /* if isUnique returns 0, then person has entered a pre-existing username */
                if (!isUnique(uName, line)) {
                        printf("%s matches %s! Cannot create user profile.\n", uName, line);
                        r_status = 0;
                } else {
                        printf("%s does not match %s\n", uName, line);
                        r_status = 1;
                }
                int i;
		myfgets(line,MAX-1,p);
		myfgets(line,MAX-1,p);
		myfgets(line,MAX-1,p);
		myfgets(line,MAX-1,p);
        }
        fclose(p);
        printf("compile completed.\n");

        if (r_status) {
                /* redirect to new user profile */
            //    printTop();
              printf("\nThe user profile has been created.\n");
	      printSuccess();
          //      printTail();
        } else {
                /* redirect to login/registration page */
              //  printTop();
              printf("\nThe user profile was not made.\n");
	      printFailure();
              //  printTail();
        }
        return 0;
}
