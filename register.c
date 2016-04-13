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
int unQstring(char *str) {
	unsigned int i;
	char tmp[MAX];
	char *ptr = tmp;
	memset(tmp, 0, sizeof(tmp));

	for (i=0; i <strlen(str); i++) {
		if (str[i] != '%') { *ptr++ = str[i]; continue;  }
		if (!isdigit(str[i+1]) || !isdigit(str[i+2])) { *ptr++ = str[i]; continue; }
		*ptr++ = ((str[i+1] - '0') << 4) | (str[i+2] - '0');
		i += 2;
	}
	*ptr = '\0';
	strcpy(str, tmp);
	return 0;
}

void printSuccess() {
	printf("Content-Type: text/html; charset:iso-8859-1\n\n"
	"<html>"
	"<head><title> Registration Success </title></head>"
	"<body>"
	"<center><h3> Welcome to Tinder for Friends </h3> </center><br>"
//	"\n Registration was a success >> link to dashboard page \n"
	"<a href='../tff/login.html'>Click here to log-in</a>"
	"</body>"
	"</html>");
}
void printFailure() {
	printf("Content-Type: text/html; charset:iso-8859-1\n\n"
	"<html><head><title> Registration Failure </title></head>"
	"<body>"
//	"\nregistration failed >> link to login page or welcome page\n"
	"<center><h3>We're Sorry Jargon</h3></center>"
	"<p>Your profile could not be made. Choose a better Username"
	"<a href='../tff/login.html'>Click here to try again</a><br>"
	"<a href=='../tff/index.html'>Return to Welcome page</a>"
	"</body></html>");
}

int main(void) {
//	char *uName=(char *)malloc(sizeof(char)*MAX);
	char *data;
	data = getenv("QUERY_STRING");
	if (data == NULL) {
		/* "ERROR: Unsuccessful data transfer from form to script.\n" */
		printf("ERROR: QUERY_STRING not found.\n"); return 1;
//		printf("Content-Type: text/html; charset:iso-8859-1\n\n"
//		"<html>"
//		"<head><title> QUERY_STRIG ERROR </title></head>"
//		"<body><p>ERROR: Unsuccessfull data transfer from form to script.</p></body></html>");
	} else {
	// this doesn't work because there are no spaces in qeury string
//		sscanf(data,"user=%s",uName);
		printf("%s",data);
		unQstring(data);
		printf("%s",data);
	}

//        FILE *p = fopen(FDATA, "rw");
//        char *line;
//        int r_status;
//        line = (char *)malloc(sizeof(char)*MAX);

//        if (p == NULL) {
////                printf("Congrats you're our first subscriber!\n");
//	/* write data into new users.txt file */
//		FILE *users;
//		users = fopen("users.txt", "w");
//		if (users == NULL) {
////			printf("ERROR: Cannot open users.txt.\n");
//			return EXIT_FAILURE;
//		} 
//		fprintf(fp, "%s", data);
////		fprintf(users,"%s","FULLNAME\nJOB DESCRIPTION\nUsername\nPASSWORD\n");		
//                return 0;
//       } else {
////		printf("checking if %s is unique...\n",uName);
//		int i;
//		for (i=0;i<3;i++) { myfgets(line,MAX-1,p); }
//	        while(!feof(p)) {
// //   	        	printf("comparing ... %s to %s\n", uName, line);
//  	        	/* if isUnique returns 0, then person has entered a pre-existing username */
//              		if (!isUnique(uName, line)) {
//    //            		printf("%s matches %s! Cannot create user profile.\n", uName, line);
//                		r_status = 0;
//               	  	} else {
//      //                  	printf("%s does not match %s\n", uName, line);
//                        	r_status = 1;
//                	}
//                for (i=0;i<4;i++) { myfgets(line,MAX-1,p); }
//        	}
//	}
//        fclose(p);
        printf("compile completed.\n");

//        if (r_status) {
//                /* redirect to new user profile */
//              printf("\nThe user profile has been created.\n");
//	      printSuccess();
//        } else {
//                /* redirect to login/registration page */
//              printf("\nThe user profile was not made.\n");
//	      printFailure();
//        }
        return 0;
}
