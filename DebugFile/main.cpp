#include "DebugFile.hpp"
#include <iostream>

using namespace std;

int main()
{
    // Usage

    cout << std::fixed << DebugFile::GetValue("testattr") << endl;
    cout << std::fixed << DebugFile::GetInt("testattr") << endl;
    cout << std::fixed << DebugFile::GetFloat("testattr") << endl;
    cout << std::fixed << DebugFile::GetFloat("var2") << endl;
    cout << std::fixed << DebugFile::GetString("var2") << endl;
    cout << std::fixed << DebugFile::GetInt("var3") << endl;
    std::getchar();
    return 0;
}