// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Data generation. Random functions emulate nature, not concerned with the security of such. 
// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Data generation. Random functions emulate nature, not concerned with the security of such. 

#include <stdio.h>
#include <iostream>
#include <time.h> //time seeding srand
#include <stdlib.h> //rand & srand
#include <string>
#include <fstream> //file operations

using namespace std;

int temperature_inside();
int flow_speed(int a);
int temperature_outside();
bool gps_position();
int battery_level();
int hard_drive_space();
bool wifi_signal();
void sensor_naming();

//Class declared for sensor characteristcs
//Import to Database with these
class sensorVT235 {
public:
    string sensor_ID;
    string ip_address;
    int flow_speed(int a) {
        int speed = 7;
        int temp_inside;
        temp_inside = temperature_inside();
        //beware of constant use, overriding catastrophes.
        //ideal speed & viscosity
        if (a == 500) {
            speed = 7;
        }

        //low viscosity, lowers speed.
        else if ((viscosity(temp_inside) < 490) && (viscosity(temp_inside) > 480)) {
            speed = 4;
        }

        //lowest viscosity, lowest speed
        else if ((viscosity(temp_inside) <= 480) && (viscosity(temp_inside) > 450)) {
            speed = 3;
        }

        //high viscosity, higher speed.
        else if ((viscosity(temp_inside) > 500) && (viscosity(temp_inside) < 510)) {
            speed = 8;
        }
        //highest viscosity, highest speed
        else if ((viscosity(temp_inside) > 510) && (viscosity(temp_inside) <= 525)) {
            speed = 9;
        }


        //catastrophe conditions
        /*
        calls gpsposition function. if random odds compare to TRUE,
        GPS not in the right position signalling catastrophe
        */
        if ((gps_position()) == true) {
            speed = 0;
        }

        //high temp signals outside catastrophe, therefore speed stop. 
        if ((temperature_outside()) >= 220) {
            speed = 0;
        }
        return speed;
    }
    int temperature_inside() {
        srand((unsigned)time(0));
        //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
        int temp_inside;
        temp_inside = 100 + (rand() % 10);

        return temp_inside;
    }
    int viscosity(int temp_inside) {
        //ideal viscosity occurs at 105 degrees F
        int visc = 500;
        int temp_change = 0;
        int visc_change = 0;

        if (temp_inside == 105) {
            visc = 500;
        }
        else if (temp_inside > 105) {
            //if temp above 105, viscosity increases as function of temp*5
            temp_change = (temp_inside - 105);
            visc_change = temp_change * 5;
            visc += visc_change;
        }
        else if (temp_inside < 105) {
            //if temp below 105, viscosity decreases as function of temp*5
            //actual temp - ideal temp = change in temp. 
            temp_change = (105 - temp_inside);
            visc_change = temp_change * 5;
            visc -= visc_change;
        }
        return visc;
    }

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
    bool gps_position() {
        int physical_catastrophe_odds;
        int occurence_odds;
        string occurence;
        bool catastrophe;


        //change moduli for testing purposes.
        physical_catastrophe_odds = (rand() % 500);
        occurence_odds = (rand() % 25);


        /*uncomment to test for logic:
        physical_catastrophe_odds = 1;
        occurence_odds = 1;
        */

        if (physical_catastrophe_odds == occurence_odds)
            catastrophe = true;

        else
            catastrophe = false;

        return catastrophe;
    }

    //int battery_level();
    bool wifi_signal() {
        int sending;
        int receiving;
        bool signal = false;
        sending = rand() % 5;
        receiving = rand() % 5;

        if (sending = receiving) {
            signal = true;
        }
        return signal;
    }
    int hard_drive_space() {
        int available_memory = 1000;
        int sending;
        int receiving;
        bool signal = false;
        //wifi signal logic included.
        sending = rand() % 5;
        receiving = rand() % 5;

        if (sending == receiving) {
            signal = true;
        }

        else {
            while ((sending != receiving) && (available_memory > 0)) {
                available_memory--;
                cout << available_memory << endl;
                sending = rand() % 500;
                receiving = rand() % 500;
            }

            //if wifi signal is good, memory is reset, showing transfer of data. 
            if (sending == receiving) {
                available_memory = 1000;
            }
        }
        return available_memory;
    }

};

class sensorPSX25 {
public:
    string sensor_ID;
    string ip_address;
    int flow_speed(int a) {
        int speed = 7;
        int temp_inside;
        temp_inside = temperature_inside();
        //beware of constant use, overriding catastrophes.
        //ideal speed & viscosity
        if (a == 500) {
            speed = 7;
        }

        //low viscosity, lowers speed.
        else if ((viscosity(temp_inside) < 490) && (viscosity(temp_inside) > 480)) {
            speed = 4;
        }

        //lowest viscosity, lowest speed
        else if ((viscosity(temp_inside) <= 480) && (viscosity(temp_inside) > 450)) {
            speed = 3;
        }

        //high viscosity, higher speed.
        else if ((viscosity(temp_inside) > 500) && (viscosity(temp_inside) < 510)) {
            speed = 8;
        }
        //highest viscosity, highest speed
        else if ((viscosity(temp_inside) > 510) && (viscosity(temp_inside) <= 525)) {
            speed = 9;
        }


        //catastrophe conditions
        /*
        calls gpsposition function. if random odds compare to TRUE,
        GPS not in the right position signalling catastrophe
        */
        if ((gps_position()) == true) {
            speed = 0;
        }

        //high temp signals outside catastrophe, therefore speed stop. 
        if ((temperature_outside()) >= 220) {
            speed = 0;
        }
        return speed;
    }
    int temperature_inside() {
        srand((unsigned)time(0));
        //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
        int temp_inside;
        temp_inside = 100 + (rand() % 10);

        return temp_inside;
    }
    int viscosity(int temp_inside) {
        //ideal viscosity occurs at 105 degrees F
        int visc = 500;
        int temp_change = 0;
        int visc_change = 0;

        if (temp_inside == 105) {
            visc = 500;
        }
        else if (temp_inside > 105) {
            //if temp above 105, viscosity increases as function of temp*5
            temp_change = (temp_inside - 105);
            visc_change = temp_change * 5;
            visc += visc_change;
        }
        else if (temp_inside < 105) {
            //if temp below 105, viscosity decreases as function of temp*5
            //actual temp - ideal temp = change in temp. 
            temp_change = (105 - temp_inside);
            visc_change = temp_change * 5;
            visc -= visc_change;
        }
        return visc;
    }

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
    bool gps_position() {
        int physical_catastrophe_odds;
        int occurence_odds;
        string occurence;
        bool catastrophe;


        //change moduli for testing purposes.
        physical_catastrophe_odds = (rand() % 500);
        occurence_odds = (rand() % 25);


        /*uncomment to test for logic:
        physical_catastrophe_odds = 1;
        occurence_odds = 1;
        */

        if (physical_catastrophe_odds == occurence_odds)
            catastrophe = true;

        else
            catastrophe = false;

        return catastrophe;
    }

    //int battery_level();
    bool wifi_signal() {
        int sending;
        int receiving;
        bool signal = false;
        sending = rand() % 5;
        receiving = rand() % 5;

        if (sending = receiving) {
            signal = true;
        }
        return signal;
    }
    int hard_drive_space() {
        int available_memory = 1000;
        int sending;
        int receiving;
        bool signal = false;
        //wifi signal logic included.
        sending = rand() % 5;
        receiving = rand() % 5;

        if (sending == receiving) {
            signal = true;
        }

        else {
            while ((sending != receiving) && (available_memory > 0)) {
                available_memory--;
                cout << available_memory << endl;
                sending = rand() % 500;
                receiving = rand() % 500;
            }

            //if wifi signal is good, memory is reset, showing transfer of data. 
            if (sending == receiving) {
                available_memory = 1000;
            }
        }
        return available_memory;
    }
    
    //PSX25 UNIQUE FUNCTIONS
    int valve_control() {
        int speed_check;
        int valve_position;
        int warning;

        speed_check = flow_speed(viscosity(temperature_inside()));
        //default closed position.
        valve_position = 90;

        while (speed_check == 7) {
            //while running, default 45 degree valve position.
            valve_position = 45;
            if (speed_check < 7) {
                //less than 7 mph valve opens 15 degrees
                valve_position -= 15;
            }

            else if (speed_check > 7) {
                //more than 7mph, valve closes 15 degrees
                valve_position += 15;
            }
        }
        //return conditions
        if (speed_check == 0) {
            //0 mph shows catastrophe
            valve_position = 90;
            warning = 1;
            return warning;
        }
        else {
            return valve_position;
        }
    } //based on speed or as defined by database.
    
    string account_permissions;
};

class Verify {

public:
    void verifyUser() {

        string username = "";
        string password = "";
        bool loginSuccess = false;

        cout << "\tHello! Please login below.\n\n";

        do {
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (username == "Crew" && password == "ExxonCrew11") {
                cout << "\nSuccessful Login\n\n";
                loginSuccess = true;
            }

            else if ((username == "PSX25" && password == "PSX25") || (username == "VT235x-c" && password == "VT235x-c")) {
                cout << "\nSuccessful Login\n\n";
                loginSuccess = true;
            }

            else {
                cout << "Incorrect username/password combo \n";
                cout << "Please try again.\n\n";
            }

        } while (!loginSuccess);

    }//end function verifyUser   
};

int main() {

    srand((unsigned)time(0));

    sensorVT235 vt235a;
    sensorVT235 vt235b;
    sensorPSX25 psx25a;

    int i;

    vt235a.ip_address = "192.168.0.2 ";
    vt235b.ip_address = "192.168.0.3 ";
    psx25a.ip_address = "192.168.0.4 ";

    fstream fs("database.txt", fstream::out | fstream::app);
    

    cout << "Enter your username and password" << endl;

    for (i = 0; i < 60; i++) {

        fs << "Sensor ID: " << vt235a.sensor_ID << "0-vt235, ";
        fs << "Sensor IP: " << vt235a.ip_address;
        fs <<"Inside Temp(F): " << vt235a.temperature_inside() << ", ";
        fs << "Outside Temp(F): " <<vt235a.temperature_outside() << ", ";
        fs << "Viscosity(cST): " << vt235a.viscosity(temperature_inside()) << ", ";
        fs << "Flow Speed: " << vt235a.flow_speed(viscosity(temperature_inside())) << ", ";
        fs << "GPS Position Correct? " << vt235a.gps_position() << ", ";
        //fs << "Battery Level: " << vt235a.battery_level() << ", ";
        fs << "Hard Drive Space: " << vt235a.hard_drive_space() << ", ";
        fs << "WiFi Connected? " << vt235a.wifi_signal();
        fs << endl;

        fs << "Sensor ID: " << vt235b.sensor_ID << "3-vt235, ";
        fs << "Sensor IP: " << vt235b.ip_address << ", ";
        fs << "Inside Temp(F): " << vt235b.temperature_inside() << ", ";
        fs << "Outside Temp(F): " << vt235b.temperature_outside() << ", ";
        fs << "Viscosity(cST) : " << vt235b.viscosity(temperature_inside()) << ", ";
        fs << "Flow Speed: " << vt235b.flow_speed(viscosity(temperature_inside())) << ", ";
        fs << "GPS Position Correct?: " << vt235b.gps_position() << ", ";
        //fs << "Battery Level: " <<  vt235b.battery_level() << ", ";
        fs << "Hard Drive Space: " << vt235b.hard_drive_space() << ", ";
        fs << "WiFi Connected? " << vt235b.wifi_signal();
        fs << endl;
        //psxa data input
        fs << "" << "Sensor ID: " << psx25a.sensor_ID << "0-psx25, ";
        fs << "" << "Sensor IP: " << psx25a.ip_address;
        fs << "Inside Temp(F): " << psx25a.temperature_inside() << ", ";
        fs << "Outside Temp(F): " << psx25a.temperature_outside() << ", ";
        fs << "Viscosity(cST) : " << psx25a.viscosity(temperature_inside()) << ", ";
        fs << "Flow Speed: " << psx25a.flow_speed(viscosity(temperature_inside())) << ", ";
        fs << "GPS Position Correct?: " << psx25a.gps_position() << ", ";
        //fs << "Battery Level: " << psx25a.battery_level() << ", ";
        fs << "Hard Drive Space" << psx25a.hard_drive_space() << ", ";
        fs << "WiFi Connected? " << psx25a.wifi_signal();
        fs << " Valve Position: " << psx25a.valve_control();
        fs << endl;

        fs.close();
    }
 
}



int flow_speed(int a) {
    int speed = 7;
    int temp_inside;
    temp_inside = temperature_inside();
    //beware of constant use, overriding catastrophes.
    //ideal speed & viscosity
    if (a == 500) {
        speed = 7;
    }

    //low viscosity, lowers speed.
    else if ((viscosity(temp_inside) < 490) && (viscosity(temp_inside) > 480)) {
        speed = 4;
    }

    //lowest viscosity, lowest speed
    else if ((viscosity(temp_inside) <= 480) && (viscosity(temp_inside) > 450)) {
        speed = 3;
    }

    //high viscosity, higher speed.
    else if ((viscosity(temp_inside) > 500) && (viscosity(temp_inside) < 510)) {
        speed = 8;
    }
    //highest viscosity, highest speed
    else if ((viscosity(temp_inside) > 510) && (viscosity(temp_inside) <= 525)) {
        speed = 9;
    }


    //catastrophe conditions
    /*
    calls gpsposition function. if random odds compare to TRUE,
    GPS not in the right position signalling catastrophe
    */
    if ((gps_position()) == true) {
        speed = 0;
    }

    //high temp signals outside catastrophe, therefore speed stop. 
    if ((temperature_outside()) >= 220) {
        speed = 0;
    }
    return speed;
}
int temperature_inside() {
    srand((unsigned)time(0));
    //https://www.bitdegree.org/learn/random-number-generator-cpp#random-numbers-between-1-and-100
    int temp_inside;
    temp_inside = 100 + (rand() % 10);

    return temp_inside;
}
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
bool gps_position() {
    int physical_catastrophe_odds;
    int occurence_odds;
    string occurence;
    bool catastrophe;


    //change moduli for testing purposes.
    physical_catastrophe_odds = (rand() % 500);
    occurence_odds = (rand() % 25);
    

    /*uncomment to test for logic:
    physical_catastrophe_odds = 1;
    occurence_odds = 1;
    */

    if (physical_catastrophe_odds == occurence_odds)
        catastrophe = true;

    else
        catastrophe = false;

    return catastrophe;
}
//viscosity changes at temperature changes
int viscosity(int temp_inside) {
    //ideal viscosity occurs at 105 degrees F
    int visc = 500;
    int temp_change = 0;
    int visc_change = 0;

    if (temp_inside == 105) {
        visc = 500;
    }
    else if (temp_inside > 105) {
        //if temp above 105, viscosity increases as function of temp*5
        temp_change = (temp_inside - 105);
        visc_change = temp_change * 5;
        visc += visc_change;
    }
    else if (temp_inside < 105) {
        //if temp below 105, viscosity decreases as function of temp*5
        //actual temp - ideal temp = change in temp. 
        temp_change = (105 - temp_inside);
        visc_change = temp_change * 5;
        visc -= visc_change;
    }
    return visc;
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
    //changed to 11 for purposes of project.
    //for (i = 0; i < 2000; i += 12) {
    for (i = 0; i < 12; i += 12) {
        vt235x_mile_marker = i;
        //to_string makes integer compatible with string. 
        sensor_ID = to_string(vt235x_mile_marker) + "-vt235x";
        //outputs sensor_ID into csv file
        sensorNames << sensor_ID << endl;
    }

    //iterates through 2000 miles to create names of psx sensors
    //changed to 6 to create 2 names
    for (i = 0; i < 6; i += 3) {
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
/*
int battery_level() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec
      //logic for light&dark. 
    int charge = 50;
    string charge_status;

    while (tm.tm_hour != 25) {
        if (tm.tm_hour < 6) {
            //charge goes up, every 30 minutes, & if charge not full
            if (((tm.tm_min == 30) || (tm.tm_min == 0)) && (charge != 100)) {
                charge++;
            }
        }

        else if (tm.tm_hour > 20) {
            //charge goes down every 30 min & if charge != 0
            if (((tm.tm_min == 30) || (tm.tm_min == 0)) && (charge != 0)) {
                charge--;
            }
        }

        if (charge < 20) {
            charge_status = "low battery";
        }
        else if (charge == 100) {
            charge_status = "battery full";
        }
        else {
            charge_status = "battery dead";
        }
        cout << charge << endl;
        cout << charge_status << endl;
    }
}
*/
int hard_drive_space() {
    int available_memory = 1000;
    int sending;
    int receiving;
    bool signal = false;
    //wifi signal logic included.
    sending = rand() % 5;
    receiving = rand() % 5;

    if (sending == receiving) {
        signal = true;
    }

    else {
        while ((sending != receiving) && (available_memory > 0)) {
            available_memory--;
            sending = rand() % 500;
            receiving = rand() % 500;
        }

        //if wifi signal is good, memory is reset, showing transfer of data. 
        if (sending == receiving) {
            available_memory = 1000;
        }
    }
    return available_memory;
}
bool wifi_signal() {
    int sending;
    int receiving;
    bool signal = false;
    sending = rand() % 5;
    receiving = rand() % 5;

    if (sending = receiving) {
        signal = true;
    }
    return signal;
}
//start valve control function
int valve_control() {
    int speed_check;
    int valve_position;
    int warning;

    speed_check = flow_speed(viscosity(temperature_inside()));
    //default closed position.
    valve_position = 90;

    while (speed_check == 7) {
        //while running, default 45 degree valve position.
        valve_position = 45;
        if (speed_check < 7) {
            //less than 7 mph valve opens 15 degrees
            valve_position -= 15;
        }

        else if (speed_check > 7) {
            //more than 7mph, valve closes 15 degrees
            valve_position += 15;
        }
    }
    //return conditions
    if (speed_check == 0) {
        //0 mph shows catastrophe
        valve_position = 90;
        warning = 1;
        return warning;
    }
    else {
        return valve_position;
    }
}
//close valve control function
