#include <stdio.h>
#include <string.h>
#include "student.h"

int main() {
    printf("Welcome to Student Management System for KUET\n");
    printf("---------------------------------------------\n");

    Student student1;
    int choice;

    printf("1. Add Student\n");
    printf("2. Display Student\n");
    printf("3. Delete Student\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    FILE *fp = fopen("students.txt", "a+");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    switch(choice) {
        case 1: {
            addStudent(fp, &student1);
            break;
        }
        case 2: {
            displayStudent(fp, &student1);
            break;
        }
        case 3: {
            deleteStudent(fp, &student1);
            break;
        }
    }
    
    fclose(fp);
    return 0;
}
