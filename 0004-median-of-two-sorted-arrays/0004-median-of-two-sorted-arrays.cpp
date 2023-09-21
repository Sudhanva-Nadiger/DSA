class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {  
        int SizeOfMergedArray=nums1.size()+nums2.size();
int MergedArray[SizeOfMergedArray];
int Location=0;
vector<int>::iterator Num1Iter = nums1.begin();
vector<int>::iterator Num2Iter = nums2.begin();

 while(Num1Iter != nums1.end() || Num2Iter != nums2.end())
  {
      //Reset the numbers to the max. 
      //This is used as a flag to always have the smallest upfront
      int Num1=INT_MAX;
      int Num2=INT_MAX; 
      //Get the next number if the array is not empty
      if(Num1Iter != nums1.end())
      {
         Num1=*Num1Iter;
      }
      //Get the next number if the array is not empty
      if(Num2Iter != nums2.end())
      {  
         Num2=*Num2Iter;
      }    
     //Which value is smaller 1st or 2nd? 
     //First is smaller....
     if(Num1<Num2)
     {
        //place it in the memory location
        MergedArray[Location]=Num1;
        Num1Iter++;

     }
     //Second is smaller....
     else
     {

        MergedArray[Location]=Num2;
        Num2Iter++;

     }
     //Next memory location
     Location++;
  }//Completed sorting the array 
   //Even number of elements therefor take the middle two and average them
   if (SizeOfMergedArray %2 ==0)
    {
       return (float)((MergedArray[(SizeOfMergedArray/2)-1])+MergedArray[(SizeOfMergedArray/2)])/2;
    }
    //odd number so take the middle. 
    else
       return (float)(MergedArray[SizeOfMergedArray/2]);
}
};