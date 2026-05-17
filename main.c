#include <stdio.h>
#include <string.h>

// Structure to store student details
typedef struct
{
    char name[50];
    int admissionNo;
    int age;
    float marks[3];
    float average;
    char grade;

} Student;


void addStudent(Student list[], int *total);
void displayStudent(Student list[], int total);
void searchStudent(Student list[], int total);
void updateStudent(Student list[], int total);
void get_top_performer(Student list[], int total);
char calculateGrade(float avg);

int main() {

    int choice, total_records = 0;

    // Array size for student database
    Student database[100];

    do {

        // Main menu
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert new record\n");
        printf("2. View all records\n");
        printf("3. Locate Student\n");
        printf("4. Edit student marks\n");
        printf("5. View Top scorer\n");
        printf("6. Exit system\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        // Validate menu choice
        if(choice < 1 || choice > 6)
        {
            printf("Invalid input\n");
            continue;
        }

        // Exit program
        if (choice == 6) {
            printf("Shutting down... Goodbye.\n");
            break;
        }

        // Execute selected option
        switch (choice) {

            case 1:
                addStudent(database, &total_records);
                break;

            case 2:
                displayStudent(database, total_records);
                break;

            case 3:
                searchStudent(database, total_records);
                break;

            case 4:
                updateStudent(database, total_records);
                break;

            case 5:
                get_top_performer(database, total_records);
                break;

            default:
                printf("Invalid selection! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

// Determines student grade based on average marks
char calculateGrade(float avgScore) {

    if (avgScore >= 70.0) return 'A';
    if (avgScore >= 60.0) return 'B';
    if (avgScore >= 50.0) return 'C';
    if (avgScore >= 40.0) return 'D';

    return 'E';
}

// Adds a new student record
void addStudent(Student list[], int *total) {

    // Prevent exceeding array size
    if (*total >= 100) {
        printf("Database limit reached.\n");
        return;
    }

    // Pointer to current student position
    Student *ptr = &list[*total];

    printf("\nEnter Full Name: ");


    getchar();

    fgets((*ptr).name, 50, stdin);


    (*ptr).name[strcspn((*ptr).name, "\n")] = 0;

    printf("Enter Admission No: ");
    scanf("%d", &(*ptr).admissionNo);

    printf("Enter Student Age: ");
    scanf("%d", &(*ptr).age);

    float sum = 0.0;

    // Input marks for 3 units
    for (int i = 0; i < 3; i++) {

        printf("Enter Score for Unit %d: ", i + 1);
        scanf("%f", &(*ptr).marks[i]);

        sum += (*ptr).marks[i];
    }

    // Calculate average and grade
    (*ptr).average = sum / 3.0;
    (*ptr).grade = calculateGrade((*ptr).average);

    // Increase total student count
    (*total)++;

    printf("Record saved!\n");
}

// Diplays all stored student records
void displayStudent(Student list[], int total) {

    if (total == 0) {
        printf("\nNo data stored yet.\n");
        return;
    }

    printf("\n--- REGISTERED STUDENTS ---");

    for (int i = 0; i < total; i++) {

        printf("\nName: %s", list[i].name);
        printf("\nAdmission Number: %d", list[i].admissionNo);
        printf("\nAge: %d", list[i].age);
        printf("\nAverage: %.2f", list[i].average);
        printf("\nGrade: %c\n", list[i].grade);

        printf("--------------------------");
    }
}

// Serches for a student using admission numer
void searchStudent(Student list[], int total) {

    if (total == 0) {
        printf("\nNo data to search.\n");
        return;
    }

    int targetId;

    printf("\nType Admission ID to find: ");
    scanf("%d", &targetId);

    //search through database
    for (int i = 0; i < total; i++) {

        if (list[i].admissionNo == targetId) {

            printf("\nMatch Found:");
            printf("\nName: %s", list[i].name);
            printf("\nAdmission Number: %d", list[i].admissionNo);
            printf("\nAge: %d", list[i].age);
            printf("\nAverage: %.2f", list[i].average);
            printf("\nGrade: %c\n", list[i].grade);

            return;
        }
    }

    printf("\nNo student matching ID %d found.\n", targetId);
}

// Updates marks for a specific student
void updateStudent(Student list[], int total) {

    if (total == 0) {
        printf("\nNo data to modify.\n");
        return;
    }

    int targetId;

    printf("\nType Admission ID to update: ");
    scanf("%d", &targetId);

    for (int i = 0; i < total; i++) {

        if (list[i].admissionNo == targetId) {

            printf("\nModifying grades for %s\n", list[i].name);

            float sum = 0.0;

            // Input new marks
            for (int j = 0; j < 3; j++) {

                printf("Enter new Score for Unit %d: ", j + 1);
                scanf("%f", &list[i].marks[j]);

                sum += list[i].marks[j];
            }

            // Recalculate average and grade
            list[i].average = sum / 3.0;
            list[i].grade = calculateGrade(list[i].average);

            printf("Grades recalculated successfully.\n");

            return;
        }
    }

    printf("\nTarget ID not found.\n");
}

// Finds and displays the student with highest average
void get_top_performer(Student list[], int total) {

    if (total == 0) {
        printf("\nNo records recorded.\n");
        return;
    }

    int top_index = 0;

    // Compare averages to locate highest scorer
    for (int i = 1; i < total; i++) {

        if (list[i].average > list[top_index].average) {
            top_index = i;
        }
    }

    printf("\n*** HIGHEST PERFORMER ***\n");

    printf("Name: %s\n", list[top_index].name);
    printf("Admission ID: %d\n", list[top_index].admissionNo);
    printf("Mean Score: %.2f\n", list[top_index].average);
    printf("Final Grade: %c\n", list[top_index].grade);
}
