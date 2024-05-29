/*
 * This is a snakes and ladders game, made by Matthew Wuyts.
 */

// Included libraries
#include <stdio.h>

// Struct to keep player data
typedef struct Player{
    char name[32];                              // Player name
    int placement;                              // Which field?
} Player;

// Functions
int diceRoll() {                                // Manual dice roll
    int roll;
    printf("> Roll and note the number (1-6):");
    scanf("%d", &roll);
    while ((roll < 1) || (roll > 6)) {
        printf("> Invalid number, roll again (1-6):");
        scanf("%d", &roll);
    }
    return roll;
}

int exceptions(Player p) {                     // Snakes and ladders
    switch (p.placement) {
        case 2:
            printf("@ A ladder!\n");
            return 45;
        case 4:
            printf("@ A ladder!\n");
            return 27;
        case 9:
            printf("@ A ladder!\n");
            return 31;
        case 16:
            printf("@ A snake!\n");
            return 8;
        case 47:
            printf("@ A ladder!\n");
            return 84;
        case 52:
            printf("@ A snake!\n");
            return 28;
        case 70:
            printf("@ A ladder!\n");
            return 87;
        case 71:
            printf("@ A ladder!\n");
            return 91;
        case 78:
            printf("@ A snake!\n");
            return 25;
        case 93:
            printf("@ A snake!\n");
            return 89;
        case 95:
            printf("@ A snake!\n");
            return 75;
        case 99:
            printf("@ A snake!\n");
            return 21;
        default:
            return p.placement;
    }
}

int actions(Player p) {                         // Player actions
    int roll;
    printf("# Current position of %s: %d \n", p.name, p.placement);
    roll = diceRoll();
    printf("# %s rolled: %d \n", p.name, roll);
    p.placement += roll;
    p.placement = exceptions(p);
    printf("# New position of %s: %d \n\n", p.name, p.placement);

    return p.placement;
}

int main(void) {                                // Main function
    // Variables
    Player p1;
    Player p2;
    p1.placement = p2.placement = 1;

    // Welcome message
    printf(" ____________________________________________ \n");
    printf("| Welcome to the game of snakes and ladders! |\n");
    printf("| First to 100 or more wins! Good luck :)    |\n");
    printf("|____________________________________________|\n");
    printf("> Name of Player 1: ");
    scanf("%s", p1.name);
    printf("# Welcome %s\n", p1.name);
    printf("> Name of Player 2: ");
    scanf("%s", p2.name);
    printf("# Welcome %s\n", p2.name);
    printf("\n");

    // Game
    while (p1.placement < 100 || p2.placement < 100) {
        // Player 1
        p1.placement = actions(p1);
        if (p1.placement >= 100) {
            printf("!!! The winner is: %s !!!\n", p1.name);
            return 1;
        }
        // Player 2
        p2.placement = actions(p2);
        if (p2.placement >= 100) {
            printf("!!! The winner is: %s !!!\n", p2.name);
            return 1;
        }
    }

    return 0;
}
