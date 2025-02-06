//I hate my life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ANSI color codes
#define RESET "\e[0m"
#define BOLD "\e[1m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define CYAN "\e[36m"
#define WHITE "\e[97m"

// Path to ASCII art file
#define ASCII_ART_FILE "/home/$USER/dogna.txt"

void print_ascii_art() {
    FILE *file = fopen(ASCII_ART_FILE, "r");
    if (file == NULL) {
        printf(RED "ASCII art file not found at %s\n" RESET, ASCII_ART_FILE);
        return;
    }
    
    printf(CYAN BOLD);
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf(RESET);
    
    fclose(file);
}

void print_system_info() {
    printf("\n" YELLOW BOLD "System Information:\n" RESET);
    printf(BLUE "-------------------------------------\n" RESET);

    // Execute Neofetch and print output
    system("neofetch --stdout");

    printf("\n" YELLOW BOLD "Custom Info:\n" RESET);
    printf(BLUE "-------------------------------------\n" RESET);
    
    // Print uptime
    printf(GREEN "Uptime: " CYAN);
    system("uptime -p");
    printf(RESET);

    // Print kernel version
    printf(GREEN "Kernel: " CYAN);
    system("uname -r");
    printf(RESET);

    // Print architecture
    printf(GREEN "Architecture: " CYAN);
    system("uname -m");
    printf(RESET);

    // Print shell
    printf(GREEN "Shell: " CYAN "%s\n" RESET, getenv("SHELL"));

    // Print home directory
    printf(GREEN "Home Directory: " CYAN "%s\n" RESET, getenv("HOME"));

    // Print CPU model
    printf(GREEN "CPU: " CYAN);
    system("lscpu | grep 'Model name' | sed 's/Model name: *//'");
    printf(RESET);

    // Print RAM size
    printf(GREEN "RAM: " CYAN);
    system("free -h | grep 'Mem:' | awk '{print $2}'");
    printf(RESET);
}

int main() {
    system("clear");  // Clear the screen
    print_ascii_art();
    print_system_info();
    return 0;
}
