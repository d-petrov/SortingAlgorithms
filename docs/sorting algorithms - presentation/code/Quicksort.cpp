void Partition(vector<int> &aInputData, int aPivot, int& aLeft, int& aRight)
{
   while (aLeft <= aRight)
   {
     while(aInputData[aLeft] < aPivot)
     {
       aLeft++;
     }
     while(aInputData[aRight] > aPivot)
     {
       aRight--;
     }
     if(aLeft <= aRight)
     {
       swap(aInputData[aLeft],aInputData[aRight]);
       aLeft++;
       aRight--;
     }
  }
}
void Quicksort(vector<int> &aInputData, int aFirst, int aLast)
{
  if(aFirst == aLast)
  {
    return;
  }
  //
  int left = aFirst;
  int right = aLast;
  //
  int pivot = aInputData[(left + right) / 2];
  //
  Partition(aInputData,pivot,left,right);
  //
  if(left < aLast)
  {
    DoSort(aInputData, left, aLast);
  }
  if(aFirst < right)
  {
    DoSort(aInputData, aFirst, right);
  }
}