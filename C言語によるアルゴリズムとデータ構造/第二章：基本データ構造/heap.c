/*
スタックとキューでは、取り出す要素の順番が、それらが挿入された順番に依存していた。
ここでは、データ集合Sが順序集合であるとし、データ構造に格納されている要素で最小のものを取り出す操作を考える。
そのためのデータ構造がヒープで、優先順位付きキューとも呼ばれる。
ヒープは二分木で実現される。
データ集合の各要素を二分木の頂点に1対1に割り当てる。
ヒープ条件：親の要素は子の要素より小さい
完全二分木：高さはlog n
頂点vの要素を配列のi番目に配置すると、vの左の子は2i番目の配置、右の子は2i+1番目の配置らしい
2iを要素数nと比較することで、頂点vが子を持つかどうかがわかる。
変数sizeにはヒープの要素数nを入れる
*/
# define HMAX 1000

struct heap
{
    int box[HMAX];
    int size;
};

void swap(int *u, int *v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

void create(struct heap *h)
{
    h->size = 0;
}

void insert(struct heap *h, int item)
{
    int i;
    i = ++h->size;
    h->box[i] = item;
    while(i > 1 && h->[box] < h->box[i/2]){
        swap(&h->box[i], &h->[box[i/2]]); //親と子を比較して親の方が大きい間はswapする、またその親と子を比較する、という感じ
        i /= 2;
    }
}

int findmin(struct heap *h)
{
    return(h->box[1]);
}

void deletemin(struct heap *h)
{
    int i,k;
    i = 1;

    h->box[1] = h->box[h->size];//先頭に最後尾の要素に入れたやつを入れる。これで最小のやつは削除された。
    --h->size; //要素数を一つ減らす
    while (2*i <= h->size){ //anとその子の間でヒープ条件が成立するかを見ていく
        k = 2*i; //kはiの子
        if (k < h->size && h->box[k] > h->box[k+1]) //
            k++;
        if (h->box[i] <= h->box[k])
            break;
        swap(&h->box[i], &h->box[k]);
        i = k;
    }
}

