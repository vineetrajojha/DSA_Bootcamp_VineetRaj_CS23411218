class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;

        for (int pile : piles) {
            high = max(high, pile);
        }

        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calculateHours(piles, mid) <= h) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    long long calculateHours(vector<int>& piles, int k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
        }
        return hours;
    }
};