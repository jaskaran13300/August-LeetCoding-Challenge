void buildTriangle(vector<int> &temp,int rowIndex){
    temp.push_back(1);
    // triangle.push_back(temp);
    for(long long int j=0;j<rowIndex;j++){
        vector<int>temp2;
        temp2.push_back(1);
        for(long long int i=0;i<temp.size()-1;i++){
            temp2.push_back(temp[i]+temp[i+1]);
        }
        temp2.push_back(1);
        // triangle.push_back(temp2);
        temp.clear();
        temp=temp2;
    }
}
class Solution {
public:
    
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        buildTriangle(temp,rowIndex);
        // vector<int>ans;
        // for(auto vc:triangle){
        //     for(auto ele:vc){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(long long int i=0;i<triangle[rowIndex].size();i++){
        //     ans.push_back(triangle[rowIndex][i]);
        // }
        
        return temp;
    }
};
