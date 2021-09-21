#include <iostream>
#include "Solution.h"

int main()
{

    //boolalpha可以让输出流将bool解析成为true或者false
    std::cout << std::boolalpha << Solution().isVaild("()[]{}") << std::endl;
    std::cout << std::boolalpha << Solution().isVaild("[](})") << std::endl;
    std::cout << std::boolalpha << Solution().isVaild("(]") << std::endl;

    return 0;
}