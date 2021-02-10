#include <string>
#include <vector>

template <class T>
class ToolBox
{
public:
    std::string transVector2String(const std::vector<T>& InVec)
    {
        std::string retStr = "[";
        for (std::size_t index = 0; index < InVec.size(); index++)
        {
            retStr += std::to_string(InVec[index]);
            if (index != InVec.size() - 1)
            {
                retStr += ", ";
            }
        }
        retStr += "]";
        return retStr;
    }
};