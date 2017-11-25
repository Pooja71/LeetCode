/*************
Two sum problem without unique solution.
The pairs are to be returned such that the first index is smaller than
the second index.
Indices should not be zero based.
**************/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

using HashMap = unordered_map<int, int>;

// We first sort the input array, and then use the start and end pointers 
// Time = O(nlogn) Space = O(n) -> so create the sorted array.
vector<pair<int, int>> twoSumWithSort(vector<int> nums, int target)  {
  vector<pair<int, int>> retVal;
  vector<pair<int, int>> sortedArr;
  int n = nums.size();
  for(int i = 0; i < n; i++)
    sortedArr.emplace_back(pair<int, int>(nums[i], i));
  sort(sortedArr.begin(), sortedArr.end());
  int start = 0;
  int end = n-1;
  while(start < end)  {
    int sum = sortedArr[start].first + sortedArr[end].first;
    if(sum < target)
      start++;
    else if(sum > target)
      end--;
    else  {
      
      retVal.emplace_back((sortedArr[start].second < sortedArr[end].second) ? pair<int, int>(sortedArr[start].second+1, sortedArr[end].second+1) 
                                                                            : pair<int, int>(sortedArr[end].second+1, sortedArr[start].second+1));
      start++;
      end--;
    }
  }
  return retVal;
}

// We use a Hashmap to save the values encountered with their index.
// During each iteration, search the map for the target diff.
// Time = O(n) Space = O(n)
vector<pair<int, int>> twoSumWitHash(const vector<int> &nums, int target)  {
  vector<pair<int, int>> retVal;
  HashMap map;
  int n = nums.size();
  for(int i = 0; i < n; i++)  {
    int diff = target - nums[i];
    HashMap::iterator it = map.find(diff);
    if(it != map.end())  {
      retVal.emplace_back(pair<int, int>(it->second+1, i+1));
    }
    else  {
      map[nums[i]] = i;
    }
  }
  return retVal;
}

int main() {
  
  /****** Testcase 1 ******/
  vector<int> nums = {5, 3, 1, 2, 7, 4, 6};
  vector<pair<int, int>> result1 = twoSumWithSort(nums, 9);
  vector<pair<int, int>> result2 = twoSumWitHash(nums, 9);
  cout << "Using sort: " << endl;
  for(auto np : result1)  {
    cout << np.first << " , " << np.second << endl;
  }
  
  cout << endl << "Using hash: " << endl;
  for(auto np : result2)  {
    cout << np.first << " , " << np.second << endl;
  }
  return 0;
}

