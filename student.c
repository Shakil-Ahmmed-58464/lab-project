#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(FILE *fp, Student *student) {
    printf("Enter Student Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    printf("Enter Student Roll: ");
    scanf("%u", &student->roll);
    getchar();

    fprintf(fp, "%s %u\n", student->name, student->roll);
    printf("Student added successfully!\n");
}

void displayStudent(FILE *fp, Student *student) {
        printf("Enter Student Roll: ");
        unsigned int roll;
        scanf("%u", &roll);
        rewind(fp);

        while (fscanf(fp, "\n%99[^0-9] %u", student->name, &student->roll) == 2 && fp != NULL)
        {
            if (student->roll == roll)
            {
                printf("Name: %s\n", student->name);
                printf("Roll: %u\n", student->roll);
                break;
            }
        }
    }

void deleteStudent(FILE *fp, Student *student) {
    printf("Enter student roll: ");
    unsigned int roll;
    scanf("%u", &roll);
    rewind(fp);
    FILE *fp2 = fopen("temp.txt", "a+");
    while (fscanf(fp, "\n%99[^0-9] %u", student->name, &student->roll) == 2 && fp != NULL) {
        if(student->roll != roll) {
            fprintf(fp2, "%s %u\n", student->name, student->roll);
        }
    }
    if (remove("students.txt") != 0 || rename("temp.txt", "students.txt") != 0) {
        printf("Failed to delete Student\n");
    } else {
        printf("Student Deleted Successfully\n");
    }
    fclose(fp2);
    
}