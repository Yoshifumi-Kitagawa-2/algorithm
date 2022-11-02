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
この部分は、pop の返す値が SUCCESS である間続ける、次のような while ループに書き換えることもできる。
*/
