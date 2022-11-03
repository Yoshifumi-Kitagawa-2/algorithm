/*
a1,a2・・・anを左から右へ走査しながら隣り合う二つの数値を比較し、それらが小さい順になるように必要なら入れ替えを行う。
アルゴリズムはこの入れ替えが起こらなくなるまで列の走査を繰り返す
計算量はO(n^2)→あまり効率的でない
*/
void bubblesprt(int n)
{
    int *a[n];
    int i,j,sorted;
    j = n;
    do{
        sorted = 1;
        j = j - 1;//合計n回走査すれば必ず終わるので。
        for (i = 1;i <= j;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(&a[i],&a[i+1]);
                sorted = 0;
            }
        }
    } while(!sorted);//!sorted は !(sorted != 0)なのでsorted == 0

}