#include <iostream>
#include "TSP.h"
#include <chrono>
#include <fstream>

using namespace std;

int main() {

    TSP test;
    std::vector<int> result;
    ofstream out("output.txt");

    if (!test.readGraph("input.txt"))
    {
        out << "Couldn't read file. Exiting... " << std::endl;
        out.close();
        exit(1);
    }
    ///////////////// Running Bruteforce solution ///////////////////

    out << "Brute Force Solution:\n" << endl;

    auto start = std::chrono::system_clock::now();

    out << "Minimum Cost: " << test.bruteForce(0, result) << endl;

    auto end = std::chrono::system_clock::now();

    out << "Brute force runtime: " << std::chrono::duration_cast<std::chrono::microseconds >(end - start).count() << " milliseconds.\n" << endl;

    // Uncomment to see the path
/*
    for ( auto& i : result )
        out << i << " ";
    out << endl;
*/

///////////////// Running DP solution ///////////////////

    out << "Dynamic Programming Solution:\n" << endl;
    start = std::chrono::system_clock::now();

    out << "Minimum Cost: " << test.DP(0) << endl;

    end = std::chrono::system_clock::now();

    out << "DP runtime: " << std::chrono::duration_cast<std::chrono::microseconds >(end - start).count() << " milliseconds.\n" << endl;

    out.close();
    return 0;
}
