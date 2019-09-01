//Arick Mounts
#include <stdio.h>
#include <stdlib.h>   
#include <ctype.h>

void twentyNum(int randnum);
static int rollem(void);

static int p=0, pc=0;

/*
 *A guessing game that the users plays by guessing the programs randomly generated value
 *C @ TCC
 *Arick Mounts
 */

void main (void){
    char input;
    srand(time(0));
    printf("Would you like to play a guessing game?\n");
    printf("Enter Y for yes, or N for no: ");
    scanf("%c", &input);
    input= toupper(input);    
    
    while (input == 'Y'){
        getchar();
        twentyNum(rollem());
        printf("Would you like to play again?\n");
        printf("Enter Y for yes, or N for no: \n");
        scanf("%c", &input);
        input= toupper(input);
    }
    printf("Final score: Player:%d Computer:%d\n", p, pc);
}

void twentyNum(int randnum)
{
    int input;
    int guessnum = 0, g = 1;
 
    printf("************************\n\n");
    printf("Welcome to the guessing game!\n");
    printf("I'm thinking of a number between 1 and 20.\n");
    printf("You have 4 guesses, enter 0 to forfeit\n");
    scanf("%d", &input);
    getchar();
    while(guessnum<4 && input!=0){
        if (input==randnum){
            g=0;
            
        } else if( input>randnum && guessnum!=3){
            printf("The number is lower\n");
            scanf("%d", &input);
            getchar();
        }else if(input<randnum && guessnum!=3){
            printf("The number is higher\n");
            scanf("%d", &input);
            getchar();
        }else if (guessnum==3){
            g=2;
        }
        guessnum++;
    }
    if(g == 2){
        printf("You lose! The number was: %d\n", randnum);
        pc++;
        
    }else if(g==0){
            printf("That's right! The number was: %d\n",randnum);
            p++;
    }
    printf("Current score is: Player:%d Computer:%d\n\n", p, pc);
    printf("************************\n");
 
}
static int rollem(void)  /* private to this file */
{
    int roll;
    int sides = 20;
    
    roll = rand() % sides + 1;   
    
    return roll;
}