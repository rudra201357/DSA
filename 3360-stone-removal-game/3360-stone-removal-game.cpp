class Solution {
public:
    bool canAliceWin(int n) {
        int stoneToRemove = 10;
        bool turnA= true;
        while(n>=stoneToRemove){
            n-=stoneToRemove;
            stoneToRemove--;
            turnA =!turnA;
        }
        return !turnA;
    }
};