/* There is a biker going on a road trip. 
 * The road trip consists of n + 1 points at different altitudes. 
 * The biker starts his trip on point 0 with altitude equal 0.
 * 
 * You are given an integer array gain of length n where gain[i] is the net gain in altitude 
 * between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largest_altitude = 0;
        int now_altitude = 0;
        for (auto gain_altitude : gain)
        {
            now_altitude += gain_altitude;
            if (largest_altitude < now_altitude)
                largest_altitude = now_altitude;
        }
        return largest_altitude;
    }
};
