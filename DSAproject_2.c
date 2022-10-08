#include <stdio.h>
#include <string.h>

//creating option such as 
//1)want to create file
//2)want to edit file
//3)see the changes made int the file
//4)exit the program


typedef struct alldetails
{
    int createFile;
    int editFile;
    int exitProgram;
    char fileName[30];
    int noOfMembers;
    char members[10][15];
    int idsOFMember[10];
    int totalNoOfChangesMade;
    char changesMade[10][1000];
    char NameChanges[10][10];
}files;

files f1;

int main(){

    FILE *file1; // Here we use FILE struct and pointer



    printf("                                       - - - - - - - - - - - - - - -\n");
    printf("                                       | Welcome to the mini github |\n");
    printf("                                       - - - - - - - - - - - - - - -\n");
    f1.totalNoOfChangesMade=0;
    // here we use infinte loop to run the program again and again 
    while(1){
        int a;
        // here we create the some functions which we perform in output
        printf("-----------------------------------------------\n");
        printf("| 1. Create file                              |\n");
        printf("-----------------------------------------------\n");
        printf("| 2. Edit file                                |\n");
        printf("-----------------------------------------------\n");
        printf("| 3. To see changes made in existing file     |\n");
        printf("-----------------------------------------------\n");
        printf("| 4. To preview file                          |\n");
        printf("-----------------------------------------------\n");
        printf("| 5. Exiting the program                      |\n");
        printf("-----------------------------------------------\n");
        printf("Enter the number to start:");
        scanf("%d",&a); //Here the input from user is scanned by using %d function 

        if(a==1){
            printf("Write the name of the file you want to create(with extension):");
            scanf("%s",f1.fileName);
            printf("----------------------------------------------------------------------------\n");
            printf("|Note: enter only the number of members who have the permission to edit file|\n");
            printf("----------------------------------------------------------------------------\n");
            printf("Enter the number of members:");
            scanf("%d",&f1.noOfMembers);
            //action is made to files based on input given by the user
            for (int i = 0; i < f1.noOfMembers; i++)
            {
                printf("Write the name of member %d:",i+1);
                scanf("%s",f1.members[i]);
                printf("Write the id of member %d:",i+1);
                scanf("%d",&f1.idsOFMember[i]);
            }
            printf("-----------------------------------------------------------\n");
            printf("|Congratulation! your files has been created successfully.|\n");
            printf("-----------------------------------------------------------\n");
// The file is now created successfully using input according to user's choice
            file1=fopen(f1.fileName,"a+");
        }
        else if(a==2){
            char name[15];
            int id;
            printf("Enter your name:");
            scanf("%s",name);
            printf("Enter your id:");
            scanf("%d",&id);
            int counter=0;
            int c=0;
            for (int i = 0; i < f1.noOfMembers; i++) //Name and ID are taken from user while trying to access the file
            {
                if(id==f1.idsOFMember[i] && strcmp(name,f1.members[i])==0){ 
                    counter=1;
                    c=i;
                }
            }
                //if it matches the names given previously, then ONLY access will be provided 
            if(counter==1){
                char temp[1000];
                char temp1;
                char temp2='y';
               //this is the if statement when the user name and ID do match, access is allowed 
                printf("Congratulation! %s you are allowed to make changes in file\n",f1.members[c]);
                while(temp2=='y'){ 
                    printf("Write the things you want append in file\n");
                    scanf("%c",&temp1);
                    fgets(temp,sizeof(temp),stdin);
                    printf("Do you want to append anything else(y/n):");
                    scanf("%c",&temp2);
                    fprintf(file1,"%s\n",temp);
                    strcpy(f1.changesMade[f1.totalNoOfChangesMade],temp);
                    strcpy(f1.NameChanges[f1.totalNoOfChangesMade],f1.members[c]);
                    f1.totalNoOfChangesMade++;
                    char temp3;
                    printf("Preview of file\n");
                    printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
                    fseek(file1 , 0 , SEEK_SET);
                    while((temp3 = fgetc(file1)) != EOF)
                    {
                        printf("%c", temp3);
                    } 
                    printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
                }

            }
            else{ //since name and ID entered didn't match, access is denied 
                printf("-----------------------------\n");
                printf("|Enter the valid Name and Id|\n");
                printf("-----------------------------\n");
            }
        }
        else if(a==3){
            for (int i = f1.totalNoOfChangesMade-1; i >=0; i--)
            {
                printf("%-10s added --> %s \n",f1.NameChanges[i],f1.changesMade[i]);
            }
          //prints data regarding which changes were made by every user if more than one user edits a file  
        }
        else if(a==4){
            char temp3;
            printf("Preview of the file\n");
            printf("-------------------------------------------------\n");
            fseek(file1 , 0 , SEEK_SET);
            while((temp3 = fgetc(file1)) != EOF)
            {
                printf("%c", temp3);
            }  //this opens the final file we want to view
            // for (int i = 0; i <f1.totalNoOfChangesMade; i++)
            // {
            //     printf("%s \n",f1.changesMade[i]);
            // }
            printf("-------------------------------------------------\n");
        } //the changes made are showed in stack form (LIFO) to the user
        else if(a==5){
            break;
        }
    }
}
