int maxbit(int data[], int n) //輔助函数，求數据的最大位數
{
    int maxData = data[0];      ///< 最大數
    /// 先求出最大數，再求其位數，这样有原先依次每个數判斷其位數，稍微優化點。
    for (int i = 1; i < n; ++i) {
        if (maxData < data[i]) maxData = data[i];
    }
    int d = 1; int p = 10;
    while (maxData >= p){
        p *= 10;
        ++d;
    }
    return d;
    /*    int d = 1; //保存最大的位數
          int p = 10;
          for(int i = 0; i < n; ++i){
          while(data[i] >= p){
         	 p *= 10;
         	 ++d;
          }
          }
          return d;*/
}
void radixsort(int data[], int n) //基數排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //計數器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) { //進行d次排序
        for(j = 0; j < 10; j++) count[j] = 0; //每次分配前清空計數器
        for(j = 0; j < n; j++){
            k = (data[j] / radix) % 10; //統計每個桶中的記錄數
            count[k]++;
        }
        for(j = 1; j < 10; j++) count[j] = count[j - 1] + count[j]; //將tmp中的位置依次分配给每個桶
        for(j = n - 1; j >= 0; j--) { //將所有桶中記錄依次收集到tmp中
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //將臨時數組的内容複製到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}
