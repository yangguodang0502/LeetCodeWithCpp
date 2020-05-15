#include <iostream>
#include <vector>
#include <string>
#include "BinaryTree/297/Codec.h"
#include "BinarySearch/658/FindClosestElements.h"

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

    Solution solution;
    vector<int> vec {1,1,1,10,10,10};
    solution.findClosestElements(vec, 1, 9);
    
    getchar();
}