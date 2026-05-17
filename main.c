#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure Definition
typedef struct {
    char name[50];
    int admissionNo, age;
    float marks[3], average;
    char grade;
} Student;

// Function Prototypes
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void updateStudent(Student students[], int count);
void bestStudent(Student students[], int count);
char calculateGrade(float avg);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Best Performing Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                displayStudents(students, studentCount);
                break;

            case 3:
                searchStudent(students, studentCount);
                break;

            case 4:
                updateStudent(students, studentCount);
                break;

            case 5:
                bestStudent(students, studentCount);
                break;

            case 6:
                printf("Exiting program... Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }

    } while (choice != 6);

    return 0;
}

// Grade Calculation Function
char calculateGrade(float avg) {
    if (avg >= 70)
        return 'A';
    else if (avg >= 60)
        return 'B';
    else if (avg >= 50)
        return 'C';
    else if (avg >= 40)
        return 'D';
    else
        return 'E';
}

// Function to Add Student
void addStudent(Student students[], int *count) {

    if (*count >= MAX_STUDENTS) {
        printf("System full! Cannot add more students.\n");
        return;
    }

    Student *s = &students[*count];

    printf("\nEnter Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Admission Number: ");
    scanf("%d", &s->admissionNo);

    printf("Enter Age: ");
    scanf("%d", &s->age);

    float total = 0;

    for (int i = 0; i < 3; i++) {
        printf("Enter Marks for Subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
        total += s->marks[i];
    }

    s->average = total / 3.0;
    s->grade = calculateGrade(s->average);

    (*count)++;

    printf("Student added successfully!\n");
}

// Function to Display Students
void displayStudents(Student students[], int count) {

    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {

        printf("\nName: %s\n", students[i].name);
        printf("Admission Number: %d\n", students[i].admissionNo);
        printf("Age: %d\n", students[i].age);
        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
        printf("---------------------\n");
    }
}

// Function to Search Student
void searchStudent(Student students[], int count) {

    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchAdmn;

    printf("\nEnter Admission Number to search: ");
    scanf("%d", &searchAdmn);

    for (int i = 0; i < count; i++) {

        if (students[i].admissionNo == searchAdmn) {

            printf("\nStudent Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Admission Number: %d\n", students[i].admissionNo);
            printf("Age: %d\n", students[i].age);
            printf("Average: %.2f\n", students[i].average);
            printf("Grade: %c\n", students[i].grade);

            return;
        }
    }

    printf("Student with Admission Number %d not found.\n", searchAdmn);
}

// Function to Update Student
void updateStudent(Student students[], int count) {

    if (count == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int searchAdmn;

    printf("\nEnter Admission Number to update: ");
    scanf("%d", &searchAdmn);

    for (int i = 0; i < count; i++) {

        if (students[i].admissionNo == searchAdmn) {

            printf("\nUpdating marks for %s...\n", students[i].name);

            float total = 0;

            for (int j = 0; j < 3; j++) {

                printf("Enter new Marks for Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);

                total += students[i].marks[j];
            }

            students[i].average = total / 3.0;
            students[i].grade = calculateGrade(students[i].average);

            printf("Record updated successfully!\n");

            return;
        }
    }

    printf("Student not found.\n");
}

// Function to Find Best Student
void bestStudent(Student students[], int count) {

    if (count == 0) {
        printf("\nNo records available.\n");
        return;
    }

    int bestIdx = 0;

    for (int i = 1; i < count; i++) {

        if (students[i].average > students[bestIdx].average) {
            bestIdx = i;
        }
    }

    printf("\n--- Best Performing Student ---\n");
    printf("Name: %s\n", students[bestIdx].name);
    printf("Admission Number: %d\n", students[bestIdx].admissionNo);
    printf("Average: %.2f\n", students[bestIdx].average);
    printf("Grade: %c\n", students[bestIdx].grade);
}
