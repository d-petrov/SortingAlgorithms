int CalculateGap(int aGap)
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
void SortChild(vector<int> &aInputData)
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