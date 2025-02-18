// Instructions
// main.cpp
// Your program will receive a list of files as arguments.
// The list will contain at least 2 files.
// The last file is the output file.
// For each file except the last one:
// Read the data into a vector.
// The data in the file is formatted with one double per line. You should read until the end of the file.
// Call the stats function.
// Write the stats to the output file in the following format: <min>,<max>,<avg>,<std_dev>\n.
// At the end of the program, the output file should be a csv file with 4 columns and as many rows as input files.
// No header in the output file.

#include <cmath>
#include <fstream>
#include <vector>
#include "stats.h"

void writeToFile(const string &content, ofstream &outFile)
{
    if (outFile.is_open())
    {
        outFile << content;
    }
}

double computeMin(vector<double> &data)
{
    double min = data[0];
    for (int i = 0; i < size(data); i++)
    {
        // If the next element is smaller than the current 
        // (unless we are at the final element)
        if (((i - 1) != size(data)) && ((i + 1) < data[i]))
        {
            min = data[i + 1];
        }
    }
    return min;
}

double computeMean(vector<double> &data)
{
    double sum;
    for (int i = 0; i < size(data); i++)
    {
        sum += data[i];
    }
    return (sum / size(data));
}

double computeStdDev(double mean, vector<double> &data)
{
    double deviationSum;
    for (int i = 0; i < size(data); i++)
    {
        deviationSum += ((data[i] - mean) * (data[i] - mean));
    }
    return sqrt((deviationSum / size(data)));
}

int main()
{
    string inputFile = "";
    string outputFile = "";

    ifstream input(inputFile);
    ofstream output(outputFile);
    return 0;
}
