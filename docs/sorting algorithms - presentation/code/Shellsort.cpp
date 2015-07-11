void Shellsort(vector<int> &aInputData)
{
  size_t len = aInputData.size();
  //
  int dist = 0;
  //Assigns gap size to be half of the original size initially, 
  //which is the original Donald Shell sequence N/2*i, i={1,n}
  for (dist = len/2; dist > 0; dist /= 2)
  {
    for (int i = dist; i < len; i++)
    {
      for (int j = i - dist; j >= 0 && aInputData[j] > aInputData[j + dist]; j -= dist)
      {
        swap(aInputData[j],aInputData[j + dist]);
      }
    }
  }
}s