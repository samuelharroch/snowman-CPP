/**
 * AUTHORS: @SamuelHarroch
 * 
 * Date: 2021-02
 */


#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    
    /*Hat snowman test (first digit)*/
    //Straw Hat
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    //mexican hat 
    CHECK(nospaces(snowman(21114411)) == nospaces(" ___ \n.....\n(.,.)\n( : )\n( : )"));
    //Fez
    CHECK(nospaces(snowman(31114411)) == nospaces("  _  \n /_\\ \n(.,.)\n( : )\n( : )"));
    //Russian hat 
    CHECK(nospaces(snowman(41114411)) == nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( : )"));
    
    /* Nose/Mouth snowman test (second digit)*/
    //Dot nose
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    //line mouse
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    
    /*Eyes snowman test (third & 4th digits)*/
    //o eyes 
    CHECK(nospaces(snowman(11224411)) == nospaces("_===_\n(o,o)\n( : )\n( : )"));
     //0 eyes
    CHECK(nospaces(snowman(11334411)) == nospaces("_===_\n(O,O)\n( : )\n( : )"));
     //left close right o
    CHECK(nospaces(snowman(11424411)) == nospaces("_===_\n(-,o)\n( : )\n( : )"));
    
    /*Right and Left Arms (5th and 6th digits)*/
    // normals arms <>
    CHECK(nospaces(snowman(11111111)) == nospaces(" _===_\n (.,.)\n<( : )>\n ( : )"));
    // left Upwards Ridht downwards
    CHECK(nospaces(snowman(11112311)) == nospaces(" _===_\n\\(.,.)\n ( : )\\ \n ( : )"));

    /*Torso snowman test (7th digit) */
    //vest
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
    //Inwards Arms 
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
    
    /*Base snowman test (last digit)*/
    //feet
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(" ")"));
    //flat
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
    //none
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )"));
    
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(123412349));
    CHECK_THROWS(snowman(12345678));
    CHECK_THROWS(snowman(12341230));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(11125333));
    
}