// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h> //time seeding srand
#include <stdlib.h> //rand & srand

using namespace std; 

//Class declared for sensor characteristcs
//Import to Database with these
class sensor {
    string sensor_ID;
    int ip_address;
    int flow_speed();
    int viscosity();
    int temperature();
    double gps_position();
    int battery_level();
    int hard_drive_space();
    int wifi_signal();
    string account_permissions;
} vt235;

//function declarations
int flow_speed();
int viscosity();
int temperature();
double gps_position();
int battery_level();
int hard_drive_space();
int wifi_signal();
void sensor_naming(sensor sensor_type);
sensor vt235x;
sensor psx25;

int main()
{
    sensor vt235x;
    sensor psx25;
    cout << "Hello World!\n";
    cout << temperature_inside() << endl;
    cout << temperature_outside() << endl;
    //void sensor_naming(sensor vt235x);
    //void sensor_naming(sensor psx25);

}



int flow_speed() {
    int speed;
    srand(time(NULL));
    speed = 7;
    return speed;
}
/*
int viscosity() {

};
*/

int temperature_inside() {
    srand((unsigned)time(0));
    //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
    int temp_inside;
    temp_inside = 100 + (rand() % 10);

    return temp_inside;
}

int temperature_outside() {
    srand((unsigned)time(0));
    //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
    int temp_outside;
    int catastrophe_temp;
    //temp calculations\
    //simulate typical temperatures outside. 
    temp_outside = (rand() % 120);
    //serve as the trigger point for a catastrophe
    catastrophe_temp = (rand() % 225);

    if (catastrophe_temp > 220) {
        return catastrophe_temp;
    }

    else {
        return temp_outside;
    }
}

/*
double gps_position() {

};

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

};

int hard_drive_space() {
         srand(time(NULL));
};

int wifi_signal() {
         srand(time(NULL));
};
*/


/* revisit once basics done
void sensor_naming(sensor sensor_type) {
    //call one of each type in main
    int mile_marker;
    int i;
    //going through 2000 miles of pipe to name
    for (i = 0; i < 2000; i += 12)
            mile_marker = i;
            *sensor_ID = sensor_type + mile_marker;
    }


    //name of sensor should be vt235 or PSX + mile marker

}
*/


