/*
 * Author: Sherlyn Ballestero Cruz
 * Date: 24/22/2026
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
const float Radiation_MAX = 1.0;   // Maximum safe radiation level

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

//prototype
void inputParameter(float *parameter,float min, float max,char paramName []);
void displayCollectedData(void);
void sumarizeWarnings(void);



int main()
{
 
    // Step 2: Input Validation for Temperature
    // Use a loop to validate input and ensure it is within a reasonable range
    inputParameter(&temperature,-100,100,"temperature");

    
    // Step 3: Input Validation for Windspeed
    // Use a loop to ensure the windspeed is non-negative
    inputParameter(&windspeed,0,__FLT_MAX__,"windspeed, (non-negative value)");
    
    // Step 4: Input Validation for Dust Level
    // Use a loop to ensure dust level is between 0% and 100%
    inputParameter(&dustLevelPercent,0,100,"dust level percent");
    
    
    // Step 5: Input Validation for Radiation Level
    // Use a loop to ensure the radiation level is non-negative
    inputParameter(&radiationLevel,0,__FLT_MAX__,"radiation level,(non-negative value)");


    // Step 6: Check for Critical Thresholds Using If-Else Statements
    // Compare sensor data against defined thresholds and set warning flags
    if(temperature>TEMP_MAX || temperature<TEMP_MIN){
        tempWarning=true;
        printf("WARNING: Temperature extreme (%.1f °C) \n",temperature);
    }
    
    if (dustLevelPercent>DUST_MAX)
    {
        dustWarning=true;
        printf("WARNING: Dust Lavel Percent too high! \n");
    }
    
    if(windspeed>WindS_MAX){

        windspeedWarning=true;
        printf("WARNING: strong wind detected (%.1f m/s), risk of structural damage\n", windspeed); 
    }
    
    if(radiationLevel>Radiation_MAX){

        radWarning=true;
        printf("WARNING: High radiation detected, (%.3f mSv/h) - Possible solar event!\n", radiationLevel);  
    }

    if(tempWarning||dustWarning||windspeedWarning||radWarning){
        shutdownRequired=true;
        printf("Rover shutdown required to prevent damage.\n");
    }

    

    // Step 7: Display the Collected Data in a Formatted Output
    // Print sensor data clearly in a table format
    displayCollectedData();
    
    
    // Step 8: Summarize Warnings if Critical Conditions Are Triggered
    // Display warnings based on the set flags
    sumarizeWarnings();
  

    return 0;
}


void inputParameter(float *parameter,float min, float max,char paramName []){
      while(true)
      {
        //ask the user for data
        printf("Please enter the %s value:",paramName);
        //validate the input is a float and was saved correctly
        validationIndex=scanf("%f",parameter);

        if (validationIndex==1)
        {
            //check if the value is in a reasonable range, for example for a percent between 0 and 100
            if(*parameter>=min && *parameter<=max){
                validationIndex=0;
                break;  
            }
            else
            {
                printf("Error: %s out of reasonable range: [%.1f, %.1f].\n",paramName, min, max);
                // Clear the input buffer
                while (getchar() != '\n');
          
            }  

        } 
        else
        {  
            printf("Error - invalid data type received. Values must be a number or decimal in reasonables range. Please try again.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
    } 
}

void displayCollectedData(void)
{
    printf("Entered Sensor  Data\n");
    printf("---------------------------\n");
    printf("Temperature: (%.1f °C)\n",temperature);
    printf("Windspeed:(%.1f m/s)\n",windspeed);
    printf("Dust Level: (%.1f%%)\n",dustLevelPercent);
    printf("Radiation Level:  (%.3f mSv/h)\n",radiationLevel);
    printf("---------------------------\n");

} 

void sumarizeWarnings(void)
{
      printf("\nSystem Warnings Summary:\n");
    printf("---------------------------\n");
    if (!shutdownRequired) {
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
}