#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include "snowman.hpp"

using namespace std;

const long  First_legal_num= 11111111;
const long  Last_legal_num =44444444;
const size_t num_of_digits = 8;

string left_space;


enum Part {Hat, Nose_Mouth, Left_Eye, Right_Eye, Left_Arm, Right_Arm, Torso, Base};
enum options {ONE=1,TWO,THREE,FOUR};


void shift_right(array <int,num_of_digits> numbers){
    int none=4;

    if (numbers.at(Left_Arm)!= none){
        left_space=" ";
    }
    else{
        left_space="";
    }
}

string make_hat(array <int,num_of_digits> numbers){
    switch (numbers.at(Hat))
    {
    case ONE:
        return left_space+ "_===_\n";
    case TWO:
        return left_space+ " ___ \n"+left_space+".....\n";
    case THREE:
        return left_space+ "  _  \n"+left_space+" /_\\ \n";
    case FOUR:
        return left_space+ " ___ \n"+left_space+"(_*_)\n";
    
    }
    return "error";
}

string make_left_eye(array <int,num_of_digits> numbers){
    switch (numbers.at(Left_Eye))
    {
    case ONE:
        return ".";
    case TWO:
        return "o";
    case THREE:
        return "O";
    case FOUR:
        return "-";
    
    }
    return "error";
}

string make_nose_mouth(array <int,num_of_digits> numbers){
    switch (numbers.at(Nose_Mouth))
    {
    case ONE:
        return ",";
    case TWO:
        return ".";
    case THREE:
        return "_";
    case FOUR:
        return " ";
    
    }
    return "error";
}

string make_right_eye(array <int,num_of_digits> numbers){
   switch (numbers.at(Right_Eye))
    {
    case ONE:
        return ".";
    case TWO:
        return "o";
    case THREE:
        return "O";
    case FOUR:
        return "-";
    
    }
    return "error";
}

string make_head(array <int,num_of_digits> numbers){
    string head;

    if(numbers.at(Left_Arm)==TWO){
        head+="\\";
    }else{
        head+=left_space;

    }

    head+="("+make_left_eye(numbers)+ make_nose_mouth(numbers)
    +make_right_eye(numbers)+")";

    if(numbers.at(Right_Arm)==TWO){head+="/";}

    return head+"\n";
}

string make_left_arm(array <int,num_of_digits> numbers){
    switch (numbers.at(Left_Arm))
    {
    case ONE:
        return "<";
    case THREE:
        return "/";
    default:
        return left_space;
    
    }

}

string make_torso(array <int,num_of_digits> numbers){
    switch (numbers.at(Torso))
    {
    case ONE:
        return " : ";
    case TWO:
        return "] [";
    case THREE:
        return "> <";
    case FOUR:
        return "   ";
    
    }
    return "error";
}

string make_right_arm(array <int,num_of_digits> numbers){
    switch (numbers.at(Right_Arm))
    {
    case ONE:
        return ">";
    case THREE:
        return "\\";
    default:
        return left_space;
    
    }
    return "error";
}

string make_body(array <int,num_of_digits> numbers){
    
    return make_left_arm(numbers)+"("+make_torso(numbers)
    +")"+make_right_arm(numbers)+"\n";
}

string make_base(array <int,num_of_digits> numbers){
    switch (numbers.at(Base))
    {
    case ONE:
        return left_space+"( : )";
    case TWO:
        return left_space+"(\" \")";
    case THREE:
        return left_space+"(___)";
    case FOUR:
        return left_space+"(   )";
    
    }
    return "error";
}

namespace ariel{
    string snowman(long serial_number){
        
    array <int,num_of_digits> numbers {};

    if (serial_number< First_legal_num || serial_number>Last_legal_num){
        throw runtime_error("no correct input");
     }

    const int units=10;

     for (int i = num_of_digits-1; i >=0 ; i--)
    {
        int digit= (int)serial_number%units;
    
        if (digit==0 || digit >4){
            throw runtime_error("no correct digit");
        }
        numbers.at(i) =digit;
        
        serial_number/=units;
    }

    
      shift_right(numbers);
      return make_hat(numbers) + make_head(numbers) + make_body(numbers) + make_base(numbers)+"\n"; 

    }
}

