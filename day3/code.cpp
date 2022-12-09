#include <stdlib.h>    // atoi
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>   // sort

using namespace std;

int countRucksacks(string const& filename)
{
  string line;
  ifstream input (filename);
  int line_count = 0;
  if (input.is_open())
  {
    while(input >> line)
    {
      line_count++;
    }
  }
  else cerr << "File failed to open" << endl;

  return line_count;
}
vector<vector<char>> readData(string const& filename)
{
  vector<vector<char>> rucksacks(countRucksacks(filename), vector<char>()); 

  string line;
  string word;
  istringstream iss;

  ifstream input (filename);
   
  if (input.is_open())
  {
//    while(not input.eof())                   // read line by line
    for( int i = 0;not input.eof(); i++)
    {
      getline(input, line);
      if (input.good())
      {
        iss.clear();
        iss.str(line);
        while (iss.good())                    // read word by word
        {
          iss >> word;
          for (char c : word)                // read character by character
          {
            rucksacks[i].push_back(c);
            // cout << c << endl;
          }
        }
      }
    }
  }
  else
  {
    cerr << "Failed to open the file" << endl;
  }
  return rucksacks;
}

int priority(char ch)                        // Returns priority of a given letter
{
  int value;
  map<char, int> priority_map;
  
  priority_map.insert(pair<char, int>('a', 1)); 
  priority_map.insert(pair<char, int>('b', 2));
  priority_map.insert(pair<char, int>('c', 3));
  priority_map.insert(pair<char, int>('d', 4));
  priority_map.insert(pair<char, int>('e', 5));
  priority_map.insert(pair<char, int>('f', 6));
  priority_map.insert(pair<char, int>('g', 7));
  priority_map.insert(pair<char, int>('h', 8));
  priority_map.insert(pair<char, int>('i', 9));
  priority_map.insert(pair<char, int>('j', 10)); 
  priority_map.insert(pair<char, int>('k', 11));
  priority_map.insert(pair<char, int>('l', 12));
  priority_map.insert(pair<char, int>('m', 13));
  priority_map.insert(pair<char, int>('n', 14));
  priority_map.insert(pair<char, int>('o', 15));
  priority_map.insert(pair<char, int>('p', 16));
  priority_map.insert(pair<char, int>('q', 17));
  priority_map.insert(pair<char, int>('r', 18));
  priority_map.insert(pair<char, int>('s', 19));
  priority_map.insert(pair<char, int>('t', 20));
  priority_map.insert(pair<char, int>('u', 21));
  priority_map.insert(pair<char, int>('v', 22));
  priority_map.insert(pair<char, int>('w', 23));
  priority_map.insert(pair<char, int>('x', 24));
  priority_map.insert(pair<char, int>('y', 25));
  priority_map.insert(pair<char, int>('z', 26));
  priority_map.insert(pair<char, int>('A', 27)); 
  priority_map.insert(pair<char, int>('B', 28)); 
  priority_map.insert(pair<char, int>('C', 29));
  priority_map.insert(pair<char, int>('D', 30));
  priority_map.insert(pair<char, int>('E', 31));
  priority_map.insert(pair<char, int>('F', 32));
  priority_map.insert(pair<char, int>('G', 33));
  priority_map.insert(pair<char, int>('H', 34));
  priority_map.insert(pair<char, int>('I', 35));
  priority_map.insert(pair<char, int>('J', 36));
  priority_map.insert(pair<char, int>('K', 37));
  priority_map.insert(pair<char, int>('L', 38));
  priority_map.insert(pair<char, int>('M', 39));
  priority_map.insert(pair<char, int>('N', 40));
  priority_map.insert(pair<char, int>('O', 41));
  priority_map.insert(pair<char, int>('P', 42));
  priority_map.insert(pair<char, int>('Q', 43));
  priority_map.insert(pair<char, int>('R', 44));
  priority_map.insert(pair<char, int>('S', 45));
  priority_map.insert(pair<char, int>('T', 46));
  priority_map.insert(pair<char, int>('U', 47));
  priority_map.insert(pair<char, int>('V', 48));
  priority_map.insert(pair<char, int>('W', 49));
  priority_map.insert(pair<char, int>('X', 50));
  priority_map.insert(pair<char, int>('Y', 51));
  priority_map.insert(pair<char, int>('Z', 52));
  
  value = priority_map.find(ch)->second;          // '->second' is a mystery. Maybe turns value to int..
  return value;
}
// change auto later
char findIntersection(vector<char> rucksack)
{
  vector<char> compartment1;
  vector<char> compartment2;
  vector<char> intersection;

  for(int i = 0; i < rucksack.size()/2; i++)    // Put half of items into each compartment
  {
    compartment1.push_back(rucksack[i]);
    compartment2.push_back(rucksack[rucksack.size()/2 + i]);
  }

  sort(compartment1.begin(), compartment1.end()); // Sorting vectors helps finding intersection
  sort(compartment2.begin(), compartment2.end());

  set_intersection(compartment1.begin(), compartment1.end(), // Finds intersection of compartments
                   compartment2.begin(), compartment2.end(),
                   back_inserter(intersection));            // Stores result in intersection vectors
  char result = intersection[0];
  return result;
}

char findBadge(vector<char> elf1, vector<char> elf2, vector<char> elf3)
{
  sort(elf1.begin(), elf1.end());
  sort(elf2.begin(), elf2.end());
  sort(elf3.begin(), elf3.end());
  vector<char> candidate1;
  vector<char> candidate2;
  vector<char> candidate3;
  vector<char> inters12;
  vector<char> inters23;
  vector<char> inters13;
  set_intersection(elf1.begin(), elf1.end(),
                   elf2.begin(), elf2.end(),
                   back_inserter(inters12));
  set_intersection(elf2.begin(), elf2.end(),
                   elf3.begin(), elf3.end(),
                   back_inserter(inters23));
  set_intersection(elf1.begin(), elf1.end(),
                   elf3.begin(), elf3.end(),
                   back_inserter(inters13));
  sort(inters12.begin(), inters12.end());
  sort(inters23.begin(), inters23.end());
  sort(inters13.begin(), inters13.end());

  set_intersection(inters12.begin(), inters12.end(),
                   inters23.begin(), inters23.end(),
                   back_inserter(candidate1));

  set_intersection(inters23.begin(), inters23.end(),
                   inters13.begin(), inters13.end(),
                   back_inserter(candidate2));

  sort(candidate1.begin(), candidate1.end());
  sort(candidate2.begin(), candidate2.end());

  set_intersection(candidate1.begin(), candidate1.end(),
                   candidate2.begin(), candidate2.end(),
                   back_inserter(candidate3));
  char badge = candidate3[0];
  return badge;
}

int main()
{
  vector<vector<char>> rucksacks;
  string filepath = "data.txt"; 
  rucksacks = readData(filepath); 
  int num_rucksacks = countRucksacks(filepath);
  
//  int sum = 0;
//  int temp;
//  for (int i = 0; i < num_rucksacks; i++)
//  {
//   temp = priority(findIntersection(rucksacks[i]));
//   sum += temp; 
//   cout << "Rucksack " << i << " contributes: " << temp  << endl;
//  }
//  cout << endl;
//  cout << "The final sum of " << num_rucksacks << " rucksacks is: " << sum << endl;
  int sum = 0;
  for (int i = 0; i<num_rucksacks-2; i+=3)
  {
   sum += priority(findBadge(rucksacks[i], rucksacks[i+1], rucksacks[i+2])); 
  }
  cout << "Sum of all badges iss: " << sum;
}

