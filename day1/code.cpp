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
#include <queue>
#include <cassert>

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
class Result
{
public:
  vector<int> indices;
  vector<int> maxima;
  Result()
  {
    indices = {0, 0, 0};
    maxima = {0, 0, 0};
  }
};


Result find3Max(map<int, int> mp)
{
  int x = 0;
  int first = 0;
  int first_idx = 0;
  int second = 0;
  int second_idx = 0;
  int third = 0;
  int third_idx = 0;
  Result result;
  for(int i = 0; i < mp.size(); i++)
  {
    x = mp[i];
    if(x > third and x < second and x < first)
    {
      third = x;
      third_idx = i; 
    }
    else if(x > third and x > second and x < first)
    {
      third = second;
      third_idx = second_idx;
      second = x;
      second_idx = i;
    }
    else if(x > third and x > second and x > first)
    {
      third = second;
      third_idx = second_idx;
      second = first;
      second_idx = first_idx;
      first = x;
      first_idx = i;
    }
    else if(x == second)
    {
     third = x;
     third_idx = i;
    }
    else if(x == first)
    {
      third = second;
      third_idx = second_idx;
      second = x;
      second_idx = i;
    }
  }
  result.indices[0] = first_idx;
  result.maxima[0] = first;
  result.indices[1] = second_idx;
  result.maxima[1] = second;
  result.indices[2] = third_idx;
  result.maxima[2] = third;
  return result;
}

int sum3elves(Result result)
{
  int sum = 0;
  for(int i = 0; i < 3; i++)
  {
    sum += result.maxima[i];
  }
  return sum;
}

int main(){
  Expedition expedition;
  expedition.readData("data.txt");

  map<int, int> summed_list;
  summed_list = expedition.sumInventories();
  vector<int> maxima;
  maxima = findMax(summed_list);

  Result result;
  result = find3Max(summed_list);

  cout << "The first elf is : " << result.indices[0] << endl;
  cout << "With total calories value: " << result.maxima[0] << endl;
  
  cout << "The second elf is : " << result.indices[1] << endl;
  cout << "With total calories value: " << result.maxima[1] << endl;

  cout << "The third elf is : " << result.indices[2] << endl;
  cout << "With total calories value: " << result.maxima[2] << endl;  int sum3 = sum3elves(result);

  cout << "Sum of 3 biggest food inventories is: " << sum3 << endl;
}
