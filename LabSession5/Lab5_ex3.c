
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Add(){
    FILE *fptr = fopen("Student_Database.txt", "a+");
    if(fptr == NULL){

        printf("Unable to open the file");
        exit(1);
    }
    char name[30], dept[30], cgpa[5], roll[10];
    printf("\nEnter student's name: ");
    scanf(" %[^\n]",name);
    printf("\nEnter student's department: ");
    scanf(" %[^\n]",dept);
    printf("\nEnter student's roll number: ");
    scanf(" %[^\n]",roll);
    printf("\nEnter student's CPGA: ");
    scanf(" %[^\n]",cgpa);

    fprintf(fptr,"%-10s | %-25s | %-30s | %-5s\n", roll, name, dept, cgpa);

    printf("\nStudent record added successfully ✅\n");
    fclose(fptr);
}


void Modify(){
    FILE *fptr = fopen("Student_Database.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if(fptr == NULL || temp == NULL){

        printf("Unable to open the file");
        exit(1);
    }

    char roll[10], searchRoll[10];
    char name[30], dept[30], cgpa[5];
    char line[200];
    int found = 0;

    printf("Enter roll number of student to modify: ");
    scanf(" %[^\n]",searchRoll);
    
    while(fgets(line, sizeof(line), fptr)){

        sscanf(line, "%s", roll);

        if(strcmp(roll, searchRoll) == 0){
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]",name);
            printf("Enter new department: ");
            scanf(" %[^\n]",dept);
            printf("Enter new CGPA: ");
            scanf(" %[^\n]",cgpa);

            fprintf(temp, "%-10s | %-25s | %-30s | %-5s\n", roll, name, dept, cgpa);
        }
        else{
            fputs(line, temp);
        }
    }
    fclose(fptr);
    fclose(temp);

    remove("Student_Database.txt");
    rename("temp.txt", "Student_Database.txt");

    if (found)
        printf("\nRecord modified successfully!\n");
    else
        printf("\nRecord not found!\n");

}

void Delete(){
    FILE *fptr = fopen("Student_Database.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    
    if(fptr == NULL || temp == NULL){
        printf("Unable to open the file");
        exit(1);
    }
    char roll[10], name[30], dept[30], cgpa[5];
    char searchRoll[10];
    char line[200];
    int found = 0;

    printf("Enter the roll number of student to be delete: ");
    scanf(" %[^\n]",searchRoll);

    while(fgets(line, sizeof(line), fptr)){

        sscanf(line, "%s", roll);

        if(strcmp(searchRoll, roll) != 0){
            fputs(line, temp);
        }
        else{
            found = 1;
        }
    }
    fclose(fptr);
    fclose(temp);

    remove("Student_Database.txt");
    rename("temp.txt", "Student_Database.txt");

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nRecord not found!\n");

}

void Display(){
    FILE *fptr = fopen("Student_Database.txt", "r");

    if(fptr == NULL){
        printf("Unable to open the file");
        exit(1);
    }

    char line[200];
    int found = 0;


    printf("\n%-10s | %-25s | %-30s | %-5s\n", "ROLL NO.", "NAME", "DEPARTMENT", "CGPA");
    printf("-------------------------------------------------------------------------------\n");
    while(fgets(line, sizeof(line), fptr)){
        printf("%s", line);
        }

    fclose(fptr);
}

int main(){

    FILE *fptr = fopen("Student_Database.txt", "a+");
    if(fptr == NULL){
        printf("Unable to open the file");
        exit(1);
    }
    fclose(fptr);

    int choice;

    while(1){
        printf("\n---Student's Database Menu----\n");
        printf("1. Add Student's Record\n");
        printf("2. Display Record\n");
        printf("3. Delete Student's Record\n");
        printf("4. Edit Student's Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                Add();
                break;
            
            case 2:
                Display();
                break;
            
            case 3:
                Delete();
                break;
            
            case 4:
                Modify();
                break;

            case 5:
                fclose(fptr);
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.");
        }
    }
}



