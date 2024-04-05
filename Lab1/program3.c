#include <stdio.h>

int main(){
    int seconds;
    seconds= 0;
    printf("Enter the total time elapsed: ");
    scanf("%d", &seconds);
    int hours, minutes, secs;
    hours = seconds / (60*60);
    seconds  = seconds % ( 60*60);
    minutes = seconds/60;
    seconds = seconds%60;
    secs = seconds;
    printf("Enter the total time elapsed: %d:%d:%d", hours, minutes, secs);
    return 0;
}