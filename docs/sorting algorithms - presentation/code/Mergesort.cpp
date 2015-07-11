vector<int> Mergesort(vector<int> &aInputData)
{
  if(aInputData.size() == 1)
  {
    return aInputData;
  }
  // 
  vector<int>::iterator middle = aInputData.begin() + (aInputData.size() / 2);
  //
  vector<int> leftData(aInputData.begin(), middle);
  vector<int> rightData(middle, aInputData.end());
  //
  leftData = DoSort(leftData);
  rightData = DoSort(rightData);

  return DoMerge(aInputData,leftData, rightData);
}
vector<int> Merge(vector<int> &aInputData, vector<int> &aLeft, vector<int> &aRight)
{
  vector<int> result;
  unsigned left_it = 0, right_it = 0;
  //
  while(left_it < aLeft.size() && right_it < aRight.size())
  {
    if(aLeft[left_it] < aRight[right_it])
    {
      result.push_back(aLeft[left_it]);
      left_it++;
    }
    else
    {
      result.push_back(aRight[right_it]);
      right_it++;
    }
  }
  //
  while(left_it < aLeft.size())
  {
    result.push_back(aLeft[left_it]);
    left_it++;
  }
  //
  while(right_it < aRight.size())
  {
    result.push_back(aRight[right_it]);
    right_it++;
  }
  //
  aInputData = result;
  //
  return result;
}