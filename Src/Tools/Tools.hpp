#include <catch2/catch.hpp>
#include <glog/logging.h>
#include <string>
#include <vector>
using namespace std;
using VecInt = vector<int>;
template <class T>
class ToolBox
{
public:
    std::string transVector2String(const std::vector<T>& inVec)
    {
        std::string retStr = "[";
        for (std::size_t index = 0; index < inVec.size(); index++)
        {
            retStr += std::to_string(inVec[index]);
            if (index != inVec.size() - 1)
            {
                retStr += ", ";
            }
        }
        retStr += "]";
        return retStr;
    }
};
