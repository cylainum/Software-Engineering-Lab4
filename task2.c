#include <stdio.h>
#include <ctype.h> 


//init to celsius
float k_to_c(float kelvin) {
    return (kelvin - 273.15);
}
float f_to_c(float fahrenheit) {
    return ((fahrenheit-32)*(5.0/9.0));
}
//c to target
float c_to_f(float celsius) {
    return ((celsius*(9.0/5.0))+32);
}
float c_to_k(float celsius) {
    return (celsius + 273.15);
}


int main() {
    float temp;
    char category;
    int heat_level; //to later say how hot/cold it is.
    printf("Enter the temperature value: ");  // ToDo: add decimal support
    scanf("%f", &temp);
    
    while(1) {
        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &category); 
        if((toupper(category) != 'C') && (toupper(category) != 'K') && (toupper(category) != 'F')){ // This if-statement is to catch if the user
            printf("Please enter a valid character.\n");                                      // enters an unexpected char, like 'w'
        }
        else break;
    }
    if(toupper(category) == 'K') {
        
        temp = k_to_c(temp);
        category = 'C';
    } 
    if(toupper(category) == 'F') {
        temp = f_to_c(temp);
        category = 'C';
    }
    // Doing this now, while it's in Celsius.
    if (temp < 0) {
        heat_level = 0;
    } 
    else if (temp < 10) {
        heat_level = 1;
    } 
    else if (temp < 25) {
        heat_level = 2;
    } 
    else if (temp < 35) {
        heat_level = 3;
    } 
    else {
        heat_level = 4;
    }

    char target;
    
    while(1){
        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &target);
        if((toupper(target) != 'C') && (toupper(target) != 'K') && (toupper(target) != 'F')){ // This if-statement is to catch if the user
                printf("Please enter a valid character.\n");                                      // enters an unexpected char, like 'w'
        } else break;
    }
    if(toupper(target) == 'C') {
        printf("Converted temperature: %f\n", temp);
    }
    if(toupper(target) == 'K') {
        temp = c_to_k(temp);
        printf("Converted temperature: %f\n", temp);

    }
    if(toupper(target) == 'F') {
        temp = c_to_f(temp);
        printf("Converted temperature: %f\n", temp);
    }
    switch(heat_level){
        case 0: printf("Temperature category: Freezing\n"); 
                printf("Weather Advisory: Stay indoors."); break;
        case 1: printf("Temperature category: Cold\n"); 
                printf("Weather Advisory: Wear a coat!"); break;
        case 2: printf("Temperature category: Comfortable\n"); 
                printf("Weather Advisory: None."); break;
        case 3: printf("Temperature category: Hot\n");
                printf("Weather Advisory: Drink some water"); break;
        case 4: printf("Temperature category: Extreme Heat\n"); 
                printf("Weather Advisory: Wear light clothes!"); break;
    }
    return temp;
}