class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) return 1;
        for (int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i]) continue;
            if (n == 0) break;
            if (i > 0 && i < flowerbed.size()-1){
                if (!flowerbed[i-1] && !flowerbed[i+1]){
                    n--;
                    flowerbed[i] = 1;
                }
            }
            if (i == 0 && flowerbed.size() > 1){
                if (!flowerbed[i+1]){
                    n--;
                    flowerbed[i] = 1;
                }
            }
            if (i == flowerbed.size() - 1 && flowerbed.size() > 1){
                if (!flowerbed[i-1]){
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n == 0;
    }
};