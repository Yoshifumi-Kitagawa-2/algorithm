/*増分列で微調整する*/
/*挿入法のアルゴリズムの外側に増分列を制御するwhile文が付加されただけで非常に単純*/
void shellsort()
{
    int i,j,k,temp;
    while (t>=1){
        k = h[t]; t = t-1;
        for (i = k+1; i<=n; i++){
            temp = a[i]; j = i;
            while(j > k && a[j-k] > temp){
                a[j] = a[j-k];
                j = j-k;
            }
            a[j] = temp;
        }
    }
}