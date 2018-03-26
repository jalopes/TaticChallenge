void swap(long long* a, long long* b, char* c[], char * d[], long long* e, long long* f)
{
    long long t = *a;
    *a = *b;
    *b = t;

    char* v = *c;
    *c = *d;
    *d = v;

    long long s = *e;
    *e = *f;
    *f = s;
}

int partition (long long arr[], char** arr2, long long arr3[], int low, int high)
{
    long long pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j], &arr2[i], &arr2[j], &arr3[i], &arr3[j]);
        }
    }
    swap(&arr[i + 1], &arr[high], &arr2[i + 1], &arr2[high], &arr3[i + 1], &arr3[high]);
    return (i + 1);
}


void quickSort(long long arr[], char** arr2, long long arr3[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, arr2, arr3, low, high);
        quickSort(arr, arr2, arr3, low, pi - 1);
        quickSort(arr, arr2, arr3, pi + 1, high);
    }
}

int binaryMin(long long v[], int min, int max, long long x){

    if(v[min] == x){
        return min;
    }
    else if( v[max] == x){
        return max;
    }
    else if (v[min + 1] == x){
        return min + 1;
    }
    else if(max - min == 1){
        return min + 1;
    }
    else if(v[min + (max - min)/2] < x){
        return binaryMin(v, min + (max - min)/2, max, x );
    }
    else if(v[max - (max - min)/2] > x){
        return binaryMin(v, min, max - (max - min)/2, x );
    }
}


int binaryMax(long long v[], int min, int max, long long x){

    if(v[min] == x){
        return min;
    }
    else if( v[max] == x){
        return max;
    }
    else if (v[min + 1] == x){
        return min + 1;
    }
    else if(max - min == 1){
        return max - 1;
    }
    else if(v[min + (max - min)/2] < x){
        return binaryMax(v, min + (max - min)/2, max, x );
    }
    else if(v[max - (max - min)/2] > x){
        return binaryMax(v, min, max - (max - min)/2, x );
    }
}

int modBinarySearch(long long v[], int min, int max, long long x, int arg){

    if(v[min] == x){
        return min;
    }
    else if( v[max] == x){
        return max;
    }
    else if (v[min + 1] == x){
        return min + 1;
    }
    else if(max - min == 1){
        if (arg == 1){
            return max - 1;
        }
        else if (arg == -1){
            return min + 1;
        }
    }
    else if(v[min + (max - min)/2] < x){
        return binaryMax(v, min + (max - min)/2, max, x );
    }
    else if(v[max - (max - min)/2] > x){
        return binaryMax(v, min, max - (max - min)/2, x );
    }
}