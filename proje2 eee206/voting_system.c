#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	char number[50]; //Using the char data type, we created number for student ID, password for password, and answer to answer the vote.
	char password[50];
	char answer[50];
};
int main(){
	int i,j,menu,yes=0,no=0;
	char user[50],pass[50];
	FILE *fp,*fp2; //We used the FILE *fp, *fp2 pointers to define the file.
	fp = fopen("file.txt","r"); //We open the file where we store our master data and we can read it.
	fp2 = fopen("file2.txt","w");  //We create a file where we write the new data.
	struct student s[3]; //We defined an array of student type consisting of 3 students.
	for(i=0;i<3;i++){  //We created a for loop where 3 users can login.
		fscanf(fp,"%s %s %s",&s[i].number,&s[i].password,&s[i].answer);  //Using fscanf, we read the fp, that is, the data in our first file.
		//We write the data we read from the file to this command.
	}
	fclose(fp);	//We close the pointer with the fclose(fp) command.
	while(1){
		printf("1.Vote\n2.Change Vote\n3.Change Password\n4.Exit\nSelect Menu[1/2/3/4]: ");scanf("%d",&menu); //We are creating an interface for our voting system.
		switch(menu){
			case 1:
				printf("\nUsername : ");scanf("%s",&user);
				i=0;
				while(strcmp(user,s[i].number)!=0&&i<3){  //We check if the username exists.
					i++;
				}
				if(i==3){
					printf("User Not Found!\n\n");  //If username is not registered, we say username not found.
				}
				else{
					printf("Password : ");scanf("%s",&pass);
					while(strcmp(pass,s[i].password)!=0){
						printf("Wrong Password! Try again : ");scanf("%s",&pass);
					}
					if(strcmp("-",s[i].answer)==0){  //If the answer is not "-", we understand that the user has voted.
						printf("Are you happy [yes/no] : ");scanf("%s",&s[i].answer);
						printf("\n");
					}
					else{
						printf("You have already anwered!\n\n");  //If the registered user has already voted, we direct the user to the interface by saying you have already answered.
					}
				}
				break;
			case 2:
				printf("\nUsername : ");scanf("%s",&user);
				i=0;
				while(strcmp(user,s[i].number)!=0&&i<3){
					i++;
				}
				if(i==3){
					printf("User Not Found!\n\n");
				}
				else{
					printf("Password : ");scanf("%s",&pass);
					while(strcmp(pass,s[i].password)!=0){
						printf("Wrong Password! Try again : ");scanf("%s",&pass);
					}
					if(strcmp("-",s[j].answer)==0){  //If the answer is "-", we understand that the user has not voted before.
						printf("You are voting first time! Are you happy [yes/no]: ");scanf("%s",&s[i].answer);  
						//If a user who has not voted before wants to change the game, we ask Are you happy by saying you are voting first time.
						printf("\n");
					}
					else{
						printf("Are you happy [yes/no] : ");scanf("%s",&s[i].answer);
						printf("\n");
					}
				}
				break;
			case 3:
				printf("\nUsername : ");scanf("%s",&user);
				i=0;
				while(strcmp(user,s[i].number)!=0&&i<3){
					i++;
				}
				if(i==3){
					printf("User Not Found!\n\n");
				}
				else{
					printf("Password : ");scanf("%s",&pass);
					while(strcmp(pass,s[i].password)!=0){
						printf("Wrong Password! Try again : ");scanf("%s",&pass);
					}
					printf("New Password : ");scanf("%s",&s[i].password);
				}
				break;
			case 4:
				for(i=0;i<3;i++){  //We create a for loop to count the yes and no votes.
					if(strcmp("yes",s[i].answer)==0){
						yes++;
					}
					else if(strcmp("no",s[i].answer)==0){
						no++;
					}
					fprintf(fp2,"%s %s %s\n",s[i].number,s[i].password,s[i].answer);  //We write new information to file2 in the same format as the file.
				}
				fclose(fp2);  //We close File2.
				remove("file.txt");  //we delete the file.
				rename("file2.txt","file.txt");  //We rename file2 as file
				printf("\n\nYes:%d\nNo:%d",yes,no);  //We write this command to display yes and no votes on the screen.
				return 0;
			default:
				printf("Invalid input!\n\n");
		}
	}	
	return 0;
}

