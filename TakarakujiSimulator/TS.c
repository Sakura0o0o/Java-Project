#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

  int kuchi;
  int sum = 0;
  int daikin = 0;
  int num = 0;
  int countera = 0;
  int counterb = 0;
  int counterc = 0;
  int counterd = 0;
  int countere = 0;
  int counterf = 0;
  int counterg = 0;
  int counterh = 0;
  int counteri = 0;

  printf("*****ジャンボ宝くじ*****\n");
  printf("何口買いますか? (1口300円のバラ売りです):");
  scanf("%d",&kuchi);

  srand(time(NULL));

  
  for(int i = 0; i < kuchi; i++){
    num = rand()%20000000+1;

    //2000万分の1
    if(num == 2){
      sum += 700000000;
      countera++;
    }

    //1000万分の1
    if(num == 1 || num == 3){
      sum += 150000000;
      counterb++;
    }

    //250万分の1
    if(num >= 4 && num <= 11){
      sum += 10000000;
      counterc++;
    }
	
    //100万分の1
    if(num >= 12 && num <= 20){
      sum += 100000;
      counteri++;
    }

    //5万分の1
    if(num >= 21 && num <= 420){
      sum += 1000000;
      counterd++;
    }

    //1万分の1
    if(num >= 421 && num <= 2420){
       sum += 50000;
       countere++;
    } 

    //1000分の1
    if(num >= 2421 && num <= 22420){
      sum += 10000;
      counterf++;
    }

    //100分の1
    if(num >= 22421 && num <= 222420){
      sum += 3000;
      counterg++;
    }

    //10分の1
    if(num >= 222421 && num <= 2222420){
      sum += 300;
      counterh++;
    }

  }

  daikin = kuchi * 300;

  printf("\n");
  printf("***結果***\n");
  printf("代金　：%d円\n",daikin);
  printf("当選額：%d円\n",sum);
  printf("利益　：%d円\n",sum-daikin);
  printf(" **内訳**\n");
  printf("１等　　：%d\n",countera);
  printf("前後　　：%d\n",counterb);
  printf("２等　　：%d\n",counterc);
  printf("３等　　：%d\n",counterd);
  printf("４等　　：%d\n",countere);
  printf("５等　　：%d\n",counterf);
  printf("６等　　：%d\n",counterg);
  printf("７等　　：%d\n",counterh);
  printf("組み違い：%d\n",counteri);
  
  
  

    
 
}
