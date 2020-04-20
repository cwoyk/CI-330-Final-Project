// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Data generation. Random functions emulate nature, not concerned with the security of such. 

#include <stdio.h>
#include <iostream>
#include <time.h> //time seeding srand
#include <stdlib.h> //rand & srand
#include <string>
#include <fstream> //file operations

using namespace std; 

//Class declared for sensor characteristcs
//Import to Database with these
class sensor {
    string sensor_ID;
    int ip_address;
    int flow_speed();
    int viscosity();
    int temperature_inside();
    int temperature_outside();
    void gps_position();
    int battery_level();
    int hard_drive_space();
    int wifi_signal();
    string account_permissions;
} vt235;

//function declarations

int viscosity(int temp_inside);
int temperature_inside();
int flow_speed(int a);
int temperature_outside();
bool gps_position();
int battery_level();
int hard_drive_space();
int wifi_signal();
void sensor_naming();
sensor vt235x;
sensor psx25;


int main()
{
    sensor vt235x;
    sensor psx25;
   
    srand((unsigned)time(0));
    cout << temperature_inside() << endl;
    cout << temperature_outside() << endl;
 
    viscosity(temperature_inside()); //still need warnings
    flow_speed(viscosity(temperature_inside()));
    sensor_naming(); //exported to csv file

    //void sensor_naming(sensor vt235x);
    //void sensor_naming(sensor psx25);

}



bool gps_position() {
    int physical_catastrophe_odds;
    int occurence_odds;
    string occurence;
    bool catastrophe;
    
    //change moduli for testing purposes. 
    physical_catastrophe_odds = (rand() % 500);
    occurence_odds = (rand() % 25);
    
    cout << physical_catastrophe_odds << endl;
    cout << occurence_odds << endl;
    
    /*  
    uncomment to test for logic:
    physical_catastrophe_odds = 1;
    occurence_odds = 1;
    */
    if (physical_catastrophe_odds == occurence_odds)
        cout << "catastrophe occured. GPS location off.";
        catastrophe = true;
    return catastrophe; 
}


int flow_speed(int a) {
    int speed = 7;
    
    //beware of constant use, overriding catastrophes.
    //ideal speed & viscosity
    if (a = 500){
        speed = 7;
    }
    
    //low viscosity, lowers speed.
    else if((viscosity(temperature_inside()) < 490) && (viscosity(temperature_inside()) > 480)) {
        speed = 4;
    }
    
    //lowest viscosity, lowest speed
    else if((viscosity(temperature_inside()) <= 480) && (viscosity(temperature_inside()) > 450)) {
        speed = 3;
    }
    
    //high viscosity, higher speed.
    else if((viscosity(temperature_inside()) > 500) && (viscosity(temperature_inside()) < 510)) {
        speed = 8;
    }
    //highest viscosity, highest speed
    else if((viscosity(temperature_inside()) > 510) && (viscosity(temperature_inside()) <= 525)) {
        speed = 9;
    }
    */
    
    //catastrophe conditions
    /*
    calls gpsposition function. if random odds compare to TRUE, 
    GPS not in the right position signalling catastrophe
    */
    if ((gps_position()) == true) {
        speed = 0;
    }
    
    //high temp signals outside catastrophe, therefore speed stop. 
   /* if ((temperature_outside()) >= 220) {
        speed = 0;
    } */
    return speed;
}
    
//viscosity changes at temperature changes
int viscosity() {
    //ideal viscosity occurs at 105 degrees F
    int visc = 500;
    int temp_inside;
    
    int temp_change = 0;
    int visc_change = 0;
    
    if (temp_inside == 105){
        visc = 500;
    }
    else if( temp_inside > 105){
        //if temp above 105, viscosity increases as function of temp*5
        temp_change = (temp_inside - 105);
        visc_change = temp_change * 5;
        visc += visc_change;
    }
    else if(temp_inside < 105){
        //if temp below 105, viscosity decreases as function of temp*5
        //actual temp - ideal temp = change in temp. 
        temp_change =(105 - temp_inside);
        visc_change = temp_change * 5;
        visc -= visc_change;
    }
    return visc;
}

int temperature_inside() {
    srand((unsigned)time(0));
    //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
    int temp_inside;
    temp_inside = 100 + (rand() % 10);
   
    return temp_inside;
}
/*
REPEAT VISCOSITY
//viscosity changes at temperature changes
int  viscosity(int temp_inside) {
    //ideal viscosity occurs at 105 degrees F
    int visc = 500;
    
    int temp_change = 0;
    int visc_change = 0;
    
    if (temp_inside == 105){
        visc = 500;
    }
    else if( temp_inside > 105){
        //if temp above 105, viscosity increases as function of temp*5
        temp_change = (temp_inside - 105);
        visc_change = temp_change * 5;
        visc += visc_change;
    }
    else if(temp_inside < 105){
        //if temp below 105, viscosity decreases as function of temp*5
        //actual temp - ideal temp = change in temp. 
        temp_change =(105 - temp_inside);
        visc_change = temp_change * 5;
        visc -= visc_change;
    }
    return visc;
}
END REPEAT
*/



//done
int temperature_outside() {
    //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
    int temp_outside;
    int catastrophe_temp;
    //temp calculations\
    //simulate typical temperatures outside. 
    temp_outside = (rand() % 120);

    //serve as the trigger point for a catastrophe
    catastrophe_temp = (rand() % 225);
    
    //uncomment to test the 'if' loop
    //catastrophe_temp = 225;

    if (catastrophe_temp > 220) {
        return catastrophe_temp;
    }

    else {
        return temp_outside;
    }
}




void sensor_naming() {    
    
    string sensor_ID;
    int vt235x_mile_marker;
    int psx_mile_marker;
    int i;
    
    //file creation for output of sensor names
    ofstream sensorNames;
    sensorNames.open("SensorNames.csv");
    
    // going through 2000 miles of pipe to name
    for (i = 0; i < 2000; i += 12) {
        vt235x_mile_marker = i;
        //to_string makes integer compatible with string. 
        sensor_ID = to_string(vt235x_mile_marker) + "-vt235x";
        //outputs sensor_ID into csv file
        sensorNames << sensor_ID << endl;
    }
     
    //iterates through 2000 miles to create names of psx sensors
    for (i = 0; i < 2000; i +=3) {
        psx_mile_marker = i;
        //to_string makes integer compatible with string. 
        sensor_ID = to_string(psx_mile_marker) + "-psx25";
        //outputs sensor_ID into csv file
        sensorNames << sensor_ID << endl;
    }
//closes csv file     
    sensorNames.close();
    return;
}



bool gps_position() {
    int physical_catastrophe_odds;
    int occurence_odds;
    string occurence;
    srand((unsigned)time(0));
    //change moduli for testing purposes. 
    physical_catastrophe_odds = (rand() % 500);
    occurence_odds = (rand() % 25);
    
    cout << physical_catastrophe_odds << endl;
    cout << occurence_odds << endl;
    
    /*  
    uncomment to test for logic:
    physical_catastrophe_odds = 1;
    occurence_odds = 1;
    */
    if (physical_catastrophe_odds == occurence_odds)
        cout << "catastrophe occured. GPS location off.";
        catastrophe = TRUE;
    return; 
}

/*
int battery_level() {
             time_t t = time(NULL);
    struct tm tm = *localtime(&t);
  //tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec
    //logic for light&dark. 
    int charge = 50; 
    string charge_status;
    
    while (tm.tm_hour != 25){    
        if(tm.tm_hour < 6){ 
            //charge goes up, every 30 minutes, & if charge not full
            if (((tm.tm_min == 30) || (tm.tm_min == 0)) && (charge != 100)){
                charge++;
            }
        }
    
        else if(tm.tm_hour > 20){
            //charge goes down every 30 min & if charge != 0
            if (((tm.tm_min == 30) || (tm.tm_min == 0)) && (charge != 0)){
                charge--;
            }    
        }
        
        if(charge < 20){
            charge_status = "low battery";
        }
        else if(charge = 100){
            charge_status = "battery full";
        }
        else{
            charge_status = "battery dead";
        }  
        cout << charge << endl;
        cout << charge_status << endl;
}
int hard_drive_space() {
         srand(time(NULL));
    
    if wifi signal is good. free hard drive space. 
        time since free, decrease available space.
        
}
int wifi_signal() {
         srand(time(NULL));
}
OS 3 WAYS
FORK PROCESS
SEND DATA TO DATABASE
    MYSQL INSTANCE
VV
GLOBAL VARIABLE/THREAD TO EMULATE. 
 WHEN STORED TO GLOBAL VARIABLE ENCRYPT, WHEN READ FROM VARIABLE, DECRYPT. 
    BITWISE NOT.
*/
