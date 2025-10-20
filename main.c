#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    unsigned int roll;
} Student;

int main()
{
    printf("Welcome to Student Management System for KUET\n");
    printf("---------------------------------------------\n");

    Student Student1;
    int choice;
    printf("1. Add Student\n");
    printf("2. Display Student\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    FILE *fp = fopen("students.txt", "a+");
    if (!fp)
    {
        perror("Error opening file");
        return 1;
    }

    switch (choice)
    {
    case 1:
    {
        printf("Enter Student Name: ");
        getchar(); // consume leftover newline from scanf
        fgets(Student1.name, sizeof(Student1.name), stdin);
        Student1.name[strcspn(Student1.name, "\n")] = '\0'; // remove newline
        printf("Enter Student Roll: ");
        scanf("%u", &Student1.roll);
        fprintf(fp, "%s %u\n", Student1.name, Student1.roll);
        printf("Student added successfully!\n");
        break;
    }

    case 2:
    {
        printf("Enter Student Roll: ");
        unsigned int roll;
        scanf("%u", &roll);
        rewind(fp);

        while (fscanf(fp, " %99[^0-9] %u", Student1.name, &Student1.roll) == 2 && fp != NULL)
        {
            if (Student1.roll == roll)
            {
                printf("Name: %s\n", Student1.name);
                printf("Roll: %u\n", Student1.roll);
                break;
            }
        }
        break;
    }

    default:
        printf("Invalid choice! Please enter a number between 1 and 3.\n");
    }

    fclose(fp);
    return 0;
}
