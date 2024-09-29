### clsString Class Description
The `clsString` class is a comprehensive utility class designed to handle various string operations in C++. This class encapsulates a wide range of functionalities, from basic string manipulation to more complex operations like counting specific types of characters and altering the case of letters. Below is a detailed description of the class, its methods, and the Object-Oriented Programming (OOP) principles it employs.

#### Class Overview
The `clsString` class is defined with the following key components:
- **Private Member Variable**: `_value` of type `string` to store the string value.
- **Constructors**: Two constructors are provided, one default constructor that initializes `_value` to an empty string, and another that initializes `_value` with a given string.
- **Properties**: Getter and setter methods for the `_value` member variable, with a property declaration for ease of access.
- **Static Methods**: Various static methods to perform operations on strings passed as arguments.
- **Instance Methods**: Instance methods that operate on the `_value` member variable.

#### Constructors
- **Default Constructor**: Initializes `_value` to an empty string.
- **Parameterized Constructor**: Initializes `_value` with a given string.

#### Properties
- **value**: A property that allows getting and setting the `_value` member variable using the `getString` and `setString` methods.

#### Methods
1. **String Length**:
   - `static short length(string value)`: Returns the length of the given string.
   - `short length()`: Returns the length of the `_value` string.

2. **Word Count**:
   - `static short countEachWordInString(string userText)`: Counts the number of words in the given string.
   - `short countEachWordInString()`: Counts the number of words in the `_value` string.

3. **Letter Count**:
   - `enum enWhatToCount`: An enumeration to specify what type of characters to count (capital letters, small letters, digits, special letters, or all).
   - `static short countLetters(string userText, enWhatToCount whatToCount = enWhatToCount::all)`: Counts the specified type of characters in the given string.
   - `short countLetters(enWhatToCount whatToCount = enWhatToCount::all)`: Counts the specified type of characters in the `_value` string.

4. **Character Count**:
   - `static short letterCountInString(string userText, char userCharacter)`: Counts the occurrences of a specific character in the given string.
   - `short letterCountInString(char userCharacter)`: Counts the occurrences of a specific character in the `_value` string.
   - `static short ignoredCaseLetterCount(string userText, char userCharacter)`: Counts the occurrences of a specific character in the given string, ignoring case.
   - `short ignoredCaseLetterCount(char userCharacter)`: Counts the occurrences of a specific character in the `_value` string, ignoring case.

5. **Vowel Count**:
   - `static bool isVowel(char userCharacter)`: Checks if a character is a vowel.
   - `static short countVowels(string userText)`: Counts the number of vowels in the given string.
   - `short countVowels()`: Counts the number of vowels in the `_value` string.

6. **Case Conversion**:
   - `static string uppercaseFirstLetterOfEachWord(string userText)`: Converts the first letter of each word in the given string to uppercase.
   - `void uppercaseFirstLetterOfEachWord()`: Converts the first letter of each word in the `_value` string to uppercase.
   - `static string lowercaseFirstLetterOfEachWord(string userText)`: Converts the first letter of each word in the given string to lowercase.
   - `void lowercaseFirstLetterOfEachWord()`: Converts the first letter of each word in the `_value` string to lowercase.
   - `static string uppercaseAllLetters(string userText)`: Converts all letters in the given string to uppercase.
   - `void uppercaseAllLetters()`: Converts all letters in the `_value` string to uppercase.
   - `static string lowercaseAllLetters(string userText)`: Converts all letters in the given string to lowercase.
   - `void lowercaseAllLetters()`: Converts all letters in the `_value` string to lowercase.
   - `static char invertCharacterCase(char userCharacter)`: Inverts the case of a given character.
   - `static string invertAllLettersCase(string userText)`: Inverts the case of all letters in the given string.
   - `void invertAllLettersCase()`: Inverts the case of all letters in the `_value` string.

7. **Punctuation Removal**:
   - `static string removePunctuations(string userText)`: Removes all punctuation characters from the given string.
   - `void removePunctuations()`: Removes all punctuation characters from the `_value` string.

8. **String Analysis**:
   - `static void getFirstLetter(string userText)`: Prints the first letter of each word in the given string.
   - `void getFirstLetter()`: Prints the first letter of each word in the `_value` string.
   - `static string getAllVowelsInString(string userText)`: Returns a string containing all vowels in the given string.
   - `string getAllVowelsInString()`: Returns a string containing all vowels in the `_value` string.
   - `static void printStringLetters(string text)`: Prints all characters in the given string.
   - `void printStringLetters()`: Prints all characters in the `_value` string.
   - `static void printEachWordInString(string userText)`: Prints each word in the given string.
   - `void printEachWordInString()`: Prints each word in the `_value` string.

9. **String Split and Join**:
   - `static vector<string> split(string userText, string delimiter)`: Splits the given string into a vector of strings based on the delimiter.
   - `vector<string> split(string delimiter)`: Splits the `_value` string into a vector of strings based on the delimiter.
   - `static string join(string names[], string delimiter)`: Joins an array of strings into a single string with the delimiter.
   - `static string join(vector<string> names, string delimiter)`: Joins a vector of strings into a single string with the delimiter.

10. **Vector Printing**:
    - `static void printVector(vector<string> text)`: Prints all elements in the given vector.
    - `void printVector()`: Prints all elements in the vector obtained by splitting the `_value` string.

11. **String Trimming**:
    - `static string trimLeft(string userText)`: Trims leading non-alphabetic characters from the given string.
    - `void trimLeft()`: Trims leading non-alphabetic characters from the `_value` string.
    - `static string trimRight(string userText)`: Trims trailing non-alphabetic characters from the given string.
    - `void trimRight()`: Trims trailing non-alphabetic characters from the `_value` string.
    - `static string trim(string& userText)`: Trims leading and trailing non-alphabetic characters from the given string.
    - `void trim()`: Trims leading and trailing non-alphabetic characters from the `_value` string.

12. **String Reversal and Replacement**:
    - `static string reversedWords(string userText)`: Reverses the order of words in the given string.
    - `void reversedWords()`: Reverses the order of words in the `_value` string.
    - `static string replaceWordsInString(string userText, string toBeReplaced, string alternative, bool matchCase = true)`: Replaces occurrences of a word in the given string with an alternative word.
    - `void replaceWordsInString(string toBeReplaced, string alternative, bool matchCase = true)`: Replaces occurrences of a word in the `_value` string with an alternative word.
