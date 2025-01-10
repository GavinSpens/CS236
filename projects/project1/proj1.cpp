#include "token.h"
#include "scanner.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    string filename = argv[1];

    ifstream in;
    in.open(filename);
    stringstream ss;
    ss << in.rdbuf();
    string input = ss.str();
    in.close();

    Scanner scanner(input);
    int total_tokens = 0;
    while (true)
    {
        Token token = scanner.scanToken();
        cout << token.toString() << endl;
        total_tokens++;
        if (token.getType() == END or token.getType() == UNDEFINED)
        {
            break;
        }
    }
    cout << "Total Tokens = " << total_tokens << endl;
}