class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        vector<int> buckets(N+1, 0);

        for(int i : citations){
            if (i >= N){
                buckets[N]++;
            } else {
                buckets[i]++;
            }
        }

        int count = 0;
        for(int i = N; i >= 0; i--){
            count += buckets[i];
            if(count >= i) {
                return i;
            }
        }

        return 0;
    }
};
