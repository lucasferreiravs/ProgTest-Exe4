/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

//Concatenate string with a char function
string Concat(string s, char c)
{
    return s += c; 
}

//Remove last character function
string Remove(string s)
{
    if (s != "")
        s.erase(s.end()-1);
    
    return s;
}

//Checking if a string is a lowercase and valid ascii[a..z] letter
bool CheckLower(string s)
{
    char letters[s.length() + 1];
 
    strcpy(letters, s.c_str());
 
    for (int i = 0; i < s.length(); i++)
    {   
        if (!islower(letters[i]))
        {
            return false;
            exit;
        }
    }
    
    return true;
}

//Checking if a string is lower alredy checks if its formed only by letters ascii[a..z]
bool CheckLetter(string s)
{
    char letters[s.length() + 1];
 
    strcpy(letters, s.c_str());
 
    for (int i = 0; i < s.length(); i++)
    {   
        if (!isalpha(letters[i]))
        {
            return false;
            exit;
        }
    }
    
    return true;
}

//Function to determine if it's possible to match two strings in a certain number os steps
bool ConcatRemove(string s, string t, int k)
{

    //Input validations
    //Checks if the inicial string is lowercase(also a valid letter) and if it's lower than 100 characters 
    if (!CheckLower(s) or (s.length()>100) or (s==""))
    {
        cout << "Invalid inicial string!" << endl;
        return false;
    }

    //Checks if the desired string is lowercase(also a valid letter) and if it's lower than 100 characters 
    if (!CheckLower(t) or (t.length()>100) or (t==""))
    {
        cout << "Invalid desired string!" << endl;
        return false;
    }

    //Checks if the operations number is between 1 and 100.
    if ((k < 1) or (k > 100))
    {
        cout << "Invalid number of operations!" << endl;
        return false;
    }

    //operations counter
    int ope = 0;

    //strings to char arrays to compare each character
    char s_char[s.length() + 1];
    char t_char[t.length() + 1];

    //Passing the strings to char arrays
    strcpy(s_char, s.c_str());
    strcpy(t_char, t.c_str()); 
    
    //Temporary string
    string temp = s;
       
    //Remove iterations
    for (int i = 0; i <= s.length()-1; i++)
    {
        //If a character is different, the program starts removing all the characters after it
        if (s_char[i] != t_char[i])
        {
             for (int r = s.length()-1; r >= i; r--)
             {
                temp = Remove(temp);
                ope++;
             } 
             
             break;
        }
        
    }

    //Concatenate iterations
    for (int i = 0; i <= t.length()-1; i++)
    {
        //If a character is different, it will append to the temp string
        if (t_char[i] != s_char[i])
        {
            temp = Concat(temp, t_char[i]);
            ope++;
        }
        
    }       
    
    //Print the result and the operations needed
    //cout << temp << endl;
    //cout << ope << endl;
       
    //return true if it's possible
    if ((t == temp) and (ope <= k))
        return true;
    else
        return false;
}

//Main class of the unit test
int main()
{

    //1º - Testing inicial string constraints
    cout << "1º - Test INICIAL string constraints: Uppercase" << endl;
    cout << "Inicial String: Blabla" << endl;
    cout << "Result of the function: " << ConcatRemove("Blabla","blablabcde",8) << endl;

    cout << endl;
    cout << endl;
   
    cout << "2º - Test INICIAL string constraints: null" << endl;
    cout << "Inicial String: ''" << endl;
    cout << "Result of the function: " << ConcatRemove("","blablabcde",8) << endl;
    
    cout << endl;
    cout << endl;
    
    cout << "3º - Test INICIAL string constraints: > 100 characters" << endl;
    cout << "Inicial String: abcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvw" << endl;
    cout << "Result of the function: " << ConcatRemove("abcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvw","blablabcde",8) << endl;

    cout << endl;
    cout << endl;


    //2º - Testing inicial string constraints
    cout << "4º - Test DESIRED string constraints: Uppercase" << endl;
    cout << "Desired String: Blabla" << endl;
    cout << "Result of the function: " << ConcatRemove("blabla","Blabla",8) << endl;

    cout << endl;
    cout << endl;

    cout << "5º - Test DESIRED string constraints: null" << endl;
    cout << "Desired String: ''" << endl;
    cout << "Result of the function: " << ConcatRemove("blabla","",8) << endl;
    
    cout << endl;
    cout << endl;

    cout << "6º - Test DESIRED string constraints: > 100 characters" << endl;
    cout << "Desired String: abcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvw" << endl;
    cout << "Result of the function: " << ConcatRemove("blabla","abcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvwxyzabcdefghijklmnopkrstuvw",8) << endl;

    cout << endl;
    cout << endl;

    //3º - Testing inicial string constraints
    cout << "7º - Test OPERATIONS number constraints: < 1" << endl;
    cout << "Operations: 0" << endl;
    cout << "Result of the function: " << ConcatRemove("blabla","blabla",0) << endl;

    cout << endl;
    cout << endl;

    cout << "8º - Test OPERATIONS number constraints: > 100" << endl;
    cout << "Operations: 101" << endl;
    cout << "Result of the function: " << ConcatRemove("blabla","blabla",101) << endl;
    
    cout << endl;
    cout << endl;
    
    cout << "-------------------------------------------------------------------";
    
    cout << endl;
    cout << endl;

    //4º - Testing the code functionality
    cout << "9º - Function test" << endl;
    cout << "Inicial string: blablablabla" << endl;
    cout << "Inicial string: blablabcde" << endl;
    cout << "Operations: 8" << endl;
    cout << "Expected result: YES" << endl;
    
    if (ConcatRemove("blablablabla","blablabcde",8))
        cout << "Result: YES"<< endl;
    else
        cout << "Result: NO"<< endl;

    cout << endl;
    cout << endl;        
        
    //5º - Testing the code functionality
    cout << "10º - Function test" << endl;
    cout << "Inicial string: ab" << endl;
    cout << "Inicial string: def" << endl;
    cout << "Operations: 9" << endl;
    cout << "Expected result: YES" << endl;
    
    if (ConcatRemove("ab","def",9))
        cout << "Result: YES"<< endl;
    else
        cout << "Result: NO"<< endl;  
        
    cout << endl;
    cout << endl;        
        
    //6º - Testing the code functionality
    cout << "11º - Function test" << endl;
    cout << "Inicial string: word" << endl;
    cout << "Inicial string: word" << endl;
    cout << "Operations: 1" << endl;
    cout << "Expected result: YES" << endl;
    
    if (ConcatRemove("word","word",1))
        cout << "Result: YES"<< endl;
    else
        cout << "Result: NO"<< endl;   
        
    cout << endl;
    cout << endl;       

    //7º - Testing the code functionality
    cout << "12º - Function test" << endl;
    cout << "Inicial string: program" << endl;
    cout << "Inicial string: java" << endl;
    cout << "Operations: 7" << endl;
    cout << "Expected result: NO" << endl;
    
    if (ConcatRemove("coding","java",7))
        cout << "Result: YES"<< endl;
    else
        cout << "Result: NO"<< endl;

    cout << endl;
    cout << endl;        
        
    //8º - Testing the code functionality
    cout << "13º - Function test" << endl;
    cout << "Inicial string: online" << endl;
    cout << "Inicial string: wifi" << endl;
    cout << "Operations: 9" << endl;
    cout << "Expected result: NO" << endl;
    
    if (ConcatRemove("online","wifi",9))
        cout << "Result: YES"<< endl;
    else
        cout << "Result: NO"<< endl;  
        
    cout << endl;
    cout << endl;        
        
    //9º - Testing the code functionality
    cout << "14º - Function test" << endl;
    cout << "Inicial string: language" << endl;
    cout << "Inicial string: lang" << endl;
    cout << "Operations: 3" << endl;
    cout << "Expected result: NO" << endl;
    
    if (ConcatRemove("language","lang",3))
        cout << "Result: YES"<< endl;
    else
        cout << "Result: NO"<< endl;   

    return 0;
}