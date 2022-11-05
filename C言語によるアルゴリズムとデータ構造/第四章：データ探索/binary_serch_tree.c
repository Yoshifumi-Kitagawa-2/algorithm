/*
二分探索木
二分探索ではSの要素は配列に格納されるため、要素の探索は効率が良いが、要素の挿入や削除を頻繁に行うには都合が悪い。
二分探索木ではデータの探索・挿入・削除を効率よく行うためのデータ構造である。
各要素vの値は左の子より値が大きく、右の子よりも小さい

基本操作
1：member(x)・・・xがSの要素であるか否かを判定
2：insert(x)・・・xがSの要素でないなら集合Sにxを加える
3：delete(x)・・・xがSの要素ならxを除去する。

この3つの基本操作を伴うデータ構造は一般に辞書と呼ばれる。
*/

/*
2分探索木上の基本操作①
*/

struct vertex{
    int data;
    struct vertex *l, *r;
}*root;

struct vertex *new(){
    return((struct vertex *)malloc(sizeof(struct vertex)));
}

struct vertex *create(){
    struct vertex *p;

    p = new();
    p->data=0;
    p->r=NULL;
    return(p);
}

int member(int x){
    struct vertex *p;

    p = root;
    do{
        if (x < p->data)
            p=p->l;
        else  p=p->r;
    }while(p != NULL && x != p->data);
    return(p!=NULL);
}

/*2分探索木上の基本操作②*/
void insert(int x){
    struct vertex *p, *f;
    p = root;
    do{
        f = p;
        if (x < p->data){
            p=p->l;
        else p=p->r;
    }while(p!= NULL);
    p = new();
    p->l = p->r = NULL;
    if (x < f->data)
        f->l = p;
    else f->r = p;
} 

/*二分探索木上の基本操作③*/
void delete(int x){
    struct vertex *p, *f, *q;
    p = root;
    do{
        f = p;
        if (x < p->data){
            p=p->l;
        else p=p->r;
    }while(x!=p->data);
    
    if (p->l == NULL || p->r == NULL){
        if (p->r == NULL)
            q = p->l;
        else q= p->r;
        if (f->l == p)
            f->l = q;
        else f->r = q;
    }
    else{
        q = p->r;
        f = q;
        while(q->l != NULL){
            f = q;
            q = q->l;
        }
        p->data = q->data;
        if (q = f)
            p->r = q->r;
        else f->l = q->r;
    }
}