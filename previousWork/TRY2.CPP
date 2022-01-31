#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
int h=50;
int r=5;
int turn=35,k;
int i;
int fl=0;
int chk1=0;
int co=0;

void begin(){
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(170,150,"Welcome to the JOURNEY!!");
	outtextxy(177,180,"Loading, Please Wait...");

	for(i=190;i<510;i++)
	{
		delay(5);
		setcolor(co);
		line(i,210,i,230);
		if(co==15)
			co=0;
		co++;
	}
	outtextxy(170,250,"Press Enter to continue ");
	// getch();
}
void mountains(){
	line(0,80,80,10);

line(80,10,160,80);

line(160,80,240,10);

line(240,10,320,80);

line(320,80,400,10);

line(400,10,480,80);

line(480,80,560,10);

line(560,10,680,80);
}
void rotate(float x1, float y1, float x2, float y2, int turns, int turn){
	float delx,dely,theta;
	delx=x2-x1;
	dely=y2-y2;
	theta=-turn*0.0174532925;
	if(turns==1){
			x2=((delx*cos(theta))-(dely*sin(theta))+x1);
			y2=((delx*sin(theta))+(dely*cos(theta))+y1);}
	else{
			x2=((delx*cos(theta))+(dely*sin(theta))+x1);
			y2=(-(delx*sin(theta))+(dely*cos(theta))+y1);}
	line(x1,y1,x2,y2);
}

void star(int midx,int midy){
       i=7;
		setcolor(i);
		setfillstyle(SOLID_FILL, i);

		/* top portion of star */
		line(midx, midy - 10, midx + 5, midy);
		line(midx, midy - 10, midx, midy + 5);
		line(midx + 5, midy, midx, midy + 5);
	      //	floodfill(midx + 1, midy + 1, i);

		setcolor(DARKGRAY);
	   //	setfillstyle(SOLID_FILL, DARKGRAY);
		line(midx + 5, midy, midx + 14, midy);
		line(midx + 5, midy, midx, midy + 5);
		line(midx + 14, midy, midx, midy + 5);
	       //	floodfill(midx + 3, midy +1, DARKGRAY);

		/* right portion of star */
		setcolor(i);
	     //   setfillstyle(SOLID_FILL, i);
		line(midx + 14, midy, midx, midy + 5);
		line(midx + 14, midy, midx + 4, midy + 5);
		line(midx + 4, midy + 5, midx, midy + 5);
	       //	floodfill(midx  , midy + 5, i);

		setcolor(DARKGRAY);
	      //  setfillstyle(SOLID_FILL, DARKGRAY);
		line(midx + 4, midy + 5, midx, midy + 5);
		line(midx + 4, midy + 5, midx + 11, midy + 16);
		line(midx + 11, midy + 16, midx, midy + 5);
	       //	floodfill(midx , midy + 5, DARKGRAY);

		/* bottom right portion of star */
		setcolor(i);
		setfillstyle(SOLID_FILL, i);
		line(midx + 11, midy + 16, midx, midy + 5);
		line(midx + 11, midy + 16, midx, midy + 9);
		line(midx, midy + 9, midx, midy + 5);
	       //	floodfill(midx + 1, midy + 9, i);
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		line(midx, midy + 9, midx, midy + 5);
		line(midx, midy + 5, midx - 11, midy + 16);
		line(midx - 11, midy + 16, midx, midy + 9);
	       //	floodfill(midx - 1, midy + 9, DARKGRAY);

		/* bottom left portion of star */
		setcolor(i);
		setfillstyle(SOLID_FILL, i);
		line(midx, midy + 5, midx - 11, midy + 16);
		line(midx - 4, midy + 5, midx - 11, midy + 16);
		line(midx - 4, midy + 5, midx, midy + 5);
	       //	floodfill(midx - 3, midy + 5, i);

		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		line(midx - 4, midy + 5, midx, midy + 5);
		line(midx - 14, midy, midx - 4, midy + 5);
		line(midx - 14, midy, midx, midy + 5);
	      //	floodfill(midx - 4, midy + 4, DARKGRAY);

		/* left portion of star */
		setcolor(i);
		setfillstyle(SOLID_FILL, i);
		line(midx - 5, midy, midx - 14, midy);
		line(midx - 14, midy, midx, midy + 5);
		line(midx - 5, midy, midx, midy + 5);
	      //	floodfill(midx - 5, midy + 1, i);

		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		line(midx - 5, midy, midx, midy + 5);
		line(midx, midy - 10, midx - 5, midy);
		line(midx, midy - 10, midx, midy + 5);
	      //	floodfill(midx - 3, midy, DARKGRAY);

		/* sleep for 2 seconds */
	       // sleep(2);
	       delay(2);

	}
void moon(){
	setcolor(WHITE);
arc(321,40,67,294,40);
	arc(351,40,113,250,40);
	setfillstyle(11,15);
	floodfill(294,30,WHITE);


}

void fly(int x,int y){

	
		setcolor(RED);
		circle(x,y,1);
		if(fl<2)
		{line(x,y,x-5,y-5);
		line(x,y,x+5,y-5); }
		else if(fl>=2&&fl<4)
	       {	line(x,y,x-6,y-2);
		line(x,y,x+6,y-2);    }
		else if(fl>=4&&fl<6)
		{line(x,y,x-7,y);
		line(x,y,x+7,y);}
		else
			fl=0;
		delay(100);
		fl++;
		// cleardevice();

}
void manh(int i)
{

// x=i+20;y=i+40;
// setcolor(RED);
	     //	float g=(r+10)/2;
		circle(100+r+10,r+10+i,r);
	   //	circle(100+(r+10)-g+2,i+2+(r+10)-(r+10)/2,5);
	    //	circle(100+(r+10)+g+2,i+2+(r+10)-(r+10)/2,5);
	     //	circle(100+r+10,i+r+10,3);
	     //	rectangle((100+r+10)-g+2,i+2+5+(r+10)+(r+10)/2,100+-2+(r+10)+g,i-2-5+(r+10)+(r+10)/2);
		line(100+r+10,i+(2*r)+10,100+r+10,i+r+h-3);

	line(100+r+10,12+i+((2*r)+h-30)/2,100+r+3,i+(((2*r)+h-30)/2)+25);
	line(100+r+10,12+i+((2*r)+h-30)/2,100+r+17,i+(((2*r)+h-30)/2)+25);
	line(100+r+10,i+r+h-5,100+r-2,i+(r+h-30)+40);
	line(100+r+10,i+r+h-5,100+r+22,i+(r+h-30)+40);
		delay(50);

}
void man(int i){

		float g=350;
		circle(r+10+i,g+r+10,r);
	      //	circle((r+10)-g+i+2,2+(r+10)-(r+10)/2,5);
	       //	circle((r+10)+g+i+2,2+(r+10)-(r+10)/2,5);
	       //	circle(r+10+i,r+10,3);
	      //	rectangle((r+10)-g+i+2,2+5+(r+10)+(r+10)/2,-2+(r+10)+g+i,-2-5+(r+10)+(r+10)/2);
		line(r+10+i,g+(2*r)+10,r+10+i,g+r+h-3);
		rotate(r+10+i,g+((2*r)+h-30)/2+12,r+10+i-25,g+(((2*r)+h-30)/2)-25,1,turn);
		rotate(r+10+i,g+((2*r)+h-30)/2+12,r+10+i+25,g+(((2*r)+h-30)/2)+25,0,turn);
		rotate(r+10+i,g+r+h-5,r+10+i-40,g+(r+h-30)-40,1,turn);
		rotate(r+10+i,g+r+h-5,r+10+i+40,g+(r+h-30)+40,0,turn);
				if(turn>90)
					k=-1;
				if(turn==35)
					k=1;
				turn+=k;
				delay(30);


}

void end(){
		for(int i=1;i<7;i++)
		{
				setcolor(i);
				 // set text style as
				 // settextstyle(font, orientation, size)
				 settextstyle(4,0,5);

				 // print text at coordinate x,y;
				 outtextxy(100,100,"THANK YOU");

				 setcolor(7-i);
				 settextstyle(4,1,5);

				 outtextxy(400,200,"THANK YOU");

				 delay(500);
		}
}
void scene(){
	setbkcolor(WHITE);

	setcolor(DARKGRAY);

	line(0,80,680,80);

	//draw mountains/

	mountains();

	//draw the Sun/

	arc(321,45,0,180,40);

	setfillstyle(SOLID_FILL,LIGHTCYAN);

	floodfill(20,60,DARKGRAY);

	//Fill color in mountains/

	setfillstyle(3,BROWN);

	floodfill(70,50,DARKGRAY);

	floodfill(230,50,DARKGRAY);

	floodfill(260,50,DARKGRAY);

	floodfill(380,50,DARKGRAY);

	floodfill(555,50,DARKGRAY);

	//Fill color in Sun/

	setfillstyle(SOLID_FILL,YELLOW);

	floodfill(340,50,DARKGRAY);

	//create hut and vase/

	rectangle(50,180,150,300);

	rectangle(150,180,320,300);

	rectangle(80,250,120,300);

	//Fill color in door/

	setcolor(DARKGRAY);

	setfillstyle(SOLID_FILL,BROWN);

	floodfill(112,260,DARKGRAY);

	//fill color in hut/

	setfillstyle(INTERLEAVE_FILL,RED);

	floodfill(300,200,DARKGRAY);

	setfillstyle(INTERLEAVE_FILL,RED);

	floodfill(60,290,DARKGRAY);

	line(100,100,50,180);

	line(100,100,150,180);

	line(100,100,300,100);

	line(300,100,320,180);
	setfillstyle(INTERLEAVE_FILL,BROWN);

	floodfill(301,110,DARKGRAY);

	floodfill(101,170,DARKGRAY);

	line(450,300,480,300);

	line(450,300,420,240);

	line(480,300,510,240);

	line(420,240,510,240);

	//Fill the color is vass/

	setfillstyle(SOLID_FILL,BROWN);

	floodfill(440,260,DARKGRAY);

	//create flowers/

	setcolor(GREEN);

	line(451,300,451,150);

	line(463,300,463,150);

	line(478,300,478,150);

	line(492,278,492,150);

	line(437,276,437,150);

	setcolor(RED);

	circle(451,148,4);

	setfillstyle(SOLID_FILL,RED);

	floodfill(451,148,RED);

	circle(463,148,4);

	floodfill(463,148,RED);

	circle(478,148,4);

	floodfill(478,148,RED);

	circle(492,148,4);

	floodfill(492,148,RED);

	circle(437,148,4);

	floodfill(437,148,RED);

	//draw grass/

	setcolor(GREEN);

	line(0,400,640,400);

	line(0,402,640,402);

	line(0,404,640,404);

	line(0,406,640,406);

	line(0,408,640,408);

	line(0,410,640,410);

	setfillstyle(SOLID_FILL,GREEN);

	floodfill(400,420,GREEN);

	//draw stairs/

	setcolor(BROWN);

	line(80,300,40,400);

	line(120,300,80,400);

	line(75,310,115,310);

	line(75,312,115,312);

	line(70,322,110,322);

	line(70,324,110,324);

	line(65,333,105,333);

	line(65,335,105,335);

	line(61,344,101,344);

	line(61,346,101,346);

	line(57,355,97,355);

	line(57,357,97,357);

	line(52,366,92,366);

	line(52,368,92,368);

	line(48,377,88,377);

	line(48,379,88,379);

	line(45,388,85,388);

	line(45,390,85,390);

}

void nscene(){
	setbkcolor(7);
	cleardevice();

	setcolor(8);

	line(0,80,680,80);

	//draw mountains/

	mountains();

	//draw the Sun/

	// arc(321,45,0,180,40);

	// setfillstyle(SOLID_FILL,7);

	// floodfill(20,60,15);

	//Fill color in mountains/

	setfillstyle(3,BROWN);

	floodfill(70,50,8);

	floodfill(230,50,8);

	floodfill(260,50,8);

	floodfill(380,50,8);

	floodfill(555,50,8);

	moon();
	

	star(20,60);
	star(50,10);
	star(110,10);
	star(140,60);
	star(430,10);
	star(460,60);
	star(500,60);
	star(530,10);
	star(590,10);
	setcolor(WHITE);
	line(320,80,680,400);
	line(480,80,680,260);
	line(320,80,480,80);
	setfillstyle(3,3);

	floodfill(350,100,15);

	delay(1000);
}

void main()

{

int gd=DETECT,gm;

initgraph(&gd,&gm,"c:\\turboc3\\bgi");

begin();

int tag=-1;
int qw,er;
qw=0,er=0;
while(1)
{	// moment of man
	// cleardevice();
	scene();
	setcolor(RED);
		tag++;
		// man horizontal
		if(tag<10){
			setfillstyle(SOLID_FILL,WHITE);

			floodfill(112,260,DARKGRAY);
		}
		if(tag<100)
			manh(tag+250);
		else{
			if(tag<=410)
			{man(tag);
				// setcolor(12);
				qw++;er++;
				if(100+er==145)
					er=0;
				if(680-qw==437)
					qw=0;
				fly(680-qw,100+er);
				fly(700-qw,150+er);
				fly(660-qw,120+er);
				fly(705-qw,100+er);
				

			}
			if(tag==411)
				{qw=0;er=0;}
			if(tag>411)
			{
				man(410);
				qw++;er++;
				if(145-er==100)
					er=0;
				if(437+qw==680)
					qw=0;
				fly(437+qw,145-er);
				fly(680+qw,150-er);
				fly(680+qw,120-er);
				fly(680+qw,130-er);
				if(er==0||qw==0)
					chk1=1;
			}
			if((145-er==100&&437+qw==680)||tag==600||chk1==1)
				break;
		}
			// delay(10);
			cleardevice();
	}
setbkcolor(WHITE);
cleardevice();
settextstyle(3,0,5);
outtextxy(50,200,"It was a great day,");
outtextxy(100,350,"time to go home.");
getch();
cleardevice();
scene();
tag=411;
while(1){
	// cleardevice();
	tag--;
	setcolor(RED);
	if(tag<10){
			setfillstyle(SOLID_FILL,WHITE);

			floodfill(112,260,DARKGRAY);
		}
	if(tag>100)
	{
		man(tag);
	}
	else{
		manh(tag+250);
	}
	if(tag==0)
		break;
	delay(30);
	cleardevice();
	scene();
}
setbkcolor(8);
cleardevice();

setcolor(RED);
settextstyle(5,0,5);
outtextxy(20,200,"Its a shady Night!");
getch();
cleardevice();
nscene();
nscene();
delay(1000);
getch();

cleardevice();
end();

getch();

closegraph();

}