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
#endif
