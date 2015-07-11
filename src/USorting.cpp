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
  __int64 tickCountStart = GetTickCount();
  //
  result.iterations = SortChild(aInputData);
  //
  __int64 tickCountEnd = GetTickCount();
  //
  result.ticks = tickCountEnd - tickCountStart;
  //
  return result;
}
//---------------------------------------------------------------------------
__int64 InsertionSort::SortChild(vector<int> &aInputData)
{
  size_t len = aInputData.size();

  int current = 0;
  __int64 iterations = 0;
  //
  for (unsigned i = 1, j; i < len; i++,++iterations)
  {
    j = i;
    current = aInputData[j];
    //
    while (j > 0 && aInputData[j-1] > current)
    {
        aInputData[j] = aInputData[j-1];
        j--;
        ++iterations;
    }
    aInputData[j] = current;
  }
  return iterations;
}
//---------------------------------------------------------------------------
__int64 SelectionSort::SortChild(vector<int> &aInputData)
{
  unsigned j = 0;
  unsigned min = 0;
  __int64 iterations = 0;
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
      iterations++;
    }
    if(min != i)
    {
      swap(aInputData[i], aInputData[min]);//internal function
      iterations++;
    }
  }
  return iterations;
}
//---------------------------------------------------------------------------
__int64 BubbleSort::SortChild(vector<int> &aInputData)
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
//---------------------------------------------------------------------------
__int64 Shellsort::SortChild(vector<int> &aInputData)
{
  size_t len = aInputData.size();
  //
  int gapSize = 0;
  //Assigns gap size to be half of the original size initially, which is the original Donald Shell sequence N/2*i, i={1,n}
  for (gapSize = len/2; gapSize > 0; gapSize /= 2)
  {
    for (int i = gapSize; i < len; i++)
    {
      for (int j = i - gapSize; j >= 0 && aInputData[j] > aInputData[j + gapSize]; j -= gapSize)
      {
        swap(aInputData[j],aInputData[j + gapSize]);
      }
    }
  }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


