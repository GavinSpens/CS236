#include "token.h"
#include "scanner.h"
using namespace std;

int main()
{
    Scanner s = Scanner("  ,  ,  ");
    Token t = s.scanToken();
    cout << t.toString() << endl;
}