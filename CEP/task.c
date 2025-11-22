
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    char title[100];
} Task;

Task *loadTask(int *count){
    FILE *fptr = fopen("Task_Database.txt", "r");

    if (fptr == NULL){
        printf("File not found");
        return;
    }


    Task *tasks = NULL;
    *count = 0;
    Task temp;

    while (fscanf(fptr, "%d | %[^\n]\n", &temp.id, temp.title) == 2) {
        tasks = realloc(tasks, sizeof(Task) * (*count + 1));
        tasks[*count] = temp;
        (*count)++;
    }

    fclose(fptr);
    return tasks;
}


void saveTasks(Task *tasks, int count){
    FILE *fptr = fopen("Task_Database.txt", "w");

    if (fptr == NULL){
        printf("File not found");
        return;
    }

    for(int i=0; i<count; i++ ){
        fprintf(fptr, "%d | %s\n", tasks[i].id, tasks[i].title);
    };

    fclose(fptr);
}


void Add() {
    int count;
    Task *tasks = loadTask(&count);

    Task newtask;
    if (count == 0){
        newtask.id = 1;
    }
    else {
        newtask.id = tasks[count - 1].id + 1;
    };

    printf("Enter Task title: ");
    scanf(" %[^\n]", newtask.title);

    tasks = realloc(tasks, sizeof(Task)*(count + 1));
    tasks[count] = newtask;
    count ++;
    

    saveTasks(tasks, count);
    free(tasks);

    printf("Task Added Successfully ✅\n");
}

void Display() {
    int count;
    Task *tasks = loadTask(&count);

    if (count == 0) {
        printf("No Task record found\n");
        return;
    }

    printf("%-5s | %-100s \n", "ID", "TITLE");
    for(int i = 0; i < count; i++){
        printf("%-5d | %-100s \n", tasks[i].id, tasks[i].title);
    }

    free(tasks);
}


void Delete(){
    int count;

    Task *tasks = loadTask(&count);

    int id;
    printf("Enter Task ID to delete: ");
    scanf("%d", &id);

    Task *newtasks = NULL;
    int newCount = 0;

    for(int i=0; i<count; i++){
        if (tasks[i].id != id){
            newtasks = realloc(newtasks, sizeof(Task) * (newCount + 1));
            newtasks[newCount] = tasks[i];
            newCount++;
        }
    }

    for(int i=0; i < newCount; i++){
        newtasks[i].id = i + 1;
    }

    saveTasks(newtasks, newCount);

    free(tasks);
    free(newtasks);

    printf("Task Deleted Successfully ✅\n");
}

void Modify() {
    int count;
    Task *tasks = loadTask(&count);

    int id;
    printf("Enter Task ID to modify: ");
    scanf("%d", &id);

    int found = 0;
    for (int i=0; i < count; i++){
        if (tasks[i].id == id) {
            printf("Enter new Title: ");
            scanf(" %[^\n]", tasks[i].title);
            found = 1;
            break;
        }
    }

    if (found){
        saveTasks(tasks, count);
        printf("Tasks Modified And Saved Successfully ✅\n");
    }
    else {
        printf("Task with the given ID not found.\n");
    }

    free(tasks);
}


int main(){
    int choice;

    while(1){
        printf("\n---Task Tracker----\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Tasks\n");
        printf("4. Modify Task\n");
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
                printf("Exiting...");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.");
        }
    }
}