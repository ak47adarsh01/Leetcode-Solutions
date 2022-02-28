class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int newColor) {
       
        int oldCol = image[i][j];
        
        if(newColor == oldCol)
            return image;
        
        image[i][j] = newColor;
        
        if(i < image.size()-1 && image[i+1][j] == oldCol) 
            floodFill(image, i+1, j, newColor);
        
            
        if(j < image[0].size() - 1 && image[i][j+1] == oldCol) 
             floodFill(image, i, j+1, newColor);
    
           
        if(i > 0 && image[i-1][j] == oldCol) 
            floodFill(image, i-1, j, newColor);

            
        if(j > 0 && image[i][j-1] == oldCol) 
             floodFill(image, i, j-1, newColor);
        
        return image;
    }
};