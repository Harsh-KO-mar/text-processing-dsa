#include "rle.h"
#define ull unsigned long long int
#include<cstring>
#include<iostream>
using namespace std;
int pow(int n, int k) {//n^k
    int sum = 1;
    for (int i=0; i<k; i++) {
        sum *= n;
    }
    return sum;
}
string DecimalToBinary(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1 
    }   
      string rev = string(str.rbegin(), str.rend());
      return rev;
}
 
int binaryToDecimal(string input) {
    int len = 0;
    int sum = 0;
    while(input[len++] != '\0') {
    ;}
    int i = 0;
    len--;
    while(input[i] != '\0') {
        if (input[i] == '1') {
            sum += pow(2,len);
        }
        len--;
        i++;
    }
    return sum/2;
}

int percentTen (int i) {
    int k = 1;
    while (i / k != 0) {
        k *= 10;
    }
    k = k/10;
    return k;
}

// Constructor
rle::rle(int gamma): gamma(gamma){}

// Convert integer to gamma-bit binary string
string rle::f(int i){
    string final;
    int bruh = pow(2,gamma) - 1;
    int k = i/bruh;
    int x = i%bruh;
    string zeroes;
    string ones;
    string tmp = DecimalToBinary(x);
    int tmpLen = 0;
    while (tmp[tmpLen++] != '\0') {;}
    for (int j=0; j<gamma; j++) {
        zeroes.append("0");
        ones.append("1");
    }
    for (int j=0; j<k; j++) {
        final.append(ones);
        final.append(zeroes);
    }
    for (int i=0; i<=gamma-tmpLen; i++) {
        final += '0';
    }
    final.append(tmp);
    return final;
}

// Convert gamma-bit binary string to integer
int rle::g(string i){
    int sum = 0;
    int len = 0;
    while(i[len++] != '\0') {;}
    for (int j=0; j<len; j = gamma+j) {
        string tmp;
        for (int k = 0; k<gamma; k++) {
            tmp += i[j + k];
        }
        int bruh = binaryToDecimal(tmp);
        sum += bruh;
    }
    return sum;
}

// Compress the input file
string rle::compress(string input_string){
    string bruh;
    bruh += input_string[0];
    //cout<<bruh<<"\n";
    int iter = 1;
    int charsMatched = 1;
    bool flag = false;
    while(input_string[iter] != '\0') {
        if ((input_string[iter] == '1' && input_string[iter - 1] == '1') || (input_string[iter] == '0' && input_string[iter - 1] == '0')) {
            charsMatched ++;
            //cout<<"current thing is "<<input_string[iter]<<"no. of things matched is "<<charsMatched<<"\n";
        }
        else {
            string tmp = f(charsMatched);
            //cout<<tmp<<"\n";
            charsMatched = 1;
            bruh.append(tmp);
        }
        //cout<<input_string[iter];
        iter++;
    }
    if (!flag) {
        string tmp = f(charsMatched);
        charsMatched = 1;
        bruh.append(tmp);
    }
    //cout<<bruh<<"\n";
    return bruh;
}

// Decompress the input file
string rle::decompress(string input_string){ 
    string bruh;
    //bruh += input_string[0];
    bool isOne;
    if (input_string[0] == '1') {
        isOne = true;
    }
    else {
        isOne = false;
    }
    for (int iter = 1; input_string[iter] != '\0' ;iter = gamma + iter ) {
        string tmp;
        tmp += input_string[iter];
        tmp += input_string[iter+1];
        tmp += input_string[iter+2];
        tmp += input_string[iter+3];
        //cout<<"tmp is "<<tmp<<"\n";
        int gay;
        gay = binaryToDecimal(tmp);
        //cout<<"gay is "<<gay<<"\n";
        for (int i=0; i<gay; i++) {
            if (isOne) {
                bruh += '1';
            }
            else {
                bruh += '0';
            }
        }
        isOne = !isOne;
    }
    return bruh;
}
