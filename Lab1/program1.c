#include <stdio.h>

int main(){
    float u, a, t,v,s ;
    u=a=t = 0;
    printf("Enter the initial velocity: ");
    scanf("%f", &u);
    printf("Enter the acceleration: ");
    scanf("%f", &a);
    printf("Enter the elapsed time: ");
    scanf("%f", &t);
    v = u + a * t;
    s = u*t + 0.5 * a * t*t;
    printf("the final velocity is: %.2f \n",v);
    printf("the distance is: %.2f",s);
    return 0;
}