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
  int current = 0;
  __int64 iterations = 0;
  //
  for (unsigned i = 1, j; i < dataLength; i++,++iterations)
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
  for (unsigned i = 0; i < dataLength-1; i++)
  {
    min = i;
    for (j = i + 1; j < dataLength; j++)
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
__int64 Shellsort::SortChild(vector<int> &aInputData)
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
__int64 Combsort::SortChild(vector<int> &aInputData)
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
#pragma package(smart_init)


