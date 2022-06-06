#include <iostream>
#include <vector>
#include <functional> // for std::placholders::_1
#include <algorithm> // for count_if


bool divisible(int num, int den)
{
    return ((num % den == 0) ? true : false);
}

int count_divisible_by_5(std::vector<int> &nums)
{
   int result = std::count_if(nums.begin(), nums.end(), std::bind(&divisible, std::placeholders::_1, 5));

   return result;
}

int main(int argc, char **argv)
{
    std::vector<int> nums = {5,10,15,20,25,30,35,40,45};
    std::cout<<count_divisible_by_5(nums)<<std::endl;
    return 0;
}