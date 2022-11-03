/*
キュー：先入先出
スタックに要素を入れる：push
削除：pop
一次元入れるbox[1..n]とキューの先頭と最後尾を示す変数front、rearで表現する
*/
# define QMAX 1000
struct queue
{
    char box[QMAX];
    int front,rear; //rearは最後尾
}

void create(struct queue *q)
{
    q->front = 1;
    q->rear  = 0;
}

void insert(struct queue *q, char item)
{
    q->box[++q->rear] = item;
}

void delete(struct queue *q)
{
    ++q->front;
}

int empty(struct queue *q)
{
    return(q->rear < q->front);
}

char top(struct queue *q)
{
    return(q->box[q->front]);
}





