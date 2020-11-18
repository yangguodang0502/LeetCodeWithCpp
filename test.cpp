#include <iostream>
#include <vector>
#include <string>
#include "BinaryTree/297/Codec.h"
#include "labuladong/188/maxProfit.h"

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
    vector<int> nums {3,2,6,5,0,3};
    int ret = solution.maxProfit(2, nums);
    
    getchar();
}