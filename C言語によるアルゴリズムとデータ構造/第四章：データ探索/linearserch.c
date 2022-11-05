#define NUM 100000
#define NAME_MAX 8

typedef struct {
    int number;
    char name[NAME_MAX];
} DATA_T;

int linearSearch(DATA_T data[], int number, int num_data) {
    int i;

    for (i = 0; i < num_data; i++) {

        /* 文字列を先頭から順に１つずつ比較 */
        if (data[i].number == number) {

            /* 一致したら探索終了 */
            return i;
        }
    }

    /* 見つからなかった場合 */
    return -1;
}