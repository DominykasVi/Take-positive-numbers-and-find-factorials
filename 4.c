#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void memory_allocation_check(void *pointer){
    if(pointer == NULL){
        printf("Cannot allocate memory\n");
        exit(1);
    }
}

unsigned int is_prime(int number) {
    if (number > 1) {
        for (int i = 2; i <= sqrt(number) + 0.0001; ++i) {
            if (!(number % i))
                return 0;
        }
        return 1;
    }
    return 0;
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int add_number() {
    int number;
    int return_code;
    while ((return_code = scanf("%9d", &number) == 0) || (getchar() != '\n')) {
        scanf("%*[^\n]");
        printf("Enter a  valid number: ");
    }
    return number;

}

int main() {
    int *array = NULL;
    int input = 0;
    int counter = 0;
    printf("Enter positive integer numbers, when you want to stop enter negative value\n");

    while (input >= 0){
        printf("Enter number:");
        input  = add_number();

        if(input < 0) {
            break;
        }

        array = (int*) realloc(array, (sizeof(int *) * (counter + 1)));
        memory_allocation_check(array);
        array[counter] = input;
        ++counter;
    }

    int *prime_array= NULL;
    int prime_counter = 0;
    for(int i = 0; i < counter; ++i) {
        //printf("%d ", array[i]);
        int repetition = 0;
        if(is_prime(array[i])){
            for(int j = 0; j < prime_counter; ++j){
                if(array[i] == prime_array[j]){
                    ++repetition;
                }
            }
            if(repetition == 0){
                prime_array = (int*) realloc(prime_array, (sizeof(int *) * (prime_counter + 1)));
                memory_allocation_check(prime_array);
                prime_array[prime_counter] = array[i];
                ++prime_counter;
            }
        }
    }

    free(array);

    bubbleSort(prime_array, prime_counter);
    for (int i = 0; i < prime_counter; ++i){
        printf("%d ", prime_array[i]);
    }
}