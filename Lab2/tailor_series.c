#include <stdio.h>
/* the used rule is e^x = 1 + x/ + x^2 /!2 +x^3 / 3! +......
*/
int main()
{
    float x =0.0;
    double  exponential_result = 1.0,  term_value = 1.0;
    int num_iteration;

    printf("please enter the exponent : ");
    scanf("%f", &x);

    printf("please enter number of iteration : ");
    scanf("%i", &num_iteration);

    for (int i = 1; i <=num_iteration; i++)
    {
       term_value = term_value * (x / i);
        exponential_result = exponential_result +term_value ;
    }

    printf("Exponential Result is: %lf\n", exponential_result );

    return 0;
}

