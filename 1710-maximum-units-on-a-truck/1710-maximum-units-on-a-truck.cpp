class Solution {
public:
   int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      
       // sort by number of units / box
       
	sort(begin(boxTypes), end(boxTypes), [](auto& a, auto& b){ return a[1] > b[1];}); 
	int maxUnits = 0;
	for(auto& box : boxTypes) {
        // keep choosing greedily till you run out of truckSize 
		if(truckSize <= 0) break;   
         // add (no of box * units) in that box
		maxUnits += min(truckSize, box[0]) * box[1];
		truckSize -= box[0];
	}
	return maxUnits;
}

};