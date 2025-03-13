#include <iostream>
#include <iomanip>
#include <map>
#include <limits>
#include <vector>
#include <string>
#include <windows.h>

// Add this to prevent macro conflicts
#undef min
#undef max

using namespace std;

// Function to set console color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear screen
void clearScreen() {
    system("cls");
}

// Function to display banner
void displayBanner() {
    cout << "          GPA CALCULATOR 2.0          \n";
	cout << "──────────────────────────────────────\n";
    setColor(7); // Reset to default color
}

// Optimized grade point calculation using const reference
const double getGradePoint(const string& grade) {
    static const map<string, double> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3},
        {"B", 3.0}, {"B-", 2.7}, {"C+", 2.3}, {"C", 2.0},
        {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, {"D-", 0.7},
        {"F", 0.0}
    };

    auto it = gradeMap.find(grade);
    if (it != gradeMap.end()) {
        return it->second;
    }
    setColor(12); // Red
    cout << "Invalid grade entered! Defaulting to 0.0" << endl;
    setColor(7); // Reset color
    return 0.0;
}

// Function to get validated input
template<typename T>
T getValidInput(const string& prompt, T min, T max) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        setColor(12); // Red
        cout << "Invalid input! Please try again." << endl;
        setColor(7); // Reset color
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    clearScreen();
    displayBanner();

    // Previous semester data
    double previousCredits = 0.0, previousGPA = 0.0;
    
    setColor(14); // Yellow
    cout << "Do you have previous semester data? (y/n): ";
    setColor(7);
    char hasPreviousData;
    cin >> hasPreviousData;
    cin.ignore();

    if (tolower(hasPreviousData) == 'y') {
        previousCredits = getValidInput<double>("Enter total previous credits: ", 0.0, 1000.0);
        previousGPA = getValidInput<double>("Enter previous GPA (0.0-4.0): ", 0.0, 4.0);
    }

    int numSubjects = getValidInput<int>("Enter number of current subjects: ", 1, 20);

    vector<tuple<string, double, double>> subjects; // name, credits, grade points
    double totalCredits = 0.0, totalPoints = 0.0;

    clearScreen();
    displayBanner();

    // Input subject details
    for (int i = 0; i < numSubjects; ++i) {
        setColor(11);
        cout << "\nSubject " << (i + 1) << " of " << numSubjects << endl;
        cout << "───────────────────────\n";
        setColor(7);

        string subjectName;
        cout << "Subject name: ";
        getline(cin, subjectName);

        double credit = getValidInput<double>("Credit hours: ", 0.1, 6.0);
        
        cout << "Grade (A+,A,A-,B+,B,B-,C+,C,C-,D+,D,D-,F): ";
        string grade;
        cin >> grade;
        cin.ignore();

        double gradePoint = getGradePoint(grade);
        subjects.emplace_back(subjectName, credit, gradePoint);
        totalCredits += credit;
        totalPoints += credit * gradePoint;
    }

    // Display results
    clearScreen();
    displayBanner();
    
    setColor(10); // Green
    cout << "\nRESULTS SUMMARY\n";
    cout << "───────────────\n\n";
    setColor(7);

    cout << setprecision(2) << fixed;
    
    // Subject-wise results
    for (const auto& subject : subjects) {
        cout << left << setw(30) << get<0>(subject) << ": ";
        setColor(11);
        cout << get<2>(subject) << " GPA" << endl;
        setColor(7);
    }

    double currentGPA = (totalCredits > 0) ? (totalPoints / totalCredits) : 0.0;
    
    cout << "\n────────────────────────────────────\n";
    setColor(14);
    cout << "Current Semester GPA: " << currentGPA << endl;

    if (tolower(hasPreviousData) == 'y' && previousCredits > 0) {
        double cumulativeTotalPoints = (previousGPA * previousCredits) + totalPoints;
        double cumulativeTotalCredits = previousCredits + totalCredits;
        double cumulativeGPA = cumulativeTotalPoints / cumulativeTotalCredits;
        cout << "Cumulative GPA: " << cumulativeGPA << endl;
    }
    setColor(7);

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}