void shell_sort(int* ptr, int len)
{
    int gap = len / 2;
    while(gap){
        for(int i = gap; i < len; ++i, gap /= 2) {
            for(int j = i; j >= gap; j-=gap){
                if(ptr[j] > ptr[j-gap]) swap(ptr, j, j-gap, gap);
                else break;
            }
        }
    }
}
