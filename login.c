#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA "../users.txt"
#define MAX 50

/* compare two strings (case sensitive) */
int mystrcmp(char *a, char *b) {
        for ( ; ; a++, b++) {
                int d = *a - *b;
                if (d != 0 || !*a) return d;
        }
}

/* retrive a line from a file */
void myfgets(char array[], int limit, FILE *p) {
        int i=0,c;
        if (p==NULL) { array[0]='\0'; return; }

        c=fgetc(p);
        while(!feof(p) && c != '\n' && i<limit) {
                array[i]=c; i++;
                c=fgetc(p);
        }
        if (i<limit) array[i]='\0'; else array[limit-1]='\0';
}

/* decode qeurystring */
void unencode(char *src, char *last, char *dest) {
	for( ; src != last; src++, dest++)
		if (*src == '+' || *src == '&' )
			*dest = ' ';
		else if (*src == '%') {
			int code;
     			if (sscanf(src+1, "%2x", &code) != 1) code = '?';
     			*dest = code;
     			src += 2; 
		} else
     			*dest = *src;
	*dest = '\n';
	*++dest = '\0';
}

/* check if username exists in user logfile */
int findUser(char *uname, FILE *p) {
        int count = 0,i;
        char *f_uname = (char *)malloc(sizeof(char)*MAX);

        for (i=0;i<3;i++) { myfgets(f_uname,MAX-1,p); }
        while (!feof(p)) {
                if (!mystrcmp(uname,f_uname))
                        return count;
                for (i=0;i<4;i++) { myfgets(f_uname,MAX-1,p); }
                count=count+4;
        }
        return 0;
}

/* check if password matches the existing username */
int passMatch(char *pass, int line, FILE *p) {
        int i;
        char *f_pass = (char *)malloc(sizeof(char)*MAX);

        myfgets(f_pass,MAX-1,p);
        if (!mystrcmp(pass,f_pass)) return 1;
        else return 0;
}

/* print login success */
void printSuccess() {
        printf("<head>"
//	"<meta http-equiv='refresh' content=\"0; url='../dashboard.html'/>"
	"<title> Login Success </title><head>"
        "<body>"
	"<a href='./dashboard.py'>link to dashboard</a>");
}

/* print login password failure */
void printPFailure() {
        printf("<head><title> Login Failure </title></head>"
        "<body>"
        "<p>Log into Tinder for Friends"
        "<p>The password you provided was incorrect.<br>"
        "<a href='../login.html'>Try Again</a><br>"
        "<a href='../index.html'>Return to Welcome Page</a>");
}

/* print login username failure */
void printUFailure() {
        printf("<head><title> Login Failure </title></head>"
        "<body>"
        "<p>Log into Tinder for Friends"
        "<p>The Username you provided does not match!<br>"
        "<a href='../login.html'>Try Again</a><br>"
        "<a href='../index.html'>Return to Welcome Page</a><br>");
}


int main(int argc, char *argv[]) {
	/* Begin HTML script */
	printf("Content-Type: text/html\n\n"
	"<html>");

	/* open user logfile for reading, if unsuccessfull open throw error message */
	FILE *fp;
	fp=fopen(DATA,"r");
	if (fp==NULL) { printf("ERROR CANNOT OPEN USER LOG\n"); return 1; }

	/* retrive information from html form */
	char *userinput = (char *)malloc(sizeof(char)*MAX);
	char *data = (char *)malloc(sizeof(char)*MAX);
	char *uname = (char *)malloc(sizeof(char)*MAX);
	char *pass = (char *)malloc(sizeof(char)*MAX);
	char *endp;
	
	char *lenstr = getenv("CONTENT_LENGTH");
	int len = strtol(lenstr,&endp,10);
	fread(userinput, len, 1, stdin);
	if (userinput==NULL) { printf("ERROR CANNOT RETRIEVE USER INPUT\n"); return 2; }
	unencode(userinput, userinput+len, data);
	sscanf(data, "user=%s pass=%s", uname, pass);

	/* If given username is found in user log and if the password matches, login in successfull */
	int line = findUser(uname, fp);
	if (line) {
		int match = passMatch(pass,line,fp);
		if (match) {
			printSuccess();
		} else {
			printPFailure();
		}
	} else {
		printUFailure();
	}

	fclose(fp);

	/* End HTML script */
	printf("</body></html>");
	return 0;
}
