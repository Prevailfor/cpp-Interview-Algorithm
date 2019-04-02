
class Solution1{
 
public:
	bool Find(int target, vector<vector<int> >array){
		for(int i = 0; i < array.size(); ++i){
			int fd = BinarySearch(array[i], target);
			if(fd != -1)
				return true;
		}
	}
 
 private:
 	int BinarySearch(vector<int>vt, int target){
 		int l = 0;
 		int h = vt.size()-1;
 		while(l <= h){
 			int mid = (l + h) / 2;
 			if(vt[mid] == target)
 				return 1;
 			else if(vt[mid] < target)
 				l = mid+ 1;
 			else h = mid - 1;
 		}
 	}
 		return -1;
};
