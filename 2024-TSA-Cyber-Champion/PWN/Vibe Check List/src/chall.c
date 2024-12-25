// gcc -o chall chall.c -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -pie -fPIE -Wl,-z,relro,-z,now
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char description[0x50];
    struct Task *next;
    int id;
    int priority;
} Task;

Task *head = NULL; // Head of the linked list

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void vibeCheckBanner() {
    printf("==============================================\n");
    printf("||      🌀 Welcome to the Vibe Check List 🌀     ||\n");
    printf("||    Let's vibe out and check some tasks!    ||\n");
    printf("==============================================\n\n");
}

void addTask() {
    Task *newTask = (Task *)malloc(sizeof(Task));
    if (!newTask) {
        printf("Failed to allocate memory for new task.\n");
        return;
    }
    
    printf("🎯 Enter task description: ");
    getchar(); // Clear the buffer   
    scanf("%80s",&newTask->description);

    printf("🔢 Set priority level (1-5): ");
    scanf("%d", &newTask->priority);

    // Assign ID and insert into linked list
    newTask->id = (head == NULL) ? 1 : head->id + 1;
    newTask->next = head;
    head = newTask;

    printf("✅ Task added successfully!\n");
}

void displayTasks() {
    if (head == NULL) {
        printf("🎉 No tasks to show! You've vibed out of work!\n");
        return;
    }

    printf("\n📋 Your Current Vibe Check List:\n");
    printf("==============================================\n");
    Task *current = head;
    while (current != NULL) {
        printf("📌 Task ID: %d\n", current->id);
        printf("🔸 Description: %s\n", current->description);
        printf("⚡ Priority: %d\n", current->priority);
        printf("==============================================\n");
        current = current->next;
    }
}

void deleteTask() {
    if (head == NULL) {
        printf("🎉 No tasks to delete. Chill vibes all around!\n");
        return;
    }

    int taskId;
    printf("🗑️ Enter the Task ID you want to delete: ");
    scanf("%d", &taskId);

    Task *current = head;
    Task *previous = NULL;

    while (current != NULL && current->id != taskId) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("❌ Task ID not found!\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    current = 0;
    printf("🚮 Task deleted successfully!\n");
}

void modifyTask() {
    if (head == NULL) {
        printf("🎉 No tasks to modify. Just vibes!\n");
        return;
    }

    int taskId;
    printf("📝 Enter the Task ID you want to modify: ");
    scanf("%d", &taskId);

    Task *current = head;

    while (current != NULL && current->id != taskId) {
        current = current->next;
    }

    if (current == NULL) {
        printf("❌ Task ID not found!\n");
        return;
    }

    printf("🎯 Enter new task description: ");
    getchar(); // Clear the buffer
    scanf("%80s",&current->description);
    printf("🔢 Set new priority level (1-5): ");
    scanf("%d", &current->priority);

    printf("✅ Task modified successfully!\n");
}

void menu() {
    int choice;

    do {
        printf("\n==== 💫 Main Menu 💫 ====\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Modify Task\n");
        printf("5. Exit\n");
        printf("=========================\n");
        printf("Choose your vibe: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                modifyTask();
                break;
            case 5:
                printf("👋 See you next time on the Vibe Check List!\n");
                break;
            default:
                printf("❌ Invalid choice, try again!\n");
        }
    } while (choice != 5);
}

int main() {
    setup();
    vibeCheckBanner();
    menu();
    return 0;
}
