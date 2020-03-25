#include <iostream>
#include <vector>
#include <string>
#include "BinaryTree/297/Codec.h"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    Codec codec;
    cout << codec.serialize(codec.deserialize("1,2,3,#,#,4,5"));
    cout << endl;
    
    getchar();
}