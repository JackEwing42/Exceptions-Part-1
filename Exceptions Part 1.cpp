// Jack Ewing
// CIS 1202
// August 2nd, 2025

#include <iostream>
#include <cctype>
using namespace std;
char character(char start, int offset);

class invalidCharacterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: not a letter.";
    }
};

class invalidRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Resulting character is out of letter range.";
    }
};

int main()
{
    char start;
    int offset;
    cout << "Please enter the letter you would like to start with and how much you would like to offset it by " << endl;
    try {
        for (int i = 0; i < 4; i++)
        {
            cout << "Test " << i + 1 << ": " << endl;
            cout << "Letter: "; cin >> start;
            cout << "Offset: "; cin >> offset;
            cout << endl << character(start, offset) << endl;
        }
    }
    catch (const invalidCharacterException& e) {
        cerr << "Character Error: " << e.what() << endl;
    }
    catch (const invalidRangeException& e) {
        cerr << "Range Error: " << e.what() << endl;
    }
}

char character(char start, int offset) {
    if (!isalpha(start))
        throw invalidCharacterException();

    char result = start + offset;

    if (islower(start)) {
        if (result < 'a' || result > 'z')
            throw invalidRangeException();
    }
    else if (isupper(start)) {
        if (result < 'A' || result > 'Z')
            throw invalidRangeException();
    }

    return result;
}