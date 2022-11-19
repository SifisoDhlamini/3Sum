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
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
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
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    while (left < right && nums[left] == temp[1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == temp[2])
                    {
                        right--;
                    }
                }
            }
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