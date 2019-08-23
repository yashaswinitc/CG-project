#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 40.0
GLfloat theta=0;
float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;    
int light=1,day=1,plane=0,comet=0,xm=900,train=0,then=0;      
char ch;

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//sun
for(l=0;l<=30;l++)
 {
  glColor3f(1.0,0.9,0.0);
  draw_circle(100,625,l);

 }

//sunlines
glColor3f(1.0,0.9,0.0);
glLineWidth(2.0);
glBegin(GL_LINES);
glVertex2f(40,625);
glVertex2f(65,625);
glVertex2f(100,660);
glVertex2f(100,690);
glVertex2f(160,625);
glVertex2f(135,625);
glVertex2f(100,590);
glVertex2f(100,565);
glVertex2f(55,675);
glVertex2f(85,640);
glVertex2f(115,640);
glVertex2f(145,675);
glVertex2f(55,575);
glVertex2f(85,610);
glVertex2f(115,610);
glVertex2f(145,575);
glEnd();



//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);
		

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}




	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}






//grass
glColor3f(0.0,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

}

else
{

//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();




}
//track boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();

//platform

glColor3f(0.560784,0.560784,0.737255);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,250);
glVertex2f(1100,250);
glVertex2f(1100,160);
glEnd();

//table 1

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(140,190);
glVertex2f(140,210);
glVertex2f(155,210);
glVertex2f(155,190);
glEnd();

glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(130,210);
glVertex2f(130,215);
glVertex2f(225,215);
glVertex2f(225,210);
glEnd();

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(200,190);
glVertex2f(200,210);
glVertex2f(215,210);
glVertex2f(215,190);
glEnd();             

//table 2

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(390,190);
glVertex2f(390,210);
glVertex2f(405,210);
glVertex2f(405,190);
glEnd();

glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(380,210);
glVertex2f(380,215);
glVertex2f(475,215);
glVertex2f(475,210);
glEnd();

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(450,190);
glVertex2f(450,210);
glVertex2f(465,210);
glVertex2f(465,190);
glEnd();

//table 3

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(840,190);
glVertex2f(840,210);
glVertex2f(855,210);
glVertex2f(855,190);
glEnd();

glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(830,210);
glVertex2f(830,215);
glVertex2f(925,215);
glVertex2f(925,210);
glEnd();

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(900,190);
glVertex2f(900,210);
glVertex2f(915,210);
glVertex2f(915,190);
glEnd();

//track 
glColor3f(0.623529,0.623529,0.372549);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,100);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

//Railway track
//below
glColor3f(0.458,0.123,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100,0);
glVertex2f(-100,20);
glVertex2f(1100,20);
glVertex2f(1100,0);
glEnd();
//above track
glColor3f(0.458,0.123,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100,80);
glVertex2f(-100,100);
glVertex2f(1100,100);
glVertex2f(1100,80);
glEnd();

//1
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(0,20);
glVertex2f(0,80);
glVertex2f(10,80);
glVertex2f(10,20);
glEnd();
//2
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(80,20);
glVertex2f(80,80);
glVertex2f(90,80);
glVertex2f(90,20);
glEnd();
//3
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(150,20);
glVertex2f(150,80);
glVertex2f(160,80);
glVertex2f(160,20);
glEnd();

//4
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(220,20);
glVertex2f(220,80);
glVertex2f(230,80);
glVertex2f(230,20);
glEnd();

//5
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(290,20);
glVertex2f(290,80);
glVertex2f(300,80);
glVertex2f(300,20);
glEnd();
//6
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(360,20);
glVertex2f(360,80);
glVertex2f(370,80);
glVertex2f(370,20);
glEnd();
//7
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(430,20);
glVertex2f(430,80);
glVertex2f(440,80);
glVertex2f(440,20);
glEnd();
//8
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(500,20);
glVertex2f(500,80);
glVertex2f(510,80);
glVertex2f(510,20);
glEnd();
//9
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(570,20);
glVertex2f(570,80);
glVertex2f(580,80);
glVertex2f(580,20);
glEnd();
//10
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(640,20);
glVertex2f(640,80);
glVertex2f(650,80);
glVertex2f(650,20);
glEnd();
//11
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(710,20);
glVertex2f(710,80);
glVertex2f(720,80);
glVertex2f(720,20);
glEnd();
//12
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(770,20);
glVertex2f(770,80);
glVertex2f(780,80);
glVertex2f(780,20);
glEnd();
//13
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(840,20);
glVertex2f(840,80);
glVertex2f(850,80);
glVertex2f(850,20);
glEnd();
//14
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(900,20);
glVertex2f(900,80);
glVertex2f(910,80);
glVertex2f(910,20);
glEnd();
//15
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(970,20);
glVertex2f(970,80);
glVertex2f(980,80);
glVertex2f(980,20);
glEnd();
//16
glColor3f(0.4,0.4,0.4);
glBegin(GL_POLYGON);
glVertex2f(1040,20);
glVertex2f(1040,80);
glVertex2f(1050,80);
glVertex2f(1050,20);
glEnd();

//track bounbary
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(-100,100);
glVertex2f(-100,150);
glVertex2f(1100,150);
glVertex2f(1100,100);
glEnd();

//railway station boundary (fence)
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(0,250);
glVertex2f(0,310);
glVertex2f(5,320);
glVertex2f(10,310);
glVertex2f(10,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,250);
glVertex2f(90,310);
glVertex2f(95,320);
glVertex2f(100,310);
glVertex2f(100,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(140,250);
glVertex2f(140,310);
glVertex2f(145,320);
glVertex2f(150,310);
glVertex2f(150,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(190,250);
glVertex2f(190,310);
glVertex2f(195,320);
glVertex2f(200,310);
glVertex2f(200,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(240,250);
glVertex2f(240,310);
glVertex2f(245,320);
glVertex2f(250,310);
glVertex2f(250,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(340,250);
glVertex2f(340,310);
glVertex2f(345,320);
glVertex2f(350,310);
glVertex2f(350,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(390,250);
glVertex2f(390,310);
glVertex2f(395,320);
glVertex2f(400,310);
glVertex2f(400,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,250);
glVertex2f(950,310);
glVertex2f(955,320);
glVertex2f(960,310);
glVertex2f(960,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1000,250);
glVertex2f(1000,310);
glVertex2f(1005,320);
glVertex2f(1010,310);
glVertex2f(1010,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1050,250);
glVertex2f(1050,310);
glVertex2f(1055,320);
glVertex2f(1060,310);
glVertex2f(1060,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,295);
glVertex2f(950,305);
glVertex2f(1100,305);
glVertex2f(1100,295);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,265);
glVertex2f(950,275);
glVertex2f(1100,275);
glVertex2f(1100,265);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,295);
glVertex2f(0,305);
glVertex2f(400,305);
glVertex2f(400,295);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,265);
glVertex2f(0,275);
glVertex2f(400,275);
glVertex2f(400,265);
glEnd();

//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(50,185);
glVertex2f(50,255);
glVertex2f(65,255);
glVertex2f(65,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,250,l);
		draw_circle(80,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(50,290,l);
		draw_circle(70,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,315,l);
	}

//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(300,185);
glVertex2f(300,255);
glVertex2f(315,255);
glVertex2f(315,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,250,l);
		draw_circle(330,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(300,290,l);
		draw_circle(320,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(310,315,l);
	}


//railway station 
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(400,250);
glVertex2f(400,450);
glVertex2f(950,450);
glVertex2f(950,250);
glEnd();

//roof
glColor3f(1.0,0.123,0.0);
glBegin(GL_POLYGON);
glVertex2f(350,450);
glVertex2f(450,500);
glVertex2f(900,500);
glVertex2f(1000,450);
glEnd();
//side window 1
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(400,400);
glVertex2f(350,350);
glVertex2f(400,350);
glEnd();

//side window 2
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(950,400);
glVertex2f(1000,350);
glVertex2f(950,350);
glEnd();

//Wall
glColor3f(0.0,0.4,0.9);
glBegin(GL_POLYGON);
glVertex2f(425,250);
glVertex2f(425,400);
glVertex2f(450,425);
glVertex2f(550,425);
glVertex2f(575,400);
glVertex2f(575,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(600,250);
glVertex2f(600,400);
glVertex2f(625,425);
glVertex2f(725,425);
glVertex2f(750,400);
glVertex2f(750,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(775,250);
glVertex2f(775,400);
glVertex2f(800,425);
glVertex2f(900,425);
glVertex2f(925,400);
glVertex2f(925,250);
glEnd();

//window 1
glColor3f(0.9,0.4,0.7);
glBegin(GL_POLYGON);
glVertex2f(450,300);
glVertex2f(450,375);
glVertex2f(550,375);
glVertex2f(550,300);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(450,337.5);
glVertex2f(550,337.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(500,375);
glVertex2f(500,300);
glEnd();


//window 2
glColor3f(0.9,0.4,0.7);
glBegin(GL_POLYGON);
glVertex2f(800,300);
glVertex2f(800,375);
glVertex2f(900,375);
glVertex2f(900,300);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(800,337.5);
glVertex2f(900,337.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(850,375);
glVertex2f(850,300);
glEnd();

//door
glColor3f(0.91,0.89,0.124);
glBegin(GL_POLYGON);
glVertex2f(625,250);
glVertex2f(625,375);
glVertex2f(725,375);
glVertex2f(725,250);
glEnd();


//signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();


	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}
if(train==1)
{
//train carrier 3

glColor3f(0.8,0.1,0.8);
glBegin(GL_POLYGON);
glVertex2f(-600+i-xm,50); 
glVertex2f(-600+i-xm,300);
glVertex2f(-1000+i-xm,300);
glVertex2f(-1000+i-xm,50);
glEnd();

//top 3

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-590+i-xm,300); 
glVertex2f(-590+i-xm,310);
glVertex2f(-1010+i-xm,310);
glVertex2f(-1010+i-xm,300);
glEnd();

// Windows 3

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-825+i-xm,175); 
glVertex2f(-825+i-xm,285);
glVertex2f(-985+i-xm,285);
glVertex2f(-985+i-xm,175);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-615+i-xm,175); 
glVertex2f(-615+i-xm,285);
glVertex2f(-775+i-xm,285);
glVertex2f(-775+i-xm,175);
glEnd();

//carrier 2 wheels
for(l=0;l<50;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-675+i-xm,50,l);
	draw_circle(-925+i-xm,50,l);
}
//line wheel
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(-675+i-xm,50);
glVertex2f(-625+i-xm,50);
glBegin(GL_LINES);
glVertex2f(-675+i-xm,50);
glVertex2f(-670+i-xm,-750);

glBegin(GL_LINES);
glVertex2f(-675+i-xm,50); 
glVertex2f(-675+i-xm,100);
glBegin(GL_LINES);
glVertex2f(-675+i-xm,50);
glVertex2f(-725+i-xm,50);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(-925+i-xm,50);
glVertex2f(-875+i-xm,50);
glBegin(GL_LINES);
glVertex2f(-925+i-xm,50);
glVertex2f(-920+i-xm,-7500);

glBegin(GL_LINES);
glVertex2f(-925+i-xm,50); 
glVertex2f(-925+i-xm,100);
glBegin(GL_LINES);
glVertex2f(-925+i-xm,50);
glVertex2f(-975+i-xm,50);
glEnd();
//train carrier 2

glColor3f(0.8,0.1,0.8);
glBegin(GL_POLYGON);
glVertex2f(-150+i-xm,50); 
glVertex2f(-150+i-xm,300);
glVertex2f(-550+i-xm,300);
glVertex2f(-550+i-xm,50);
glEnd();

//top 2

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-140+i-xm,300); 
glVertex2f(-140+i-xm,310);
glVertex2f(-560+i-xm,310);
glVertex2f(-560+i-xm,300);
glEnd();

// Windows 2

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-375+i-xm,175); 
glVertex2f(-375+i-xm,285);
glVertex2f(-535+i-xm,285);
glVertex2f(-535+i-xm,175);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-165+i-xm,175); 
glVertex2f(-165+i-xm,285);
glVertex2f(-325+i-xm,285);
glVertex2f(-325+i-xm,175);
glEnd();

//connecter 2
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-550+i-xm,75); 
glVertex2f(-550+i-xm,95);
glVertex2f(-600+i-xm,95);
glVertex2f(-600+i-xm,75);
glEnd();

// carrier 2 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-225+i-xm,50,l);
	draw_circle(-475+i-xm,50,l);



//line wheel
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(-225+i-xm,50);
glVertex2f(-175+i-xm,50);
glBegin(GL_LINES);
glVertex2f(-225+i-xm,50);
glVertex2f(-180+i-xm,-7500);

glBegin(GL_LINES);
glVertex2f(-225+i-xm,50); 
glVertex2f(-225+i-xm,100);
glBegin(GL_LINES);
glVertex2f(-225+i-xm,50);
glVertex2f(-275+i-xm,50);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(-475+i-xm,50);
glVertex2f(-425+i-xm,50);
glBegin(GL_LINES);
glVertex2f(-475+i-xm,50);
glVertex2f(-430+i-xm,-7500);

glBegin(GL_LINES);
glVertex2f(-475+i-xm,50); 
glVertex2f(-475+i-xm,100);
glBegin(GL_LINES);
glVertex2f(-475+i-xm,50);
glVertex2f(-525+i-xm,50);
glEnd();
   }


// train carrier 1


glColor3f(0.8,0.1,0.8);
glBegin(GL_POLYGON);
glVertex2f(300+i-xm,50); 
glVertex2f(300+i-xm,300);
glVertex2f(-100+i-xm,300);
glVertex2f(-100+i-xm,50);
glEnd();

void *font2=GLUT_BITMAP_TIMES_ROMAN_24;
glColor3f(1.0,1.0,1.0);
glRasterPos2f(-30+i-xm,140);
        declare("RAJADHANI EXPRESS");

//top 1

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(310+i-xm,300); 
glVertex2f(310+i-xm,310);
glVertex2f(-110+i-xm,310);
glVertex2f(-110+i-xm,300);
glEnd();


// Windows 1

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(75+i-xm,175); 
glVertex2f(75+i-xm,285);
glVertex2f(-85+i-xm,285);
glVertex2f(-85+i-xm,175);
glEnd();



glBegin(GL_POLYGON);
glVertex2f(285+i-xm,175); 
glVertex2f(285+i-xm,285);
glVertex2f(125+i-xm,285);
glVertex2f(125+i-xm,175);
glEnd();

//connecter 1

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100+i-xm,75); 
glVertex2f(-100+i-xm,95);
glVertex2f(-150+i-xm,95);
glVertex2f(-150+i-xm,75);
glEnd();

// carrier 1 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-25+i-xm,50,l);
	draw_circle(225+i-xm,50,l);
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(-25+i-xm,50);
glVertex2f(25+i-xm,50);
glBegin(GL_LINES);
glVertex2f(-25+i-xm,50);
glVertex2f(-20+i-xm,-750);

glBegin(GL_LINES);
glVertex2f(-25+i-xm,50); 
glVertex2f(-25+i-xm,100);
glBegin(GL_LINES);
glVertex2f(-25+i-xm,50);
glVertex2f(-75+i-xm,50);
glEnd();



glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(225+i-xm,50);
glVertex2f(275+i-xm,50);
glBegin(GL_LINES);
glVertex2f(225+i-xm,50);
glVertex2f(220+i-xm,-750);

glBegin(GL_LINES);
glVertex2f(225+i-xm,50); 
glVertex2f(225+i-xm,100);
glBegin(GL_LINES);
glVertex2f(225+i-xm,50);
glVertex2f(175+i-xm,50);
glEnd();
}




//train base

glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,50); 
glVertex2f(350+i-xm,125);
glVertex2f(755+i-xm,125);
glVertex2f(820+i-xm,50);
glEnd();

//train control chamber

glColor3f(1.0,0.25,0.0);
glBegin(GL_POLYGON);
glVertex2f(360+i-xm,125); 
glVertex2f(360+i-xm,325);
glVertex2f(560+i-xm,325);
glVertex2f(560+i-xm,125);
glEnd();

//window

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(375+i-xm,175); 
glVertex2f(375+i-xm,315);
glVertex2f(545+i-xm,315);
glVertex2f(545+i-xm,175);
glEnd();


//train top
glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,325); 
glVertex2f(350+i-xm,350);
glVertex2f(570+i-xm,350);
glVertex2f(570+i-xm,325);
glEnd();

//tain engine
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(560+i-xm,125); 
glVertex2f(560+i-xm,225);
glVertex2f(755+i-xm,225);
glVertex2f(755+i-xm,125);
glEnd();
// D1
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(580+i-xm,125); 
glVertex2f(580+i-xm,225);
glVertex2f(590+i-xm,225);
glVertex2f(590+i-xm,125);
glEnd();


//D2
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(600+i-xm,125); 
glVertex2f(600+i-xm,225);
glVertex2f(610+i-xm,225);
glVertex2f(610+i-xm,125);
glEnd();

//D3
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(735+i-xm,125); 
glVertex2f(735+i-xm,225);
glVertex2f(745+i-xm,225);
glVertex2f(745+i-xm,125);
glEnd();

//tain smoke

glColor3f(0.196078,0.6,0.9);
glBegin(GL_POLYGON);
glVertex2f(650+i-xm,225); 
glVertex2f(650+i-xm,275);
glVertex2f(700+i-xm,275);
glVertex2f(700+i-xm,225);
glEnd();

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(640+i-xm,275); 
glVertex2f(640+i-xm,300);
glVertex2f(710+i-xm,300);
glVertex2f(710+i-xm,275);
glEnd();

//train head-light

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(755+i-xm,225); 
glVertex2f(765+i-xm,225);
glVertex2f(765+i-xm,185);
glVertex2f(755+i-xm,185);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(755+i-xm,225); 
glVertex2f(785+i-xm,225);
glVertex2f(755+i-xm,205);

glEnd();

// connector 1

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,75); 
glVertex2f(350+i-xm,95);
glVertex2f(300+i-xm,95);
glVertex2f(300+i-xm,75);
glEnd();

//train wheels 0

for(l=0;l<50;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(425+i-xm,50,l);
	draw_circle(700+i-xm,50,l);



glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(425+i-xm,50);
glVertex2f(475+i-xm,50);
glBegin(GL_LINES);
glVertex2f(425+i-xm,50);
glVertex2f(430+i-xm,-750);

glBegin(GL_LINES);
glVertex2f(425+i-xm,50); 
glVertex2f(425+i-xm,100);
glBegin(GL_LINES);
glVertex2f(425+i-xm,50);
glVertex2f(375+i-xm,50);
glEnd();



glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(700+i-xm,50);
glVertex2f(750+i-xm,50);
glBegin(GL_LINES);
glVertex2f(700+i-xm,50);
glVertex2f(705+i-xm,-750);

glBegin(GL_LINES);
glVertex2f(700+i-xm,50); 
glVertex2f(700+i-xm,100);
glBegin(GL_LINES);
glVertex2f(700+i-xm,50);
glVertex2f(650+i-xm,50);
glEnd();

   }

}

   //Railway Station Board

glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2f(500,500);
glVertex2f(500,520); 
glVertex2f(510,520);
glVertex2f(510,500);
glEnd();

glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2f(790,500);
glVertex2f(790,520); 
glVertex2f(800,520);
glVertex2f(800,500);
glEnd();

glColor3f(0.435294,0.258824,0.258824);
glBegin(GL_POLYGON);
glVertex2f(470,510);
glVertex2f(470,540); 
glVertex2f(500,550);
glVertex2f(850,550);
glVertex2f(880,540);
glVertex2f(880,510);
glEnd();

glColor3f(1.0,1.0,1.0);
     glRasterPos2f(500,520);
     declare("MANGLORE RAILWAY STATION");

glFlush();
}

/////addeddd
/*void text1a()
{
char string2[]="SDMIT";
void *font2=GLUT_BITMAP_TIMES_ROMAN_24;
int k;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(200,50,0);
for(k=0;k<5;k++)
        glutBitmapCharacter(font2,string2[k]);
}*/

void traffic_light()
{	
int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{

glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);

		glColor3f(0.0,0.7,0.0);
		draw_circle(1065,375,l);
		}
	  }

	else
	  {

for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);

		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
}



void vt1()
{
glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,650);
          declare("VELOCITY : 1.45Km/Hr");

           glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,610);
          declare("TIME : 27.5m");

glFlush();
glEnd();
}


void vt2()
{
glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,650);
          declare("VELOCITY : 0.37Km/Hr");

           glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,610);
          declare("TIME : 55m");
glFlush();
glEnd();
}


void vt3()
{
glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,650);
          declare("VELOCITY : 3.27Km/Hr");

           glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,610);
          declare("TIME : 18.33m");

glFlush();
glEnd();
}

void vt4()
{
glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,650);
          declare("VELOCITY : 9.01Km/Hr");

           glColor3f(0.0,0.0,0.0);
         glRasterPos2f(830,610);
          declare("TIME : 11m");
glFlush();
glEnd();
}

void Medium()
{	
	int Speed=60;
	glClearColor(1.0,1.0,1.0,1.0);

if(light==0 && (i>=0 && i<=1150)) 
 {

	 i+=Speed/10;
     m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }
 
 if(light==0 && (i>=2600 && i<=3000)) 
 {

	 i+=Speed/10;
	 m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0)
 {
	 i=i;
	 m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=Speed/10;
     m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>3500)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
if(c>500)
 {
	comet=0;
 }
vt3();
glutPostRedisplay();
 
 
}
void Speed()
{	
	int Speed=100;
	glClearColor(1.0,1.0,1.0,1.0);

if(light==0 && (i>=0 && i<=1150)) 
 {

	 i+=Speed/10;
     m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }
 
 if(light==0 && (i>=2600 && i<=3000)) 
 {

	 i+=Speed/10;
	 m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0)
 {
	 i=i;
	 m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=Speed/10;
     m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>3500)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
if(c>500)
 {
	comet=0;
 }
vt4();
glutPostRedisplay();
}
 



void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (i>=0 && i<=1150)) 
 {

	 i+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }
 
 if(light==0 && (i>=2600 && i<=3000)) 
 {

	 i+=SPEED/10;
	 m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0)
 {
	 i=i;
	 m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>3500)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
if(c>500)
 {
	comet=0;
 }
glutPostRedisplay();
}

void Slow()
{
int Speed=20;
glClearColor(1.0,1.0,1.0,1.0);

if(light==0 && (i>=0 && i<=1150)) 
 {

	 i+=Speed/10;
     m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }
 
 if(light==0 && (i>=2600 && i<=3000)) 
 {

	 i+=Speed/10;
	 m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0)
 {
	 i=i;
	 m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=Speed/10;
     m+=Speed/150;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>3500)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
if(c>500)
 {
	comet=0;
 }
vt2();
glutPostRedisplay();
}




void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;

	case 'r':
	case 'R':
		light=0;
		break;


		
	case 't':
case 'T':
		train=1;
		i=0;
                
		break;

    };

}



void myinit1()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}


/*
if(speed==100)
{
	glPushMatrix();
glColor3fv(color[0]);
	output(-11,6,"FrontInverted");
	glPopMatrix();
glRotatef(theta,0.0,0.0,1.0);
}
glFlush();
//glutSwapBuffers();
}
*/



void main_menu(int id)
{


switch(id)
	{
	
	case 1: glutIdleFunc(Slow);
                  /* vt2();
		glEnd();
                 glFlush();*/
	        	

		    break;
	
	case 2: glutIdleFunc(Medium);
		/*vt3();
		glEnd();
		glFlush();*/

      

	
		    break;
	case 3: glutIdleFunc(Speed);
		/*vt4();
		glEnd();
		glFlush();*/

		break;

	case 4:exit(0);
	}
	glutPostRedisplay();

}


void intro()
{
	//glColor3ub(147+100,105+80+50,203+50);
glColor3f(0.6,0.6,0.9);
glBegin(GL_POLYGON);
      	glVertex2i(0,0);
	  	glVertex2i(0,650);
      	glVertex2i(800+200,250+400);
        glVertex2i(0,250+400);
glEnd();
}

void texti()
{
char string[]="WELCOME TO CG MINI PROJECT";
void *font=GLUT_BITMAP_TIMES_ROMAN_24;
int k;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(380,590,0);
for(k=0;k<26;k++)
glutBitmapCharacter(font,string[k]);



char string1[]="MOVING TRAIN";
void *font1=GLUT_BITMAP_TIMES_ROMAN_24;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(460,520,0);
for(k=0;k<12;k++)
glutBitmapCharacter(font1,string1[k]);

char string8[]="CLICK LEFT BUTTON TO START";
void *font8=GLUT_BITMAP_HELVETICA_18;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(600,160,0);
for(k=0;k<26;k++)
glutBitmapCharacter(font8,string8[k]);


char string4[]="SUBMITTED BY:";
void *font4=GLUT_BITMAP_TIMES_ROMAN_24;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(50,400,0);
for(k=0;k<14;k++)
glutBitmapCharacter(font4,string4[k]);

char string5[]="YASHASWINI T C      4SU16CS122";
void *font5=GLUT_BITMAP_HELVETICA_18;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(50,350,0);
for(k=0;k<30;k++)
glutBitmapCharacter(font5,string5[k]);

char string6[]="ASHWINI KODI        4SU16CS123";
void *font6=GLUT_BITMAP_HELVETICA_18;
glColor3f(0.0,0.0,0.0);
glRasterPos3f(50,310,0);
for(k=0;k<30;k++)
glutBitmapCharacter(font6,string6[k]);


}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
   then=1;
    glutPostRedisplay();

	}

}


void display()
{

glClear(GL_COLOR_BUFFER_BIT);
if(then==0)
    {
		intro();
	    texti();
	}
	if(then==1)
	{

draw_object();
traffic_light();
}
 
glFlush();
glutSwapBuffers();

}



int main(int argc,char** argv)
{


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Traffic Control");
	glutDisplayFunc(display);
          glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit1();
 	int c_menu=glutCreateMenu(main_menu);
	glutAddMenuEntry("Slow",1);
	glutAddMenuEntry("Medium",2);
          glutAddMenuEntry("Fast",3);
	 glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);





/*int a=glutCreateWindow("WORKING");
	myinit();
	glutKeyboardFunc(keys);
	glutDisplayFunc(mydisplay);

*/

	glutMainLoop();
	return 0;
}

