/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_PATH_SIZE 10
#define MAX_PATH_SIZE 70
#define PATH_MULTIPLE 5
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MIN_MOVES 3
#define MAX_MOVES 26

// Imports
#include <stdio.h>

// Structure Definitions
struct PlayerInfo {
    int lives; // The number of lives the player has.
    char symbol; // The player's selected symbol (representation of player).
    int treasures; // The amount of treasures that have been found by the player.
    int pastPositions[MAX_PATH_SIZE]; // (bin) The history of all past entered positions.
};

struct GameInfo {
    int maxMoves; // The maximum number of moves a player can make in a game.
    int pathLength; // The length of the path the game has.
    int bombMap[MAX_PATH_SIZE]; // (bin) The location of all bombs on the path.
    int treasureMap[MAX_PATH_SIZE]; // (bin) The location of all treasure on the path.
};

// Main Function
int main (void) {
    // Type Definitions
    typedef struct PlayerInfo playerInfo;
    typedef struct GameInfo gameInfo;

    // Variable Declarations
    playerInfo player;  // Instance of our player.
    gameInfo game;      // Instance of our game.
    int correct = 0;    // User input validation tracker.

    // Introduction Screen
    printf("================================\n"
           "         Treasure Hunt!         \n"
           "================================\n");

    //  ========================
    //  | Player Configuration |
    //  ========================
    printf("\n"
           "PLAYER Configuration\n"
           "--------------------\n");

    // Prompt the user for their symbol.
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    // Begin validation loop
    while (!correct) {
        // Prompt user for amount of lives.
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        // Validate response.
        if ((player.lives >= MIN_LIVES) && (player.lives <= MAX_LIVES)) {
            correct = 1;
        } else {
            printf("     Must be between 1 and 10!\n");
            correct = 0;
        }
        // Continue the loop if not correct.
    }

    correct = 0; // Reset for next usage.

    // Player configuration complete
    printf("Player configuration set-up is complete\n");

    //  ======================
    //  | Game Configuration |
    //  ======================
    printf("\n"
           "GAME Configuration\n"
           "------------------\n");

    // Begin validation loop
    while (!correct) {
        // Prompt user for the path length.
        printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH_SIZE, MAX_PATH_SIZE);
        scanf("%d", &game.pathLength);

        // Validate response.
        if ((game.pathLength >= MIN_PATH_SIZE) && (game.pathLength <= MAX_PATH_SIZE) && ((game.pathLength % PATH_MULTIPLE) == 0)) {
            correct = 1;
        } else {
            // The provided path length is invalid. Return error.
            printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_MULTIPLE, MIN_PATH_SIZE, MAX_PATH_SIZE);
            correct = 0;
        }
        // Continue the loop if not correct.
    }

    correct = 0; // Reset for next usage.

    // Begin validation loop
    while (!correct) {
        // Prompt user for move limit.
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);

        // Validate response.
        if ((game.maxMoves >= MIN_MOVES) && (game.maxMoves <= MAX_MOVES)) {
            correct = 1;
        } else {
            // The provided move limit is invalid. Return error.
            printf("     Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
            correct = 0;
        }
        // Continue the loop if not correct.
    }

    correct = 0; // Reset for next usage.

    //  ======================
    //  |   Bomb Placement   |
    //  ======================
    printf("\n"
           "BOMB Placement\n"
           "--------------\n");
    // Print instructions
    printf("Enter the bomb positions in sets of %d where a value\n"
           "of 1=BOMB,and 0=NO BOMB. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", PATH_MULTIPLE, game.pathLength);

    int i; // Declare before statement before loop for backwards compatibility.

    // Loop starting at Path Multiple, incrementing by Path Multiple each time until reaches path length
    for (i = PATH_MULTIPLE; i <= game.pathLength; i += PATH_MULTIPLE) {
        // Begin validation loop
        while (!correct) {
            // Prompt the user for input.
            if ((i < 10) && ((i - (PATH_MULTIPLE - 1) < 10)))
            {
                // If both sides are less than 10.
                printf("   Positions [ %d- %d]: ", i - (PATH_MULTIPLE - 1), i);
            } else if (i - (PATH_MULTIPLE - 1) < 10)
            {
                // If only the first is less than 10.
                printf("   Positions [ %d-%d]: ", i - (PATH_MULTIPLE - 1), i);
            } else
            {
                // Both are greater than 10.
                printf("   Positions [%d-%d]: ", i - (PATH_MULTIPLE - 1), i);
            }

            // Scan the input.
            // Loop amount of times the path multiple is to get input.
            int j;
            for (j = PATH_MULTIPLE; j > 0; j--)
            {
                // Get each of the values based on each number.
                // They are placed in the index of i - j (left to right, just a little more complicated)
                scanf("%d", &game.bombMap[i - j]);

                if ((game.bombMap[i - j] != 0) && (game.bombMap[i - j] != 1))
                {
                    // User provided a value that wasnt a zero or one.
                    correct = 0;
                    printf("      ERROR: Please enter only values of zero or one! Detected: %d\n", game.bombMap[i - j]);
                } else {
                    correct = 1;
                }
            }
        }
        correct = 0; // Reset for next iteration.
    }
    // The bomb locations are now setup. Output confirmation
    printf("BOMB placement set\n");

    //  ==========================
    //  |   Treasure Placement   |
    //  ==========================
    printf("\n"
           "TREASURE Placement\n"
           "------------------\n");
    // Print instructions
    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE,and 0=NO TREASURE. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", PATH_MULTIPLE, game.pathLength);

    int k; // Declare before statement before loop for backwards compatibility.

    // Loop starting at Path Multiple, incrementing by Path Multiple each time until reaches path length
    for (k = PATH_MULTIPLE; k <= game.pathLength; k += PATH_MULTIPLE) {
        // Begin validation loop
        while (!correct) {
            // Prompt the user for input.
            if ((k < 10) && ((k - (PATH_MULTIPLE - 1) < 10)))
            {
                // If both sides are less than 10.
                printf("   Positions [ %d- %d]: ", k - (PATH_MULTIPLE - 1), k);
            } else if (k - (PATH_MULTIPLE - 1) < 10)
            {
                // If only the first is less than 10.
                printf("   Positions [ %d-%d]: ", k - (PATH_MULTIPLE - 1), k);
            } else
            {
                // Both are greater than 10.
                printf("   Positions [%d-%d]: ", k - (PATH_MULTIPLE - 1), k);
            }

            // Scan the input.
            // Loop amount of times the path multiple is to get input.
            int l;
            for (l = PATH_MULTIPLE; l > 0; l--)
            {
                // Get each of the values based on each number.
                // They are placed in the index of i - j (left to right, just a little more complicated)
                scanf("%d", &game.treasureMap[k - l]);

                if ((game.treasureMap[k - l] != 0) && (game.treasureMap[k - l] != 1))
                {
                    // User provided a value that wasn't a zero or one.
                    correct = 0;
                    printf("      ERROR: Please enter only values of zero or one! Detected: %d\n", game.treasureMap[k - l]);
                } else {
                    correct = 1;
                }
            }
        }
        correct = 0; // Reset for next iteration.
    }
    // The treasure is now placed and the game is setup. Output confirmation
    printf("TREASURE placement set\n"
           "\n"
           "GAME configuration set-up is complete...\n");


    return 0;
}
