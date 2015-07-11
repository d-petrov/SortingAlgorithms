procedure CombSort (A[])
  gap = Length(A)
  do
     swapped = false
     if (gap > 1) then gap = floor ( gap/1.3 )
     for(i < (Length(A) - gap) 
        if (A[i] > A[i + gap]) 
           swap (A[i], A[i + gap])
           swapped = true
        end if
     end for
  while (swapped == true or gap > 1)
end procedure

