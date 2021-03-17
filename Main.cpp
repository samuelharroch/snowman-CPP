#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include <cstdlib> 
#include <ctime> 
#include "snowman.hpp"

using namespace std;

long Generate_random_input(){
    srand((unsigned)time(0));
    long n=0;

    for(int i=0 ; i<8;i++){
        n*=10;
        n+=(rand()%4)+1;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    cout<< "Say Hello to the Chiness Snowman\n"<< ariel::snowman(32444433)<< endl;
    cout<< "Say Hello to Olaf the Snowman\n"<< ariel::snowman(12222212)<< endl;
    cout<< "Say Hello to Random the Snowman\n"<< ariel::snowman(Generate_random_input())<< endl;


   
    return 0;
}
