// gcc chall.c -lpthread -o chall
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

// Global variables
pthread_mutex_t heehee;
pthread_cond_t anu;
bool c = false;
bool s = false;

typedef struct reserveSkel{
    int total_bayar;
    int total_cooking_time;  // New field for total cooking time
    int *appetizer_choices;        // Array to store indexes of selected appetizers
    int *appetizer_quantities;     // Array to store quantities of selected appetizers
    int *main_course_choices;      // Array to store indexes of selected main courses
    int *main_course_quantities;   // Array to store quantities of selected main courses
    int *dessert_choices;          // Array to store indexes of selected desserts
    int *dessert_quantities;       // Array to store quantities of selected desserts
    int *beverage_choices;         // Array to store indexes of selected beverages
    int *beverage_quantities;      // Array to store quantities of selected beverages
} *reserve_t;

typedef struct menuSkel{
    char menu_name[0xb0];
    int price;
    int time_cook;
} *menu_t;

int money;
char cust_name[32];

char w_menu;
menu_t w;

void mainMenu();

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    mallopt(M_ARENA_MAX, 1);
}

void printColored(const char* text, const char* color) {
    // ANSI escape codes for colors
    const char* colors[] = {
        "\033[0m", // Reset
        "\033[31m", // Red
        "\033[32m", // Green
        "\033[33m", // Yellow
        "\033[34m", // Blue
        "\033[35m", // Magenta
        "\033[36m", // Cyan
        "\033[37m", // White
    };
    
    int colorIndex = 0; // Default to reset color
    if (strcmp(color, "red") == 0) colorIndex = 1;
    else if (strcmp(color, "green") == 0) colorIndex = 2;
    else if (strcmp(color, "yellow") == 0) colorIndex = 3;
    else if (strcmp(color, "blue") == 0) colorIndex = 4;
    else if (strcmp(color, "magenta") == 0) colorIndex = 5;
    else if (strcmp(color, "cyan") == 0) colorIndex = 6;
    else if (strcmp(color, "white") == 0) colorIndex = 7;

    printf("%s%s\033[0m", colors[colorIndex], text); // Print colored text
}

void displayWelcomeBanner() {
    printf("********************************************\n");
    printColored("            Welcome to Our Restaurant!    ", "cyan");
    printf("\n********************************************\n");
    printf("        Where Delicious Meets Delight!      \n");
    printf("********************************************\n");
    printf("           Enjoy Your Culinary Journey!     \n");
    printf("********************************************\n");
}

void initializeMenu(menu_t menu[], int size, char *names[], int prices[], int cook_times[]) {
    for (int i = 0; i < size; i++) {
        menu[i] = (struct menuSkel *)malloc(sizeof(struct menuSkel)); // Allocate memory for each menu item
        if (menu[i] == NULL) {
            perror("Failed to allocate memory for menu item");
            exit(EXIT_FAILURE); // Exit if memory allocation fails
        }
        if (menu[i] != NULL) {
            strcpy(menu[i]->menu_name, names[i]);  // Copy the name into the struct
            menu[i]->price = prices[i];             // Assign the price
            menu[i]->time_cook = cook_times[i];     // Assign the cooking time
        }
    }
}

void displayMenu(menu_t menu[], int size) {
    printf("\n+--------------------------------------------------------+\n");
    printf("| %-2s | %-40s | %-8s |\n", "No", "Menu Item", "Price |");
    printf("+--------------------------------------------------------+\n");
    
    for (int i = 0; i < size; i++) {
        printf("| %-2d | %-40s | $%-8d |\n", 
               i + 1, menu[i]->menu_name, menu[i]->price);
    }

    printf("+--------------------------------------------------------+\n\n");
}

void displayReservationSummary(reserve_t reservation, menu_t appetizers[], int appetizer_count, menu_t mainCourses[], int main_course_count, menu_t desserts[], int dessert_count, menu_t beverages[], int beverage_count) {
    printf("\n--- Reservation Summary ---\n");
    printf("Customer Name: %s\n", cust_name);
    printf("Total Amount to Pay: %d\n", reservation->total_bayar);

    // Display Appetizers
    printf("\n--- Appetizers ---\n");
    for (int i = 0; i < appetizer_count; i++) {
        printf("%s (Quantity: %d)\n", 
               appetizers[reservation->appetizer_choices[i]]->menu_name, 
               reservation->appetizer_quantities[i]);
    }

    // Display Main Courses
    printf("\n--- Main Courses ---\n");
    for (int i = 0; i < main_course_count; i++) {
        printf("%s (Quantity: %d)\n", 
               mainCourses[reservation->main_course_choices[i]]->menu_name, 
               reservation->main_course_quantities[i]);
    }

    // Display Desserts
    printf("\n--- Desserts ---\n");
    for (int i = 0; i < dessert_count; i++) {
        printf("%s (Quantity: %d)\n", 
               desserts[reservation->dessert_choices[i]]->menu_name, 
               reservation->dessert_quantities[i]);
    }

    // Display Beverages
    printf("\n--- Beverages ---\n");
    for (int i = 0; i < beverage_count; i++) {
        printf("%s (Quantity: %d)\n", 
               beverages[reservation->beverage_choices[i]]->menu_name, 
               reservation->beverage_quantities[i]);
    }

    printf("---------------------------\n");
}

unsigned int read_int() {
    char buf[16];
    while (1) {
        if (fgets(buf, sizeof(buf), stdin)) {
            char *endptr;
            unsigned long value = strtoul(buf, &endptr, 10);
            if (endptr != buf && *endptr == '\n') {
                return value; // Valid input
            }
        }
        printf("Invalid input, please enter a number: ");
    }
}

int read_menu_choice(int max_option) {
    int choice;
    while (1) {
        choice = read_int();
        if (choice >= 1 && choice <= max_option) {
            return choice - 1; // Return index for internal use
        }
        printf("Please enter a valid choice (1 - %d): ", max_option);
    }
}

void handleOrder(menu_t menu[], int menu_size, reserve_t reservation, int *count, char *type, int **choices, int **quantities) {
    displayMenu(menu, menu_size); 
    printf("How many %s would you like to choose? ", type);
    *count = read_int();
    
    *choices = malloc(*count * sizeof(int)); 
    *quantities = malloc(*count * sizeof(int)); 

    for (int i = 0; i < *count; i++) {
        printf("Choose your %s (1 - %d): ", type, menu_size);
        (*choices)[i] = read_menu_choice(menu_size);
        
        printf("How many of %s would you like? ", menu[(*choices)[i]]->menu_name);
        (*quantities)[i] = read_int();
        reservation->total_bayar += menu[(*choices)[i]]->price * (*quantities)[i];
        
        // Add cooking time for this item to the total cooking time
        reservation->total_cooking_time += menu[(*choices)[i]]->time_cook * (*quantities)[i];
    }
}

void cooking(reserve_t reservation, menu_t *menu, int *choices, int *quantities, int itemCount, const char *dishType) {
    printf("Cooking process for %s started...\n", dishType);

    for (int i = 0; i < itemCount; i++) {
        int choice = choices[i];
        int quantity = quantities[i];

        for (int q = 0; q < quantity; q++) {
            // Allocate memory for menu_name and time_cook
            char *local_menu_name = (char *)malloc(strlen(menu[choice]->menu_name) + 1); // +1 for null terminator
            if (local_menu_name == NULL) {
                perror("Failed to allocate memory for menu name");
                exit(EXIT_FAILURE);
            }
            
            // Copy menu name into dynamically allocated memory
            strcpy(local_menu_name, menu[choice]->menu_name);

            int *local_time_cook = (int *)malloc(sizeof(int));
            if (local_time_cook == NULL) {
                perror("Failed to allocate memory for time cook");
                free(local_menu_name); // Free previously allocated memory before exit
                exit(EXIT_FAILURE);
            }
            
            // Store the cooking time value
            *local_time_cook = menu[choice]->time_cook;

            // Simulate cooking
            printf("Preparing %s (%s) for %d seconds...\n", local_menu_name, dishType, *local_time_cook);
            // sleep(*local_time_cook);  // Simulate cooking time for this dish
            sleep(*local_time_cook);
            printf("%s (%s) is ready!\n", local_menu_name, dishType);
        }
    }

    printf("All %s are cooked!\n", dishType);
}


void wCooking(menu_t menu, const char *dishType) {
    printf("Cooking process for %s started...\n", dishType);

    // Allocate memory for menu_name and time_cook
    char *local_menu_name = (char *)malloc(strlen(menu->menu_name) + 1); // +1 for null terminator
    if (local_menu_name == NULL) {
        perror("Failed to allocate memory for menu name");
        exit(EXIT_FAILURE);
    }
    
    // Copy menu name into dynamically allocated memory
    memcpy(local_menu_name, menu->menu_name,(sizeof(menu->menu_name)));

    // Simulate cooking
    printf("Preparing %s (%s) for %d seconds...\n", local_menu_name, dishType, menu->time_cook);

    sleep(10);
    printf("%s (%s) is ready!\n", local_menu_name, dishType);

    printf("All %s are cooked!\n", dishType);
}

void customerCheck() {
    printf("\nPlease enter your name: ");
    scanf(" %31s", cust_name);
    printf("============================================\n");
    printColored("       Welcome sir ", "green");
    money = printf(cust_name);
    printf("!\n");
    printf("============================================\n");
    printColored("         You have: $", "yellow");
    printf("%d\n", money); // Display the amount of money
    printf("============================================\n");
    printf("         Enjoy your dining experience!\n");
    printf("============================================\n");
}

void *makeReservation(void *args) {
    menu_t *menus = (menu_t *)args; // Pointer to the menu arrays
    while (true) {
        reserve_t reservation = (reserve_t)malloc(sizeof(struct reserveSkel));
        if (!reservation) {
            perror("Failed to allocate memory for reservation");
            exit(EXIT_FAILURE);
        }
        
        // Initialize the reservation
        reservation->total_bayar = 0; // Initialize total price
        reservation->total_cooking_time = 0; // Initialize total cooking time

        // Handling orders
        int appetizer_count, main_course_count, dessert_count, beverage_count;

        handleOrder(menus[0], 3, reservation, &appetizer_count, "appetizers", &reservation->appetizer_choices, &reservation->appetizer_quantities);
        handleOrder(menus[1], 5, reservation, &main_course_count, "main courses", &reservation->main_course_choices, &reservation->main_course_quantities);
        handleOrder(menus[2], 3, reservation, &dessert_count, "desserts", &reservation->dessert_choices, &reservation->dessert_quantities);
        handleOrder(menus[3], 3, reservation, &beverage_count, "beverages", &reservation->beverage_choices, &reservation->beverage_quantities);

        // Display reservation summary
        displayReservationSummary(reservation, menus[0], appetizer_count, 
                                menus[1], main_course_count, 
                                menus[2], dessert_count, 
                                menus[3], beverage_count);
        
        // Check if enough money is available
        if (money < reservation->total_bayar) {
            printf("You do not have enough money. Please reorder.\n");
            continue; // Re-order
        } else {
            printf("You have enough money. Preparing to start cooking process...\n");
            money = money - reservation->total_bayar;
            // Start cooking process
            if (appetizer_count != 0) {
                cooking(reservation, menus[0], reservation->appetizer_choices, reservation->appetizer_quantities, appetizer_count, "Appetizer");
            }
            if (main_course_count != 0) {
                cooking(reservation, menus[1], reservation->main_course_choices, reservation->main_course_quantities, main_course_count, "Main Course");
            }
            if (dessert_count != 0) {
                cooking(reservation, menus[2], reservation->dessert_choices, reservation->dessert_quantities, dessert_count, "Dessert");
            }
            if (beverage_count != 0) {
                cooking(reservation, menus[3], reservation->beverage_choices, reservation->beverage_quantities, beverage_count, "Beverage");
            }
        }

        w_menu = reservation->total_cooking_time;

        // Signal the main menu to wake up
        pthread_mutex_lock(&heehee);
        c = true; // Set the flag
        pthread_cond_signal(&anu); // Signal the main menu thread
        pthread_mutex_unlock(&heehee);

        // Wait until we get the signal to stop
        while (!s) {
            sleep(1); // Sleep until we are told to stop
        }

        menu_t *specials = w;
        if(!c){            
            wCooking(specials, "Special Dishes");
            printf("Reservation for customer is being processed...\n");
        }

        pthread_mutex_lock(&heehee);
        c = true; // Set the flag
        pthread_cond_signal(&anu); // Signal the main menu thread
        pthread_mutex_unlock(&heehee);
        break;
    }
    while (s) {
        sleep(1); // Sleep until we are told to stop
    }
    return NULL; // Exit the thread
}

void mainMenu() {    
    menu_t appetizers[3], mainCourses[5], desserts[3], beverages[3];

    initializeMenu(appetizers, 3, 
        (char *[]){"French Tasty Fries", "American ChickCorn Cream Soup", "American Homemade Nugget"}, 
        (int[]){300000, 500000, 400000}, 
        (int[]){3, 10, 8}); // Example cooking times

    initializeMenu(mainCourses, 5, 
        (char *[]){"Laksa Rice Noodle Soup with Seafood and Tofu", 
                   "Stir Fried Eggplant and Tofu with Chopped Garlic and Chili", 
                   "Spaghetti bolognese in a tomato sauce with cheese", 
                   "Open lasagne with vegetables and spinach sauce", 
                   "Icelandic fillet of with crispy fat"}, 
        (int[]){1500000, 2500000, 2000000, 3500000, 5000000}, 
        (int[]){15, 20, 25, 30, 35}); // Example cooking times
   
    initializeMenu(desserts, 3, 
        (char *[]){"Caramel Brownie Lava Cake", 
                   "Deep Fries Mars Bar & Ice Cream", 
                   "Dark Choco Truffle"}, 
        (int[]){700000, 900000, 500000}, 
        (int[]){10, 12, 8}); // Example cooking times

    initializeMenu(beverages, 3, 
        (char *[]){"Iced tea", 
                   "Fresh Fruit Juice", 
                   "Pressed Fresh Lemonade"}, 
        (int[]){400000, 1000000, 800000}, 
        (int[]){2, 5, 5}); // Example cooking times
    
    // Create an array of menus to pass to the thread
    menu_t **menus = malloc(sizeof(menu_t *) * 4);  // Allocate memory for 4 categories
    menus[0] = appetizers; menus[1] = mainCourses; menus[2]= desserts;  menus[3] = beverages;

    // Initialize the mutex and condition variable
    pthread_mutex_init(&heehee, NULL);
    pthread_cond_init(&anu, NULL); // Initialize condition variable

    // Create the reservation thread
    pthread_t reservation_thread;
    pthread_create(&reservation_thread, NULL, makeReservation, (void *)menus);

    // Sleep until notified that cooking is done
    pthread_mutex_lock(&heehee);
    while (!c) {
        pthread_cond_wait(&anu, &heehee); // Wait for signal
    }
    pthread_mutex_unlock(&heehee);

    if (money > 25000000){
        char response;
        w = &menus[w_menu];

        printf("Looks like you enjoy our dishes. Wanna try our special menu for you? (y/n): ");
        scanf(" %c", &response); // Get user input

        pthread_mutex_lock(&heehee);
        if (response == 'y' || response == 'Y') {
            printf("Our special menu allow customer to create their own menu. So, what are you wanna cook chef? ");
            scanf(" %144s",w->menu_name);
            getchar();
            printf("What ingredient we need chef? ");
            w->price = read_int();
            printf("Any other ingredient we need chef? ");
            w->time_cook = read_int();
            printf("Alright chef!\n We continuing with cooking...\n");            
            c = false;
            s = true;
        }
        pthread_mutex_unlock(&heehee);
    }

    pthread_mutex_lock(&heehee);
    while (!c) {
        pthread_cond_wait(&anu, &heehee);
    }
    pthread_mutex_unlock(&heehee);
    return 0;
}

int main(){
    setup();
    displayWelcomeBanner();
    customerCheck();
    getchar();
    mainMenu();
    return 0;
}
