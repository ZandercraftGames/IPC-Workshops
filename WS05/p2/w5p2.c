/*
	==================================================
	Workshop #5 (Part-2):
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
#define MAX_MOVES 15

// Imports
#include <stdio.h>

// Structure Definitions
typedef struct PlayerInfo {
    int lives; // The number of lives the player has.
    char symbol; // The player's selected symbol (representation of player).
    int treasures; // The amount of treasures that have been found by the player.
    int currentPosition; // The player's current position.
    int pastPositions[MAX_PATH_SIZE]; // (bin) The history of all past entered positions.
    int movesLeft; // The amount of moves the player has left.
} playerInfo;

typedef struct GameInfo {
    int maxMoves; // The maximum number of moves a player can make in a game.
    int pathLength; // The length of the path the game has.
    int bombMap[MAX_PATH_SIZE]; // (bin) The location of all bombs on the path.
    int treasureMap[MAX_PATH_SIZE]; // (bin) The location of all treasure on the path.
} gameInfo;


//  ========================
//  | Display HUD Function |
//  ========================
// Note: Skip to main function below to start reading code.
int displayHUD (gameInfo game, playerInfo player) {
    // Player Bar Management
    int playerBar;
    for (playerBar = 0; playerBar < game.pathLength; playerBar++) {
        if ((playerBar + 1) == player.currentPosition) {
            // Found the player's current position. Print their symbol
            printf("  %c", player.symbol);
        } else if ((player.currentPosition + 1) > 0) {
            // Player's position is initialized, but is not the current position.
            // Because of structs, when uninitialized value is negative
            printf(" ");
        }
        // Else, do not print player bar if the first move has not been made.
    }

    printf("\n  "); // Newline separator

    // Game Path Management
    int pathBar;
    for (pathBar = 0; pathBar < game.pathLength; pathBar++) {
        if (player.pastPositions[pathBar] == 0) {
            // This location is undiscovered by the player.
            printf("-");
        } else if ((player.pastPositions[pathBar] == 1) && (game.bombMap[pathBar] == 1) && (game.treasureMap[pathBar] == 1)) {
            // The location is discovered and has both treasure and a bomb.
            printf("&");
        } else if ((player.pastPositions[pathBar] == 1) && (game.bombMap[pathBar] == 1)) {
            // The location is discovered and has a bomb.
            printf("!");
        } else if ((player.pastPositions[pathBar] == 1) && (game.treasureMap[pathBar] == 1)) {
            // The location is discovered and has treasure.
            printf("$");
        } else if ((player.pastPositions[pathBar] == 1) && (game.bombMap[pathBar == 0]) && (game.treasureMap[pathBar] == 0)) {
            // The location is discovered and has nothing.
            printf(".");
        } else {
            printf("ERROR: The program encountered faulty data inside of the path.\n");
            return 1;  // Return non-zero exit code and end program.
        }
    }

    printf("\n  "); // Newline separator

    // Major Position Ruler (Shows first number every 10 positions)
    int majorPositionBar;
    for (majorPositionBar = 0; majorPositionBar < game.pathLength; majorPositionBar++) {
        if (((majorPositionBar + 1) % 10 == 0) && ((majorPositionBar + 1) / 10 != 0)) {
            // Position bar is not zero and is a multiple of 10.
            printf("%d", (majorPositionBar + 1) / 10);
        } else {
            printf("|");
        }
    }

    printf("\n  "); // Newline separator

    // Minor Position Ruler
    int minorPositionBar;
    for (minorPositionBar = 1; minorPositionBar <= game.pathLength; minorPositionBar++) {
        printf("%d", minorPositionBar % 10);
    }

    // Print out game statistics bar
    printf("\n"
           "+---------------------------------------------------+\n"
           "  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n"
           "+---------------------------------------------------+\n",
           player.lives, player.treasures, player.movesLeft);

    return 0; // Return 0 for successful run.
}


// Main Function
int main (void) {
    // Variable Declarations
    playerInfo player;  // Instance of our player.
    gameInfo game;      // Instance of our game.
    int correct = 0;    // User input validation tracker.
    int running;    // Used to keep track of if the game is running for main loop.
    player.pastPositions[0] = 0;
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
            printf("    Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
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
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
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
                    // User provided a value that wasn't a zero or one.
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
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
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
    // The treasure is now placed and the game is set up. Output confirmation
    printf("TREASURE placement set\n"
           "\n"
           "GAME configuration set-up is complete...\n");

    //  ==================================
    //  |   Configuration Confirmation   |
    //  ==================================
    printf("\n"
           "------------------------------------\n"
           "TREASURE HUNT Configuration Settings\n"
           "------------------------------------\n");

    // Player configuration
    printf("Player:\n"
           "   Symbol     : %c\n"
           "   Lives      : %d\n"
           "   Treasure   : [ready for gameplay]\n"
           "   History    : [ready for gameplay]\n",
           player.symbol,
           player.lives);

    printf("\n"); // newline as separator

    // Game configuration
    printf("Game:\n"
           "   Path Length: %d\n", game.pathLength);

    // Bombs output
    printf("   Bombs      : ");
    int m;
    for (m = 0; m < game.pathLength; m++) printf("%d", game.bombMap[m]);

    // Treasure output
    printf("\n"
           "   Treasure   : ");
    int n;
    for (n = 0; n < game.pathLength; n++) printf("%d", game.treasureMap[n]);

    printf("\n");

    // Print readiness confirmation
    printf("\n"
           "====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n"
           "\n");

    //  ======================================
    //  |   Fill Needed Arrays With Zeroes   |
    //  ======================================
    // This is done because the variables are not initialized to 0 when in a struct.
    int zeroing;
    for (zeroing = 0; zeroing < game.pathLength; zeroing++) {
        player.pastPositions[zeroing] = 0;
    }

    //  ========================
    //  |   Main Game Begins   |
    //  ========================
    // Begin main game loop
    running = 1; // Set the game to running status.
    player.movesLeft = game.maxMoves; // Set the player's moves to the amount of moves in the game.
    player.treasures = 0; // Initialize the player's treasures to zero.
    while (running) {
        // Display the HUD
        displayHUD(game, player);

        //  ==============================
        //  |     Player Interaction     |
        //  ==============================
        correct = 0; // Reset to zero for next use
        // Begin the input validation loop
        int selectedMove;
        while (!correct) {
            // Prompt user for input
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &selectedMove);

            // Validate response
            if ((selectedMove >= 1) && (selectedMove <= game.pathLength)) {
                printf("\n"); // Add extra newline

                if (player.pastPositions[selectedMove - 1] == 1) {
                    // The player has been here before. Do nothing.
                    printf("===============> Dope! You've been here before!\n\n");
                } else if ((game.treasureMap[selectedMove - 1] == 1) && (game.bombMap[selectedMove - 1] == 1)) {
                    // Player found a place with a bomb and treasure.
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n"
                           "===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    player.movesLeft--; // remove one move.
                    player.lives--; // remove one life.
                    player.treasures++; // add one treasure.
                } else if (game.treasureMap[selectedMove - 1] == 1) {
                    // The player found a place with treasure
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    player.movesLeft--; // remove one move.
                    player.treasures++; // add one treasure.
                } else if (game.bombMap[selectedMove - 1] == 1) {
                    // The player found a place with a bomb
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                    player.movesLeft--;
                    player.lives--;
                } else {
                    // The player found a place with nothing.
                    printf("===============> [.] ...Nothing found here... [.]\n\n");
                    player.movesLeft--; // remove one move.
                }

                player.pastPositions[selectedMove - 1] = 1; // Add to player history
                player.currentPosition = selectedMove;  // Set the player's current position
                correct = 1;
            } else {
                // Invalid response. Return error.
                printf("  Out of Range!!!\n");
                correct = 0;
            }
            // Prompt again if the response is not valid.
        }

        // Check if the game should be over.
        if (player.lives == 0) {
            // The player is out of lives.
            printf ("No more LIVES remaining!\n\n");

            running = 0;
        } else if (player.movesLeft == 0) {
            // The player is out of moves.
            printf("No more MOVES remaining!\n\n");

            running = 0;
        }
        // If the player is still alive and not out of moves, keep the game going :)
    }

    //  ========================
    //  |     Game Is Over     |
    //  ========================

    // Display the HUD
    displayHUD(game, player); // Display the HUD.

    // Display the game over screen.
    printf("\n"
           "##################\n"
           "#   Game over!   #\n"
           "##################\n"
           "\n"
           "You should play again and try to beat your score!\n");
    return 0;
}