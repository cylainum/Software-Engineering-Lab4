#include <stdio.h>
#include <ctype.h> // For toLower for scale input.

int main() {
    int temperature;
    char category;
    printf("Enter the temperature value: "); scanf("%d", &temperature);
    printf("Enter the original scale (C, F, or K): "); 
    scanf("%c", &category);
    
    if(tolower(category) != 'c');
        printf("%c",tolower(category));
    return 0;
}