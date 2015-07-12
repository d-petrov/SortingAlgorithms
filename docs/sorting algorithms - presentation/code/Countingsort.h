void Countingsort(vector<int> &aInputData)
{
  //upperBoundary,dataLength - class members
  vector<int> sortedData(aInputData);
  vector<int> tempData;
  for(int i = 0; i <= /*upperBoundary*/dataLength; i++) //access violation if boundary < datasize
  {
    tempData.push_back(0);
  }
  //create histogram
  for(int j = 0; j < dataLength; j++)
  {
    tempData[aInputData[j]] = tempData[aInputData[j]] + 1;
  }
  //Sort the histogram
  for(int i = 1; i <= upperBoundary; i++)
  {
    tempData[i] = tempData[i] + tempData[i-1];
  }
  //Place the sorted data into its place
  for(int j = dataLength - 1; j >= 0; j--)
  {
    sortedData[tempData[aInputData[j]] - 1] = aInputData[j];
    tempData[aInputData[j]] = tempData[aInputData[j]] - 1;
  }
  //Overwrite the input data
  for(int i = 0; i < aInputData.size(); i++)
  {
    aInputData[i] = sortedData[i];
  }
}