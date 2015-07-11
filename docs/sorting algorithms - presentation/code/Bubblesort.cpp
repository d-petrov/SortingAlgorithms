void BubbleSort(vector<int> &aInputData)
{
  size_t len = aInputData.size();
  //
  for (int i = len; i > 1 ; i--)
  {
    for (int j = 0; j < i - 1 ; j++)
    {
      if(aInputData[j] > aInputData[j + 1])
      {
        swap(aInputData[j],aInputData[j + 1]);
      }
    }
  }
}