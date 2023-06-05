//
//  main.cpp
//  CPlusPlusKeyWords
//
//  Created by brian on 11/29/22.
//
//  in this project I will attempt to implement and describe all C++ keywords
//
///  long ✅
///  short ✅
///  charX_t ✅
///  float ✅
///  double ✅
///  int ✅
///  char ✅
///  wchar_t ✅
///  signed ✅
///  unsigned ✅
///
///  namespace ✅
///  sizeof() ✅
//
#include <iostream>

int main()
{
    //datatypes
    {
        std::cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        std::cout << "charX_t values and types: " << std::endl;
        char8_t shortChar = 255;    //set to max value of 255
        char16_t medChar = 65535;   //set to max value of 65535
        char32_t longChar = 4294967295; //set to max value of 4,294,967,295
        
        std::cout << "\tchar8_t: " << shortChar << std::endl;
        std::cout << "\tchar16_t: " <<medChar << std::endl;
        std::cout << "\tchar32_t" << longChar << std::endl;
        
        {
            //creates a scope where these variables will live
            std::cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
            std::cout << "integer values and types: " << std::endl;
            using std::cout, std::endl;
            short signedShort = 32767;
            int signedInt = 2147483647;
            long signedLongInt = 9223372036854775807;
            long long signedLongLongInt = 9223372036854775807;
            
            
            cout << "\tshort: " << signedShort << endl;
            cout << "\tint: " << signedInt << endl;
            cout << "\tlong int: " << signedLongInt << endl;
            cout << "\tlong long int: " << signedLongLongInt << endl;
        }
        
        //cout << "Hello" << endl;  //code will not function as it is oytside of the scope
        
        std::cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        std::cout << "floating values and types: " << std::endl;
        float signedFloat = 2147483647;
        double signedDouble = 9223372036854775807;
        long double signedLongDouble = 9223372036854775807;
        
        
        std::cout << "\tsigned float: " << signedDouble << std::endl;
        std::cout << "\tsigned double: " << signedFloat << std::endl;
        std::cout << "\tsigned long double: " << signedLongDouble << std::endl;
        
        
        std::cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        std::cout << "other values and types: " << std::endl;
        signed char  signedChar = 127;
        unsigned char unsignedChar = 255;
        wchar_t signedWideChar = 32767;
        
        std::cout << "\tsignedChar: " << (int) signedChar << std::endl;
        std::cout << "\tunsignedChar: " << static_cast<short>(unsignedChar) << std::endl;
        std::cout << "\tsignedWideChar: " << (short) signedWideChar << " | size of wideChar: " << sizeof(signedWideChar) << std::endl;
    
        
    }
    
    return 0;
}
