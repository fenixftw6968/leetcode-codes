class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        vector<vector<int>> temp(mat.size(),vector<int>(mat.size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                temp[j][mat.size()-i-1]=mat[i][j];
            }
        }
        mat=temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(mat==target) return true;
            rotate(mat);
        }
        return false;
    }
};