#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <thread>
using namespace std;

#include "openconfig/openconfig_platform/openconfig_platform.pb.h"

int main(int argv, char** argc) {
    // First argument is small file, second is big file
    ifstream smallFile(argc[1], ios::binary);
    string smallBin;
    smallFile.seekg(0, std::ios::end);
    smallBin.reserve(smallFile.tellg());
    smallFile.seekg(0, std::ios::beg);
    smallBin.assign((istreambuf_iterator<char>(smallFile)), istreambuf_iterator<char>());

    // Wow, I had forgotten how much work it is just to read a whole file in C++
    ifstream bigFile(argc[2], ios::binary);
    string bigBin;
    bigFile.seekg(0, std::ios::end);
    bigBin.reserve(bigFile.tellg());
    bigFile.seekg(0, std::ios::beg);
    bigBin.assign((istreambuf_iterator<char>(bigFile)), istreambuf_iterator<char>());

    /****************************************************************
     * Small message deserialize test
     ***************************************************************/
    // Root level Proto message.
    openconfig::openconfig_platform::Components smallRoot;

    chrono::steady_clock::time_point startSmall = chrono::steady_clock::now();
    int num_iter_small = 5082544;
    for (int i = 0; i < num_iter_small; i++) {
        smallRoot.ParseFromString(smallBin);
    }
    chrono::steady_clock::time_point endSmall = chrono::steady_clock::now();

    chrono::duration<double> diff = chrono::duration_cast<chrono::duration<double>>(endSmall-startSmall);
    double diff_small = diff.count();

    /****************************************************************
     * Big message deserialize test
     ***************************************************************/
    // Root level Proto message.
    openconfig::openconfig_platform::Components bigRoot;

    chrono::steady_clock::time_point startBig = chrono::steady_clock::now();
    int num_iter_big = 416;
    for (int i = 0; i < num_iter_big; i++) {
        bigRoot.ParseFromString(bigBin);
    }
    chrono::steady_clock::time_point endBig = chrono::steady_clock::now();

    diff = chrono::duration_cast<chrono::duration<double>>(endBig-startBig);
    double diff_big = diff.count();

    /****************************************************************
     * Print results
     ***************************************************************/
    printf("cpp-gpb-proto-deserialize,%e,%e,%e,%e\n",
           diff_small/num_iter_small,
           diff_small,
           diff_big/num_iter_big,
           diff_big);

    /****************************************************************
     * Small message serialize test
     ***************************************************************/
    // Root level Proto message.
    string smallStr;

    startSmall = chrono::steady_clock::now();
    num_iter_small = 19899491;
    for (int i = 0; i < num_iter_small; i++) {
        smallRoot.SerializeToString(&smallStr);
    }
    endSmall = chrono::steady_clock::now();

    diff = chrono::duration_cast<chrono::duration<double>>(endSmall-startSmall);
    diff_small = diff.count();

    /****************************************************************
     * Big message serialize test
     ***************************************************************/
    // Root level Proto message.
    string bigStr;

    startBig = chrono::steady_clock::now();
    num_iter_big = 927;
    for (int i = 0; i < num_iter_big; i++) {
        bigRoot.SerializeToString(&bigStr);
    }
    endBig = chrono::steady_clock::now();

    diff = chrono::duration_cast<chrono::duration<double>>(endBig-startBig);
    diff_big = diff.count();

    /****************************************************************
     * Print results
     ***************************************************************/
    printf("cpp-gpb-proto-serialize,%e,%e,%e,%e\n",
           diff_small/num_iter_small,
           diff_small,
           diff_big/num_iter_big,
           diff_big);

    return 0;
}
