#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<windows.h>
int main()
{
	initwindow(500,500);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	char date[100];
	char tm[100];
	while(true){
		outtextxy(205,17,"____Clock_____");
		_strdate(date);
		_strtime(tm);
		outtextxy(340,430,tm);
		outtextxy(360,450,date);
		outtextxy(380,470,"made by samanta");
		//system("cls");
	//Time related variable
	time_t t;
	struct tm *currenttime;
	char a[100];

	//To get mid point of graph
	int midx=getmaxx()/2;
	int midy=getmaxy()/2;

	//variable for sorting hour,minute and second info

	int IMS; //for min,hour,sec
	t=time(0);
	currenttime=localtime(&t);
	//coordinate info for hours
	int CoordsForHourX[12]={50,87,100,87,50,0,-50,-87,-100,-87,-50,0};//using calculator
	int CoordsForHourY[12]={-87,-50,0,50,87,100,87,50,0,-50,-87,-100};
	//coordinate info for minutes
		int CoordsForMinSecX[60]={0,18,35,53,69,85,100,114,126,138,
		                         147,155,162,166,169,170,169,166,162,155,
								 147,138,126,114,100,85,69,53,35,18,0,
								 -18,-35,-53,-69,-85,-100,-114,-126,-138,-147,-155,-162,-166,-169,-170,-169,-166,
									-162,-155,-147,-138,-126,-114,-100,-85,-89,-53,-35,-18};
		int CoordsForMinSecY[60]={-170,-169,-166,-162,-155,-147,-138,-126,-114,-100,-85,-69,-53,-35,-18,0,18,35,53,69,85,100,114,126,138,147,155,162,166
		                           ,169,170,169,166,162,155,147,138,126,114,100,85,69,53,35,18,0,-18,-35,-53,-69,-85,-100,-114,-126,-138,-147,-155,-162,-166
		                           ,-169};
	//drawing the circle
	circle(midx,midy,200);
	//for printing numbers
	outtextxy(midx+95-5,midy-165-5,"I");
	outtextxy(midx+165-5,midy-95-5,"II");
	outtextxy(midx+190-5,midy-0-7,"III");
	outtextxy(midx+165-7,midy+95-7,"IV");
	outtextxy(midx+95-5,midy+165-10,"V");
	outtextxy(midx+0-3,midy+190-10,"VI");
	outtextxy(midx-95+0,midy+165-10,"VII");
	outtextxy(midx-165-2,midy+95-10,"VIII");
	outtextxy(midx-190-3,midy-0-7,"IX");
	outtextxy(midx-165-5,midy-95-3,"X");
	outtextxy(midx-95-5,midy-165-5,"XI");
	outtextxy(midx+0-6,midy-190-5,"XII");
	strftime(a,100,"%I",currenttime);
	sscanf(a,"%d",&IMS);
	line(midx,midy,midx+CoordsForHourX[IMS-1],midy+CoordsForHourY[IMS-1]);
	strftime(a,100,"%M",currenttime);
	sscanf(a,"%d",&IMS);
	line(midx,midy,midx+CoordsForMinSecX[IMS],midy+CoordsForMinSecY[IMS]);
	strftime(a,100,"%S",currenttime);
	sscanf(a,"%d",&IMS);
	line(midx,midy,midx+CoordsForMinSecX[IMS],midy+CoordsForMinSecY[IMS]);
	//Sleep(90);
	delay(1000);
	cleardevice();
}
}
