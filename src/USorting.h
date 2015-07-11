//---------------------------------------------------------------------------

#ifndef USortingH
#define USortingH
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
struct RuntimeResult
{
  __int64 ticks;
  __int64 iterations;
};
//---------------------------------------------------------------------------
class SortBase  //base class
{
  protected:
    size_t dataLength;//input data size
  public:
     virtual RuntimeResult Sort(vector<int> &aInputData);
     virtual __int64 SortChild(vector<int> &aInputData)=0;
};
//---------------------------------------------------------------------------
class InsertionSort : public SortBase
{
  private:
     __int64 SortChild(vector<int> &aInputData);
};
//---------------------------------------------------------------------------
class SelectionSort : public SortBase
{
  private:
     __int64 SortChild(vector<int> &aInputData);
};
//---------------------------------------------------------------------------
class BubbleSort : public SortBase
{
  private:
     __int64 SortChild(vector<int> &aInputData);
};
//---------------------------------------------------------------------------
class Shellsort : public SortBase
{
  private:
     __int64 SortChild(vector<int> &aInputData);
};
//---------------------------------------------------------------------------
class Combsort : public SortBase
{
  private:
     int CalculateGap(int aGap);
     __int64 SortChild(vector<int> &aInputData);
};
//---------------------------------------------------------------------------
class Mergesort : public SortBase
{
  private:
     vector<int> DoSort(vector<int> &aInputData);
     vector<int> DoMerge(vector<int> &aInputData, vector<int> &aLeft, vector<int> &aRight);
    //
     __int64 SortChild(vector<int> &aInputData);
};
//---------------------------------------------------------------------------
class Quicksort : public SortBase
{
  private:
     void Partition(vector<int> &aInputData, int aPivot, int& aLeft, int& aRight);
     void DoSort(vector<int> &aInputData, int aFirst, int aLast);
     //
     __int64 SortChild(vector<int> &aInputData);
};
#endif
