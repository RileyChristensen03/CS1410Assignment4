//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 TOKEN
#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class DieSide { // Lists the sides of a die
  One, Two, Three, Four, Five, Six
};


struct HistBar {    // Represents a bar in a histogram
  int count;
  DieSide label;
};

HistBar results[] = {{0, DieSide::One}, {0, DieSide::Two}, {0, DieSide::Three}, {0, DieSide::Four}, {0, DieSide::Five}, {0, DieSide::Six}};

void rollDice(HistBar h[], int n = 1){
  int random_num = 0;
  for(int i = 1; i <= n; i++){
    random_num = rand() % 6 + 1;
    if(random_num == 1){
      h[0].count++;
    }
    else if(random_num == 2){
      h[1].count++;
    }
    else if(random_num == 3){
      h[2].count++;
    }
    else if(random_num == 4){
      h[3].count++;
    }
    else if(random_num == 5){
      h[4].count++;
    }
    else if(random_num == 6){
      h[5].count++;
    }
  }

  // stringstream sout;
  // default_random_engine en;
  // uniform_int_distribution<> r{1,6};
  // for(int i = 0; i < 100; i++){
  //    cout << results[r(en)]++;
  // }
  
}

string histogram(HistBar h[], char c = '*'){
  //string return_string;
  stringstream return_string;
  string s;
  string index;
  for(int i = 0; i < 6; i++){
    if(i == 0){
      index = " ONEs: ";
    }
    else if(i == 1){
      index = " TWOs: ";
    }
    else if(i == 2){
      index = " THREEs: ";
    }
    else if(i == 3){
      index = " FOURs: ";
    }
    else if(i == 4){
      index = " FIVEs: ";
    }
    else if (i == 5){
      index = " SIXes: ";
    }
   return_string << to_string(h[i].count) << index;
   int size = h[i].count;
   string stars = "";
    for(int i = 0; i < size; i++) {
      stars += c;
    }
   return_string << stars;
   return_string << endl;
  }
  s = return_string.str();
  return s;
}

void reset(HistBar h[]){
  for(int i = 0; i < 6; i++){
    h[i].count = 0;
  }
  
}

int main(){
  // TODO
  srand(time(NULL));

  int choice;
  do {
    cout << "Dice rolling simulation" << endl
    << "=======================" << endl
    << "1. Roll Dice" << endl
    << "2. Display histogram" << endl
    << "3. Reset histogram" << endl
    << "4. Quit program\n" << endl
    << "Enter your choice:" << endl;

    cin >> choice;

    switch(choice) {
      case 1:
        rollDice(results);
        break;
      case 2:
        cout << histogram(results) << endl;
        break;
      case 3:
        reset(results);
        break;
      case 4:
        cout << "Goodbye\n";
        break;
      default:
        cout << "Invalid choice.\n" << endl;
    }
  } while(choice != 4);
  return 0;
}