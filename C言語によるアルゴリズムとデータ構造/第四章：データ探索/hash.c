/*
member(x)は次のように実行される。
まず、h(x)を計算し、次にa[h(x)]が指しているリスト先頭の要素から順に調べ、xが入っているか否かを判定する。
delete(xの場合は、このようにして見つけたxをリストから削除する。
insert(x)はa[h(x)]が指しているリストの先頭にxを挿入すればよい。
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

void delete(struct element *l, int k)
{
    if (k > 1)
        delete(l->next, k-1)
    else l->next = l->next->next;
}

int member(struct element *l, int x) //member(l,a)は、リスト中に要素aが含まれているか否かを判定する関数
{
    while(l->next != NULL && l->next->data != x)
        l = l->next;
    return(l->next != NULL);
}
//ここからhash
struct element *a[m];

int h(int x){
    return(x % m);
}

void createhash(){
    struct element *create();
    int i;

    for (i = 0; i <= m-1;i++)
        a[i] = create();
}
void inserthash(int x){
    insert(a[h(x), 1, x]);
}

void deletehash(int x){
    deletall(a[h(x), x]);
}

int memberhash(int x){
    return(member(a[h(x), x]));
}

