// Find whether a given number is a power of 4 or not

float logn(int n,int b){
    return log(n)/log(b);
}

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0){
            return false;
        }
        float x=logn(num,4);
        if(floor(x)==ceil(x)){
            return true;
        }
        return false;
    }
};
