#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float greaternum(int);
int randomNumber();
void guessingnum(int*);

int main() {
    srand(time(0));
    int num,count = 0;
    int randomnum = randomNumber();
    printf("%d", randomnum);
    for (int i=0;;i++){
        guessingnum(&num);
        // int a = 48;
        // printf("%d",greaternum(randomnum));
        if (abs(num-randomnum)<=5 && num!=randomnum){
            printf("too close\n");
        }
        else if (num>randomnum){
            printf("too high\n");
        }
        else if(num<randomnum){
            printf("too low\n");
        }

        else if (num==randomnum){
            printf("you won\n");
            break;
        }
        else {
            printf("sorry theere is an error\n");
        }
        count++;
    }
    printf("You took this many attempts: %d",count);
}

int randomNumber(){
    return rand() % 100 +1;
}

void guessingnum(int *a){
    printf("enter your guess: ");
    scanf("%d", a);
}

// float greaternum(int a){
//     return (a/10.0)+1;
// }