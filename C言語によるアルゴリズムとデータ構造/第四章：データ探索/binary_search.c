/*二分探索*/

int member (int x)
{
    int n;
    int a[n];
    int m ,l,r;
    l = 1;
    r = n;
    do{
        m = (l+r)/2;
        if(x <= a[m])
            r = m-1;
        else l = m+1;
    }while (l<=r && x!=a[m])
    return(x == a[m]);
}