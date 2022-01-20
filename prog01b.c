#include <stdio.h>
#define rep(a,b,c)  for(int a = b ; a < c ; a++)

double subave_ptr(double *b);   /* プロトタイプ宣言 */

int main()
{
  double a[3];

  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &a, a+1, a+2);

  double ave = subave_ptr( &a);   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("平均差し引き後のデータ:  %+.3f  %+.3f  %+.3f\n",*a, *(a + 1), *(a + 2));
  return 0;
}

/* 平均を計算して各データから引き算する関数。戻り値はその平均値。 */
double subave_ptr(double *b)
{

  double ave ;
  rep(i,0,3)ave += b[i];
  ave = ave / 3;
  printf("%lf\n",ave);
 
  
  rep(i,0,3){
    b[i] = b[i] - ave;
  }
    return ave;

}
