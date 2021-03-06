#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA "../users.txt"
#define QLEN atoi(getenv("CONTENT_LENGTH")) /* defines a max length for 'query string' */
#define VLEN QLEN-8 /* defines a max length for any variable value in 'query string' */

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

/* check if username exists in user logfile, returns line number it is found on */
int findUser(char *uname, FILE *p) {
        int count = 0,i;
        char *f_uname = (char *)malloc(sizeof(char)*VLEN);

        myfgets(f_uname,VLEN-1,p);
        while (!feof(p)) {
                if (!mystrcmp(uname,f_uname))
                        return count;
                for (i=0;i<4;i++) { myfgets(f_uname,VLEN-1,p); }
                count=count+4;
        }
        return -1;
}

/* check if password matches the existing username */
int passMatch(char *pass, int line, FILE *p) {
        int i;
        char *f_pass = (char *)malloc(sizeof(char)*VLEN);

        myfgets(f_pass,VLEN-1,p);
        if (!mystrcmp(pass,f_pass)) return 1;
        else return 0;
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

/* print login success */
void printSuccess(char *uname) {
	printf("<head>"
	//"<meta http-equiv='refresh' content=\"0;url=./dashboard.py\">"
	" <title> Login Success </title> </head>"
	"<body>"
	"<form action='./dashboard.py' method='post'>"
	"	<input type='submit' name='Go to Dashboard' value='Go to Dashboard'>"
	"	<input type='hidden' name='username' value='%s'>"
	"</form>", uname);
}

/* print login password failure */
void printPFailure() {
        printf("<head><title> Login Failure </title></head>"
        "<body>"
        "	<p>Log into Tinder for Friends"
        "	<p>The password you provided was incorrect.<br>"
        "	<a href='../login.html'>Try Again</a><br>"
        "	<a href='../index.html'>Return to Welcome Page</a>");
}

/* print login username failure */
void printUFailure() {
        printf("<head><title> Login Failure </title></head>"
        "<body>"
        "<p>Log into Tinder for Friends"
        "<p>The Username you provided does not exist!<br>"
        "<a href='../login.html'>Try Again</a><br>"
        "<a href='../index.html'>Return to Welcome Page</a><br>");
}


int main(int argc, char *argv[]) {
	/* Begin HTML script */
	printf("Content-Type: text/html\n\n"
	"<html>");

	/* retrive information from html form */
	char *userinput = (char *)malloc(sizeof(char)*QLEN);
	fread(userinput, QLEN, 1, stdin);
	if (userinput == NULL) { printf("<p>ERROR CANNOT RETRIEVE USERINPUT\n"); return 2; }

	/* pull username and password from userinput */
	char *uname = getInfo(userinput, 5); 		/* retrieve username */
	char *data = strstr(userinput, "pass");
	char *pass = getInfo(data, 5); 			/* retrieve password */

	/* allocate memory */
        double *ptr_d;
        FILE *ptr_fp;

        ptr_d = (double *)malloc(BUFSIZ*sizeof(double));
        if (!ptr_d) { printf("(1) MEMORY ALLOCATION ERROR<br>"); return 1; }

        /* open user log file for reading */
        if ((ptr_fp = fopen(DATA,"r")) == NULL) { printf("(2) ERROR UNABLE TO OPEN %s<br>", DATA); return 2; }

	/* If given username is found in user log and if the password matches, login in successfull */
	int line = findUser(uname, ptr_fp);
	if (line != -1) {
		int match = passMatch(pass,line,ptr_fp);
		if (match) {
			printSuccess(uname);
		} else {
			printPFailure();
		}
	} else {
		printUFailure();
	}
	fclose(ptr_fp);
	free(ptr_d);

	/* End HTML script */
	printf("</body></html>");
	return 0;
}
