/******************************************************************************/
#ifndef STATIC_SORTER
#define STATIC_SORTER
/******************************************************************************/

template<unsigned short K>
void static_insertion_sort(double(&arr)[K])
{
    for (unsigned short i=1; i<K; ++i)
    {
        double value = arr[i];
        short  hole  = i;

        for (;  hole > 0 && value < arr[hole-1];  --hole)
            arr[hole] = arr[hole-1];
        
        arr[hole] = value;
    }
}

/******************************************************************************/
#endif
/******************************************************************************/
