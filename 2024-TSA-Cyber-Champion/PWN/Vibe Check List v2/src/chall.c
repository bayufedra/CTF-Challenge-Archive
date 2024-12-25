// gcc -o chall chall.c -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -pie -fPIE -Wl,-z,relro,-z,now
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <syscall.h>
#include <sys/prctl.h>
#include <linux/audit.h>
#include <linux/filter.h>
#include <stddef.h>
#include <seccomp.h>

typedef struct Task {
    char description[0x50];
    struct Task *next;  // Mangled pointer for the next task
    int id;
    int priority;
} Task;

Task *head = NULL;
uintptr_t mangle_key;

#define RESET "\033[0m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"

int readline(char *buf, size_t n) {
    for (int i = 0; i < n; i++) {
        if (read(0, &buf[i], 1) != 1) {
            exit(1);
        }
        if (buf[i] == '\n') {
            return i;
        }
    }
    return n;
}

// Function to mangle (encrypt) a pointer using a given key
Task* mangle_ptr(Task* ptr, uintptr_t key) {
    uintptr_t mangled = (uintptr_t)ptr ^ key; // Step 1: XOR with rotated key
    uintptr_t rotated_key = (key << 7) | (key >> (sizeof(uintptr_t) * 8 - 7)); // Rotate key for second XOR
    mangled ^= rotated_key;
    return (Task*)mangled;
}

// Function to demangle (decrypt) a pointer using a given key
Task* demangle_ptr(Task* mangled_ptr, uintptr_t key) {
    uintptr_t rotated_key = (key << 7) | (key >> (sizeof(uintptr_t) * 8 - 7)); // Rotate key for second XOR
    uintptr_t demangled = (uintptr_t)mangled_ptr ^ rotated_key; // Step 1: Reverse XOR with rotated key
    demangled ^= key;
    return (Task*)demangled;
}

void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int urandom_fd = open("/dev/urandom", O_RDONLY);
    if (urandom_fd < 0 || read(urandom_fd, &mangle_key, sizeof(mangle_key)) != sizeof(mangle_key)) {
        perror("Failed to initialize mangle key");
        exit(EXIT_FAILURE);
    }
    
    close(urandom_fd);
    struct sock_filter filter[] = {
        BPF_STMT(BPF_LD | BPF_W | BPF_ABS, (offsetof(struct seccomp_data, nr))),

        BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, __NR_execveat, 3, 0),
        BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, __NR_execve, 2, 0),
        BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, __NR_fork, 1, 0),

        BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW),

        BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_KILL),
    };

    struct sock_fprog prog = {
        .len = sizeof(filter) / sizeof(struct sock_filter),
        .filter = filter,
    };

    if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
        perror("prctl(PR_SET_NO_NEW_PRIVS)");
        exit(-1);
    }

    if (syscall(SYS_seccomp, SECCOMP_SET_MODE_FILTER, 0, &prog)) {
        perror("seccomp");
        exit(-1);
    }
}

void vibeCheckBanner() {
    printf(YELLOW "==================================================\n" RESET);
    printf(YELLOW "||     🌟 Welcome to the Vibe Check List v2 🌟      ||\n" RESET);
    printf(YELLOW "||  Now with enhanced security and smoother vibes!  ||\n" RESET);
    printf(YELLOW "==================================================\n\n" RESET);
}

void addTask() {
    Task *newTask = (Task *)malloc(sizeof(Task));
    if (!newTask) {
        printf(RED "Failed to allocate memory for new task.\n" RESET);
        return;
    }
    
    printf(CYAN "🎯 Enter task description: " RESET);
    getchar();
    readline(newTask->description,sizeof(newTask->description));

    printf(CYAN "🔢 Set priority level (1-5): " RESET);
    scanf("%d", &newTask->priority);

    newTask->id = (head == NULL) ? 1 : head->id + 1;
    newTask->next = mangle_ptr(head, mangle_key);
    head = newTask;

    printf(GREEN "✅ Task added successfully to Vibe Check List v2!\n" RESET);
}

void displayTasks() {
    if (head == NULL) {
        printf(GREEN "🎉 No tasks to show! You've vibed out of work!\n" RESET);
        return;
    }

    printf("\n" BLUE "📋 Your Current Vibe Check List v2:\n" RESET);
    printf(BLUE "==================================================\n" RESET);
    Task *current = head;
    while (current != NULL) {
        printf(CYAN "📌 Task ID: %d\n" RESET, current->id);
        printf(CYAN "🔸 Description: %s" RESET, current->description);
        printf(CYAN "⚡ Priority: %d\n" RESET, current->priority);
        printf(BLUE "==================================================\n" RESET);
        current = demangle_ptr(current->next, mangle_key);
    }
}

void deleteTask() {
    if (head == NULL) {
        printf(GREEN "🎉 No tasks to delete. Chill vibes all around!\n" RESET);
        return;
    }

    int taskId;
    printf(CYAN "🗑️ Enter the Task ID you want to delete: " RESET);
    scanf("%d", &taskId);

    Task *current = head;
    Task *previous = NULL;

    while (current != NULL && current->id != taskId) {
        previous = current;
        current = demangle_ptr(current->next, mangle_key);
    }

    if (current == NULL) {
        printf(RED "❌ Task ID not found!\n" RESET);
        return;
    }

    if (previous == NULL) {
        head = demangle_ptr(current->next, mangle_key);
    } else {
        previous->next = mangle_ptr(demangle_ptr(current->next, mangle_key), mangle_key);
    }

    free(current);
    current = 0;
    printf(GREEN "🚮 Task deleted successfully from Vibe Check List v2!\n" RESET);
}

void modifyTask() {
    if (head == NULL) {
        printf(GREEN "🎉 No tasks to modify. Just vibes!\n" RESET);
        return;
    }

    int taskId;
    printf(CYAN "📝 Enter the Task ID you want to modify: " RESET);
    scanf(" %d", &taskId);

    Task *current = head;

    while (current != NULL && current->id != taskId) {
        current = demangle_ptr(current->next, mangle_key);
    }

    if (current == NULL) {
        printf(RED "❌ Task ID not found!\n" RESET);
        return;
    }

    printf(CYAN "🎯 Enter new task description: " RESET);
    getchar();
    readline(current->description,strlen(current->description)); // Check current content length, so no overflow

    printf(CYAN "🔢 Set new priority level (1-5): " RESET);
    scanf("%d", &current->priority);

    printf(GREEN "✅ Task modified successfully in Vibe Check List v2!\n" RESET);
}

void menu() {
    int choice;

    do {
        printf("\n" BLUE "==== 💫 Main Menu - Vibe Check List v2 💫 ====\n" RESET);
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Modify Task\n");
        printf("5. Exit\n");
        printf(BLUE "===========================================\n" RESET);
        printf(CYAN "Choose your vibe: " RESET);
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
                printf(GREEN "👋 Thanks for using Vibe Check List v2! Stay secure and keep vibing!\n" RESET);
                break;
            default:
                printf(RED "❌ Invalid choice, try again!\n" RESET);
        }
    } while (choice != 5);
}

int main() {
    setup();
    vibeCheckBanner();
    menu();
    return 0;
}
