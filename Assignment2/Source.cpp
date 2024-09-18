#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// We will make function for the students which will store the first and last names 
struct STUDENT_DATA
{
    std::string FIRST_NAME;
    std::string LAST_NAME;
};

// As instruction given we will declare vector to store all the data's

std::vector<STUDENT_DATA> students;

// We will make function to load student data from given file
void LOAD_STUDENTS_DATA(const std::string& fileName)
{
    std::ifstream SOURCE_FILE(fileName);  // This will ppen the file
    std::string LINES;

    // As we have to check if the file opened successfully
    if ( SOURCE_FILE.is_open() )
    {
        while ( getline(SOURCE_FILE, LINES) )
        {
            std::stringstream SPLIT_LINES(LINES);  // As per instruction we have to split the line into first/last name
            std::string FIRST_NAMES, LAST_NAMES;

            // USing comma to seperate first and last name
            if (getline(SPLIT_LINES, FIRST_NAMES, ',') && getline(SPLIT_LINES, LAST_NAMES))
            {
                STUDENT_DATA STUDENTS;  // We will create a object STUDENT_DATA 
                STUDENTS.FIRST_NAME = FIRST_NAMES; // Will make object of firstname
                STUDENTS.LAST_NAME = LAST_NAMES; // Will make object of lastname

                // WE will Push the student object in the vector
                students.push_back(STUDENTS);
            }
        }
        SOURCE_FILE.close();  // Will close the file after featchin all the data
    }
    else // error message if somthig went wrong
    {
        std::cout << "wOOPS something went wrong cannot open the file:  " << fileName << std::endl;
    }
}

int main() 
{
    // We will call the function to load the datas from the given file
    LOAD_STUDENTS_DATA("StudentData.txt");

    // This will print the student data to verify it was loaded perfectly.
    for (const auto& STUDENTS: students) 
    {
        // This statment will print each student's first and last name
        std::cout << "First Name: " << STUDENTS.FIRST_NAME << ", Last Name: " << STUDENTS.LAST_NAME << std::endl;
    }

    return 1;
}
