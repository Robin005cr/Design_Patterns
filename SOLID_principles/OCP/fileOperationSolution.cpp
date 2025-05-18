/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : fileOperationSolution.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileOperation(const string& inputFilePath, const string& outputFilePath)
{
    ifstream inFile(inputFilePath);
    ofstream outFile(outputFilePath);

    if (!inFile.is_open()) {
        cerr << "Error: Cannot open input file at path: " << inputFilePath << endl;
        return;
    }

    if (!outFile.is_open()) {
        cerr << "Error: Cannot open or create output file at path: " << outputFilePath << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    cout << "Contents copied from " << inputFilePath << " to " << outputFilePath << endl;

    inFile.close();
    outFile.close();
}
int main()
{
    string inputPath = "C:/Users/YourName/Documents/input.txt";
    string outputPath = "C:/Users/YourName/Documents/output.txt";

    fileOperation(inputPath, outputPath);

    return 0;
}
