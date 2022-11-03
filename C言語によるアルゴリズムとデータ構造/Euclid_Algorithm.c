/*ユークリッドのアルゴリズム*/

int Euclid(int n, int m)
{
    if (m == 0)
        return(n);
    else return(Euclid(m, n % m));
}
