void DoSelectionSort(vector<int> &aInputData)
{
  unsigned j = 0;
  unsigned min = 0;
  //
  size_t len = aInputData.size();
  //
  for (unsigned i = 0; i < len-1; i++)
  {
    min = i;
    for (j = i + 1; j < len; j++)
    {
      if (aInputData[i] < aInputData[min])
      {
        min = j;
      }     
    }
    if(min != i)
    {
      swap(aInputData[i], aInputData[min]);//internal function     
    }
  }
}