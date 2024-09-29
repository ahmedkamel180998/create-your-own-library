#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _value;
public:
	// constructors
	clsString()
	{
		_value = "";
	}
	clsString(string value)
	{
		_value = value;
	}
	// set and get properties
	void setString(string value)
	{
		_value = value;
	}
	string getString()
	{
		return _value;
	}
	__declspec(property(get = getString, put = setString)) string value;

	// string count properties
	static short length(string value)
	{
		return value.length();
	}
	short length()
	{
		return length(value);
	}

	static short countEachWordInString(string userText)
	{
		string delimiter = " ";
		short delimiterPosition = 0, counter = 0;

		while ((delimiterPosition = userText.find(delimiter)) != userText.npos)
		{
			counter++;
			userText.erase(0, delimiterPosition + delimiter.length());
		}
		if (userText != "")
			counter++;
		return counter;
	}
	short countEachWordInString()
	{
		return countEachWordInString(value);
	}

	enum enWhatToCount
	{
		capitalLetters = 1,
		smallLetters = 2,
		digits = 3,
		specialLetters = 4,
		all = 5
	};
	static short countLetters(string userText, enWhatToCount whatToCount = enWhatToCount::all)
	{
		short counter = 0;

		if (whatToCount == enWhatToCount::all)
			return userText.length();

		for (short i = 0; i < userText.length(); i++)
		{
			if (whatToCount == enWhatToCount::capitalLetters && isupper(userText[i]))
				counter++;
			else if (whatToCount == enWhatToCount::smallLetters && islower(userText[i]))
				counter++;
			else if (whatToCount == enWhatToCount::digits && isdigit(userText[i]))
				counter++;
			else if (whatToCount == enWhatToCount::specialLetters && ispunct(userText[i]))
				counter++;
		}
		return counter;
	}
	short countLetters(enWhatToCount whatToCount = enWhatToCount::all)
	{
		return countLetters(value, whatToCount);
	}

	static short letterCountInString(string userText, char userCharacter)
	{
		short counter = 0;
		for (short i = 0; i < userText.length(); i++)
		{
			if (userCharacter == userText[i])
				counter++;
		}
		return counter;
	}
	short letterCountInString(char userCharacter) // match case
	{
		return letterCountInString(value, userCharacter);
	}

	static short ignoredCaseLetterCount(string userText, char userCharacter)
	{
		short counter = letterCountInString(userText, userCharacter);
		userCharacter = invertCharacterCase(userCharacter);
		counter += letterCountInString(userText, userCharacter);
		return counter;
	}
	short ignoredCaseLetterCount(char userCharacter) // ignore match case
	{
		return ignoredCaseLetterCount(value, userCharacter);
	}

	static bool isVowel(char userCharacter)
	{
		userCharacter = tolower(userCharacter);
		return userCharacter == 'a' || userCharacter == 'e' || userCharacter == 'i' || userCharacter == 'o' || userCharacter == 'u';
	}

	static short countVowels(string userText)
	{
		short counter = 0;
		for (short i = 0; i < userText.length(); i++)
		{
			if (isVowel(userText[i]))
				counter++;
		}
		return counter;
	}
	short countVowels()
	{
		return countVowels(value);
	}

	// change character case
	static string uppercaseFirstLetterOfEachWord(string userText)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < userText.length(); i++)
		{
			if (userText[i] != ' ' && isFirstLetter)
			{
				if (userText[i] >= 97 && userText[i] <= 122)
					userText[i] = toupper(userText[i]);
			}
			isFirstLetter = userText[i] == ' ' ? true : false;
		}
		return userText;
	}
	void uppercaseFirstLetterOfEachWord()
	{
		value = uppercaseFirstLetterOfEachWord(value);
	}

	static string lowercaseFirstLetterOfEachWord(string userText)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < userText.length(); i++)
		{
			if (userText[i] != ' ' && isFirstLetter)
			{
				if (isupper(userText[i]))
					userText[i] = tolower(userText[i]);
			}
			isFirstLetter = userText[i] == ' ' ? true : false;
		}
		return userText;
	}
	void lowercaseFirstLetterOfEachWord()
	{
		value = lowercaseFirstLetterOfEachWord(_value);
	}

	static string uppercaseAllLetters(string userText)
	{
		for (int i = 0; i < userText.length(); i++)
		{
			userText[i] = toupper(userText[i]);
		}
		return userText;
	}
	void uppercaseAllLetters()
	{
		value = uppercaseAllLetters(value);
	}

	static string lowercaseAllLetters(string userText)
	{
		for (int i = 0; i < userText.length(); i++)
		{
			userText[i] = tolower(userText[i]);
		}
		return userText;
	}
	void lowercaseAllLetters()
	{
		value = lowercaseAllLetters(value);
	}

	static char invertCharacterCase(char userCharacter)
	{
		return isupper(userCharacter) ? tolower(userCharacter) : toupper(userCharacter);
	}

	static string invertAllLettersCase(string userText)
	{
		for (int i = 0; i < userText.length(); i++)
		{
			//userText[i] = isupper(userText[i]) ? tolower(userText[i]) : toupper(userText[i]);
			userText[i] = invertCharacterCase(userText[i]);
		}
		return userText;
	}
	void invertAllLettersCase()
	{
		value = invertAllLettersCase(value);
	}

	static string removePunctuations(string userText)
	{
		for (short i = 0; i < userText.length(); i++)
		{
			if (ispunct(userText[i]))
				userText.erase(i, 1);
		}
		return userText;
	}
	void removePunctuations()
	{
		value = removePunctuations(value);
	}

	// string specific get functions
	static void getFirstLetter(string userText)
	{
		cout << "First Letter Of This String\n[ ";
		for (int i = 0; i < userText.length(); i++)
		{
			if (i == 0)
				cout << userText[i] << ", ";
			if (userText[i] == char(32))
				cout << userText[i + 1] << ", ";
		}
		cout << "]" << endl;
	}
	void getFirstLetter()
	{
		getFirstLetter(value);
	}

	static string getAllVowelsInString(string userText)
	{
		string vowelsInString = "";
		for (short i = 0; i < userText.length(); i++)
		{
			if (isVowel(userText[i]))
				vowelsInString.push_back(userText[i]);
		}
		return vowelsInString;
	}
	string getAllVowelsInString()
	{
		return getAllVowelsInString(value);
	}

	static void printStringLetters(string text)
	{
		cout << "\nVowel Letter in String are : \n[";
		for (short i = 0; i < text.length(); i++)
		{
			if (i == text.length() - 1)
				cout << text[i];
			else
				cout << text[i] << ", ";
		}
		cout << "]" << endl;
	}
	void printStringLetters()
	{
		printStringLetters(getAllVowelsInString(value));
	}

	static void printEachWordInString(string userText)
	{
		string delimiter = " ", stringWord;
		short delimiterPosition = 0;

		cout << "Your String Words Are :" << endl;
		while ((delimiterPosition = userText.find(delimiter)) != userText.npos)
		{
			stringWord = userText.substr(0, delimiterPosition);
			if (stringWord != "")
				cout << stringWord << endl;
			userText.erase(0, delimiterPosition + delimiter.length());
		}
		if (userText != "")
			cout << userText << endl;
	}
	void printEachWordInString()
	{
		printEachWordInString(value);
	}

	// string split and join
	static vector<string> split(string userText, string delimiter)
	{
		vector <string> splitWords;
		string stringWord;
		short delimiterPosition = 0;

		while ((delimiterPosition = userText.find(delimiter)) != userText.npos)
		{
			stringWord = userText.substr(0, delimiterPosition);
			if (stringWord != "")
				splitWords.push_back(stringWord);
			userText.erase(0, delimiterPosition + delimiter.length());
		}
		if (userText != "")
		{
			splitWords.push_back(userText);
		}
		return splitWords;
	}
	vector<string> split(string delimiter)
	{
		return split(value, delimiter);
	}

	static string join(string names[], string delimiter)
	{
		string text = "";
		for (short i = 0; i < names->length(); i++)
		{
			if (i == names->length() - 1)
				text += names[i];
			else
				text = text + names[i] + delimiter;
		}
		return text;
	}
	static string join(vector<string> names, string delimiter)
	{
		string text = "";
		for (short i = 0; i < names.size(); i++)
		{
			if (i == names.size() - 1)
				text += names[i];
			else
				text = text + names[i] + delimiter;
		}
		return text;
	}

	static void printVector(vector<string> text)
	{
		cout << "\nTokens = " << text.size() << endl;
		for (string& element : text)
		{
			cout << element << endl;
		}
	}
	void printVector()
	{
		printVector(split(" "));
	}

	// trim functions
	static string trimLeft(string userText)
	{
		for (short i = 0; i < userText.length(); i++)
		{
			if (!isalpha(userText[i]))
			{
				userText.erase(0, i + 1);
				return userText;
			}
		}
	}
	void trimLeft()
	{
		value = trimLeft(value);
	}

	static string trimRight(string userText)
	{
		for (short i = userText.length() - 1; i > 0; i--)
		{
			if (!isalpha(userText[i]))
			{
				userText.erase(i, userText.length() - i);
				return userText;
			}
		}
	}
	void trimRight()
	{
		value = trimRight(value);
	}

	static string trim(string& userText)
	{
		return trimRight(trimLeft(userText));
	}
	void trim()
	{
		value = trim(_value);
	}

	// string replace words
	static string reversedWords(string userText)
	{
		vector<string> splitWords;
		for (short i = userText.length() - 1; i > 0; i--)
		{
			if (userText[i] == ' ')
			{
				splitWords.push_back(userText.substr(i + 1, userText.length() - i - 1));
				userText.erase(i, userText.length() - i);
			}
		}
		if (userText != "")
			splitWords.push_back(userText);
		return join(splitWords, " ");
	}
	void reversedWords()
	{
		value = reversedWords(value);
	}

	static string replaceWordsInString(string userText, string toBeReplaced, string alternative, bool matchCase = true)
	{
		short wordToBeReplacedPosition = 0;
		if (matchCase)
		{
			wordToBeReplacedPosition = userText.find(toBeReplaced);
			while (wordToBeReplacedPosition != userText.npos)
			{
				userText.erase(wordToBeReplacedPosition, toBeReplaced.length());
				userText.insert(wordToBeReplacedPosition, alternative);
				wordToBeReplacedPosition = userText.find(toBeReplaced);
			}
			return userText;
		}
		else
		{
			wordToBeReplacedPosition = lowercaseAllLetters(userText).find(lowercaseAllLetters(toBeReplaced));
			while (wordToBeReplacedPosition != userText.npos)
			{
				userText.erase(wordToBeReplacedPosition, toBeReplaced.length());
				userText.insert(wordToBeReplacedPosition, alternative);
				wordToBeReplacedPosition = lowercaseAllLetters(userText).find(lowercaseAllLetters(toBeReplaced));
			}
			return userText;
		}
	}
	void replaceWordsInString(string toBeReplaced, string alternative, bool matchCase = true)
	{
		value = replaceWordsInString(value, toBeReplaced, alternative, matchCase);
	}
};