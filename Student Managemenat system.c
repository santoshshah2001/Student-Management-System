#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollNumber;
    char name[50];
    char course[50];
};
void addStudent(struct Student *students, int *count) {
    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Enter Name: ");
    scanf("%s", students[*count].name);

    printf("Enter Course: ");
    scanf("%s", students[*count].course);

    (*count)++;
    printf("Student added successfully!!!\n");
}
void findStudentByRollNumber(struct Student *students, int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Roll Number\tName\t\tCourse\n");
            printf("%d\t\t%s\t\t%s\n", students[i].rollNumber, students[i].name, students[i].course);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}
void findStudentByFirstName(struct Student *students, int count, const char *firstName) {
    printf("Roll Number\tName\t\tCourse\n");
    for (int i = 0; i < count; i++) {
        if (strstr(students[i].name, firstName) != NULL) {
            printf("%d\t\t%s\t\t%s\n", students[i].rollNumber, students[i].name, students[i].course);
        }
    }
}
void findStudentsByCourse(struct Student *students, int count, const char *course) {
    printf("Roll Number\tName\t\tCourse\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].course, course) == 0) {
            printf("%d\t\t%s\t\t%s\n", students[i].rollNumber, students[i].name, students[i].course);
        }
    }
}
int countStudents(struct Student *students, int count) {
    return count;
}
void deleteStudent(struct Student *students, int *count, int rollNumber) {
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with Roll Number %d deleted successfully!\n", rollNumber);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}
void updateStudent(struct Student *students, int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter updated Name: ");
            scanf("%s", students[i].name);

            printf("Enter updated Course: ");
            scanf("%s", students[i].course);

            printf("Student with Roll Number %d updated successfully!\n", rollNumber);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}
int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    do {
        printf("\nStudent Information Management System\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Find Student by First Name\n");
        printf("4. Find Students by Course\n");
        printf("5. Count Students\n");
        printf("6. Delete Student\n");
        printf("7. Update Student\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                {
                    int rollNumber;
                    printf("Enter Roll Number to find: ");
                    scanf("%d", &rollNumber);
                    findStudentByRollNumber(students, count, rollNumber);
                }
                break;
            case 3:
                {
                    char firstName[50];
                    printf("Enter First Name to find: ");
                    scanf("%s", firstName);
                    findStudentByFirstName(students, count, firstName);
                }
                break;
            case 4:
                {
                    char course[50];
                    printf("Enter Course to find students: ");
                    scanf("%s", course);
                    findStudentsByCourse(students, count, course);
                }
                break;
            case 5:
                printf("Number of students: %d\n", countStudents(students, count));
                break;
            case 6:
                {
                    int rollNumber;
                    printf("Enter Roll Number to delete: ");
                    scanf("%d", &rollNumber);
                    deleteStudent(students, &count, rollNumber);
                }
                break;
            case 7:
                {
                    int rollNumber;
                    printf("Enter Roll Number to update: ");
                    scanf("%d", &rollNumber);
                    updateStudent(students, count, rollNumber);
                }
                break;
            case 8:
                printf("you came out successfully!!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}
