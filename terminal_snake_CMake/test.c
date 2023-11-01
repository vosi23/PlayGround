#include <stdio.h>
#include <unistd.h>

/* Library for linux */
#include <termios.h>

/* Library for Windows */
// #include <conio.h>

/* code for linux */
int main() {
    struct termios orig_termios;
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &orig_termios); // Get current terminal attributes

    // Make a copy of the original attributes
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios); // Apply the new terminal attributes

    char c;
    printf("Enter text (press 'q' to finish):\n");

    while (1) {
        c = getchar(); // Read a single character

        if (c == 'q') {
            break; // Exit the loop if 'q' is pressed
        }

        // Process or store the character 'c' as needed
        //putchar(c); // Echo the character back
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios); // Restore original terminal attributes
    return 0;
}

/* code for windows */
// int main() {
//     char c;

//     printf("Enter text (press 'q' to finish):\n");

//     while (1) {
//         if (_kbhit()) { // Check if a key has been pressed
//             c = _getch(); // Read a single character

//             if (c == 'q') {
//                 break; // Exit the loop if 'q' is pressed
//             }

//             // Process or store the character 'c' as needed
//             putchar(c); // Echo the character back
//         }
//     }

//     return 0;
// }
