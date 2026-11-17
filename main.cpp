
#include <iostream>
#include <iomanip>
using namespace std;

// Function to calculate the new population
double population(double P, double B, double D) {
    return P * (1 + B) * (1 - D);
}

int main() {
    double startingPopulation, birthRate, deathRate;
    int years;

    cout << "Enter the starting population (minimum 2): ";
    cin >> startingPopulation;

    cout << "Enter the annual birth rate (decimal): ";
    cin >> birthRate;

    cout << "Enter the annual death rate (decimal): ";
    cin >> deathRate;

    cout << "Enter the number of years (minimum 1): ";
    cin >> years;

    if (startingPopulation < 2 || years < 1 ||
        birthRate < 0 || deathRate < 0 ||
        birthRate > 1 || deathRate > 1) {
        cout << "Invalid input." << endl;
        return 1;
    }

    double currentPopulation = startingPopulation;

    cout << fixed << setprecision(2);

    cout << "\nStarting population: "
         << startingPopulation << endl;

    cout << "\nYear\tProjected Population" << endl;
    cout << "-----------------------------" << endl;

    for (int year = 1; year <= years; year++) {
        currentPopulation = population(
            currentPopulation, birthRate, deathRate);

        cout << year << "\t" << currentPopulation << endl;
    }

    return 0;
}