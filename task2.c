#include <stdio.h>
#include <ctype.h> 


//init to celsius
float k_to_c(float kelvin) {
    return (kelvin - 273.15);
}
float f_to_c(float fahrenheit) {
    return ((fahrenheit-32)*(5/9));
}
//c to target
float c_to_f(float celsius) {
    return ((celsius*(9/5))+32);
}
float c_to_k(float celsius) {
    return (celsius + 273.15);
}


int main() {
    float temperature;
    char category;
    
    printf("Enter the temperature value: ");  // ToDo: add decimal support
    scanf("%f", &temperature);
    
    while(1) {
        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &category); 
        if((toupper(category) != 'C') && (toupper(category) != 'K') && (toupper(category) != 'F')){ // This if-statement is to catch if the user
            printf("Please enter a valid character.\n");                                      // enters an unexpected char, like 'w'
        }
        else break;
    }
    if(toupper(category) == 'K') {
        
        temperature = k_to_c(temperature);
        category = 'C';
    } 
    if(toupper(category) == 'F') {
        temperature = f_to_c(temperature);
        category = 'C';
    }
    char target;
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &target);
    if((toupper(target) != 'C') && (toupper(target) != 'K') && (toupper(target) != 'F')){ // This if-statement is to catch if the user
            printf("Please enter a valid character.\n");                                      // enters an unexpected char, like 'w'
        }
    if(toupper(target) == 'C') {
        printf("Converted temperature: %f\n", temperature);
        return temperature;
    }
    if(toupper(target) == 'K') {
        temperature = c_to_k(temperature);
        printf("Converted temperature: %f\n", temperature);
        return temperature;
    }
    if(toupper(target) == 'F') {
        temperature = c_to_f(temperature);
        printf("Converted temperature: %f\n", temperature);
        return temperature;
    }
}