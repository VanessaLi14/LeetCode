/* You have a long flowerbed in which some of the plots are planted, and some are not. 
 * However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
 * and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zero_counter = 0;
        int cna_be_planted = 0;
        flowerbed.insert (flowerbed.begin(), 0);
        flowerbed.push_back (0);
        for (auto plots : flowerbed)
        {
            if (plots == 0 && zero_counter != 3)
            {
                zero_counter ++;
                if (zero_counter == 3)
                {
                    zero_counter = 1;
                    cna_be_planted ++;
                }
            }
            if (plots == 1)
                zero_counter = 0;
        }

        return cna_be_planted >= n;
    }
};

#if 0
思路 : 
連續的數到第三個零時，就一定有一個空位可以種一朵花，像以下這樣：
 [ 1 0 0 0 0 0 0 0 1] -> 最多可以種三朵花
     1 2 3   1 2 3
         1 2 3
不過還要想到前面的 ex.[0 0 1]，或是後面的 ex.[1 0 0]，
所以做法是將vector前後各補一個零，就可以讓所有情況都能符合最開始的思路去寫。
#endif
