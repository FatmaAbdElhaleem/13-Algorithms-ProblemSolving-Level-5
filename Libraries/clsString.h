#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
    string _value;

    enum whatToCount
    {
        CapitalLetters,
        SmallLetters
    };

public:
    clsString()
    {
        _value = "";
    }
    clsString(string value)
    {
        _value = value;
    }

    void setValue(string value)
    {
        _value = value;
    }

    string value()
    {
        return _value;
    }

    static void getFirstLettersOfString(string sentence)
    {
        cout << "\nThe First letters of this string:\n";
        bool first = true;
        for (int i = 0; i < sentence.length(); i++)
        {
            if (first && sentence[i] != ' ')
                cout << sentence[i] << endl;
            first = (sentence[i] == ' ');
        }
    }
    void getFirstLettersOfString()
    {
        return getFirstLettersOfString(_value);
    }

    static string upperFirstLetters(string sentence)
    {
        bool first = true;
        for (int i = 0; i < sentence.length(); i++)
        {
            if (first && sentence[i] != ' ')
                sentence[i] = toupper(sentence[i]);
            first = (sentence[i] == ' ');
        }
        return sentence;
    }

    void upperFirstLetters()
    {
        _value = upperFirstLetters(_value);
    }

    static string lowerFirstLettersOfString(string sentence)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < sentence.size(); ++i)
        {
            if (isFirstLetter && sentence[i] != ' ')
                sentence[i] = tolower(sentence[i]);
            isFirstLetter = (sentence[i] == ' ');
        }
        return sentence;
    }
    void lowerFirstLettersOfString()
    {
        _value = lowerFirstLettersOfString(_value);
    }

    static string toUpper(string sentence)
    {
        for (int i = 0; i < sentence.size(); ++i)
        {
            sentence[i] = toupper(sentence[i]);
        }
        return sentence;
    }

    static string toLower(string sentence)
    {
        for (int i = 0; i < sentence.size(); ++i)
        {
            sentence[i] = tolower(sentence[i]);
        }
        return sentence;
    }

    void toUpper()
    {
        _value = toUpper(_value);
    }

    void toLower()
    {
        _value = toLower(_value);
    }

    static char invertCharCase(char character)
    {
        return isupper(character) ? tolower(character) : toupper(character);
    }

    static string invertLettersCase(string str)
    {
        string invertedStr;
        for (int i = 0; i < str.length(); i++)
        {
            invertedStr += invertCharCase(str[i]);
        }
        return invertedStr;
    }

    void invertLettersCase()
    {
        _value = invertLettersCase(_value);
    }

    static int countLetters(string str, whatToCount lettersType)
    {
        int counter = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (lettersType == whatToCount::CapitalLetters && isupper(str[i]))
                counter++;
            else if (lettersType == whatToCount::SmallLetters && islower(str[i]))
                counter++;
        }
        return counter;
    }

    int countCapitalLetters()
    {
        return countLetters(_value, whatToCount::CapitalLetters);
    }
    int countSmallLetters()
    {
        return countLetters(_value, whatToCount::SmallLetters);
    }

    static short countCharTimes(char ch, string str, bool caseSensitive = true)
    {
        short count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (caseSensitive)
            {
                if (str[i] == ch)
                    count++;
            }
            else
            {
                if (tolower(str[i]) == tolower(ch))
                    count++;
            }
        }
        return count;
    }
    short countSpecificLetter(char ch, bool caseSensitive = true)
    {
        return countCharTimes(ch, _value, caseSensitive);
    }

    static bool isVowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    static short countVowels(string str)
    {
        short count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (isVowel(str[i]))
                count++;
        }
        return count;
    }

    short countVowels()
    {
        return countVowels(_value);
    }

    static void printAllVowels(string str)
    {
        cout << "Vowels in string are: ";
        for (int i = 0; i < str.length(); i++)
        {
            if (isVowel(str[i]))
                cout << str[i] << " ";
        }
    }

    void printAllVowels()
    {
        return printAllVowels(_value);
    }

    static vector<string> split(string str, string delimiter)
    {
        int pos = 0;
        vector<string> vWords;

        while ((pos = str.find(delimiter)) != std::string::npos)
        {
            if (str.substr(0, pos) != "")
                vWords.push_back(str.substr(0, pos));
            str.erase(0, pos + delimiter.length());
        }
        if (!str.empty())
            vWords.push_back(str);

        return vWords;
    }

    vector<string> split(string delimiter)
    {
        return split(delimiter);
    }

    static string trimLeft(string str)
    {
        int i = 0;
        while (i < str.length() && str.at(i) == ' ')
        {
            i++;
        }

        str.erase(0, i);
        return str;
    }

    void trimLeft()
    {
        _value = trimLeft(_value);
    }

    static string trimRight(string str)
    {
        int i = str.length() - 1;
        while (i >= 0 && str.at(i) == ' ')
        {
            i--;
        }

        str.erase(i + 1, str.length() - (i + 1));
        return str;
    }

    void trimRight()
    {
        _value = trimRight(_value);
    }

    static string trim(string str)
    {
        return trimLeft(trimRight(str));
    }

    void trim()
    {
        _value = trim(_value);
    }

    static string joinVector(vector<string> v, string separator)
    {
        if (v.empty())
            return "";
        string str = "";
        for (string name : v)
        {
            str.append(name);
            str.append(separator);
        }
        return str.substr(0, str.length() - separator.length());
    }

    static string joinString(string arr[10], int length, string separator)
    {
        string str = arr[0];
        for (int i = 1; i < length; i++)
        {
            str = str + separator + arr[i];
        }
        return str;
    }

    static string reverseWords(string str)
    {
        vector<string> vString = split(str, " ");
        string reversedStr = "";

        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            iter--;
            reversedStr += *iter + " ";
        }

        return reversedStr.substr(0, reversedStr.length() - 1);
    }
    void reverseWords()
    {
        _value = reverseWords(_value);
    }

    static string replaceWord(string str, string strToReplace, string replaceTo)
    {
        short pos = str.find(strToReplace);
        while (pos != std::string::npos)
        {
            str = str.replace(pos, strToReplace.length(), replaceTo);
            pos = str.find(strToReplace, pos + replaceTo.length());
        }
        return str;
    }

    string replaceWordUsing(string strToReplace, string replaceTo)
    {
        return replaceWord(_value, strToReplace, replaceTo);
    }

    static string removePunct(string str)
    {
        string s2 = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (!ispunct(str[i]))
            {
                s2 = s2 + str[i];
            }
        }
        return s2;
    }

    void removePunct()
    {
        _value = removePunct(_value);
    }
};