/*
  Language : C++
  Advent Of Code #1
  Brief : Find elf with most food combined
  Author : Tomasz Niewiadomski
  Date : Night 04122022
*/


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Expedition{
  public:
  map<int, vector<int> > list;               // elf[i] has list of food
  
  void readData(string const& filename){
    string line;
    ifstream input (filename);
    if (input.is_open()){
      int elf_idx = 0;
      int value;
      while( getline (input, line)){
        if (!line.empty()){
          value = stoi(line);
          list[elf_idx].push_back(value);
        }
        else elf_idx++;
      }
    input.close();
    }
    else cout << "Unable to open the file";
  }
  
  map<int, int> sumInventories(){
    map<int, int> list_summed;
    for(int i = 0; i < list.size(); i++){
      list_summed[i] = accumulate(list[i].begin(), list[i].end(), 0);
    }
    return list_summed;
  }

};

vector<int> findMax(map<int, int> mp){
  int max_idx;
  int max;
  max = 0;
  vector<int> result;
  
  for(int i = 0; i < mp.size(); i++){
    if (max < mp[i]){
      max_idx = i;
      max = mp[i];
    }
  }
  result.push_back(max_idx);
  result.push_back(max);
  return result;
}

int main(){
  Expedition expedition;
  expedition.readData("data.txt");

  int elfChad;
  map<int, int> summed_list;
  summed_list = expedition.sumInventories();
  vector<int> maxima;
  maxima = findMax(summed_list);
  cout << "The elf Chad is : "<< maxima.front()  << endl;
  cout << "With total calories value: " << maxima.back() <<endl;
}
