#include <stdio.h>
#include <stdlib.h>

int main() {
    int *samples = NULL;
    int count = 0, sum = 0, sample;
    char choice;
    float avg;

    do {
        printf("Enter a sample integer value: ");
        scanf("%d", &sample);

        count++;
        samples = (int*) realloc(samples, count * sizeof(int));
        if (samples == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        samples[count - 1] = sample;
        sum += sample;

        printf("Do you want to add more samples? (1/0): ");
        scanf(" %c", &choice);

    } while (choice == '1' );

    printf("You entered the following samples: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", samples[i]);
    }
    printf("\n");

    avg = (float) sum / count;
    printf("Here is the AVG : %.2f\n",avg);

    printf("Final adjusted samples after DC shift:\n");
    for (int i = 0; i < count; i++) {
        printf("%d  ", samples[i] - (int)avg);
    }
    printf("\n");

    free(samples);

    return 0;
}
