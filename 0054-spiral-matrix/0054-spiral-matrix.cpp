class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
       int m=mat.size();
       int n=mat[0].size();
       int minr=0,minc=0;
       int maxr=m-1, maxc=n-1;
       vector<int> res;
       while(minr<=maxr && minc<=maxc){
         for(int j=minc;j<=maxc;j++){
            res.push_back(mat[minr][j]);
         }
         minr++;
         for(int i=minr;i<=maxr;i++){
            res.push_back(mat[i][maxc]);
         }
         maxc--;
         if(minr<=maxr){
            for(int j=maxc;j>=minc;j--){
              res.push_back(mat[maxr][j]);
            }
            maxr--;
         }
         if(minc<=maxc){
            for(int i=maxr;i>=minr;i--){
              res.push_back(mat[i][minc]);
            }
            minc++;
         }
       } 
       return res;
    }
};