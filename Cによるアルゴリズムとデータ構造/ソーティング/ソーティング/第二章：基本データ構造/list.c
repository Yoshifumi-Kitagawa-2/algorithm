/*
n個のデータの列を計算機上に表現するとき、各データに次のデータを指すポインタを持たせたものをリストという
リストでは、データの挿入と削除はポインタの付け替えによって行われる。
従って、一回の挿入/削除の操作はリスト中の要素数nに関係なくO(1)時間、つまり定数時間で実行できる。
一般に、配列でリストを実現する時、プログラムの初めで配列のサイズを指定しなければならない。
伸縮自在というリストの特徴を活かすためには、配列ではなくてポインタ型を使ってリストを構成するとよい。
リストの要素を次のようにデータ部とポインタ部をもつ構造体で定義する。
*/
/*ポインタ型によるリストの実現*/
struct element{
    char data;
    struct element *next;
};

struct element *new(){
    return((struct element *)malloc(sizeeof(struct element)));
}

struct element *create(){
    struct element *p;

    p = new();
    p->next = NULL;
    return(p);
}

void insert(struct element *l, int k, char item)
{
    struct element *p;

    if(k > 1)
        insert(l->next, k-1, item);
    else
    {
        p = new();
        p->data = item;
        p->next = l->next; //この二行は少しややこしい。p->nextにa3を指させる
        l->next = p; //l->nextにpを差させる。
    }
}
/*
a1→a2→a3→a4
↓
a1→a2→a5→a3→a4
になる
*/

void delete(struct element *l, int k)
{
    if (k > 1)
        delete(l->next, k-1)
    else l->next = l->next->next;
}

char access(struct element *l, int k)
{
    if (k > 1)
        return(access(l->next, k-1));
    else return(l->next->data);
}

int member(struct element *l, int x) //member(l,a)は、リスト中に要素aが含まれているか否かを判定する関数
{
    while(l->next != NULL && l->next->data != x)
        l = l->next;
    return(l->next != NULL);
}







