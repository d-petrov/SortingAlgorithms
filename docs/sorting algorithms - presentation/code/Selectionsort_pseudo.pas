procedure SelectionSort(A[])
	n = A[].length
	left = 0
	min = 0
	do
		min = left
		for(i = 0 ; i <= left + 1; i++)
			if (A[i] < A[min])
			then
				min = i
			end
		end for	
		Swap(A[min],A[left])
		++left		
	while left < n
end procedure