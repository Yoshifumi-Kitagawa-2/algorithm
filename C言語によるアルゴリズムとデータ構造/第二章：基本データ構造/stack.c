/*
スタックについて勉強するファイル
参考URL：http://www.cc.kyoto-su.ac.jp/~yamada/ap/stack.html
push: 追加されたデータは順次，下から上へ積み重なるように貯まっていく。
pop: データを取り出すときには，積み重なった一番上のデータから取り出す。取り出したデータは，スタックから取り除かれる。
次のようなコーディングで，とりあえず，スタックの機能をなすものを構築できる。
まずは，マクロ定数の定義とスタック本体の宣言である。
*/
#include <stdio.h>
# define    STACK_SIZE 100  //スタックに積むことのできるデータの最大個数
# define    SUCCESS    1    /* 成功 */
# define    FAILURE    0    /* 失敗 */

typedef int data_t;         /* スタックに貯えるデータの型 */

data_t stack_data[STACK_SIZE];  /* スタック本体 */
int stack_num;              /* スッタク内のデータ数 */

/*
data_t という新しい名前の型を定義しておく。以後，スタックの要素の型はすべて data_t 型とする。このようにする理由は，要素の型を変更するときに非常に都合が良いからである。
次に，データをプッシュする関数 push を定義する。
int push(data_t push_data) の仕様
data_t 型の引数 push_data をとり，それをスタックstack_data に積み，整数値 SUCCESS を関数値として返す。
ただし，スタックが満杯であるときは積まずに，整数値 FAILURE を関数値として返す。
*/
int push(data_t push_data)
{
    if(stack_num < STACK_SIZE){
        stack_data[stack_num] = push_data;
        stack_num ++;
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}
/*
stack_num は，現在スタックに積まれているデータの個数を保持しているが、
それは stack_data[0] から stack_data[stack_num - 1] までにデータが入っていることを意味している。
したがって，新しいデータは stack_data[stack_num] に保存することになる。そして保存した後， stack_num の値を1増やす。
*/

//次に，データを取り出す（ポップする）関数 pop を作る。
/*
int pop(data_t *pop_data) の仕様
スタックが空でないとき，stack_data にある最後の値を *pop_data に代入し，stack_num の値を 1 減じて、戻り値 SUCCESS を返す。
スタックが空であるときには何もしないで、戻り値 FAILURE を返す（*pop_data の値も変化させない）。
*/
int pop(data_t  *pop_data)
{
    if (stack_num > 0){
        stack_num --;
        *pop_data = stack_data[stack_num];
        return(SUCCESS);
    }
    else{
        return(FAILURE);
    }
}

/*
さて，以上で，スタックとそれを取り扱うための関数とができた。
これらが働くとき，スタック上のデータがどのように変化するかを逐次見るために，スッタク内のデータを表示する関数を作っておく。
*/
void    stackPrint()
{
    int i;

    printf("stack [");
    for (i = 0; i < stack_num; i++){
        printf("%3d", stack_data[i]);
    }
    printf("]\n");
}

int main(void)
{
    int i,p;

    stack_num = 0;
    for(i = 1; i <= 5; i++){
        push(i); /*1から5までの数値をpush*/
        printf("push %2d :", i);
        stackPrint();
    }
    for(i = 1; i <= 3; i++){
        pop(&p); /* 3 回だけ pop */
        printf("pop  %2d :", p);
        stackPrint();
    }
    for (i = 6; i <= 9; i++) {
        push(i);  /* 6 から 9 までの数値を push */
        printf("push %2d :", i);
        stackPrint();
    }
    while(stack_num  > 0){
        pop(&p);
        printf("pop  %2d :", p);
        stackPrint();
    }
}

/*
プログラムの最初でスタックのデータ数 stack_num を 0 に初期化している。これは絶対に忘れてはならない操作である。
5 個のデータを push した後に 3回 pop すると，残りのデータは 2 個になる。それに引き続いて push した場合には，残りのデータの後ろに保存される。出力結果を良く見て欲しい。
最後に，スタックに残っているデータを全て pop して取り出しているが，ここで，スタックが空になっていないかどうかを， stack_num > 0 によって判断している。 
*/

//前節で構築したスタックには，問題点がいくつかある。それらを直していこう。

/*
①構造体を用いる
問題点の一つ目は，スタックの本体が stack_num と stack_data という二つの変数からできていることである。
これら二つは密接に関連しあい一つのスタックを構成するものであるから，それらをまとめて構造体とすることにする。
*/

#define STACK_SIZE  100
#define SUCCESS     1
#define FAILURE     0

typedef int data_t;

typedef struct{
    int num;
    data_t  data[STACK_SIZE];
}stack_t;
/*
最初の部分は，定数マクロ定義と，データ型の定義である。
最後の４行は，構造体を定義する部分 struct {int num; data_t data[STACK_SIZE];} 
という構造体型を stack_t という新しい名前の型として定義している。
*/

/*
②大域変数を用いない
問題点の二つ目は， push や pop などの関数が，大域変数である stack_num と stack_data に対してのみ働くようになっている点である。
これでは，スタックを同時に二つ動かすことができない。
また，大域変数はできるだけ用いない方が良いという観点からも，これは修正すべきである。
そこで，スッタクの実体を大域変数としてあらかじめ用意するのではなく，必要なときにスタックを何個でも宣言して使えるようにする。
そのためには， push や pop などの関数に引数として対象とするスタックを引き渡す必要がある。
また， push や pop はそのスタックの実体に対して操作を施す必要があるので，スタックの値ではなくスタックの実体を指すポインタを引き渡さなければならない。
*/

/*
int push(stack_t *stk, data_t push_data) の仕様
stack_t 型ポインタ stk と、 data_t 型の値 push_data とを引数にとり、stk が指す場所にあるスタックに、データ push_data を追加する。
追加に成功すると SUCCESS を戻り値として返す。スッタクが満杯で追加に失敗すると，FAILURE を戻り値として返す
*/

int push(stack_t *stk, data_t push_data)
{
    if (stk->num < STACK_SIZE)
    {
        stk->data[stk->num] = push_data;
        stk->num ++;
    }
    else{
        return FAILURE;
    }
}

/*
引数 stk は stack 型の変数を指すポインタである。
stk が指す場所にある stack 型構造体のメンバ，たとえば num を参照するには， stk->num とすればよい。
これは (*stk).num と同等であるが，stk->num の方が書くのも楽だし，見た目も良い。
*/

/*
int pop(stack_t *stk, data_t *pop_data) の仕様
stack_t 型ポインタ stk を引数にとり、stk が指す場所にあるスタックからデータを取り出し（stk->num の値を１つ減じ），
その値を *pop_data に代入し、 SUCCESS を戻り値として返す。スタックが空であった場合は，FAILURE を戻り値として返す以外、何もしない。
*/

int pop(stack_t *stk, data_t *pop_data)
{
    if (stk->num > 0){
        stk->num --;
        *pop_data = stk->data[stk->num];
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}

/*
void stackPrint(stack_t *stk) の仕様
stack_t 型ポインタ stk を引数にとり、stk が指す場所にあるスタックにある全てのデータを表示する。
*/

void stackPrint(stack_t *stk)
{
    int i;

    printf("stack [");
    for (i = 0; i < stk->num; i++){
        printf("3%d", stk->data[i]);
    }
    printf("]\n");
}

int main(void)
{
    stack_t stk;
    int i,p;

    stk.num = 0; /*スタックのデータ数を0に初期化*/
    for (i = 1; i <= 4; i++)
    {
        push(&stk, i);
        printf("push %2d :", i);
        stackPrint(&stk);
    }
    while (stk.num > 0)
    {
        pop(&stk, &p);
        printf("pop %2d :", p);
        stackPrint(&stk);
    }
}