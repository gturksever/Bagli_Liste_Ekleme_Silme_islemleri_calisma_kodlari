#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct n
{
	int data;
	struct n* next;
};
typedef n node;

// malloc: ( geri döndürülecek veri tipi* ) malloc ( ayrýlacakalan * sizeof(veritipi ));

 node* start = NULL;
 node*  iter = NULL;



void sonaekle(int sona)        							//Baðlý listenin sonuna eleman ekleme fonksiyonu.
{
	 node* eklenecek = ( node*)malloc(sizeof( node));
	eklenecek->data=sona;
	eklenecek->next=NULL;
	
	if(start==NULL)
	{
		start=eklenecek;
	}
	
	else
	{
		iter = start;
		while(iter->next!=NULL)
		{
			iter=iter->next;
		}
		iter->next=eklenecek;
	}
}

void basaekle(int basa)        						     //Baðlý listenin baþýna eleman ekleme fonksiyonu.
{
	 node* basagelecek = ( node*)malloc(sizeof( node));
	basagelecek->data = basa;
	basagelecek->next = start;
	start=basagelecek;
}

void arayaekle(int bununOnuneEkle, int eklenecekSayi)    //Baðlý listenin arasýna eleman ekleme fonksiyonu 
{
	 node* arayaeklenecek =(node*)malloc(sizeof(node));
	arayaeklenecek->data=eklenecekSayi;
	iter=start;
	
	while(iter->next->data!=bununOnuneEkle)
	{
		iter=iter->next;
	}
	
	node* ondeki = (node*)malloc(sizeof(node));
	ondeki = iter -> next;
	iter -> next = arayaeklenecek;
	arayaeklenecek -> next = ondeki;
}

void yazdir()                                            //Yazdýr fonksiyonu
{
	
	
	iter=start;
	while(iter->next!=NULL)
	{
		printf("%d=>",iter->data);
		iter=iter->next;
	}
	printf("%d=>",iter->data);
	
}

void sondansil()                                         //Listenin sonundan eleman silme fonksiyonu
{
	
	if(start!=NULL)
	{
		iter=start;
		while(iter->next->next!=NULL)
		{
			iter=iter->next;
		}
		free(iter->next);
		iter->next=NULL;
	}
	else
	{
		printf("silinecek eleman kalmadý...\n");
	}	
	
}

void bastansil()
{
	node* ikinci = NULL;
	ikinci = start->next;
	free(start);
	start=ikinci;
}	

void aradansil(int x)
{
	if(start->data==x)
	{
		bastansil();
	}
	
	
	node* onceki =NULL;
	node* sonraki=NULL;
	
	iter=start;
	while(iter->next->data!=x)
	{
		iter=iter->next;
	}
	if(iter->next==NULL)
	{
		sonaekle(x);
	}
	onceki = iter;
	sonraki= iter->next->next;
	free(iter->next);
	onceki->next= sonraki;
}

int main()
{
	int secim,sona,basa,bununOnuneEkle,eklenecekSayi,sil;
	char cikis;
	while(1==1)
	
	{
		printf("Sona Eleman Eklemek  icin => 1\n");
		printf("Basa Eleman Eklemek  icin => 2\n");
		printf("Araya Eleman Eklemek icin => 3\n");
		printf("Sondan eleman silmek icin => 4\n");
		printf("Bastan eleman silmek icin => 5\n");
		printf("Aradan eleman silmek icin => 6\n");
		printf("\nyapmak istediginiz islemi seciniz.\n");
		scanf("%d",&secim);
		
		switch(secim)
		{
			case 1:
				printf("\n sona eklemek istediginiz elemani giriniz:\n");
				scanf("%d",&sona);
				sonaekle(sona);
				yazdir();
				printf("\n");
				break;	
					
			case 2:
				printf("\n basa eklemek istediginiz elemani giriniz:");
				scanf("%d",&basa);
				basaekle(basa);
				yazdir();
				printf("\n");
				break;
				
			case 3:
				printf("\n hangi sayinin onune ekleme yapacaksiniz.. ");
				scanf("%d",&bununOnuneEkle);
				printf("\n hangi sayiyi ekleyeceksiniz");
				scanf("%d",&eklenecekSayi);
				arayaekle(bununOnuneEkle,eklenecekSayi);
				yazdir();
			
			case 4:
				sondansil();
				yazdir();
				break;
				
			case 5:
				bastansil();
				yazdir();
				break;
				
			case 6:
				printf("silinecek sayiyi girin!");
				scanf("%d",&sil);
				aradansil(sil);
				
				
				
		}	
	}	
	
	getch();
	return 0;
}		
	
	

	
	
		
						
						
					
					
					
				
			
				
			
			 
			
