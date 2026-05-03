class Solution {
public:
    bool isPerfectSquare(int num) {
        // Base case: 1 ek perfect square hai (1 * 1 = 1)
        if (num == 1) return true;

        long long left = 1;
        long long right = num; // Search space 1 se num tak

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid; // Mid ka square nikaalo 

            if (square == num) {
                return true; // Mil gaya!
            } 
            else if (square < num) {
                left = mid + 1; // Square chota hai, toh aage dhundho
            } 
            else {
                right = mid - 1; // Square bada ho gaya, toh peeche dhundho
            }
        }
        
        // Agar loop khatam ho gaya aur match nahi mila
        return false;
    }
};