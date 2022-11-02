/*
クイックソートもマージソート同様に分割統治法に基づくアルゴリズム
クイックソートの最大計算量はO(n^2)
平均計算量はO(nlogn)
マージソートをプログラムとして実現する時、二つの配列を用意しておく必要があった
クイックソートでは配列一本のみで良い
長さnの列α＝(a1,a2,,,,an)を、先頭の要素a1を基準にして二つの列α1、α2に分割。
α1：a1と同じかa1より小さい数からなる列
α2：a1と同じかa1より大きい数からなる列
あとはそれぞれをソートするだけ
*/
void    partition(int p, int q, int *jp, int *ip)//配列a[p..q]に入っている列をa[p]をピボットにして二つに分割する関数である。a[p]と同じかa[p]より小さい値がa[p..j]に移され、a[p]と同じかa[p]より大きい数値がa[i..q]に移される。
{
    int *a[q];
    int i,j,s;

    i = p; j = q; s = a[p];
    while(i <= j){
        while(a[i] < s) ++i;
        while(a[j] > s) --j;
        if(i <= j){
            swap(&a[i], &a[j]);
            ++i;j--;
        }
    }
    *jp = j; *ip == i;
}

void qsort(int p, int q)
{
    int i,j;

    if(p < q)
    {
        partition(p,q, &j, &i);
        qsort(p,j);
        qsort(i,q);
    }
}

int main(void)
{
    int n;
    qsort(1,n);
}

/*
(*8 11 23 7 15 37 21 4)
(4 7)(*23 11 15 37 21 8)
(4 7)(*8 11 15 21)(*37 23)
(4)(7)(8)(*11 15 21)(23)(37)
(4)(7)(8)(11) (*15 21)(23)(37)
(4)(7)(8)(11)(15)(21)(23)(37)
*/

/*クイックソート　非再帰版*/
//クイックソートは実質的に配列の分割を繰り返すだけ→分割すべき配列の区間を覚えておくスタックを用意すれば良い
void quicksort()
{
    int n;
    struct stack s;
    int p,q,i,j;

    create(&s);
    push(&s,n);push(&s,1);
    while(!empty(&s)){
        p = top(&s);pop(&s);
        q = top(&s);pop(&s);
        partition(p,q,&j,&i);
        if (p < j){
            push(&s,j);push(&s,p);
        }
        if (i < q){
            push(&s,q);push(&s,i);
        }
    }
}