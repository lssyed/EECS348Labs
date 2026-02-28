// Program 1
# include <stdio.h>

int main() {
    int score; // Declare an integer variable to store the score

    while (1) {
        printf("Enter 0 or 1 to STOP\n"); // Prompt the user to enter a score
        printf("Enter the NFL score: "); // Prompt the user to enter the NFL score
        scanf("%d", &score); // Read the score from the user input

        if (score <= 1) { // Check if the score is 0 or 1
            break;

        }

        printf("Possible combinations for %d: \n", score);// Print the possible combinations for the entered score

        for (int td8 = 0; td8 <= score / 8; td8++) { // Loop through possible combinations of touchdowns worth 8 points
            for (int td7 = 0; td7 <= score / 7; td7++) { // Loop through possible combinations of touchdowns worth 7 points
                for (int td6 = 0; td6 <= score / 6; td6++) { // Loop through possible combinations of touchdowns worth 6 points
                    for (int fg3 = 0; fg3 <= score / 3; fg3++) { // Loop through possible combinations of field goals worth 3 points
                        for (int saf2 = 0; saf2 <= score / 2; saf2++) { // Loop through possible combinations of safeties worth 2 points
                            // Calculate the total points for this combination
                            int total = (td8 * 8) + (td7 * 7) + (td6 * 6) + (fg3 * 3) + (saf2 * 2); 
                            
                            // If the total exactly matches the target score
                            if (total == score) { 
                                printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", td8, td7, td6, fg3, saf2);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
