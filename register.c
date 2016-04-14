#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FDATA "./users.txt"
#define MAX 250
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


/* note to anna: dont use this code */
void unencode(char *src, char *last, char *dest)
{
 for(; src != last; src++, dest++)
   if(*src == '+' )
     *dest = ' ';
   else if (*src == '%') {
     int code;
     if (sscanf(src+1, "%2x", &code) != 1) code = '?';
     *dest = code;
     src += 2; }     
   else
     *dest = *src;
 *dest = '\n';
 *++dest = '\0';
}

void printSuccess() {
	printf("<html><head><title> Registration Success </title></head>"
	"<body>"
	"<center><h3> Welcome to Tinder for Friends </h3> </center><br>"
//	"\n Registration was a success >> link to dashboard page \n"
	"<a href='../tff/login.html'>Click here to log-in</a>"
	"</body>"
	"</html>");
}
void printFailure() {
	printf("<html><head><title> Registration Failure </title></head>"
	"<body>"
//	"\nregistration failed >> link to login page or welcome page\n"
	"<center><h3>We're Sorry Jargon</h3></center>"
	"<p>Your profile could not be made. Choose a better Username"
	"<a href='../tff/login.html'>Click here to try again</a><br>"
	"<a href=='../tff/index.html'>Return to Welcome page</a>"
	"</body></html>");
}

int main(void) {

	printf("Content-Type: text/html\n\n"
	"<html><head><title> Registration Page </title></head>\n"
	"<body>");

	char *uname = (char *)malloc(sizeof(char)*50);
	char *data = getenv("QUERY_STRING");
	if (data == NULL) {
		/* "ERROR: Unsuccessful data transfer from form to script.\n" */
		printf("<p>ERROR: QUERY_STRING not found.\n"
		"</body></html>");
		return 1;
	} else {
	//	char *uname = (char *)malloc(sizeof(char)*50);
//		char *undata = (char *)malloc(sizeof(char)*50);
//		printf("<p>Q_STRING success...");
//		unencode(data,data+45,undata);
//		sscanf(undata,"user=%s",uname);
//		printf("Welcome user: %s\n",user);
		uname = "astath";		
//		printf("</body></html>");
	}

        FILE *p = fopen(FDATA, "a+");
        char *line = (char *)malloc(sizeof(char)*MAX);
	int r_status;

        if (p == NULL) {
		/* users.txt didn't open send error */
		printf("<p><center><h1>ERROR 101: Could not open datafile.</h1></center>\n"
		"</body></html>\n");
		return 1;
//		FILE *users;
//		users = fopen("users.txt", "a");
//		if (users == NULL) {
//			printf("ERROR: Cannot open users.txt.\n");
//			return EXIT_FAILURE;
//		} 
//		fprintf(users, "%s\n%s\n%s\n%s\n", fullname, job, user, pass);
////		fprintf(users,"%s","FULLNAME\nJOB DESCRIPTION\nUsername\nPASSWORD\n");		
//                return 0;
       } else {
		/* users.txt opened successfully check the file for uniqueness */
//		printf("checking if %s is unique...\n",uName);
		int i;
		for (i=0;i<3;i++) { myfgets(line,MAX-1,p); }
	        while(!feof(p)) {
 //   	        	printf("comparing ... %s to %s\n", uName, line);
  	        	/* if isUnique returns 0, then person has entered a pre-existing username */
              		if (!isUnique(uname, line)) {
    //            		printf("%s matches %s! Cannot create user profile.\n", uName, line);
                		r_status = 0;
               	  	} else {
      //                  	printf("%s does not match %s\n", uName, line);
                        	r_status = 1;
                	}
                for (i=0;i<4;i++) { myfgets(line,MAX-1,p); }
        	}
	}
        fclose(p);
//        printf("compile completed.\n");

        if (r_status) {
                /* redirect to new user profile */
              printf("\nThe user profile has been created.\n");
//	      printSuccess();
        } else {
                /* redirect to login/registration page */
              printf("\nThe user profile was not made.\n");
//	      printFailure();
        }
	printf("</body></html>");

        return 0;
}
