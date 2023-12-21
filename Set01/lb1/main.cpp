/* CSCI 200: Assignment 1: L1 - Equation solver
 *
 * Author: Gabe Berta
 * Resources used Zybooks, and class slides
 *
 * This program calculates the current using voltage and resistance which are prompted from the user
 * The second calculator finds the pressure of an ideal gas. The user can decide if they want the answer in atmospheres or pascals.
 */



#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float voltage, resistance, current;

    cout << "Please enter the voltage" << endl;
    cin >> voltage;
    cout << "Please enter the resistance" << endl;
    cin >> resistance;
    current = voltage/resistance;
    cout << "The current is " << setprecision(3) << current << " Amp(s)" << endl << endl;
    
    
    float moles, temp, volume, pressure;
    int choice;
    cout << "Do you want pressure in Pascals(1) or Atm(2)? Please enter either 1 or 2" << endl;
    cin >> choice;
    if (choice == 1) {
        const float GASCONS = 8.314472;
        cout << "Please enter the number of moles that make up the gas." << endl;
        cin >> moles;
        cout << "Please enter the tempurature of the gas. (In Kelvin)" << endl;
        cin >> temp;
        cout << "Please enter the gases volume. (In cubic meters)" << endl;
        cin >> volume;
        pressure = ((moles * temp * GASCONS) / volume);
        cout << "The pressure is " << pressure << " Pascals" << endl;
        } else if (choice == 2) {
        const float GASCONS = 0.082;
        cout << "Please enter the number of moles in the gas." << endl;
        cin >> moles;
        cout << "Please enter the tempurature of the gas. (In Kelvin)" << endl;
        cin >> temp;
        cout << "Please enter the gases volume. (In Liters)" << endl;
        cin >> volume;
        pressure = ((moles * temp * GASCONS) / volume);
        cout << "The pressure is " << setprecision(3) << pressure << " Atms" << endl;       
    }

    return 0;
}