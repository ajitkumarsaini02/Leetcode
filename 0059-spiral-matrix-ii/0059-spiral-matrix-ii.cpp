class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n,vector<int> (n));
        int minr=0,minc=0;
        int maxr=n-1, maxc=n-1;
        int count=1;
        while(minr<=maxr && minc<=maxc){
            for(int j=minc;j<=maxc;j++){
                mat[minr][j]=count++;
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            for(int i=minr;i<=maxr;i++){
                mat[i][maxc]=count++;
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            for(int j=maxc;j>=minc;j--){
                mat[maxr][j]=count++;
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            for(int i=maxr;i>=minr;i--){
                mat[i][minc]=count++;
            }
            minc++;
            if(minr>maxr || minc>maxc) break;
        } 
       return mat;
    }
};