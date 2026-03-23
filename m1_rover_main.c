/*
 * Author: Sherlyn Ballestero Cruz
 * Date: 03/22/2026
 * Description: Milestone 1 - Rover Sensory Data Input and Validation
 */

// Include required header files

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Constants for thresholds

const float TEMP_MAX = 50.0;   // Indicates if the temperature(internal) is outside the safe range  
const float TEMP_MIN = -20.0;   // Indicates if the temperature (internal) is outside the safe range  

const float DUST_MAX = 75.0;   // Maximum safe dust level percent
const float WindS_MAX = 30.0;   // Maximum safe wind speed level aprox,Design to withstand up to about 30 m/s
const float Radiation_MAX = 1.0;   // Maximum safe radiation level,try safe mode or shutdown


int main() {
    // Step 1: Variable Declarations and Initialization
    // Declare variables for Temperature, Windspeed, Dust Level, and Radiation Level
    // Initialize Boolean flags for critical warnings
    float temperature;
    float windspeed;
    float dustLevelPercent; //dust lavel in percent (0%-100%)
    float radiationLevel;
    int validationIndex=0;

    //flags for critical warnings
    bool shutdownRequired = false;    // Indicates if an emergency shutdown is necessary
    bool tempWarning = false;         // Temperature is not within safe range 
    bool dustWarning=false;           // Dust is not within safe range 
    bool  windspeedWarning= false;    // Indicates if an emergency shutdown is necessary
    bool  radWarning= false;    // Indicates if an emergency shutdown is necessary
 

    // Step 2: Input Validation for Temperature
    // Use a loop to validate input and ensure it is within a reasonable range
    while(true){
        printf("Please enter the temperature value:");
        validationIndex=scanf("%f",&temperature);
        if (validationIndex==1){
            validationIndex=0;
            break;
        }
        else{  
            printf("Error - invalid data type received. Values must be a number or decimal. Please try again.\n");
        }
    }
    
    // Step 3: Input Validation for Windspeed
    // Use a loop to ensure the windspeed is non-negative
    while(true){
        printf("Please enter the  windspeed value:");
        validationIndex=scanf("%f",&windspeed);
        if (validationIndex==1 && windspeed>=0){
            break;
        }
        else{  
            printf("Error - invalid data type received. Values must be a number or decimal positive. Please try again.\n");
        }
    }
    
    // Step 4: Input Validation for Dust Level
    // Use a loop to ensure dust level is between 0% and 100%
    
    while(true){
        printf("Please enter the  dust Level Percent value:");
        validationIndex=scanf("%f",&dustLevelPercent);
        if (validationIndex==1 && dustLevelPercent>=0  && dustLevelPercent<=100){
            break;
        }
        else{  
            printf("Error - invalid data type received. Values must be a number or decimal in the range 0-100. Please try again.\n");
        }
    }
    // Step 5: Input Validation for Radiation Level
    // Use a loop to ensure the radiation level is non-negative
    while(true){
        printf("Please enter the  radiation level value:");
        validationIndex=scanf("%f",&radiationLevel);
        if (validationIndex==1 && radiationLevel>=0){
            break;
        }
        else{  
            printf("Error - invalid data type received. Values must be a number or decimal positive. Please try again.\n");
        }
    }


    // Step 6: Check for Critical Thresholds Using If-Else Statements
    // Compare sensor data against defined thresholds and set warning flags
    if(temperature>TEMP_MAX || temperature<TEMP_MIN){
        tempWarning=true;
        shutdownRequired = true;//not sure when needed shutdown
        printf("WARNING: Temperature extreme (%.1f °C) Rover shutdown required to prevent damage.\n",temperature);
       
    }
    
    if (dustLevelPercent>DUST_MAX)
    {
        dustWarning=true;
        shutdownRequired = true;
        printf("WARNING: Dust Lavel Percent too high! Rover shutdown required to prevent damage.\n");
    }
    
    if(windspeed>WindS_MAX){

        windspeedWarning=true;
        shutdownRequired = true;
        printf("WARNING: strong wind detected (%.1f m/s), risk of structural damage\n", windspeed); 
    }
    
    if(radiationLevel>Radiation_MAX){

        radWarning=true;
        shutdownRequired = true;
        printf("WARNING: High radiation detected, (%.3f mSv/h) - Possible solar event!\n", radiationLevel);  
    }

    

    // Step 7: Display the Collected Data in a Formatted Output
    // Print sensor data clearly in a table format
    printf("Entered Sensor  Data\n");
    printf("---------------------------\n");
    printf("Temperature: %f°C\n",temperature);
    printf("Windspeed: %fm/s\n",windspeed);
    printf("Dust Level: %f%%\n",dustLevelPercent);
    printf("Radiation Level: %fmSv/h\n",radiationLevel);
    printf("---------------------------\n");
    
    
    // Step 8: Summarize Warnings if Critical Conditions Are Triggered
    // Display warnings based on the set flags
    printf("\nSystem Warnings Summary:\n");
    printf("---------------------------\n");
    if (!tempWarning && !dustWarning && !windspeedWarning && !radWarning) {
        printf("No critical warnings detected.\n");
    } else 
    {
        if (tempWarning) 
        {
            printf("Temperature out of safe range (%.1f °C)\n", temperature);
        }
        if (dustWarning) 
        {
            printf("Dust level too high (%.1f%%)\n", dustLevelPercent);
        }
        if (windspeedWarning) 
        {
            printf("Windspeed too high (%.1f m/s)\n", windspeed);
        }
        if (radWarning) 
        {
            printf("Radiation level too high (%.3f mSv/h)\n", radiationLevel);
        }
    }

    return 0;
}