#include <string>
#include <vector>
#include <iostream>
  
using namespace std;

/**
 *EXERCISE 1:
 * 
 * The least common multiple (lcm) of two numbers is the smallest number which can be divided by both numbers.
 * By example: lcm(2,3) = 6. Find the lcm(a,b) using the relation lcm(a,b) = a*b/gcd(a,b) 
 * 
 * Hint: Use the Euclidean algorithm: The greatest common denominator of values a and b also divides their difference.
 * 
 * For any (a, b) we have: 
 *      If a > b: gcd(a,b) is the same as gcd(b, a%b)
 *      Analyze example: For hints on edge cases. 
 * 
 */
  
int gcd(int a, int b){
    if(b > a){
        return gcd(b, a);
    }
    if(b == 0){
        return a;
    }
    return gcd(b, a%b); //Dummy return
}

int lcm(int a, int b){  
    return a*b/gcd(a,b); // Dummy Return
}


/**
 * Exercise 2: 
 * 
 * Decimal To Binary: For a given decimal number, calculate it's binary representation.
 * 
 * To convert:
 *      When dec == 0 -> 0
 *      Otherwise 10 * [10 * (...) + dec mod 2] + dec mod 2
 * 
 */
static int decimalToBinary(int dec){
    if(dec == 0){
        return 0;
    }
    return 10 * decimalToBinary(dec/2) + dec%2;
}
   

/**
 * Exercise 3:
 * 
 * Reverse String: Reverse the characters of a string recursively.
 * 
 * Example: 
 *      string = "ICOM"
 *      reverse string = "MOCI".
 * 
 */
string reverseString(const string &str){
    
    // YOUR CODE HERE
    if(str.size() < 2){
        return str;
    }
    return str.back() + reverseString(str.substr(0, str.size() - 1));
}

/**
 * Exercise 4:
 * 
 * Sum the digits of a given number.
 * 
 * Example:
 *      Number = 13
 *      Sum_of_digits = 1 + 3 = 4
 * 
 *      Number = 123
 *      Sum_of_digits = 1 + 2 + 3 = 6
 * 
 */

int sumDigits(const int num){
    // YOUR CODE HERE
    if(num == 0){
        return 0;
    }
    return num%10 + sumDigits(num/10);
}

/**
 * Exercise 5:
 * 
 * Reverse the digits of a given number recursively.
 * Example: 
 *      input = 12
 *      output = 21
 * Hint: If the integer number 123 is divided by 10, the quotient is 123 / 10 = 12, but the remainder is 123 % 10 = 3.
 * Hint: Use a helper function.
 * 
 */
int reverseNumberHelper(int num, int reverse){
    if(num == 0){
        return reverse/10;
    }
    reverse = 10 * (reverse + num%10);
    return reverseNumberHelper(num/10, reverse);
}

int reverseNumber(const int num){
    
    // YOUR CODE HERE
    return reverseNumberHelper(num, 0);
}

/**
 * Exercise 6:
 * 
 * A sequence of Fibonnacci of strings F = {f0,f1,...,fn} is defined 
 * by f0 = "a", f1 = "b", and fn = fn-2 + fn-1, where + is the addition of two strings
 * Define a function  given a string s, such that if s is a term of the Fibonacci 
 * sequence of strings return the position associated. Otherwise return -1.
 * 
 * By example: the string s="bab" correspond to the term f_3 of the sequence, then
 * the output is 3.
 * 
 * Hint:  
 *      -Use a helper function to complete the implementation.
 *      -Use the instance .compare of the class string to compare strings  
 * 
 */

int FibonacciHelper(string s, int index, string str1, string str2){
    if(s == "a"){
        return 0;
    }
    if(s == "b"){
        return 1;
    }
    if(str1.size() >= s.size() && str1 != s){
        return -1;
    }
    if(s == str1){
        return index;
    }
    index++;
    string str = str1 + str2;
    return FibonacciHelper(s, index, str2, str);
}

int Pos_Fibonacci(string s){
    
    return FibonacciHelper(s, 0, "a", "b");
}



int main(){

    cout << boolalpha << endl;

    //test Exercise 1
    cout << "Exercise 1" << endl;
    cout << "lcm(" + to_string(30) + "," + to_string(7) + ") = " << lcm(30,7) << endl;
    cout << "lcm(" + to_string(12) + "," + to_string(8) + ") = " << lcm(12,8) << endl;
    cout << "lcm(" + to_string(15) + "," + to_string(60) + ") = " << lcm(15,60) << endl;
    cout << "lcm(" + to_string(7) + "," + to_string(0) + ") = " << lcm(7,0) << endl;
    cout << "lcm(" + to_string(11) + "," + to_string(121) + ") = " << lcm(11,121) << endl;
    cout << "\n";

    //test Exercise 2
    cout << "Exercise 2" << endl;
    cout <<  "Decimal to Binary " << 25 << " = " <<  decimalToBinary(25) << endl;
    cout <<  "Decimal to Binary " << 10 << " = " <<  decimalToBinary(10) << endl;
    cout <<  "Decimal to Binary " << 7 << " = " <<  decimalToBinary(7) << endl;
    cout <<  "Decimal to Binary " << 120 << " = " <<  decimalToBinary(120) << endl;
    cout << "\n";

    //test Exercise 3
    cout << "Exercise 3" << endl;
    string test = "house";
    cout << "Before reverse: "<< test << endl;
    cout << "After reverse: "<< reverseString(test) << endl;
    cout << "\n";

    test = "home alone";
    cout << "Before reverse: "<< test << endl;
    cout << "After reverse: "<< reverseString(test) << endl;
    cout << "\n";

    //test Exercise 4
    cout << "Exercise 4" << endl;
    cout << "Sum of digits 1934: " << sumDigits(1934) << endl;
    cout << "Sum of digits 59: " << sumDigits(59) << endl;
    cout << "Sum of digits -4: " << sumDigits(-4) << endl;
    cout << "Sum of digits 7476: " << sumDigits(7476) << endl;
    cout << "\n";

    //test Exercise 5
    cout << "Exercise 5" << endl;
    cout << "Reverse of 8721: " << reverseNumber(8721) << endl;
    cout << "Reverse of 12: " << reverseNumber(12) << endl;
    cout << "Reverse of -1: " << reverseNumber(-1) << endl;
    cout << "Reverse of 987654321: " << reverseNumber(987654321) << endl;
    cout << "\n";

    //test Exercise 6
    cout << "Exercise 6" << endl;
    cout<< "s = " <<  " bab." << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("bab") << endl;
    cout<< "s = " << "abbb." << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("abbb") << endl;
    cout<< "s = " << "abbab." << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("abbab") << endl;
    cout<< "s = " << "bababbab." << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("bababbab") << endl;
    cout<< "s = " << "babbab." << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("babbab") << endl;
    cout << "\n";

}
