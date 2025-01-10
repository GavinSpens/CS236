#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int count_chars(int argc, char *argv[], string input)
{
    int lines = 0;
    int whitespace = 0;
    int digits = 0;
    int letters = 0;

    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];

        if (isdigit(c))
        {
            digits++;
        }
        else if (isalpha(c))
        {
            letters++;
        }
        else if (c == '\n')
        {
            lines++;
            whitespace++;
        }
        else if (isspace(c))
        {
            whitespace++;
        }
    }

    cout << "chars: " << input.length() << endl;
    cout << "lines: " << lines << endl;
    cout << "wspace: " << whitespace << endl;
    cout << "digits: " << digits << endl;
    cout << "letters: " << letters << endl;

    return 0;
}

int print_input(int argc, char *argv[], string input)
{
    cout << "*** Start of Input ***" << endl;
    cout << input << endl;
    cout << "*** End of Input ***" << endl;

    return 0;
}

int main(int argc, char *argv[])
{
    char *filename = argv[1];

    ifstream in;
    in.open(filename);
    stringstream ss;
    ss << in.rdbuf();
    string input = ss.str();
    in.close();

    return count_chars(argc, argv, input);
}