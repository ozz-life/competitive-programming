// https://authorslog.vercel.app/blog/CB5AJHUJFs

class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    for (int i = 0; i < k - 1; ++i)
      colors.push_back(colors[i]);
    int res = 0;
    int cnt = 1;
    for (int i = 1; i < colors.size(); ++i) {
      if (colors[i] != colors[i - 1])
        ++cnt;
      else
        cnt = 1;
      if (cnt >= k)
        ++res;
    }
    return res;
  }
};

////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int res = 0, n = colors.size(), count = 1, last = -1;
    for (int i = 1; i < 2 * n && last != i % n; i++) {
      count = colors[i % n] != colors[(i - 1) % n] ? count + 1 : 1;
      if (count >= k) {
        if (last == -1)
          last = i;
        res++;
      }
    }
    return res;
  }
};

////////////////////////////////////////////////////////////////////////////////

// n + k - 2
// We count alternating elements for i up to n + k - 2.
// If two neighbours have the same color, we reset the count to 1.
// When the count reaches or exceeds k, we found an alternating group.

int numberOfAlternatingGroups(vector<int> &colors, int k) {
  int n = colors.size(), res = 0, cnt = 1;
  for (int i = 0; i < n + k - 2; ++i) {
    cnt = colors[i % n] != colors[(i + 1) % n] ? cnt + 1 : 1;
    res += cnt >= k;
  }
  return res;
}

////////////////////////////////////////////////////////////////////////////////
// Sliding Window

class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &s, int k) {
    int size = s.size();
    int start = 0, end = 1;
    int bad = 0; // count the trouble causing pairs in the window
    int res = 0;

    // why start < size ? every element can act as the start of the window.
    while (start < size) {
      if (s[end % size] == s[(end - 1) % size])
        bad++;
      if (end - start + 1 == k) {
        if (bad == 0)
          res++;
        start++;

        // Subtract the effect of removed pair on bad count
        if (s[start % size] == s[(start - 1) % size])
          bad--;
      }
      end++;
    }
    return res;

    // Please do UPVOTE :)
  }
};

////////////////////////////////////////////////////////////////////////////////
// This is the alternate method for circular traversal.
// if you feel trouble in this kind of circlular approach, You can use this
// approach. But make sure this approach will not work in every circular
// traversal. so learning both approach will be more beneficial

class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int n = colors.size();
    int ans = 0;
    for (int i = 0; i < k; i++) {
      colors.push_back(colors[i]);
    }
    int s = 0, e = 1;
    while (s < n) {
      if (e - s == k) {
        ans++;
        s++;
      }
      if (colors[e] != colors[e - 1]) {
        e++;
      } else {
        s = e;
        e++;
      }
    }
    return ans;
  }
};

/*
 * Alternative Method for Circular Traversal:
 * If you find circular traversal challenging, you can use this method.
 * However, be aware that this approach might not work for all circular
 * traversal problems. Therefore, learning both methods will be more beneficial.
 */

//  The fact is that sliding window question almost always follows a same
//  template. So u should head over to any article or video where the basic of
//  shrinkable and non shrinkable sliding window is taught. Now afterwards u can
//  solve a bunch of question on the same and you would be good at it.
// Here is one link for your reference:
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/c-maximum-sliding-window-cheatsheet-template/

// When it comes to cyclic arrays our main goal is to remove the additional
// complexity of cyclicity somehow. It can be done in two ways either by
// extending the array of size n to 2n, or use a modulo operation.

// https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/c-maximum-sliding-window-cheatsheet-template/

// hi dixit, im a beginner but what i got to learn is , whenever there is
// cyclicity involved, we gotta use %n operator , and from the problem
// description we were given k so it implied we need to use sliding window. so
// its a pattern for this sort of problems. hope i could help you

////////////////////////////////////////////////////////////////////////////////
// Sliding Window

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col, int k) {

        for(int i=0;i<k-1;i++){
            col.push_back(col[i]);
        }

        int n=col.size();

        int left=0;
        int right=1;
        int count=0;

        while(right<n){
            
            if(col[right]!=col[right-1]){
                if(right-left+1==k){
                    count++;
                    left++;
                }
                right++;
            }else{
                left=right;
                right++;
            }
        }

        return count;
        
    }
};

////////////////////////////////////////////////////////////////////////////////
// Обязательно HASHING https://leetcode.com/problems/alternating-groups-ii/solutions/5429881/with-explanation-rolling-hash-technique-very-easy-to-understand-and-beginner-friendly-code/
// Sliding Window Python LO-HI https://leetcode.com/problems/alternating-groups-ii/solutions/5428905/java-python-3-sliding-window-1-pass-o-n-codes-w-brief-explanation-and-analysis/