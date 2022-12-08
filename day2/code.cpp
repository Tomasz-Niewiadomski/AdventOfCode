/*
  Language: C++
  Advent of Code #2
  Brief: Find max of rock paper scissors strategy
  Author: Tomasz Niewiadomski
  Date: Night 07122022
*/
#include <iostream>
#include <fstream>
#include <stdexcept>              // To assert
using namespace std;

int weaponScore(string weapon){   // Returns value of weapon used
  int temp;
  if (weapon == "X"){
     temp = 1;
     return temp;
  } 
  else if (weapon == "Y"){
    temp = 2;
    return temp;
  }
  else if (weapon == "Z"){
    temp = 3;
    return temp;
  }
  else{
    throw invalid_argument("received value different from X/Y/Z");
    return -1;
  }
}

int battleScore(string left, string right){ // Returns 0 for L, 3 for D, 6 for W
  if (left == "A" && right == "X") return 3;
  else if (left == "A" && right == "Y") return 6;
  else if (left == "A" && right == "Z") return 0;
  else if (left == "B" && right == "X") return 0;
  else if (left == "B" && right == "Y") return 3;
  else if (left == "B" && right == "Z") return 6;
  else if (left == "C" && right == "X") return 6;
  else if (left == "C" && right == "Y") return 0;
  else if (left == "C" && right == "Z") return 3;
  else{
    throw invalid_argument("received value different from A/B/C and X/Y/Z");
    return -1;
  }
}
int new_weaponScore(string right){
  if (right == "A") return 1;
  else if (right == "B") return 2;
  else if (right == "C") return 3;
  else throw invalid_argument("Yo wtf");
}
int new_battleScore(string left, string right){ // Returns 0 for L, 3 for D, 6 for W
  if (left == "A" && right == "X") return 0;
  else if (left == "A" && right == "Y") return 3;
  else if (left == "A" && right == "Z") return 6;
  else if (left == "B" && right == "X") return 0;
  else if (left == "B" && right == "Y") return 3;
  else if (left == "B" && right == "Z") return 6;
  else if (left == "C" && right == "X") return 0;
  else if (left == "C" && right == "Y") return 3;
  else if (left == "C" && right == "Z") return 6;
  else{
    throw invalid_argument("received value different from A/B/C and X/Y/Z");
    return -1;
  }
}

string response(string left, string right){
  if (new_battleScore(left, right) == 0){
    if(left == "A") return "C";
    else if(left == "B") return "A";
    else if(left == "C") return "B";
    else throw invalid_argument("Yo wtf");
  }
  else if (new_battleScore(left, right) == 3){
    return left;
  }
  else if (new_battleScore(left, right) == 6){
    if(left == "A") return "B";
    else if(left == "B") return "C";
    else if(left == "C") return "A";
    else throw invalid_argument("Yo wtf");
  }
  else throw invalid_argument("Yo wtf");
}

int main(){
  ifstream input;
  string line;
  input.open("data.txt");

  if (input.is_open()){

    string left;
    string right;
    int battleValue;
    int weaponValue;
    int sum = 0;
    int temp;
    while (input >> left >> right){
      
      weaponValue = new_weaponScore(response(left, right));
      battleValue = new_battleScore(left, right);
      sum += weaponValue + battleValue;
    }
    input.close();
    cout << "Sum = " << sum << endl;
  }
  else{
  cout << "File Kaputt" << endl;
  }
}

