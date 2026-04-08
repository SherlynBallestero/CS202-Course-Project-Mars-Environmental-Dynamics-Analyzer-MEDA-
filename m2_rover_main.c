/*
 * Author: Sherlyn Ballestero Cruz
 * Date: 04/08/2026
 * Description: Milestone 2 - Input Validation, Calculations, and Critical Warnings
 */

// Include required header files

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


// Constants for thresholds and sensor readings
const float VALUE_MAX = 50.0;   // Maximum safe <sensor data> value

// Constants for thresholds
const float TEMP_MAX = 50.0;   // Indicates if the temperature(internal) is outside the safe range  
const float TEMP_MIN = -20.0;   // Indicates if the temperature (internal) is outside the safe range  
const float DUST_MAX = 75.0;   // Maximum safe dust level percent
const float WindS_MAX = 30.0;   // Maximum safe wind speed level aprox,Design to withstand up to about 30 m/s
const float Radiation_MAX = 1.0;   // Maximum safe radiation level

// Use either a macro or a constant to define the array size
#define NUM_READINGS 2
//varables
int validationIndex=0;
int i;
//prototype
void inputParameter(float *parameter,float min, float max,char paramName []);
int average_mensurements(float mensurements[], int number_mensurements);
void displayCollectedData(void);
void sumarizeWarnings(void);


// Step 1: Variable Declarations and Initialization
// Declare arrays to store multiple readings for Temperature, Windspeed, Dust Level, and Radiation Level
float temperature[NUM_READINGS];
float windspeed[NUM_READINGS];
float dust_level[NUM_READINGS];
float radiation_level[NUM_READINGS];
char labels[NUM_READINGS][20];


// Initialize variables for averages and Dust Severity Index 
float averages_temperature=0;
float averages_windspeed=0;
float dust_severity[NUM_READINGS];

//flags for critical warnings
bool shutdownRequired = false;    // Indicates if an emergency shutdown is necessary
bool tempWarning = false;         // Temperature is not within safe range 
bool dustWarning=false;           // Dust is not within safe range 
bool  windspeedWarning= false;    // Indicates if an emergency shutdown is necessary
bool  radWarning= false;    // Indicates if an emergency shutdown is necessary

int main() {
    
    //Initialize all elements of each array to a default value (e.g., 0.0 or "") using a for loop
    for (i = 0; i < NUM_READINGS; i++) {
        temperature[i] = 0.0;
        windspeed[i] = 0.0;
        dust_level[i] = 0.0;
        radiation_level[i] = 0.0;
        strcpy(labels[i], ""); // initialize string label
    }

    // Step 2: Input Validation for Sensor Readings
    // Use loops to prompt and validate inputs for Temperature, Windspeed, Dust Level, and Radiation Level
    // Ensure all inputs meet specified thresholds

    for(i=0;i<NUM_READINGS;++i){
        //this way to print make the text be print in red(31m), green(32m), yellow(33m)
        printf("\x1b[32m Sensor readings number %d of %d \x1b[0m\n",i+1,NUM_READINGS);
        
        // validate input for temperature
        inputParameter(&temperature[i],-100,100,"temperature");
        
        //  Validation for Windspeed
        inputParameter(&windspeed[i],0,__FLT_MAX__,"windspeed, (non-negative value)");
        
        //  ensure dust level is between 0% and 100%
        inputParameter(& dust_level[i],0,100,"dust level percent");
  
        // ensure the radiation level is non-negative
        inputParameter(&radiation_level[i],0,__FLT_MAX__,"radiation level,(non-negative value)");

    }

    // Step 3: Calculations for Environmental Data
    // Calculate average values for Temperature and Windspeed
    averages_temperature=average_mensurements(temperature,NUM_READINGS);
    averages_windspeed=average_mensurements(windspeed,NUM_READINGS);
    // Compute the Dust Severity Index using the formula: Dust Level × (1 + Windspeed / 100)
    for(i=0; i<NUM_READINGS; ++i){
        dust_severity[i]=dust_level[i]*(1+windspeed[i]/100);
    }
    
    // Step 4: Check for Critical Thresholds Using If-Else Statements
    // Compare inputs and calculated values against thresholds
    // Set warning flags for critical conditions
    for(i=0; i<NUM_READINGS; ++i){
        if(temperature[i]>TEMP_MAX || temperature[i]<TEMP_MIN){
            tempWarning=true;
            shutdownRequired=true;
            //this way to print make the text be print in red(31m), green(32m), yellow(33m)
            printf("\x1b[33m WARNING: Temperature extreme (%.1f °C) \x1b[0m\n",temperature[i]);
        }
        if(windspeed[i]>WindS_MAX){
            shutdownRequired=true;
            windspeedWarning=true;
            //this way to print make the text be print in red(31m), green(32m), yellow(33m)
            printf("\x1b[33m WARNING: strong wind detected (%.1f m/s), risk of structural damage \x1b[0m\n",windspeed[i]);
        }
        if(dust_level[i]>DUST_MAX){
            shutdownRequired=true;
            dustWarning=true;
            //this way to print make the text be print in red(31m), green(32m), yellow(33m)
            printf("\x1b[33m WARNING: Dust Lavel Percent too high (%.1f %%)! \x1b[0m\n",dust_level[i]);
            
        }
        if(radiation_level[i]>Radiation_MAX){
            shutdownRequired=true;
            radWarning=true;
            //this way to print make the text be print in red(31m), green(32m), yellow(33m)
            printf("\x1b[33m WARNING: High radiation detected, (%.3f mSv/h) - Possible solar event! \x1b[0m\n",radiation_level[i]);
  
        }
        
    }

    // Step 5: Display Sensor Data and Calculated Results
    // Print sensor data and calculated averages in a clear, formatted table
    // Include Dust Severity Index in the output
    displayCollectedData();

    // Step 6: Summarize Warnings if Critical Conditions Are Triggered
    // Display warnings for critical conditions and indicate if shutdown is required
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

int average_mensurements(float mensurements[], int number_mensurements){
    //handeling not items, avoiding division by 0
    if (number_mensurements==0){
        return 0;
    }
    //average from a array
    int sum=0;
    for(i=0; i< number_mensurements; ++i){
        sum+=mensurements[i];
    }

    return sum/number_mensurements;

}


void displayCollectedData(void)
{
    printf("\nEntered Collection of Sensor Data\n");
    printf("------------------------------------------------------\n");
    printf("\x1b[34m Temperature Readings:\x1b[0m\n");
    for(i=0; i<NUM_READINGS; ++i){
        printf("| #%d: (%.1f °C) |",i+1,temperature[i]);
    }
    printf("\n");
    
    printf("\x1b[34m Windspeed Readings:\x1b[0m\n");
    for(i=0; i<NUM_READINGS; ++i){
        printf("| #%d: (%.1f m/s) |",i+1,windspeed[i]);
    }
    printf("\n");
    //print in blue
    printf("\x1b[34m Dust Level Readings: \x1b[0m\n");
    for(i=0; i<NUM_READINGS; ++i){
        printf("| #%d: (%.1f%%) |",i+1,dust_level[i]);
    }
    printf("\n");
    
    printf("\x1b[34m Radiation Level Readings: \x1b[0m\n");
    for(i=0; i<NUM_READINGS; ++i){
        printf("| #%d: (%.2f mSv/h) |",i+1,radiation_level[i]);
    }
  
    
    printf("\n------------------------------------------------------\n");
    printf("\x1b[34m Dust Severity Index: \x1b[0m");
    for(i=0; i<NUM_READINGS; ++i){
        printf(" #%d: (%.2f), ",i+1,dust_severity[i]);
    }

    printf("\n------------------------------------------------------\n");
    printf("The average of Temperature is: (%.1f °C) \n",averages_temperature);
    printf("------------------------------------------------------\n");
    printf("The average of Windspeed is: (%.1f m/s) \n",averages_windspeed);
    printf("------------------------------------------------------\n");

} 

void sumarizeWarnings(void)
{
   
    printf("\x1b[33m System Warnings Summary:\x1b[0m\n");
    printf("---------------------------\n");
    if (!shutdownRequired) {
        printf("No critical warnings detected.\n\n");
        printf("\x1b[32m System Status: Operational \x1b[0m\n");
    } else 
    {
        if (tempWarning) 
        {
            printf("WARNING: Temperature too high! Rover shutdown required to prevent damage.\n");
        }
        if (dustWarning) 
        {
            printf("DWARNING: Dust Severity Index exceeds safe limits. Close all external ports to prevent damage.\n");
        }
        if (windspeedWarning) 
        {
            printf("Windspeed too high\n");
        }
        if (radWarning) 
        {
            printf("WARNING: Radiation level exceeds safe limits.\n");
        }
        
        printf("\n\x1b[31m System Status: SHUTDOWN \x1b[0m\n");
    }
}