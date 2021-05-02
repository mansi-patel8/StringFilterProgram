/*
* Name: Mansi Patel
* Purpose: Purpose of this class is to create a generic string filter as specified below:
            -  Capitalize;
            -  CapitalizeFirstLetter;
            -  CapitalizeFirstLetterOfEveryWord;
            -  Obenglobish;
            -  ReverseString;
            -  ToSmall; and
            -  Randomize
           Each of these filters are implemented using abstract class.   
*/

#include <iostream>
#include <string>
#include <ctime>      
#include <cstdlib>

using namespace std;

const int N = 120;      //fixed size for temp char arrays

//Base Class
class Filter
{
protected:
    string _name;

public:
    Filter(const string& name) : _name(name) {}
    virtual ~Filter() {};

    virtual string apply(const string& input) = 0;  //pure virtual function

    string get_name() { return _name; }             //going to override this function in derived classes
};

/*
* Derived class Capitalize from Filter
* get_name() as override method to get the appropriate filter name
* apply() will covert all the lower case character to uppercase in the passed string
*/
class Capitalize : public Filter
{
public:
    string capitalizeStr;

    Capitalize() : Filter("Capitalize") {}

    string get_name()
    {
        return capitalizeStr;
    }

    string apply(const string& capitalizeStr)
    {
        char tempString[N];

        //for loop to cover all  characters in the string
        for (int i = 0; i < capitalizeStr.length(); i++)
        {
            if (capitalizeStr[i] >= 97 && capitalizeStr[i] <= 122 && (capitalizeStr[i] != ' '))
            {
                //check for digits
                if (capitalizeStr[i] >= '0' && capitalizeStr[i] <= '9')
                {
                    tempString[i] = capitalizeStr[i];
                }
                else
                {
                    tempString[i] = toupper(capitalizeStr[i]);
                }
            }
            else
            {
                tempString[i] = capitalizeStr[i];
            }
        }
        return tempString;
    }
};

/*
* Derived class CapitalizeFirstLetter from Filter
* get_name() as override method to get the appropriate filter name
* apply() will covert only the first lower case character to uppercase in the passed string
*/
class CapitalizeFirstLetter : public Filter
{
public:
    string capitalizeLtr;

    CapitalizeFirstLetter() : Filter("CapitalizeFirstLetter") {}

    string get_name()
    {
        return capitalizeLtr;
    }

    string apply(const string& capitalizeLtr)
    {
        char tempLetter[N];

        //for loop to cover all  characters in the string
        for (int i = 0; i < capitalizeLtr.length(); i++)
        {
            if (i == 0) //only first letter as capital
            {
                if (capitalizeLtr[i] >= 97 && capitalizeLtr[i] <= 122 && (capitalizeLtr[i] != ' '))
                {
                    //check for digits
                    if (capitalizeLtr[i] >= '0' && capitalizeLtr[i] <= '9')
                    {
                        tempLetter[i] = capitalizeLtr[i];
                    }
                    else
                    {
                        tempLetter[i] = toupper(capitalizeLtr[i]);
                    }
                }
                else
                {
                    tempLetter[i] = capitalizeLtr[i];
                }
            }
            else //rest of the letter as it is
            {
                tempLetter[i] = capitalizeLtr[i];
            }
        }
        return tempLetter;
    }
};

/*
* Derived class CapitalizeFirstLetterOfEveryWord from Filter
* get_name() as override method to get the appropriate filter name
* apply() will covert only the first lower case character of each word to uppercase in the passed string
*/
class CapitalizeFirstLetterOfEveryWord : public Filter
{
public:
    string capitalizeFirstLtrWord;

    CapitalizeFirstLetterOfEveryWord() : Filter("CapitalizeFirstLetterOfEveryWord") {}

    string get_name()
    {
        return capitalizeFirstLtrWord;
    }

    string apply(const string& capitalizeFirstLtrWord)
    {
        char tempWordLetter[N];

        //for loop to cover all  characters in the string
        for (int i = 0; i < capitalizeFirstLtrWord.length(); i++)
        {
            if (i == 0)             //first letter convert to uppercase always
            {
                tempWordLetter[i] = toupper(capitalizeFirstLtrWord[i]);
            }
            else if (capitalizeFirstLtrWord[i - 1] == ' ')  //check if the (character - 1) is space then convert to uppercase
            {
                tempWordLetter[i] = toupper(capitalizeFirstLtrWord[i]);
            }
            else
            {
                tempWordLetter[i] = capitalizeFirstLtrWord[i];
            }
        }

        return tempWordLetter;
    }
};

/*
* Derived class Obenglobish from Filter
* get_name() as override method to get the appropriate filter name
* apply() will add 'ob' to all the vowels in the passed string
*/
class Obenglobish : public Filter
{
public:
    string obenglobishStr;

    Obenglobish() : Filter("Obenglobish") {}

    string get_name()
    {
        return obenglobishStr;
    }

    string apply(const string& obenglobishStr)
    {
        string tempString;

        for (const char v : obenglobishStr)
        {
            if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u' || v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U')
            {
                tempString += "ob";
            }

            tempString += v;
        }
        return tempString;
    }
};

/*
* Derived class ReverseString from Filter
* get_name() as override method to get the appropriate filter name
* apply() will reverse the passed string
*/
class ReverseString : public Filter
{
public:
    string reverseStr;

    ReverseString() : Filter("ReverseString") {}

    string get_name()
    {
        return reverseStr;
    }

    string apply(const string& reverseStr)
    {

        string tempString;

        for (int i = reverseStr.length() - 1; i >= 0; i--)
        {
            tempString.push_back(reverseStr[i]);
        }

        return tempString;
    }
};

/*
* Derived class ToSmall from Filter
* get_name() as override method to get the appropriate filter name
* apply() will convert all the characters to lower case in the passed string
*/
class ToSmall : public Filter
{
public:
    string smallStr;

    ToSmall() : Filter("ToSmall") {}

    string get_name()
    {
        return smallStr;
    }

    string apply(const string& smallStr)
    {
        char tempString[N];

        //for loop to covert lowercase character to uppercase
        for (int i = 0; i < smallStr.length(); i++)
        {
            if (smallStr[i] >= 65 && smallStr[i] <= 90 && (smallStr[i] != ' '))
            {
                //check for digits
                if (smallStr[i] >= '0' && smallStr[i] <= '9')
                {
                    tempString[i] = smallStr[i];
                }
                else
                {
                    tempString[i] = towlower(smallStr[i]);
                }
            }
            else
            {
                tempString[i] = smallStr[i];
            }
        }

        return tempString;
    }
};

/*
* Derived class Randomize from Filter
* get_name() as override method to get the appropriate filter name
* apply() will randomize the postion of chacaters in the passed string including spaces
*/
class Randomize : public Filter
{
public:
    string randomizeStr;

    Randomize() : Filter("Randomize") {}

    string get_name()
    {
        return randomizeStr;
    }

    string apply(const string& randomizeStr)
    {
        srand(time(0));
        int strLength = randomizeStr.length();
        string tempStr = randomizeStr;

        //start the for loop from the last character and assign character form the string by random positions
        for (int i = strLength; i > 0; i--)
        {
            int position = rand() % strLength;         //random number for position index
            char tmpChar = randomizeStr[i - 1];         //get the char from string and assign it temp
            tempStr[i - 1] = randomizeStr[position];    //get the random position in the temp string and assign the temp char
            tempStr[position] = tmpChar;                //assign position to tempchar
            return tempStr;                             //return the string
        }
    }
};

int main()
{
    const int num_filters = 7;
    Filter* filters[num_filters];

    filters[0] = new Capitalize();
    filters[1] = new CapitalizeFirstLetter();
    filters[2] = new CapitalizeFirstLetterOfEveryWord();
    filters[3] = new Obenglobish();
    filters[4] = new ReverseString();
    filters[5] = new ToSmall();
    filters[6] = new Randomize();

    string input;
    cout << "Enter srring: ";
    getline(cin, input);

    cout << "Input string: " << input << endl;
    for (int i = 0; i < num_filters; ++i)
    {
        cout << "Filter name:  " << filters[i]->get_name() << endl;
        cout << "Output:       " << filters[i]->apply(input) << endl;
    }

    for (int i = 0; i < num_filters; ++i)
        delete filters[i];
}