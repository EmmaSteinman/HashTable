/*
* hash table test file
* lindsey siegfried & emma steinman
* 6 november 2017
*/

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;


int hasher ( string s, int m )
{
  float hval = 0;
  for ( int i = 0; i < s.length(); i++)
  {
    hval += (int)s[i];
  }

  float A = (sqrt(5)-1)/2;
  float q = fmod((hval * A), 1);
  hval = floor(m * q);

  return hval;


}


int main ( void )
{
/*  cout << "lindsey : " << hasher("lindsey", 1000) << endl;
  cout << "Lindsey : " << hasher("Lindsey", 1000) << endl;
  cout << "LiNdSeY : " << hasher("LiNdSeY", 1000) << endl;
  cout << "LINDSEY : " << hasher("LINDSEY", 1000) << endl;
  cout << "emma : " << hasher("emma", 1000) << endl;
  cout << "Emma : " << hasher("Emma", 1000) << endl;
  cout << "EMMA : " << hasher("EMMA", 1000) << endl;
  cout << "computer science : " << hasher("computer science", 1000) << endl;
  cout << "teststring : " << hasher("teststring", 1000) << endl;
  */
  int m = 1000;
  ifstream ifile("words.txt");
  ofstream ofile("slots.csv");
  string line;
  while (getline(ifile, line))
  {
    int slt = hasher(line, m);
    ofile << line << "," << slt << "," << "\n";
  }

  ifile.close();
  ofile.close();

  return 0;
}
