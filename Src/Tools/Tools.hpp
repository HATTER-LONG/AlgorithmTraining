#include <catch2/catch_all.hpp>
#include <string>
#include <vector>
using namespace std;
using VecInt = vector<int>;
template <class T> class ToolBox {
public:
    std::string trans_vector2_string(const std::vector<T>& in_vec) {
        std::string ret_str = "[";
        for(std::size_t index = 0; index < in_vec.size(); index++) {
            ret_str += std::to_string(in_vec[index]);
            if(index != in_vec.size() - 1) {
                ret_str += ", ";
            }
        }
        ret_str += "]";
        return ret_str;
    }
};
