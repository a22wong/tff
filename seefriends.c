#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QLEN atoi(getenv("CONTENT_LENGTH"))

//global username
char *currUser;

void printFriend(char *user){
	printf("<input type='radio' name='frienduser' value=%s>%s<br>",user, user);
}

void getUser() {
	char *input = (char *)malloc(sizeof(char)*QLEN);
	fread(input, QLEN, 1, stdin);
	if(input == NULL) { printf("ERROR: NO INPUT\n"); }
	else printf("Input: %s\n", input);
	currUser = (char *)malloc(sizeof(char)*(sizeof(input)-9));
	currUser = input+9;
}

int main() {
	printf("Content-Type: text/html\n\n");
	printf("<html><title>View a Friend's profile</title>");
	printf("<body><center>");
	getUser();
	//currUser = "bob";
	FILE *f = fopen("../friends.txt", "r");
	
	char *line = (char *)malloc(sizeof(char)*1000);
        fgets(line, 1000, f);
	
	printf("<form>");
	//loop through each line of file
	while(!feof(f)) {
		char *token = strtok(line, " ");
		//if first tok in line is currUser, display friends
		if(!strcmp(currUser,token)) {
			printf("Friends of %s:<br>", token);
			while((token=strtok(NULL, " "))!=NULL) {
				printFriend(token);
				//token still takes \n after last token
				//printf("%s, ", token);
			}
		}
		fgets(line, 1000, f);
	}
	printf("<input type='submit' value='Submit'>");
	printf("</form>");


	//printf("Logged in as: %s\n",currUser);
	printf("</center></body></html>");
}
