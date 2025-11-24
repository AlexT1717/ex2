/******************
Name: Alexander Tokmakov
ID: 322262148
Assignment: 2
*******************/

#include <stdio.h>

int main()
{
    //For validation of the game choose number
    int isMainGameActive = 0;
    // MAIN MENU LOOP
    while (isMainGameActive == 0) {
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        int gameNumber = 0;
        //The game choose number
        scanf("%d", &gameNumber);
        switch (gameNumber) {
            // TASK 1: Ducky's Unity Game
            case 1: {
                    //For validation of the positive number
                    int isFirstGameActive = 0;
                    int maxIntBits = sizeof(int) * 8;
                    printf("please enter a positive number:\n");
                    while (isFirstGameActive == 0) {
                        int positiveNumber = 0;
                        scanf("%d", &positiveNumber);
                        if (positiveNumber < 0) {
                            printf("Invalid number, please try again\n");
                        } else {
                            //Counter for the 1's in the binary format of the number
                            int count = 0;
                            //Assume int is 32 bits go through all the bits and count the 1's
                            for (int i = 0; i < maxIntBits; i++) {
                                int isLeftBitOdd = positiveNumber & 1;
                                if (isLeftBitOdd == 1) {
                                    count++;
                                }
                                //Move the number to the next bit
                                positiveNumber = positiveNumber >> 1;
                            }
                            printf("Ducky earns %d corns\n", count);
                            //End of the task after the Output
                            isFirstGameActive = 1;
                        }
                    }
                }
                break;
            // TASK 2: The Memory Game
            case 2: {
                    //To enter the loop and to handle the validation for negative numbers
                    int numberOfDucks = -1;
                    printf("please enter the number of ducks:\n");
                    while (numberOfDucks <= 0) {
                        scanf("%d", &numberOfDucks);
                        if (numberOfDucks <= 0) {
                            printf("Invalid number, please try again\n");
                        } else {
                            printf("you entered %d ducks\n", numberOfDucks);
                            //unsigned long long because it handles up to 64 bits
                            unsigned long long ducksSounds = 0;
                            //Loop to take all the inputs for QUAK for every duck
                            for (int i = 0; i < numberOfDucks; i++) {
                                int sound = 0;
                                int isSoundValid = 0;
                                //Validation of the QUAK input
                                while (isSoundValid == 0) {
                                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", (i+1));
                                    scanf("%d", &sound);
                                    if (sound != 0 && sound != 1) {
                                        printf("Invalid number, please try again\n");
                                    } else {
                                        //Shift the number to save the sound on LSB
                                        ducksSounds = ducksSounds << 1;
                                        //Save the sound
                                        ducksSounds = ducksSounds | (sound & 1);
                                        //Pass to the next duck after a valid input
                                        isSoundValid = 1;
                                    }
                                }
                            }
                            //Loop in reverse to get the first duck from the end
                            for (int i = numberOfDucks - 1; i >= 0; i--) {
                                //Get the last bit that we need
                                unsigned long long lastDuck = ducksSounds >> i;
                                if (lastDuck & 1) {
                                    //-i + numberOfDucks is the actual number of the duck
                                    printf("duck number %d do Quak\n", (-i + numberOfDucks));
                                } else {
                                    printf("duck number %d do Sh...\n", (-i + numberOfDucks));
                                }
                            }
                        }
                    }
                }
                break;
            // TASK 3: Professor Pat's Power Calculation
            case 3: {
                    //-1 to enter the loop first and for validation of positive number input
                    int number = -1, exponent = -1, result = 0;
                    printf("please enter the number\n");
                    while (number < 0) {
                        scanf("%d", &number);
                        if (number < 0) {
                            printf("Invalid number, please try again\n");
                        } else {
                            printf("please enter the exponent\n");
                            while (exponent < 0) {
                                scanf("%d", &exponent);
                                if (exponent < 0) {
                                    printf("Invalid number, please try again\n");
                                } else {
                                    result = 1;
                                    //If exponent is 0 the result 1 if not so make the for exponent times
                                    for (int i = 0; i < exponent; i++) {
                                        //Multiply the result by the number
                                        result = result * number;
                                    }
                                }
                            }
                        }
                    }
                    printf("your power is: %d\n", result);
                }
                break;
            // TASK 4: The Duck Parade
            case 4: {
                    //For validation and to handle the number of the ducks to draw
                    int drawDucks = -1;
                    int maxDucksInOneLine = 10;
                    printf("please enter number of ducks:\n");
                    while (drawDucks < 0) {
                        scanf("%d", &drawDucks);
                        if (drawDucks < 0) {
                            printf("Invalid number, please try again\n");
                        } else {
                            //Ducks to print in the every line
                            int drawDucksToPrint = 0;
                            while (drawDucks > 0) {
                                //Max ducks in 1 line
                                if (drawDucks > maxDucksInOneLine) {
                                    drawDucksToPrint = maxDucksInOneLine;
                                    //New number of the ducks after the line
                                    drawDucks = drawDucks - maxDucksInOneLine;
                                } else {
                                    //Last line print
                                    drawDucksToPrint = drawDucks;
                                    //Exit of the loop after the last line
                                    drawDucks = 0;
                                }
                                for (int i = 0; i < drawDucksToPrint; i++) {
                                    printf("   _  \t");
                                }
                                printf("\n");
                                for (int i = 0; i < drawDucksToPrint; i++) {
                                    printf("__(o)>\t");
                                }
                                printf("\n");
                                for (int i = 0; i < drawDucksToPrint; i++) {
                                    printf("\\___) \t");
                                }
                                printf("\n");
                            }
                        }
                    }
                }
                break;
            // TASK 5: The Mystery of the Repeated Digits
            case 5: {
                    //For validation and to handle the number
                    int longNumber = -1;
                    //Flag for finish because the number is 0 also
                    int isNumberValid = 0;
                    printf("please enter number\n");
                    while (isNumberValid == 0) {
                        scanf("%d", &longNumber);
                        if (longNumber <= 0) {
                            printf("Invalid number, please try again\n");
                        } else {
                            while (longNumber != 0) {
                                //The number to find
                                int checkNumber = longNumber % 10;
                                longNumber = longNumber / 10;
                                int tempNumber = longNumber;
                                int count = 0;
                                //Find the number Loop
                                while (tempNumber != 0) {
                                    if (checkNumber == tempNumber % 10) {
                                        count++;
                                    }
                                    tempNumber = tempNumber / 10;
                                }
                                //If Appears more than once print so
                                if (count > 0) {
                                    printf("%d appears more than once!\n", checkNumber);
                                }
                                isNumberValid = 1;
                            }
                        }
                    }
                }
                break;
            // TASK 6: EXIT
            case 6: {
                    //The EXIT choose on 6
                    printf("Good night! See you at the pond tomorrow.\n");
                    //Flag for exit from the main loop
                    isMainGameActive = 1;
                }
                break;
            default:
                //The game choose number validation
                printf("Invalid option, please try again\n");
        }
    }
    return 0;
}