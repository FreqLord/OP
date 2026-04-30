#include <stdio.h>
#include <string.h>

int main() {
    char text[200], pattern[100];
    int n, m, choice;

    while(1) {
        printf("\n1. Enter Text & Pattern\n2. Search Pattern\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter text: ");
                scanf("%s", text);

                printf("Enter pattern: ");
                scanf("%s", pattern);

                n = strlen(text);
                m = strlen(pattern);
                break;

            case 2: {
                int found = 0;

                for(int i = 0; i <= n - m; i++) {
                    int j;
                    for(j = 0; j < m; j++) {
                        if(text[i + j] != pattern[j])
                            break;
                    }

                    if(j == m) {
                        printf("Pattern found at index %d\n", i);
                        found = 1;
                    }
                }

                if(!found)
                    printf("Pattern not found\n");

                break;
            }

            case 3:
                return 0;
        }
    }
}
/* 8. NAÏVE STRING MATCHING
   Best Case: O(n)
   Worst Case: O(n * m)
   Space Complexity: O(1)

Start

Display menu

Read user choice

If choice = 1:
a) Input the text
b) Input the pattern

If choice = 2:
a) Loop through the text to check for matching pattern characters
b) If a match is found, display the starting index
c) If the pattern is nowhere to be found, display "Pattern not found"

If choice = 3:
a) Exit program

Repeat steps 2 to 6 until exit is selected

Stop
*/
