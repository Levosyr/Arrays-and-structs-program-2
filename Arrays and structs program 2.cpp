#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Struct definition for a runner
struct Runner {
    string name;
    int miles[NUM_DAYS];
    int totalMiles;
    double averageMiles;
};

// Function prototypes
void readData(Runner runners[]);
void calculateStats(Runner runners[]);
void outputResults(const Runner runners[]);

int main() {
    Runner runners[NUM_RUNNERS];

    // Read data from file
    readData(runners);

    // Calculate total miles and average miles
    calculateStats(runners);

    // Output results
    outputResults(runners);

    return 0;
}

// Function to read and store the runners' data
void readData(Runner runners[]) {
    ifstream inputFile("Marathon runners.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inputFile >> runners[i].name;
        for (int j = 0; j < NUM_DAYS; ++j) {
            inputFile >> runners[i].miles[j];
        }
    }

    inputFile.close();
}

// Function to calculate total miles and average miles for each runner
void calculateStats(Runner runners[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        int totalMiles = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles += runners[i].miles[j];
        }
        runners[i].totalMiles = totalMiles;
        runners[i].averageMiles = static_cast<double>(totalMiles) / NUM_DAYS;
    }
}

// Function to output the results
void outputResults(const Runner runners[]) {
    // Output header
    cout << setw(15) << left << "Runner";
    for (int day = 1; day <= NUM_DAYS; ++day) {
        cout << setw(10) << left << "Day " << day;
    }
    cout << setw(15) << left << "Total Miles" << setw(15) << left << "Average Miles" << endl;

    // Output data for each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << setw(15) << left << runners[i].name;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(10) << left << runners[i].miles[j];
        }
        cout << setw(15) << left << runners[i].totalMiles << setw(15) << left << runners[i].averageMiles << endl;
    }
}
