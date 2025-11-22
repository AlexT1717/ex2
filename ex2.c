/******************
Name: Alexander Tokmakov
ID: 322262148
Assignment: 2
*******************/

#include <stdio.h>

int main()
{
    int flag = 0; //For validation of the game choose number
    // MAIN MENU LOOP
    while (flag == 0) {
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation Game\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        int gameNumber = 0;
        scanf("%d", &gameNumber); //The game choose number
        switch (gameNumber) {
            // TASK 1: Ducky's Unity Game
            case 1:
                int firstGameFlag = 0; //For validation of the positive number
                while (firstGameFlag == 0) {
                    printf("please enter a positive number:\n");
                    int positiveNumber = 0;
                    scanf("%d", &positiveNumber);
                    if (positiveNumber < 0) {
                        printf("Invalid number, please try again\n");
                    } else {
                        int count = 0; //Counter for the 1's in the binary format of the number
                        //Assume int is 32 bits go throw all the bits and count the 1's
                        for (int i =0; i < 31; i++) {
                            int oddNumValidation = positiveNumber & 1;
                            if (oddNumValidation == 1) {
                                count++;
                            }
                            positiveNumber = positiveNumber >> 1; //Move the number to the next bit
                        }
                        printf("Ducky earns %d corns\n", count);
                        firstGameFlag = 1; //End of the task after the Output
                    }
                }
                break;
            // TASK 2: The Memory Game
            case 2:
                int numberOfDucks = -1; //To enter the loop and to handle the validation for negative numbers
                while (numberOfDucks < 0) {
                    printf("please enter the number of ducks:\n");
                    scanf("%d", &numberOfDucks);
                    if (numberOfDucks < 0) {
                        printf("Invalid number, please try again\n");
                    } else {
                        //unsigned long long cuse its handle up to 64 bits
                        unsigned long long ducksSounds = 0;
                        //Loop to take all the inputs for QUAK for every duck
                        for (int i = 0; i < numberOfDucks; i++) {
                            int sound = 0;
                            int soundFlag = 0;
                            //Validation of the QUAK input
                            while (soundFlag == 0) {
                                printf("duck %d do QUAK? 1 for yes, 0 for no:\n", (i+1));
                                scanf("%d", &sound);
                                if (sound != 0 && sound != 1) {
                                    printf("Invalid number, please try again\n");
                                } else {
                                    ducksSounds = ducksSounds << 1; //Shift the number to save the sound on LSB
                                    ducksSounds = ducksSounds | (sound & 1); //Save the sound
                                    soundFlag = 1; //Pass to the next duck after a valid input
                                }
                            }
                        }
                        //Loop in reverse to get the first duck from the end
                        for (int i = numberOfDucks - 1; i >= 0; i--) {
                            unsigned long long lastDuck = ducksSounds >> i; //Get the last bit thet we needs
                            if (lastDuck & 1) {
                                //-i + numberOfDucks is the actual number of the duck
                                printf("duck number %d do Quak\n", (-i + numberOfDucks));
                            } else {
                                printf("duck number %d do Sh...\n", (-i + numberOfDucks));
                            }
                        }
                    }
                }
                break;
            // TASK 3: Professor Pat's Power Calculation
            case 3:
                //-1 to enter the loop first and for validation of positive number input
                int number = -1, exponent = -1, result = 0;
                while (number < 0) {
                    printf("please enter the number\n");
                    scanf("%d", &number);
                    if (number < 0) {
                        printf("Invalid number, please try again\n");
                    } else {
                        while (exponent < 0) {
                            printf("please enter the exponent\n");
                            scanf("%d", &exponent);
                            if (exponent < 0) {
                                printf("Invalid number, please try again\n");
                            } else {
                                result = 1;
                                //If exponent is 0 the result 1 if not so make the for exponent times
                                for (int i = 0; i < exponent; i++) {
                                    result = result * number; //Multiply the result by the number
                                }
                            }
                        }
                    }
                }
                printf("your power is: %d\n", result);
                break;
            // TASK 4: The Duck Parade
            case 4:
                int drawDucks = -1; //For validation and to handle the number of the ducks to draw
                while (drawDucks < 0) {
                    printf("please Enter number of ducks:\n");
                    scanf("%d", &drawDucks);
                    if (drawDucks < 0) {
                        printf("Invalid number, please try again\n");
                    } else {
                        int drawDucksToPrint = 0; //Ducks to print in the every line
                        while (drawDucks > 0) {
                            if (drawDucks > 10) {
                                drawDucksToPrint = 10;
                                drawDucks = drawDucks - 10; //New number of the ducks after the line
                            } else {
                                drawDucksToPrint = drawDucks; //Last line print
                                drawDucks = 0; //Exit of the loop after the last line
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
                break;
            // TASK 5: The Mystery of the Repeated Digits
            case 5:
                int longNumber = -1; //For validation and to handle the number
                while (longNumber < 0) {
                    printf("please enter number\n");
                    scanf("%d", &longNumber);
                    if (longNumber < 0) {
                        printf("Invalid number, please try again\n");
                    } else {
                        while (longNumber != 0) {
                            int cheakNumber = longNumber % 10; //The number to find
                            longNumber = longNumber / 10;
                            int tempNumber = longNumber;
                            int count = 0;
                            //Find the number Loop
                            while (tempNumber != 0) {
                                if (cheakNumber == tempNumber % 10) {
                                    count++;
                                }
                                tempNumber = tempNumber / 10;
                            }
                            //If Appears more than once print so
                            if (count > 0) {
                                printf("%d appears more than once!\n", cheakNumber);
                            }
                        }
                    }
                }
                break;
            // TASK 6: EXIT
            case 6:
                printf("Good night! See you at the pond tomorrow.\n"); //The EXIT choose on 6
                flag = 1; //Flag for exit from the main loop
                break;
            default:
                printf("Invalid option, please try again\n"); //The game choose number validation
        }
    }
    return 0;
}