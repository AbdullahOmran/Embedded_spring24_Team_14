#include <stdio.h>

int main()
{
    
    int firstitem = 0, seconditem= 1;
    int next_item,number_of_items= 0;

    printf("please enter number of items: ");
    scanf("%i", &number_of_items);

    printf("Fibonacci series for given %i is: ", number_of_items);

    for (int i =0; i <number_of_items; i++)
    {
        printf("%i ", firstitem);
        next_item= firstitem + seconditem;
        firstitem = seconditem;
        seconditem = next_item;
    }

    return 0;
}