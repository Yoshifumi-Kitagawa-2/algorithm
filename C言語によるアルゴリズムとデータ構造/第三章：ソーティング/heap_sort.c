/*
ヒープを用いてソーティングアルゴリズムを構成することができる
ヒープでは最小要素を見つけるのがO(1)時間でできるので、入力n個の要素を全てヒープに挿入して、その後、最小要素を取り出すことを繰り返して並べればソーティングが完了する
*/

void    heapsort()
{
    struct heap h;
    int         i;
    create(&h);
    for (i = 1; i <= n; i++)
        insert(&h, a[i]);
    for (i = 1; i <= n; i++)
    {
        a[i] = findmin(&h);
        deletemin(&h);
    }
}

/*改良版*/
void    heapify(int i, int j)
{
    int k;

    k = 2*i;
    if (k <= j){
        if (k != j && a[k]>a[k+1])
            k++;
        if (a[i]>a[k]){
            swap(&a[i], &a[k]);
            heapify(k,j);
        }
    }
}

void makeheap()
{
    int i;

    for (i=n; 1<=i; i--)
        heapify(1,n);
}

int main(void)
{
    int i;

    makeheap();
    for(i=n; 2<=0:i--){
        swap(&a[1], &a[i]);
        heapify(1,i-1);
    }
}