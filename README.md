# GPA Calculator

This is a simple GPA Calculator application written in C++ that allows users to calculate their GPA for the current semester and, if previous data is provided, their cumulative GPA.

## Features

- Calculate GPA for the current semester.
- Option to include previous semester GPA and total credits for cumulative GPA calculation.
- Validates user inputs to ensure correctness.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Basic understanding of C++ programming

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Saviru1/gpa-calculator.git
    cd gpa-calculator
    ```

2. Compile the source code:
    ```sh
    g++ -o gpa_calculator "GPA Calculator.cpp"
    ```

### Usage

1. Run the executable:
    ```sh
    ./gpa_calculator
    ```

2. Follow the on-screen prompts to enter your semester data:
    - Enter whether you have previous semester GPA and credits.
    - If yes, provide the total credits and cumulative GPA from previous semesters.
    - Enter the number of subjects for the current semester.
    - For each subject, provide the subject name, credit hours, and grade received.

3. The application will display the GPA for the current semester and, if applicable, the cumulative GPA.

## Example

```sh
Do you have previous semester GPA and total credits? (y/n): y
Enter total credits from previous semesters: 45
Enter cumulative GPA from previous semesters: 3.5

Enter the number of subjects for the current semester: 3
Enter subject name: Math
Enter credit hours for Math: 3
Enter grade for Math: A

Enter subject name: Physics
Enter credit hours for Physics: 4
Enter grade for Physics: B+

Enter subject name: Chemistry
Enter credit hours for Chemistry: 3
Enter grade for Chemistry: B

Subject-wise Results:
Math = 4.0
Physics = 3.3
Chemistry = 3.0

Your GPA for the current semester is: 3.44
Your cumulative GPA is: 3.48
```

Contributing
Contributions are welcome! Please create a pull request with a detailed description of your changes.

License
This project is licensed under the MIT License. See the LICENSE file for details.
