//---------------------------------------------------------------------------


#pragma hdrstop
//---------------------------------------------------------------------------
#include "USorting.h"
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
RuntimeResult SortBase::Sort(vector<int> &aInputData)
{
  RuntimeResult result;
  result.ticks = 0;
  result.iterations = 0;
  //
  dataLength = aInputData.size();
  if(dataLength == 0)
  {
    return result;
  }
  //
  __int64 tickCountStart = GetTickCount();
  //
  SortChild(aInputData);
  //
  __int64 tickCountEnd = GetTickCount();
  //
  result.ticks = tickCountEnd - tickCountStart;
  //
  return result;
}
//---------------------------------------------------------------------------
void InsertionSort::SortChild(vector<int> &aInputData)
{
  int current = 0;
  //
  for (unsigned i = 1, j; i < dataLength; i++)
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
//---------------------------------------------------------------------------
void SelectionSort::SortChild(vector<int> &aInputData)
{
  unsigned j = 0;
  unsigned min = 0;
  //
  for (unsigned i = 0; i < dataLength-1; i++)
  {
    min = i;
    for (j = i + 1; j < dataLength; j++)
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
//---------------------------------------------------------------------------
void BubbleSort::SortChild(vector<int> &aInputData)
{
  for (int i = dataLength; i > 1 ; i--)
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
//---------------------------------------------------------------------------
void Shellsort::SortChild(vector<int> &aInputData)
{
  int gapSize = 0;
  //Assigns gap size to be half of the original size initially, which is the original Donald Shell sequence N/2*i, i={1,n}
  for (gapSize = dataLength/2; gapSize > 0; gapSize /= 2)
  {
    for (int i = gapSize; i < dataLength; i++)
    {
      for (int j = i - gapSize; j >= 0 && aInputData[j] > aInputData[j + gapSize]; j -= gapSize)
      {
        swap(aInputData[j],aInputData[j + gapSize]);
      }
    }
  }
}
//---------------------------------------------------------------------------
int Combsort::CalculateGap(int aGap)
{
  aGap /= 1.3;
  //
	if(aGap == 9 || aGap == 10)//select a better gap ending
  {
		aGap = 11;
  }
	if(aGap < 1)
  {
		return 1;
  }
  //
	return aGap;
}
//---------------------------------------------------------------------------
void Combsort::SortChild(vector<int> &aInputData)
{
	int gap = dataLength;
	bool isSwap = false;
  //
	do
  {
		isSwap = false;
		gap = CalculateGap(gap);
    //
		for(int i = 0; i < dataLength - gap; ++i)
    {
			if(aInputData[i] > aInputData[i + gap])
      {
				isSwap = true;
				swap(aInputData[i], aInputData[i + gap]);
			}
		}
	}
  while(gap > 1 || isSwap);
}
//---------------------------------------------------------------------------
vector<int> Mergesort::DoSort(vector<int> &aInputData)
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
//---------------------------------------------------------------------------
vector<int> Mergesort::DoMerge(vector<int> &aInputData, vector<int> &aLeft, vector<int> &aRight)
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
//---------------------------------------------------------------------------
void Mergesort::SortChild(vector<int> &aInputData)
{
  DoSort(aInputData);
}
//---------------------------------------------------------------------------
void Quicksort::Partition(vector<int> &aInputData, int aPivot, int& aLeft, int& aRight)
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
//---------------------------------------------------------------------------
void Quicksort::DoSort(vector<int> &aInputData, int aFirst, int aLast)
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
//---------------------------------------------------------------------------
void Quicksort::SortChild(vector<int> &aInputData)
{
  DoSort(aInputData,aInputData.front(),aInputData.size());
}
//---------------------------------------------------------------------------
void Heapsort::SiftDown(vector<int> &aInputData, int aIndex, int aSize)
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
//---------------------------------------------------------------------------
void Heapsort::Heapify(vector<int> &aInputData)
{
  for(int index = dataLength / 2; index >= 0; index--)
  {
    SiftDown(aInputData, index, dataLength);
  }
}
//---------------------------------------------------------------------------
void Heapsort::SortChild(vector<int> &aInputData)
{
  Heapify(aInputData);
  int workLength = dataLength;
  //
  while (workLength - 1 > 0)
  {
    swap(aInputData[workLength - 1], aInputData[0]);
    SiftDown(aInputData, 0, workLength - 1);
    workLength--;
  }
}
//---------------------------------------------------------------------------
void Countingsort::SortChild(vector<int> &aInputData)
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
//---------------------------------------------------------------------------
Countingsort::Countingsort(int aBoundary)
{
  upperBoundary = aBoundary;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)


