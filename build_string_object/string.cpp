#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* data;

public:
    MyString() : data(nullptr) {}

    void input(const char* s) {
        if (data) {
            delete[] data;
        }
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    const char* output() {
        return data;
    }

    void capitalizeFirstLetterOfWords() {
        if (data) {
            bool newWord = true;
            for (size_t i = 0; i < strlen(data); i++) {
                if (isalpha(data[i])) {
                    if (newWord) {
                        data[i] = toupper(data[i]);
                        newWord = false;
                    } else {
                        data[i] = tolower(data[i]);
                    }
                } else {
                    newWord = true;
                }
            }
        }
    }

    ~MyString() {
        if (data) {
            delete[] data;
        }
    }
};

int main() {
    MyString myStr;


    char userInput[256];
    cin.getline(userInput, sizeof(userInput));

    myStr.input(userInput);
    cout << "Chuoi ban dau: " << myStr.output() << endl;

    myStr.capitalizeFirstLetterOfWords();
    cout << "Chuoi sau khi chuan hoa: " << myStr.output() << endl;

    return 0;
}
