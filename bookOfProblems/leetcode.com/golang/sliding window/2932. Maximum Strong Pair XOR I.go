func maximumStrongPairXor(nums []int) int {
	maxXOR := 0

	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			x, y := nums[i], nums[j]

			if math.Abs(float64(x-y)) <= float64(min(x, y)) {
				maxXOR = max(maxXOR, x^y)
			}
		}
	}

	return maxXOR
}

/////////////

func maximumStrongPairXor(nums []int) int {
	maxXOR := 0

	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			x, y := nums[i], nums[j]

			if abs(x-y) <= min(x, y) {
				maxXOR = max(maxXOR, x^y)
			}
		}
	}

	return maxXOR
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

////////////////////////////////////////////////////////////////////////////////

func maximumStrongPairXor(nums []int) int {
	ans := math.MinInt32
	sort.Ints(nums)

	for l, r := 0, 0; r < len(nums); r++ {
		for r < len(nums) && abs(nums[l]-nums[r]) <= min(nums[l], nums[r]) {
			ans = max(ans, nums[l]^nums[r])
			r++
		}
		l++
		r = l - 1
	}
    return ans
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}


////////////////////////////////////////////////////////////////////////////////

C++
class Solution {
	public:
		int maximumStrongPairXor(vector<int>& nums) {
			int maxi = INT_MIN; int left = 0;
	
			sort(nums.begin(),nums.end());
	
			for(int right=0;right<nums.size()-1;right++){
			  while(right<nums.size() &&
			  min(nums[left],nums[right]) >= abs(nums[left]-nums[right])){
					maxi = max(maxi , (nums[left]^nums[right]));
					right++;
				}
				left++;
				right = left-1;
			}
			
			if(maxi == INT_MIN)
			return 0 ;
			else
			return maxi;
		}
	};
	
////////////////////////////////////////////////////////////////////////////////

class Solution {
	public:
		int maximumStrongPairXor(vector<int>& nums) {
			//sort the array
			sort(nums.begin(),nums.end());
			//initialize two variables low & high
			int low=0,high=1;
			int s=0,mx=0;
			for(;high<nums.size();high++){ 
				//check for the condition & calculate xor
				if(abs(nums[high]-nums[low])<=min(nums[low],nums[high])) {
					s= nums[high] ^ nums[low];
					//update mx
					mx=max(s,mx);
				}
				else {
					//take the low pointer forward and since high=low+1 
					//and high will increment in the for loop make high=low
					low++;
					high=low;
				}
				//if high reaches the end of the array and yet the array 
				//is not completely traversed, update high and low
				if(high==nums.size()-1 && low<high) {
					high=low;
					low++;
				} 
			}
			return mx;
		}
	}; 