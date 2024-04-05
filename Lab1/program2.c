#include <stdio.h>
int main(){
    int n1, n2, n3, sum, product;
    int avg;
    n1 = n2 = n3 = 0;
    printf("Enter three different integers: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    sum  = (n1+n2+n3);
    product =(n1 * n2 * n3);
    avg =  sum / 3;
    int diff_sum_product = sum - product;
    int sum_product_sign = (diff_sum_product >>31)& 1;
    int max_sum_product = sum - sum_product_sign * diff_sum_product;
    int min_sum_product = product + sum_product_sign * diff_sum_product;
    int diff_avg_product = avg - product;
    int avg_product_sign = (diff_avg_product >>31)& 1;
    int max_avg_product = avg - avg_product_sign * diff_avg_product;
    int min_avg_product = product + avg_product_sign * diff_avg_product;
    int diff_max = max_sum_product - max_avg_product;
    int diff_min = min_sum_product - min_avg_product;
    int largest = max_sum_product - diff_max * ((diff_max >>31)& 1);
    int smallest = min_avg_product + diff_min * ((diff_min >>31)& 1);

    printf("Smallest: %d \n",smallest);
    printf("Largest: %d \n",largest);
    return 0;
}