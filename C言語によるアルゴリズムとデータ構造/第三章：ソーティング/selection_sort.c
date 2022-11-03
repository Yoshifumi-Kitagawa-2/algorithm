/*入力のn個の数値をa1,a2,・・・anの中から最小値を見つけては取り出すという操作。下のアルゴリズムでは見つけた最小値を配列の左端から順に並べる*/

void    selectionsort(int n)
{
    int *a[n];
    int i,j,min;

    for(i = 1; i <= n-1;i++)
    {
        min = i;
        for(j=i+1; j<=n; j++)
        {
            if (a[min] > a[j])
                min = j;
            swap(&a[i], &a[min]);
        }
    }
}

/*forループの回る回数が(n-1) + (n-2) + ・・・+ 1 = n(n-1)/2 なのでO(n^2)*/