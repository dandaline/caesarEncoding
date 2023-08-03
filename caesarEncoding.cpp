#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <fstream>

// encode text
char rotChar(char c, int n);

// return encoded text
std::string rotString(std::string &text, int n);

char rotChar(char c, int n)
{
    if ('A' <= c && c <= 'Z')
    {
        c = c - 'A';
        c = (c + n) % 26; // % in C++ ((x mod y) + y) mod y: (4 mod 26) + 26) mod 26) = 4
        c = c + 'A';
    }
    else if ('a' <= c && c <= 'z')
    {
        c = c - 'a';
        c = (c + n) % 26;
        c = c + 'a';
    }
    return c;
}

std::string rotString(std::string &text, int n)
{
    std::string out = "";
    int size = text.size();
    for (int i = 0; i < text.size(); i++)
    {
        char c = text.at(i);
        c = rotChar(c, n);
        out.push_back(c);
    }
    return (out);
}

int main()
{
    std::string text;
    std::cout << "Enter your text to be Caesar-encoded (ASCII alphabet, special characters will not be encoded): \n";
    std::getline(std::cin, text);
    int n = 0;
    std::cout << "Encode by how many digits? (ASCII alphabet: modulo 26): \n";
    std::cin >> n;

    // print encoded text to terminal
    std::cout << rotString(text, n) << std::endl;
}
