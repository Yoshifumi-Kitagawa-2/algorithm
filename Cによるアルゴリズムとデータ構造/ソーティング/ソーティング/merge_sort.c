/*
工夫されたアルゴリズムの一つ
①二つに分割
②それぞれをソート
③マージ：それぞれの先頭を比較し、小さい方の要素を取り出すという操作を繰り返す。一方の列が空になったら、もう一方の残りを全て取り出す
これがざっくりとした流れ
マージソートは再帰的アルゴリズム
計算量はO(nlogn)
背景)
n = 2^kとする
長さnの列をマージソートでソートした時の時間をT(n)で表すと
T(n) = {
    c1 n = 1の時
    2T(n/2) + c2n n>1の時
}
T(n) = 2T(n/2) + c2n = 2(2T(n/4) + c2n/2) + c2n = ・・・＝2^k(T1) + kc2n =2^kc1 + kc2n = c1n + c2nlogn
*/

void merge(int p, int n)
{
    int i,j,k,h,b[AMAX];

    h = n/2;
    i = p;
    j = p + h;
    for (k = p; k < p + n; k++)
        if (j == p + n || (j < p + h && a[i] <= a[j]))
            b[k] = a[i++];
        else    b[k] = a[j++];
    for (k = p; k < p + n; k++)
        a[k] = b[k];
}

void msort(int p, int n)
{
    int h;
    if (n > 1)
    {
        h = n/2;
        msort(p,h);//a[p]...a[p+h-1]に入っている長さhの列をソート
        msort(p+h, n-h);//a[p+h]...a[p+n-1]に入っている長さn-hの列をソート
        merge(p,n);
    }
}

int main(void)
{
    msort(1,n);//a[1]...a[n]に入っている長さnの列をソート
}