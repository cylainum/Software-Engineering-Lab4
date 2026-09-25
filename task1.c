#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (score > 113) { // EDGE-CASE: If bigger than highest scored NFL game, make sure they want to go through with their score.
            int check = 0;
            printf("You entered a score higher than the highest scoring NFL game.\n");
            printf("Are you sure you want to continue (You could be waiting a really long time)?\n");
            printf("(Enter 1 to continue, or any other number to enter a new score): ");
            
            if (scanf("%d", &check) != 1) {
                while (getchar() != '\n');
                printf("Invalid input. Returning to main menu.\n\n");
                continue;
            }
            if (check != 1) {
                printf("Operation canceled. Please enter a lower score.\n\n");
                continue;
            }
        }
        if (score < 0) { //EDGE-CASE: If negative, tell user to input a non-negative score.
            printf("Please enter a non-negative score\n\n");
            continue;
        }
        if (score == 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
            for (int td_fg = 0; (td_2pt * 8) + (td_fg * 7) <= score; td_fg++) {
                for (int td = 0; (td_2pt * 8) + (td_fg * 7) + (td * 6) <= score; td++) {
                    for (int fg = 0; (td_2pt * 8) + (td_fg * 7) + (td * 6) + (fg * 3) <= score; fg++) {
                        
                        int current_sum = (td_2pt * 8) + (td_fg * 7) + (td * 6) + (fg * 3);
                        int rem = score - current_sum;

                        if (rem >= 0 && rem % 2 == 0) {
                            int safety = rem / 2;
                            
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
