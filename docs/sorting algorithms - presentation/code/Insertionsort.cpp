void DoInsertionSort(vector<int> &aInputData)
{
  size_t len = aInputData.size();
  //
  int current = 0;
  //
  for (unsigned i = 1, j; i < len; i++)
  {
    j = i;
    current = aInputData[j];
    //
    while (j > 0 && aInputData[j-1] > current)
    {
        aInputData[j] = aInputData[j-1];
        j--;
    }
    aInputData[j] = current;
  }
}