#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA "../users.txt"
#define QLEN atoi(getenv("CONTENT_LENGTH")) /* defines a max length for 'query string' */
#define VLEN QLEN-23 /* defines a max length for any variable within 'query string' */


/* compare two strings, return 0 if they are same (case sensitive) */
int mystrcmp(char *a, char *b) {
        for ( ; ; a++, b++) {
                int d = *a - *b;
                if (d != 0 || !*a) return d;
        }
}

/* retrives a line from a file */
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

/* check if username exists in user logfile, return 0 if not found */
int findUser(char *uname, FILE *p) {
        int count = 0,i;
        char *f_uname = (char *)malloc(sizeof(char)*VLEN);

        myfgets(f_uname,VLEN-1,p);
        while (!feof(p)) {
                if (!mystrcmp(uname,f_uname)) {
                        return count;
		}
                for (i=0;i<4;i++) { myfgets(f_uname,VLEN-1,p); }
                count=count+4;
        }
        return -1;
}

/* retrieve a specific word from a string */
char *getInfo(char *src, int n) {
        int i=0;
        char *dest = (char *)malloc(sizeof(char)*VLEN);
        char *p;

        p = src+n;
        while ( *p != '&' ) {
                if ( *p == '+' ) {
                        dest[i] = ' ';
                        p++; i++;
                } else if ( *p == '%' ) {
                        int code;
                        if (sscanf(p+1, "%2x", &code) != 1) code = '?';
                        dest[i] = code;
                        p += 2; i++;
                }
                dest[i] = *p;
                p++; i++;
        }
        return dest;
}

/* print successfull registration page */
void printSuccess() {
	printf("<head><title> Registration Success </title></head>\n\n"
	"<body>"
	"<a href='../login.html'>Click here to log-in</a>");
}

/* print failed registration page */
void printFailure() {
	printf("<head><title> Registration Failure </title></head>\n\n"
	"<body>"
	"<center><h3>We're Sorry Jargon</h3></center>"
	"<p>Your profile could not be made. Choose a better Username<br>"
	"<a href='../login.html'>Click here to try again</a><br>"
	"<a href='../index.html'>Return to Welcome page</a>");
}

int main(void) {
	/* Begin registration html page */
	printf("Content-Type: text/html\n\n"
	"<html>");

	/*  open user logfile for reading and appending, if unsuccessfull throw error meesage */
	FILE *fp;
	fp=fopen(DATA,"a+");
	if (fp == NULL) { printf("<p>ERROR CANNOT OPEN USER LOG\n"); return 1; }

	/* retrieve information from html form */
	char *userinput = (char *)malloc(sizeof(char)*QLEN);
	fread(userinput, QLEN, 1, stdin);
	if (userinput == NULL) { printf("ERROR CANNOT RETRIVE USER INPUT\n"); return 2; }

	/* pull fullname, job despription, username and password from userinput */
	char *fname = getInfo(userinput, 9); /* retrieves fullname */

	char *data = strstr(userinput, "job");
	char *djob = getInfo(data, 4); /* retrieves job description */

	data = strstr(userinput, "user");
	char *uname = getInfo(data, 5); /* retrieves username */

 	data = strstr(userinput, "pass");
	char *pass = getInfo(data, 5); /* retrieves password */

	/* If username is not found in user logfile then create user profile */
	int match = findUser(uname, fp);
	if (match == -1) {
		fprintf(fp, "%s\n", uname);
		fprintf(fp, "%s\n", pass);
		fprintf(fp, "%s\n", fname);
		fprintf(fp, "%s\n", djob);
		printSuccess();
	} else {
		printFailure();
	}
        fclose(fp);

	/* End registration html */
	printf("</body></html>");
        return 0;
}
