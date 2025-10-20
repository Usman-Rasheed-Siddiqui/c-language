
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact {
    char name[50];
    char email[50];
    char phone[20];
};

void addContact(struct Contact **contacts, int *count){
    *count += 1;
    *contacts = (struct Contact *)realloc(*contacts, (*count) *sizeof(struct Contact));

    if (*contacts == NULL){
        fprintf(stderr, "Memory Allocation failed");
        exit(1);
    }

    printf("\nEnter name: ");
    scanf(" %[^\n]", (*contacts)[*count - 1].name);
    printf("\nEnter email: ");
    scanf(" %[^\n]", (*contacts)[*count - 1].email);
    printf("\nEnter phone: ");
    scanf(" %[^\n]", (*contacts)[*count - 1].phone);

    printf("Contact added successfully ✅\n");
}

void displayContact(struct Contact *contacts, int count){
    if (count == 0){
        printf("\nNo contacts found\n");
        return;
    }
    
    printf("\nAddress Book:\n");
    for (int i=0; i <count; i++){
        printf("Contact Info #%d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
        printf("Phone: %s\n", contacts[i].phone);
    }

}

void deleteContact(struct Contact **contacts, int *count){
    if (*count == 0){
        printf("\nNo counts to be deleted.\n");
        return;
    }

    int index;
    printf("Enter contact to be deleted: ");
    scanf("%d", &index);

    if (index<1 || index > *count){
        printf("Invalid contact number\n");
        return;
    }

    for(int i= index-1; i < *count-1; i++){
        (*contacts)[i] = (*contacts)[i + 1];
    }

    *count -= 1;

    *contacts = (struct Contact*)realloc(*contacts, (*count)*sizeof(struct Contact));
    
    if(*count >0 && *contacts == NULL){
        fprintf(stderr,"Memory Allocation failed\n");
        exit(1);
    }

    printf("\nContact Deleted Successfully\n");
}

int main(){
    struct Contact *contacts = NULL;
    int count = 0;
    int choice;

    while(1){
        printf("\n---Address Book----\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addContact(&contacts, &count);
                break;
            
            case 2:
                displayContact(contacts, count);
                break;
            
            case 3:
                deleteContact(&contacts, &count);
                break;
            
            case 4:
                free(contacts);
                printf("Exiting... Memory Freed Successfully!\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.");
        }
    }
}

