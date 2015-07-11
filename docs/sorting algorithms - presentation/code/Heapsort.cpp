void SiftDown(vector<int> &aInputData, int aIndex, int aSize)
{
  while(aIndex * 2 + 1 < aSize)
  {
    int child = (2 * aIndex + 1);
    if((child + 1 < aSize) && (aInputData[child] < aInputData[child+ 1]))
    {
      child++;
    }
    if(aInputData[aIndex] < aInputData[child])
    {
      swap(aInputData[child], aInputData[aIndex]);
      aIndex = child;
    }        
    else
    {
      return;
    }
  }
}
void Heapify(vector<int> &aInputData)
{
  for(int index = dataLength / 2; index >= 0; index--)
  {
    SiftDown(aInputData, index, dataLength);
  }
}
void SortChild(vector<int> &aInputData)
{
  Heapify(aInputData);
  int workLength = dataLength;
  //
  while (workLength - 1 > 0)
  {
    swap(aInputData[workLength -1 ], aInputData[0]);
    SiftDown(aInputData, 0, workLength - 1);
    workLength--;
  }
}