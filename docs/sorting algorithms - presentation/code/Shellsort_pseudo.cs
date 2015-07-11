#Ciura's sequence, which nobody knows why it works.
gaps = [701, 301, 132, 57, 23, 10, 4, 1]

foreach (gap in gaps)
{
    for (i = gap; i < n; i += 1)
    {
        temp = a[i]
        for (j = i; j >= gap and a[j - gap] > temp; j -= gap)
        {
            a[j] = a[j - gap]
        }
        a[j] = temp
    }
}