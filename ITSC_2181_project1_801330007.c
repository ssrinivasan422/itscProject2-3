#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
float findMin(float arr[], int size);
float findMax(float arr[], int size);
float calculateAverage(float arr[], int size);
int findIndexOf(float arr[], int size, float num);
int countOccurrences(float arr[], int size, float num);
void printFirst100(float arr[]);

float calculateMedian(float arr[], int size);
float calculateMode(float arr[], int size);
float calculateRange(float arr[], int size);
float calculateStandardDeviation(float arr[], int size, float mean);
float calculateVariance(float arr[], int size, float mean);
void sortArray(float arr[], int size);

int main() {
    // Declare an array of 1000 floats (for demo purposes, we initialize it with random numbers)
    float balance[1000];
    int size = 1000;

    // Initialize the array with random values between 0 and 100
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        balance[i] = ((float)rand()/(float)(RAND_MAX)) * 100.0; // Random float values from 0 to 100
    }

    int command = 0;
    float num;
    int index;

    while(command != 13){
        printf("Welcome to the Data Explorer: Building Essential Data Analysis Tools in C!\n");
        printf("Please choose an option by entering the corresponding number:\n");
        printf("1: Find the minimum value\n");
        printf("2: Find the maximum value\n");
        printf("3: Calculate the average\n");
        printf("4: Find the index of a given number\n");
        printf("5: Count occurrences of a given number\n");
        printf("6: Print the first 100 elements\n");
        printf("7: Calculate the median\n");
        printf("8: Calculate the mode\n");
        printf("9: Calculate the range\n");
        printf("10: Calculate the standard deviation\n");
        printf("11: Calculate the variance\n");
        printf("12: Sort the array\n");
        printf("13: Exit\n");
       

        printf("Enter your command: ");
        scanf("%d", &command);

        switch(command){
            case 1:
                printf("The minimum value is: %.2f\n", findMin(balance, size));
                break;
            case 2:
                printf("The maximum value is: %.2f\n", findMax(balance, size));
                break;
            case 3:
                printf("The average value is: %.2f\n", calculateAverage(balance, size));
                break;
            case 4:
                printf("Enter the number to find: ");
                scanf("%f", &num);

                
                index = findIndexOf(balance, size, num);

                if(index == -1){
                    printf("The number %.2f is not found in the array.\n", num);
                } 
                else{
                    printf("The number %.2f is found at index %d.\n", num, index);
                }
                break;
            case 5:
                printf("Enter the number to find: ");
                scanf("%f", &num);

                printf("The number %.2f occurs %d times in the array.\n",
           num, countOccurrences(balance, size, num));
                break;
            case 6:
                printFirst100(balance);
                break;
            case 7:
                printf("Median selected\n");
                break;
            case 8:
                printf("Mode selected\n");
                break;
            case 9:
                printf("Range selected\n");
                break;
            case 10:
                printf("Standard deviation selected\n");
                break;
            case 11:
                printf("Variance selected\n");
                break;
            case 12:
                printf("Sort selected\n");
                break;
            case 13:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command. Try again.\n");

        }
    }
}

float findMin(float arr[], int size){
    float min = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

float findMax(float arr[], int size){
    float max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

float calculateAverage(float arr[], int size){
    float average = 0;
    for(int i = 0; i < size; i++){
        average += arr[i];
    }
    average = average / size;
    return average;
}

int findIndexOf(float arr[], int size, float num){
    for(int i = 0; i < size; i++){
        if((int)(arr[i] * 100) == (int)(num * 100)){
            return i;
        }
    }
    return -1;
}

int countOccurrences(float arr[], int size, float num){
    int counter = 0;

    for(int i = 0; i < size; i++){
        
        if(fabs(arr[i] - num) < 0.01){
            counter++;
            printf("index %f\n", arr[i]);
            printf("counter %d\n", counter);
            printf("%f\n", num);
        }
    }
    return counter;
}

void printFirst100(float arr[]){
    for(int i = 0; i < 100; i++){
        printf("%.2f ", arr[i]);
    }
}

