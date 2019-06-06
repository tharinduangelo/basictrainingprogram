//
//  main.cpp
//  ArgumentsPrinter
//  Take in line of input and output the seperate tokens
//  Created by Tharindu Angelo Withanage on 6/6/19.
//  Copyright © 2019 Tharindu Angelo Withanage. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    cout << "Enter String: ";
    //get input
    getline(cin, input);
    istringstream iss(input);
    string token;
    int i = 0;
    //output tokens
    while(iss >> token){
        cout << "Arg " << i << ": " << token << endl;
        i += 1;
    }
    return 0;
}
