#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <iostream>
#define LINHA 0
#define COLUNA 1
char mapa[3][20];
int per;
int obj = 21;
int jump = 0;

void mostraPersonagem(){
        if(per == 2)
            printf("  P\n");
        else
            printf("\n");
        if(per == 1)
            printf("  P\n");
        else
            printf("\n");
}

void mostraMapa(){
    mostraPersonagem();
    for(int i = 0; i < 20; i++){
        if(obj == i)
            printf("$");
        else
            printf("_");
        if(i == 1){
            if(per == 0){
                printf("P");
            }
            else {
                printf("_");
            }
        }
    }
}

void controleJump(){
        if(kbhit()){
            if(getch()){
                jump = 1;
            }
        }
        if(jump>0){
            if(jump < 10){
                if(jump < 3)
                    per++;
                if(jump > 7)
                    per--;
                jump++;
            }
            else {
                jump = 0;
                per = 0;
            }
        }
        if(per > 2)
            per = 2;
}

void moveInimigo(){
    obj--;
    if(obj < -2){
        obj = 21;
    }
}

int main(){
    while(true){
        system("cls");
        controleJump();
        mostraMapa();
        moveInimigo();
        usleep(100000);
        if(obj == 1 && per == 0){
            return 0;
        }
    }
    return 0;
}
