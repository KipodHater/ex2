/******************
Name: Eitan Dror
ID: 218241420
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
    // MAIN MENU LOOP
    int gameSelection = -1;
    while (gameSelection != 6) {
    printf("Welcome to our games, please choose an option:\n"
       "1. Ducky's Unity Game\n"
       "2. The Memory Game\n"
       "3. Professor Pat's Power Calculation\n"
       "4. The Duck Parade\n"
       "5. The Mystery of the Repeated Digits\n"
       "6. Good Night Ducks\n");

        scanf("%d", &gameSelection);

        switch (gameSelection) {
            // TASK 1: Ducky's Unity Game
            case 1:
                int positiveBits, a;
                printf("please enter a positive number:\n");
                scanf("%d", &a);
                while(a <= 0){
                    printf("Invalid number, please try again\n");
                    scanf("%d", &a);
                }
                for(positiveBits = 0; a > 0; a>>=1) positiveBits += a&1;
                printf("Ducky earns %d corns\n", positiveBits);
                break;

            // TASK 2: The Memory Game
            case 2:
                int numberOfDucks;
                printf("please enter the number of ducks:\n");
                scanf("%d", &numberOfDucks);
                while(numberOfDucks <= 0){
                    printf("Invalid number, please try again\n");
                    scanf("%d", &numberOfDucks);
                }
                printf("you entered %d ducks\n", numberOfDucks);
                int ducksWord = 0;

                for(int i=1; i <= numberOfDucks; i++) {
                    int bit;
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i);
                    scanf("%d", &bit);
                    while(bit != 1 && bit != 0){
                        printf("Invalid number, please try again\n");
                        scanf("%d", &bit);
                    }
                    ducksWord = ducksWord | (bit << (i-1));
                }

                for(int i=1; i<= numberOfDucks; i++) {
                    int curBit = (ducksWord >> (i-1)) & 1;
                    if(curBit == 1) printf("duck number %d do Quak\n", i);
                    else printf("duck number %d do Sh...\n", i);
                }
                break;

            // TASK 3: Professor Pat's Power Calculation
            case 3:
                int number, exponent;
                printf("please enter the number\n");
                scanf("%d", &number);
                while(number < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &number);
                }
                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while(exponent < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                }
                int result = 1;
                for(int i=0; i < exponent; i++) result *= number;

                printf("your power is: %d\n", result);
                break;

            // TASK 4: The Duck Parade
            case 4:
                int n;
                printf("please enter number of ducks:\n");
                scanf("%d", &n);
                while(n < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &n);
                }
                for(int i=0; i<n/10; i++) {
                    for(int j=0; j<10; j++) printf("   _            ");
                    printf("\n");
                    for(int j=0; j<10; j++) printf("__(o)>          ");
                    printf("\n");
                    for(int j=0; j<10; j++) printf("\\___)           ");
                    printf("\n");
                    }
                for(int j=0; j<n%10; j++) printf("   _            ");
                printf("\n");
                for(int j=0; j<n%10; j++) printf("__(o)>          ");
                printf("\n");
                for(int j=0; j<n%10; j++) printf("\\___)           ");
                printf("\n");
                break;

            // TASK 5: The Mystery of the Repeated Digits
            case 5:
                int digits;
                printf("please enter number\n");
                scanf("%d", &digits);
                while(digits <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &digits);
                }
                int m = digits;
                int lastDigit = 1;
                m /= 10;
                while(m>0) {
                    lastDigit *= 10;
                    m/=10;
                }
                int hasAppeared = 0;
                while(lastDigit > 0) {
                    int curDigit = digits / (lastDigit);
                    curDigit %= 10;
                    if(hasAppeared & (1 << curDigit)) printf("%d appears more than once!\n", curDigit);
                    hasAppeared = hasAppeared | (1 << curDigit);
                    lastDigit/=10;
                }
                break;

            // TASK 6: EXIT
            case 6:
                printf("Good night! See you at the pond tomorrow.");
                break;
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    }
    return 0;
}
