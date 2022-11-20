#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

// solution to 3Sum leetcode problem using hashmap.

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         vector<vector<int>> result;
//         map<int, int> m;
//         set<vector<int>> s;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             m[nums[i]]= i;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 int sum = nums[i] + nums[j];
//                 if (m.find(-sum) != m.end() && m[-sum] != i && m[-sum] != j)
//                 {
//                     vector<int> temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(-sum);
//                     sort(temp.begin(), temp.end());
//                     s.insert(temp);
//                 }
//             }
//         }
//         for (auto i : s)
//         {
//             result.push_back(i);
//         }
//         return result;
//     }
// };

//optimized solution using two pointer approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            //to avoid duplicate triplets
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            //two pointer approach
            while (left < right)
            {
                //if sum is less than target then we need to increase the sum
                int sum = nums[left] + nums[right];
                //to avoid duplicate triplets
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    //if sum is equal to target then we have found the triplet
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    //check if the next left element is same as the current element
                    while (left < right && nums[left] == temp[1])
                    {
                        left++;
                    }
                    //check if the next right element is same as the current element
                    while (left < right && nums[right] == temp[2])
                    {
                        right--;
                    }
                }
            }
            //check if the next base (used as negated traget)element is same as the current element
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> sol = s.threeSum(nums);
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].size(); j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
