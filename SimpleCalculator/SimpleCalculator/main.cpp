//
//  main.cpp
//  SimpleCalculator
//  Able to perform the four basic operations one at a time
//  Able to store result to be used later.
//  Created by Tharindu Angelo Withanage on 6/6/19.
//  Copyright © 2019 Tharindu Angelo Withanage. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // initialising variables
    string input = "";
    float Ans = 0;
    const char op[] = "+-*/";
    
    while (true){
        //setting flags
        bool isAns = false;
        bool isAnstwice = false;
        
        puts("Enter input: ");
        //get user input
        getline(cin, input);
        //check if input is empty
        if (input.empty())
            continue;
        //check if user wants to terminate
        if (input == "quit"){
            cout << "Calculator terminated" << endl;
            break;
        }
        //Check if Ans has been entered
        auto pos = input.find("Ans");
        if(pos != string::npos){
            isAns = true;
            input.erase(pos,3);
        }
        //Check if Ans has been entered again
        auto pos2 = input.find("Ans");
        if(pos2 != string::npos){
            isAnstwice = true;
            input.erase(pos2,3);
        }
        //Check for invalid characters
        if (input.find_first_not_of("0123456789.+-*/ ") != string::npos){
            cout << "Invalid input." << endl;
            continue;
        }
        //remove whitespaces
        input.erase(remove(input.begin(),input.end(),' '), input.end());
        
        //check if any operations are mentioned
        if (input.find_first_of(op) == string::npos){
            Ans = stof(input);
        }
        else{
            //create duplicate of input
            char *dup = strdup(input.c_str());
            //break input into tokens
            char *token = strtok(dup, op);
            float num1;
            //take Answer or first token as first number
            if (isAnstwice)
                num1 = Ans;
            else
                num1 = stof(token);
            token = strtok(NULL, op);
            float num2;
            //take Answer or second token as second number
            if (isAns)
                num2 = Ans;
            else
                num2 = stof(token);
            //check if more than two tokens have been entered
            if (strtok(NULL,op) != NULL){
                cout << "Invalid input. Supports only one operation." << endl;
                continue;
            }
            //find which operation to be performed
            if (input.find("+") != string::npos)
                Ans = num1 + num2;
            else if (input.find("-") != string::npos)
                Ans = num1 - num2;
            else if (input.find("*") != string::npos)
                Ans = num1 * num2;
            else{
                //Check for zero division error
                if (num2 == 0){
                    cout << "Math Error: Attempted to Divide by Zero." << endl;
                    continue;
                }
                Ans = num1 / num2;}
        }
        //Display Answer
        cout << "Ans = " << Ans << endl;}
    return 0;
}
