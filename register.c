#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA "../users.txt"
#define MAX 250

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


/* decode query string */
void unencode(char *src, char *last, char *dest) {
	for(; src != last; src++, dest++)
		if(*src == '+' || *src == '&' )
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

/* check if username exists in user logfile, return 0 if not found */
int findUser(char *uname, FILE *p) {
        int count = 0,i;
        char *f_uname = (char *)malloc(sizeof(char)*MAX);

        for (i=0;i<3;i++) { myfgets(f_uname,MAX-1,p); }
        while (!feof(p)) {
		printf("comparing... %s and %s\n",uname,f_uname);
                if (!mystrcmp(uname,f_uname)) {
			printf("found match: %s and %s\n", uname, f_uname);
                        return count;
		}
                for (i=0;i<4;i++) { myfgets(f_uname,MAX-1,p); }
                count=count+4;
        }
        return 0;
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
	"<a href=='../index.html'>Return to Welcome page</a>");
}

int main(void) {
	/* Begin registration html page */
	printf("Content-Type: text/html\n\n"
	"<html>");

	/*  open user logfile for reading and appending, if unsuccessfull throw error meesage */
	FILE *fp;
	fp=fopen(DATA,"a+");
//	if (fp==NULL) { printf("ERROR CANNOT OPEN USER LOG\n"); return 1; }

	/* retrieve information from html form */
	char *userinput = (char *)malloc(sizeof(char)*MAX);
	char *data = (char *)malloc(sizeof(char)*MAX);
	char *fname;
	char *djob;
	char *uname;
	char *pass;
	char *endp;
	
	char *lenstr = getenv("CONTENT_LENGTH");
	int len = strtol(lenstr, &endp, 10);
	fread(userinput, len, 1, stdin);
	if (userinput == NULL) { printf("ERROR CANNOT RETRIEVE USER INPUT\n"); return 2; }
	unencode(userinput, userinput+len, data);
	sscanf(data, "fullname=%s job=%s user=%s pass=%s", fname, djob, uname, pass);

	/* temporary variables until string weurry works */
//	fname = "bukship fozket";
//	djob = "I like to fly kites for a fucking living";
//	uname = "wackshipfuzzkit";
//	pass = "milk";
	
	/* If username is not found in user logfile then create user profile */
	int match = findUser(uname, fp);
	if (!match) {
		fprintf(fp,"%s\n", fname);
		fprintf(fp,"%s\n", djob);
		fprintf(fp, "%s\n", uname);
		fprintf(fp, "%s\n", pass);
		printSuccess();
	} else {
		printFailure();
	}
        fclose(fp);

	/* End registration html */
	printf("</body></html>");
        return 0;
}
