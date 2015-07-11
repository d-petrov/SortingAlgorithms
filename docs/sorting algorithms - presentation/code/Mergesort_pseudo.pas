procedure mergesort(List A);
	if (Length(A) <= 1) then return A
	else
     List leftList = GetLeftHalfOfList(A)
	 List rightList = GetRightHalfOfList(A)
     leftList = mergesort(leftList)
     rightList = mergesort(rightList)
     return merge(leftList, rightList)
	end if
end procedure
//
procedure merge(leftList, rightList);
  List resultList
  while (leftList.NotEmpty and rightList.NotEmpty)
	if (leftList.First <= rightList.First)
	then 
		resultList.Push(leftList.First)
		leftList.Pop()
	else 
		resultList.Push(rightList.First)
		rightList.Pop()
	end if
  end while
  while (leftList.NotEmpty)
	resultList.Push(leftList.First)
	leftList.Pop()
  end while
  while (rightList.NotEmpty)
	resultList.Push(rightList.First)
	rightList.Pop()
  end while
  return resultList
end procedure