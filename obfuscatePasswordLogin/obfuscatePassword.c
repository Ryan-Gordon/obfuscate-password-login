//Login system which reads a login file and hides password input from user
//Ryan Gordon - ryangordon210@gmail.com
#include<stdio.h>
#include<stdlib.h>

FILE *fptr;
char approvedUsrnames[3][7];
char approvedPassword[3][7];

int login();
void openFile();
void closeFile();

void main() {
	
	login();
}
////in the login the file approvedLogins is read. The user must enter one of the logins found in the file to gain access
////There are 3 dummy logins within the file, these can be changed to represent real accounts in a application
///as the user enters chars for the password the char is read into a char array and a '*' is printed on screen
int login() {

	char userPassword[7] = "", usrname[7], inputChar;
	int i, loginOrClose = 1;;
	openFile();

	int numofLogins = 3;


	if (fptr != NULL)
	{
		printf("\nChecking for approved logins\n");
		while (!feof(fptr))
		{
			for (i = 0; i < 3; i++) {
				fscanf(fptr, "%s", approvedUsrnames[i]);
				fscanf(fptr, "%s", approvedPassword[i]);
			}

		}
		closeFile();
	}
	printf("\nWould you like to precede with login or quit?\n\n 1. Login\n 0. Close\n");
	scanf("%d", &loginOrClose);

	if (loginOrClose == 0) {
		exit(69);
	}
	else {
		printf("Enter User name: ");
		scanf("%s", usrname);
		printf("Enter the password <any 6 characters>: ");

		for (i = 0; i<6; i++)
		{

			inputChar = _getch();
			userPassword[i] = inputChar;
			inputChar = '*';
			printf("%c", inputChar);
		}//obfuscate the input to the user
		for (i = 0; i < 3; i++) {

			if (strcmp(approvedUsrnames[i], usrname) == 0) {//if user name equals one of the approved compare password
				if (strcmp(userPassword, approvedPassword[i]) == 0) {//if user password equals one of the approved grant access
					printf("\n\n\nLogin Successful!\n");
					getch();
					return 1;
					break;
				}//end nested if

			}//end if

		}//end for
		printf("\nUnsuccessful login, quitting application\n");
		getch();
		return 0;
	}


}
void openFile()
{
	fptr = fopen("approvedLogins.txt", "r");
	if (fptr == NULL)
	{
		printf("Error opening file ! Creating a file \n");
		fptr = fopen("approvedLogins.txt", "w");
		closeFile();
		openFile();
	}
	else {
		printf("Login file read successfully ! \n");
	}
}

void closeFile()
{
	fclose(fptr);
}