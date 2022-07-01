class Solution {
public:
    bool canMeasureWater(int jug1Cap, int jug2Cap, int tar) {
        int g = __gcd(jug1Cap, jug2Cap);
        if (tar % g == 0 && jug1Cap + jug2Cap >= tar){
            return true;
        }
        else {
            return false;
        }
    }
};