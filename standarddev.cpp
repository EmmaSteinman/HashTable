//================================================================
//standarddev.cpp
//This file calculates the standar deviation from the histogram
//================================================================


#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;



float standarddev(vector<int> slotList)
{

  float n = slotList.size();
  cout << n<< endl;
  float sum;
  for (int i = 0; i < n; i++)
    sum += slotList[i];
  cout << sum << endl;
  float mean = sum/n;
  cout << mean << endl;
  float total;
  for (int y = 0; y < n; y++)
    total += pow((slotList[y] - mean), 2);
  cout << total << endl;

  return sqrt(total / n);
}


int main (void)
{
  ifstream ifile("hash.txt");
  string line;
  vector<int> data;
  //vector<int> iterator it = data.begin();
  while (getline(ifile, line))
  {
    int ln = stoi(line);
    data.push_back(ln);
  }
  float standardDeviation = standarddev(data);
  cout << standardDeviation << endl;
  return 0;
}