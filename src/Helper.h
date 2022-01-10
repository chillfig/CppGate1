#include<vector>

using namespace std;

template <typename T>

// Helper function which returns true if given element is found in the given vector
bool contains(vector<T> vec, const T & elem)
{
    bool result = false;
    for (auto & x : vec)
    {
        if (x == elem)
        {
            result = true;
            break;
        }
    }
    return result;
}