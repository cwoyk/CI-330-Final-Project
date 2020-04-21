// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Data generation. Random functions emulate nature, not concerned with the security of such. HEADER FILE???
// VT235x Sensor reports data recieved from data generation file & sends to database. 

#include <stdio.h>
#include <iostream>
#include <time.h> //time seeding srand
#include <stdlib.h> //rand & srand
#include <string>
#include <fstream> //file operations

#inlcude "DataGeneration.cpp"

using namespace std; 

//Class declared for sensor characteristcs
//Import to Database with these

int main (){

    sensor vt235;
    vt235.flow_speed();
    vt235.viscosity(int temp_inside);
    vt235.temperature_inside();
    vt235.flow_speed(int a);
    vt235.temperature_outside();
    vt235.gps_position();
    //vt235.battery_level();
    //vt235.hard_drive_space();
    vt235.wifi_signal();  
    
}
