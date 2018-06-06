#include<cstdio>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <assert.h>
#include <cstdlib>

using namespace std;

int size(string s){
  int i = 0;
  while(s[i] != 0){
    i++;
  }
  return i;
}

int binstring_to_dec(string s)
{//we assume that all the strings are 12 char long and binary written
  int n = size(s);
  int pas = 0;
    for(int j = 0; j < 4; j++){
        if(s[j] == '1'){
          pas += pow(2,3-j);
        }
  }
  return pas;
}


string toBinary(int n)
{
  string r;
  while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
  return r;
}


string tobin(float x){
  int y;
  string s;
  y = int(x  * pow(16,3));
  s = toBinary(y);
  while (size(s)<12)
  s = s + "0";
  return s ;
}

string toascii(string s){
  int n = size(s);
  string l = "0123456789:;<=>?";
  string ret;
  assert(n == 12);
  for (int i = 0; i < 3; i++){
    int beg = i*4;
    int end = 4*i+4;
    int ind = binstring_to_dec(s.substr(beg,end));
    ret += l[ind];
  }
  return  ret;
}


int main(int argc, char* argv[]){
  printf("BEGIN TEST \n");
  float t;
  float f[100];
  string bin;
  string asc;
  f[0] = 1.0;
  for (int i = 0; i < 100; i++){
    f[i] = f[0] + i*0.01;
    bin  = tobin(f[i]);
    bin = bin.substr(1,12);
    printf("%f",f[i]-1 );
    cout <<   "  devient  "   + bin;
    asc = toascii(bin);
    cout << " qui devient " + asc + "\n";
    if(f[i] == 0.5 && asc == "800"){
      printf("//////////////////////TEST OK//////////////////////\n");
    }
  }
  printf("END TEST\n");
  return 0;
}
