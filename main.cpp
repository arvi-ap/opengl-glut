//Facebook Application type
//By Aravind Prabhu & Akshay Kumar Crasta
//this is a web version of the facebook appllication with most of its functionality

#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define pi 3.142
#define true 1
#define false 0
#define GAMESIZE 3

int field[GAMESIZE][GAMESIZE];//tic tac toe
int win=0;//tic tac toe
int window2=0;
static int who=1;

float scrollin=0;
int ichh=0;
int ichc=0;
int loginfailed=0;
float fbangle_s=0;
int admove=0;

GLfloat spid[]={133,941,141,930,154,919,169,909,185,900,197,893,218,883,231,876,249,867,267,856,285,845,294,
839,300,829,305,819,307,800,309,787,309,771/**/,304,755,298,735,294,720,291,708,288,692,285,680,285,633,285,647,
285,629,285,618,289,594,294,578,301,562,309,550,319,539,330,529,339,527,355,521,372,520,376,519,386,519,409,
523,428,533,440,543,450,556,457,572,464,591,467,606,469,623,469,643,469,659,467,673,465,689,461,714,457,730,
453,743,450,757,445,772,445,769,446,779,449,815,453,826,472,845,481,853,494,860,502,864,517,873,535,
880,550,890,568,898,579,906,597,915,606,924,622,941};

GLfloat chin[]={307,768,319,780,334,799,355,821,361,826,374,828,391,826,403,818,419,801,434,783,445,768,451,755};

GLfloat left[]={307,608,301,625,300,637,299,647,299,657,301,669,305,678,308,686,315,694,321,701,330,711,338,708,
345,704,350,700,357,691,361,682,362,674,363,670,339,647,336,643,323,628,319,620,308,607};

GLfloat right[]={446,608,450,616,453,624,455,637,456,648,454,660,451,671,448,680,442,689,433,702,425,709,418,708,
410,704,401,696,395,685,392,676,390,668,395,662,401,658,408,652,422,636,431,626,439,615,446,608};

GLfloat facetexture[]={388,777,395,760,407,750,411,735,421,721,425,695,438,677,435,660,438,648,431,634,430,615,419,
601,415,582,396,588,382,581,369,568,359,579,338,585,326,580,320,594,306,606,304,624,300,637,300,659,296,681,306,692,
308,710,318,729,323,751,336,760,347,780,388,777};

GLfloat mid[]={362,696,372,692,383,696,391,689,399,678,398,663,387,655,380,654,373,650,367,654,361,654,367,658,350,664,344,679,349,687};
GLsizei w=1000,h=1000;
GLfloat wratio=1, hratio=1;
int hi=0,hello=0;
int flag=0;
int chating=0;
int chatflag=0;
int moveup=0;
int phase=1;//which screen 1,2,3
int choise=1;//user_profile_screen choice between photo,friends etc
char name[20],password[20];
char chattext[20],userchat[20];
char c_username[20],c_mobile[20],c_vermobile[20],c_password[20],c_birthday[20];
char post[30];
int page=1;
int likeon1=0,likeon2=0,likeon3=0,likeon4=0,likeon5=0,likeon6=0,likeon7=0,likeon8=0,likeon9=0;
int f_uname=0,f_mob=0,f_remob=0,f_birth=0,f_pass=0;
int fbangle=200;
int chaton=0;
int likeon=0;
int success=0;
int fg=0;
int mov2=1,mov=1;
int frameNumber = 0;
int c_flag=0;
int revs=0;
int create=0;
//int key;
int ich,jch;//user name and password increment for login
int u,m,rm,p,b;
int play_login=false;
int typeamessage=0,chatinput=0;
int pokeon=0,eventon=0,poston=0;
int postit=0;
float cxx=0;

void myreshape(int w,int h);//reshape
void render();//the display function
void init();
void login_screen();// screen 1 : login screen
void profile_screen();//screen 2 : profile screen
void user_profile_screen();//screen 3: user profile screen
//char fbname[10]="facebook";//name of the program
char username[20]="Siddarth Malhotra";
void keyboard(unsigned char key,int x,int y);
void Specialkey(int key, int x, int y);
void mouse(int btn, int state ,int x0,int y0);
void passivemouse(int x,int y);
void Text(const char *string,float x , float y,float colorx,float colory,float colorz,void *font);//write a string at x and y position
void HugeText(char *string,float x,float y,float colorx,float colory,float colorz,float line_width,float scale);
void password_text(char *string,float x,float y)  ;
//login funcs

void headbox();
void createaccount();
void loginscreenvedio();
void message_screen();
void account_created();
void developers();

//end of login funcs
//shapes
void circlearc(float h,float k,float r);
void semicircle(float h,float k,float r);
void semicirclearc(float h,float k,float r);
void ellipse(float h,float k,float r1,float r2);
void semicirclearcnormal(float h,float k,float r,int fill);
void circle(float h,float k,float r);
void  man();

//shapes end
//profile funcs
void profilehead();
void newsfeed();
void profileinfo();
void ad();
void logo();
void profilepic(float X,float Y,float s);
void nopropic(float,float,float,float,float,float);
void req();
void likebon();
void likeboff();
void nextbutton();
void prevbutton();
void scrollbar();
void page1();
void page2();
void page3();
void page4();
void page5();
void page6();
void page7();
void page8();
void page9();
void windmill();


//end of profile funcs
//user profile funcssssssssss
void chatbox();
void timeline();
void photos();
void About();
void friends();
void chat();
void profilebody();
void bodyt(float X,float Y,float s);
void prolin(float X,float Y,float s);
void prolin2(float X,float Y,float s);
void userprofilepic();
//functionality
void authenticateuser();
void userlogin();
void playbutton();

void chatinteraction();
void chatdataflow();
void authenticate_createaccount();
void c_accountlogin();
void pokes();
void pokesymbol();
void events();
void posting();

 void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);       // set white background color
    glColor3f(0.0, 0.0, 0.0);          // set the drawing color
 	glPointSize(4.0);
 	glLineWidth(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
// draw the field
glColor3f(0,0,0);
Text(">>INSTRUCTIONS",450,440,0.8,0.3,0.2,GLUT_BITMAP_TIMES_ROMAN_24);
Text(">>Minimize to Exit!!",450,400,0,0,0,GLUT_BITMAP_9_BY_15);
Text(">>Two player game!!",450,370,0,0,0,GLUT_BITMAP_9_BY_15);
Text(">>Right click to",450,350,0,0,0,GLUT_BITMAP_9_BY_15);
Text(" RESTART!!",500,335,0,0,0,GLUT_BITMAP_9_BY_15);
 	glLineWidth(4.0);
 	glColor3f(rand()%2-0.2,rand()%2-0.3,rand()%2-0.3);
	glBegin(GL_LINES);
		glVertex2i(100, 200);
		glVertex2i(400, 200);
		glVertex2i(200, 100);
		glVertex2i(200, 400);
		glVertex2i(100, 300);
		glVertex2i(400, 300);
		glVertex2i(300, 100);
		glVertex2i(300, 400);
	glEnd();
	glColor3f(0,0,0);
 	glLineWidth(6.0);
//draw the state of the game
	for (int x=0;x<GAMESIZE;x++)
		for (int y=0;y<GAMESIZE;y++){
		switch (field[x][y])
		{
		case 1: // the cross
			glBegin(GL_LINES);
			glVertex2i(120+x*100, 120+y*100);
			glVertex2i(180+x*100, 180+y*100);
			glVertex2i(180+x*100, 120+y*100);
			glVertex2i(120+x*100, 180+y*100);
			glEnd();
			break;
		case 2: // the circle
			double angle =0;
			double angleInc = 2*M_PI/16;
			glBegin(GL_LINE_LOOP);
			glVertex2d(40*cos(angle) + 150+100*x,40*sin(angle)+150+100*y);
			for (int k=0;k<16;k++)
			{
			angle+=angleInc;
			glVertex2d(40*cos(angle) + 150+100*x,40*sin(angle)+150+100*y);
			}
			glEnd();
		}
		}
//detect a winner
 	glLineWidth(8.0);
// x winner
	for (int x=0;x<GAMESIZE;x++){
		if ((field[x][0]+field[x][1]+field[x][2]>0) && (field[x][0]==field[x][1]) && (field[x][1]==field[x][2]))
		{
		// x-winner detected
		glBegin(GL_LINES);
		glVertex2i(150+x*100, 100);
		glVertex2i(150+x*100, 400);
		glEnd();
		win=1;
		}
	}
// y winner
	for (int y=0;y<GAMESIZE;y++){
		if ((field[0][y]+field[1][y]+field[2][y]>0) && (field[0][y]==field[1][y]) && (field[1][y]==field[2][y]))
		{
		// y-winner detected
		glBegin(GL_LINES);
		glVertex2i(100,150+y*100);
		glVertex2i(400,150+y*100);
		glEnd();
		win=1;
		}
	}
// diagonal winner
		if ((field[0][0]+field[1][1]+field[2][2]>0) && (field[0][0]==field[1][1]) && (field[1][1]==field[2][2]))
		{
		glBegin(GL_LINES);
		glVertex2i(100,100);
		glVertex2i(400,400);
		glEnd();
		win=1;
		}

// diagonal winner
		if ((field[0][2]+field[1][1]+field[2][0]>0) && (field[0][2]==field[1][1]) && (field[1][1]==field[2][0]))
		{
		glBegin(GL_LINES);
		glVertex2i(100,400);
		glVertex2i(400,100);
		glEnd();
		win=1;
		}
        if(who==2 && win==1)
            Text("Congratulation the Winner is Player 1 (X)",100,50,rand()%2,rand()%2,0,GLUT_BITMAP_HELVETICA_18);
        else if(who==1 && win==1)
           Text("Congratulation the Winner is Player 2 (0)",100,70,0,rand()%2,rand()%2,GLUT_BITMAP_HELVETICA_18);
        else if(field[0][0]&&field[0][1]&&field[0][2]&&field[1][0]&&field[1][1]&&field[1][2]&&field[2][0]&&field[2][1]&&field[2][2])
            Text("DRAW!!!",100,70,rand()%2,rand()%2,rand()%2,GLUT_BITMAP_HELVETICA_18);

//draw everything
glutSwapBuffers();
	glFlush();
}

void myMouse(int button, int state, int x, int y)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	 {

		int fx=(x-100)/100;
		int fy=((480-y)-100)/100;
	//	printf("fx=%d,fy=%d,who=%d\n",fx,fy,who);

		if ((win==0) && (fx>=0) && (fx<=2) && (fy>=0) && (fy<=2) && (field[fx][fy]==0))
		{
//		printf("set field[%d,%d]=%d\n",fx,fy,who);
		field[fx][fy]=who;
		if (who==2)
            who=1;
        else
            who=2;
		}



	 }
	 else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	for (int x=0;x<GAMESIZE;x++)
		for (int y=0;y<GAMESIZE;y++){
                field[x][y]=0;
        }
	win=0;
	}
	myDisplay();
}

void menu(int value)
{
f_uname=0,f_mob=0,f_remob=0,f_birth=0,f_pass=0;
mov=0;mov2=0;page=1;
loginfailed=0;
}

int main(int argc , char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_RGB|GLUT_DOUBLE);
   glutInitWindowSize(1000,500);
   glutInitWindowPosition(100,100);
    glutCreateWindow("FACEBOOK");
    init();
    glutReshapeFunc(myreshape);
    glutDisplayFunc(render);
   glutFullScreen();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(Specialkey);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passivemouse);
    glEnable (GL_BLEND);//for enabling the transparency
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

     glutCreateMenu(menu);
  glutAddMenuEntry("Refresh",1);

  glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

}

void myreshape(int ww,int hh)
{
   glViewport(0,0,ww,hh);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0,1000.0,0.0,1000.0,-400.0,1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
w=ww;
h=hh;
   hratio=(GLfloat)h/1000;
   wratio=(GLfloat)w/1000;

}

void init()
{
glClearColor( 0.9,0.9,0.9,1.0);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();

            if(phase==1)
                login_screen();//Screen 1
            else if(phase==2)
            profile_screen();//Screen 2
           else if(phase==3)
            user_profile_screen();//screen 3
            else if(phase==4)//screen 4
                message_screen();
            else if(phase==5)
                account_created();
            else if(phase==0)
                developers();
	glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='q')
        exit(0);

    if(phase==1)
    {
                    if(flag==1)                    //username
                  {
                      if(key==13)                //Enter
                      {
                        authenticateuser();
                      }
                      if(key==8)                //Backspace
                      {
                         if(ich>0)
                            ich--;
                         name[ich]='\0';
                            userlogin();
                      }
                      else if(ich<=19)
                      {
                         if(isalpha(key) || key==32 || isdigit(key))
                         {
                           name[ich++]=key;
                            userlogin();

                         }

                      }
                  }
                  else if(flag==2)             //password
                  {

                      if(key==13)            //Enter
                      {
                         authenticateuser();
                      }
                      if(key==8)            //Backspace
                      {
                         if(jch>0)
                           jch--;
                         password[jch]='\0';
                         userlogin();
                      }
                      else if(jch<=19)
                      {
                         if(isalpha(key) || key==32 || isdigit(key))
                         {
                            password[jch++]=key;
                            userlogin();
                         }
                      }
                  }

                  if(f_uname==1 && c_flag==1)//create account user name
                  {

                      if(key==13)            //Enter
                      {

                      }
                      if(key==8)            //Backspace
                      {
                         if(u>0)
                           u--;
                         c_username[u]='\0';
                         c_accountlogin();
                      }
                      else if(u<=19)
                      {
                         if(isalpha(key) || key==32)
                         {
                           c_username[u++]=key;
                            c_accountlogin();
                         }
                      }

                    }

                     if(f_mob==1 && c_flag==2)//create account Mobile number
                  {

                      if(key==13)            //Enter
                      {

                      }
                      if(key==8)            //Backspace
                      {
                         if(m>0)
                           m--;
                         c_mobile[m]='\0';
                         c_accountlogin();
                      }
                      else if(m<=19)
                      {
                         if( key==32 || isdigit(key))
                         {
                           c_mobile[m++]=key;
                            c_accountlogin();
                         }
                      }

                }

                if(f_remob==1 && c_flag==3)//create account Re enter Mobile number
                {

                    if(key==13)            //Enter
                      {

                      }
                      if(key==8)            //Backspace
                      {
                         if(rm>0)
                           rm--;
                         c_vermobile[rm]='\0';
                         c_accountlogin();
                      }
                      else if(rm<=19)
                      {
                         if( key==32 || isdigit(key))
                         {
                           c_vermobile[rm++]=key;
                            c_accountlogin();
                         }
                      }
                }

                if(f_pass==1&& c_flag==4)//create account password
                {


                    if(key==13)            //Enter
                      {

                      }
                      if(key==8)            //Backspace
                      {
                         if(p>0)
                           p--;
                         c_password[p]='\0';
                         c_accountlogin();
                      }
                      else if(p<=19)
                      {
                        if(isalpha(key) || key==32 || isdigit(key))//alpha numeric passwordqsq
                         {
                           c_password[p++]=key;
                            c_accountlogin();
                         }
                      }

                }

                if(f_birth==1 && c_flag==5)//create account birthday
                {

                     if(key==13)            //Enter
                      {

                      }
                      if(key==8)            //Backspace
                      {
                         if(b>0)
                           b--;
                         c_birthday[b]='\0';
                         c_accountlogin();
                      }
                      else if(b<=19)
                      {
                         if( key==32 || isdigit(key)||'/')
                         {
                           c_birthday[b++]=key;
                            c_accountlogin();
                         }
                      }
                }
    }
  else  if(phase==2||phase==3)
    {
        if(chatinput==1)//chat screen interaction
        {

           if(key==13)                //Enter
          {
            //enter the data to the chat box
                chating=1;
                ichc=0;
                chatinput=0;
               moveup++;
             // glutPostRedisplay();

          }
          if(key==8)                //Backspace
          {
             if(ichc>0)
                ichc--;
             userchat[ichc]='\0';
                chatinteraction();
          }
          else if(ich<=19)
          {
             if(isalpha(key) || key==32 || isdigit(key))
             {
               userchat[ichc++]=key;
                chatinteraction();
            }

        }
    }
        else if(poston==1)//user posts input
        {

            if(key==13)                //Enter
          {
        postit=1;
        poston=0;
        glutPostRedisplay();
          }
          if(key==8)                //Backspace
          {
             if(ichh>0)
                ichh--;
             post[ichh]='\0';
                chatinteraction();
          }
          else if(ichh<=29)
          {
             if(isalpha(key) | key==32 | isdigit(key))
             {
              post[ichh++]=key;
               posting();
             }

        }
        }
    }
}



void Specialkey(int key, int x, int y)
{
    switch(key)
{
                case GLUT_KEY_DOWN:
                    if(phase==2){
                            printf("\a\n");
                            if(page<9)
                            page+=1;
                            glutPostRedisplay();
                    }
                            break;
                case GLUT_KEY_UP:
                    if(phase==2){
                    printf("\a\n");
                            if(page>=2)
                            page-=1;
                            glutPostRedisplay();
                    }
                            break;
                case GLUT_KEY_LEFT:
                    if(phase==3){
                    printf("\a\n");
                        if(choise>1)
                        choise--;
                            }
                        break;
                case GLUT_KEY_RIGHT:
                    if(phase==3){
                    printf("\a\n");
                        if(choise<=3)
                        choise++;
                            }
                        break;

}


}

void mouse(int btn, int state ,int x0,int y0)
{
  int y=h-y0;
  int x=x0;

  if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(phase==1)
        {
                        if(x>=585*wratio && x<=697*wratio && y>=907*hratio && y<=946*hratio)//user name
                        {
                            flag=1;
                            userlogin();

                        }
                        else if(x>=706*wratio && x<=811*wratio && y>=907*hratio && y<=946*hratio) //password
                        {

                            flag=2;
                            userlogin();
                        }
                        else if(x>=830*wratio && x<=914*wratio && y>=908*hratio && y<=954*hratio)//login button
                        {
                            authenticateuser();
                        }
                       else if(x>=250*wratio && x<=350*wratio && y>=550*hratio && y<=650*hratio)//play button
                        {

                            if(play_login==true)
                            play_login=false;
                            else
                                play_login=true;

                        }
                        //create account
                       else if(x<=859*wratio && x>=563*wratio && y<=681*hratio && y>=615*hratio)//create user name
                       {
                               f_uname=1;
                               c_flag=1;
                           c_accountlogin();

                        }
                        else if(x<=859*wratio  && x>=563*wratio  && y<=600*hratio && y>=538*hratio)//mobile number
                        {
                                f_mob=1;
                                c_flag=2;
                          c_accountlogin();
                        }
                        else if(x<=859*wratio && x>=563*wratio  && y<=519*hratio && y>=459*hratio)//re enter mobile number
                        {
                            f_remob=1;
                            c_flag=3;
                           c_accountlogin();
                        }
                        else if(x<=859*wratio  && x>=563*wratio  && y<=444*hratio&& y>=383*hratio)//password
                        {
                            f_pass=1;
                            c_flag=4;
                           c_accountlogin();

                        }
                        else if(x<=859*wratio  && x>=563*wratio  && y<=317*hratio && y>=269*hratio)//birthday
                        {
                            f_birth=1;
                            c_flag=5;

                          c_accountlogin();


                        }
                        else if(x<=859*wratio && x>=563*wratio && y<=225*hratio && y>=115*hratio)//create account button
                        {

                            authenticate_createaccount();
                            create=1;
                            glutPostRedisplay();
                        }
                        else if(x<=925*wratio && x>=830*wratio && y<=60*hratio && y>=20*hratio)
                        {
                            phase=0;
                            glutPostRedisplay();
                        }


        }
        else if(phase==2)
        {
            if(x>=595*wratio && x<=637*wratio && y>=940*hratio && y<=980*hratio)//home
                       {
                          phase=2;
                          glutPostRedisplay();
                       }
                    else if(x>=648*wratio && x<=691*wratio && y>=940*hratio && y<=980*hratio)//profile
                    {
                        phase=3;
                        glutPostRedisplay();
                    }
                    else if(x>=840*wratio && x<=880*wratio && y>=940*hratio && y<=980*hratio)//logout
                    {
                        phase=1;
                            int j;
            for(j=0;j<20;j++)
              name[j]='\0';
            for(j=0;j<20;j++)
              password[j]='\0';
            ich=0;
            jch=0;
                        //or add the project info or logout verification
                    }
                    else if(x>=560*wratio && x<=580*wratio && y>=5*hratio && y<=55*hratio)//next button
                    {
                            if(page<9)
                            page+=1;
                            glutPostRedisplay();
                    }
                     else if(x>=560*wratio && x<=580*wratio && y>=840*hratio && y<=890*hratio)//perv button
                    {
                            if(page>=2)
                            page-=1;
                            glutPostRedisplay();
                    }

    else if(x>=178*wratio && x<=205*wratio && y>=175*hratio && y<=200*hratio)//like button
                    {
                    if(page==1)
                    {

                        if(likeon1==0)
                        likeon1=1;
                        else if(likeon1==1)
                            likeon1=0;
                     }
                     if(page==2)
                    {
                        if(likeon2==0)
                        likeon2=1;
                        else if(likeon2==1)
                            likeon2=0;
                     }
                     if(page==3)
                    {
                           if(likeon3==0)
                        likeon3=1;
                        else if(likeon3==1)
                            likeon3=0;
                       }
                       if(page==4)
                    {
                         if(likeon4==0)
                        likeon4=1;
                        else if(likeon4==1)
                            likeon4=0;
                      }
                      if(page==5)
                    {
                          if(likeon5==0)
                        likeon5=1;
                        else if(likeon5==1)
                            likeon5=0;
                    }
                    if(page==6)
                    {

                        if(likeon6==0)
                        likeon6=1;
                        else if(likeon6==1)
                            likeon6=0;
                     }
                     if(page==7)
                    {

                        if(likeon7==0)
                        likeon7=1;
                        else if(likeon7==1)
                            likeon7=0;
                     }
                     if(page==8)
                    {

                        if(likeon8==0)
                        likeon8=1;
                        else if(likeon8==1)
                            likeon8=0;
                     }
                     if(page==9)
                    {

                        if(likeon9==0)
                        likeon9=1;
                        else if(likeon9==1)
                            likeon9=0;
                     }
                    }
                    else if(x>=847*wratio && x<=1000*wratio && y>=100*hratio && y<=500*hratio)//switch on the chat
                    {
                        chaton=1;
                        glutPostRedisplay();
                    }

                    else if(x>=865*wratio && x<=980*wratio && y>=530*hratio && y<=570*hratio)//play the tic tac toe

                    {
                    glutInitWindowSize(640,480);     // set window size
                    glutInitWindowPosition(100, 150); // set window position on screen
                    window2=glutCreateWindow("Tic Tac Toe"); // open the screen window
                    //glutKeyboardFunc(keyboard2);
                    glutMouseFunc(myMouse);     // register redraw function
                    glutDisplayFunc(myDisplay);     // register redraw function
                    myInit();
                    glutMainLoop(); 		     // go into a perpetual loop
//                    glutDestroyWindow(window2);


                    }
                    else if(x>=60*wratio && x<=100*wratio && y>=560*hratio && y<=580*hratio)//message screen
                    {
                        phase=4;
                        glutPostRedisplay();

                    //glutSwapBuffers();

                    }
                    else if(x>=810*wratio && x<=820*wratio && y>=445*hratio && y<=460*hratio)//close the chat
                        {

                           chaton=0;
                           glutPostRedisplay();
                        }
                    else  if(x>=635*wratio && x<=830*wratio && y>=0*hratio && y<=54*hratio)//chat type a message
                        {


                              typeamessage=1;
                               chatinput=1;
                              glutPostRedisplay();

                        }


                        else if(x>=60*wratio && x<=100*wratio && y>=430*hratio && y<=470*hratio)//pokes
                        {
                            if(pokeon==0){
                           pokeon=1;
                           eventon=0;
                            }
                           else
                            pokeon=0;
                           glutPostRedisplay();
                        }
                        else if(x>=55*wratio && x<=100*wratio && y>=500*hratio && y<=530*hratio)//events
                        {
                             if(eventon==0){
                           eventon=1;
                           pokeon=0;
                             }
                           else
                            eventon=0;
                           glutPostRedisplay();
                        }
                        else if(x>=60*wratio && x<=100*wratio && y>=620*hratio && y<=650*hratio)//news feed
                        {
                            page=1;
                            glutPostRedisplay();

                        }
                        else if(x>=180*wratio && x<=500*wratio && y>=720*hratio && y<=800*hratio)//post on
                        {
                            poston=1;
                            glutPostRedisplay();
                        }
                        else if(x>=500*wratio && x<=540*wratio && y>=685*hratio && y<=715*hratio)//post the typed data
                        {
                               postit=1;
                               glutPostRedisplay();
                        }



        }

       else if(phase==3)
        {
                        if(x>=595*wratio && x<=637*wratio && y>=940*hratio && y<=980*hratio)//home
                       {
                          phase=2;
                          glutPostRedisplay();
                       }
                    else if(x>=648*wratio && x<=691*wratio && y>=940*hratio && y<=980*hratio)//profile
                    {
                        phase=3;
                        glutPostRedisplay();
                    }
                    else if(x>=840*wratio && x<=880*wratio && y>=940*hratio && y<=980*hratio)//logout
                    {
                       // exit(0);
                       phase=1;
                                   int j;
                        for(j=0;j<20;j++)
                          name[j]='\0';
                        for(j=0;j<20;j++)
                          password[j]='\0';
                        ich=0;
                        jch=0;
                        //or add the project info or logout verification
                    }
                        else if(x>=219*wratio && x<=280*wratio && y>=380*hratio && y<=400*hratio)//timeline
                        {
                        choise=1;
                        phase=3;
                        glutPostRedisplay();
                        }
                        else if(x>=286*wratio && x<=340*wratio && y>=380*hratio && y<=400*hratio)//about
                        {
                        choise=2;
                        phase=3;
                        glutPostRedisplay();
                        }
                        if(x>=345*wratio && x<=415*wratio && y>=380*hratio && y<=400*hratio)//friends
                        {
                        choise=3;
                        phase=3;
                        glutPostRedisplay();
                        }
                        else if(x>=420*wratio && x<=490*wratio && y>=380*hratio && y<=400*hratio)//photos
                        {
                        choise=4;
                        phase=3;
                        glutPostRedisplay();
                        }
//printf("x=%d  y=%d\n",x,y);
                        else if(x>=810*wratio && x<=820*wratio && y>=445*hratio && y<=460*hratio)//close the chat
                        {

                           chaton=0;
                           glutPostRedisplay();
                        }
                      else  if(x>=635*wratio && x<=830*wratio && y>=0*hratio && y<=54*hratio)//chat type a message
                        {


                              typeamessage=1;
                               chatinput=1;
                              glutPostRedisplay();

                        }

                         else if(x>=847*wratio && x<=1000*wratio && y>=100*hratio && y<=500*hratio)//switch on the chat
                    {
                        chaton=1;
                        glutPostRedisplay();
                    }

                    else if(x>=885*wratio && x<=980*wratio && y>=550*hratio && y<=570*hratio)//play the tic tac toe
                    {
                    glutInitWindowSize(640,480);     // set window size
                    glutInitWindowPosition(100, 150); // set window position on screen
                    glutCreateWindow("Tic Tac Toe"); // open the screen window
                    glutMouseFunc(myMouse);     // register redraw function
                    glutDisplayFunc(myDisplay);     // register redraw function
                    myInit();
                    glutMainLoop(); 		     // go into a perpetual loop


                    }
        }
        else if(phase==4)
        {
                         if(x>=595*wratio && x<=637*wratio && y>=940*hratio && y<=980*hratio)//home
                       {
                          phase=2;
                          glutPostRedisplay();
                       }
                    else if(x>=648*wratio && x<=691*wratio && y>=940*hratio && y<=980*hratio)//profile
                    {
                        phase=3;
                        glutPostRedisplay();
                    }
                    else if(x>=840*wratio && x<=880*wratio && y>=940*hratio && y<=980*hratio)//logout
                    {
                       // exit(0);
                       phase=1;
                                   int j;
                        for(j=0;j<20;j++)
                          name[j]='\0';
                        for(j=0;j<20;j++)
                          password[j]='\0';
                        ich=0;
                        jch=0;
                        //or add the project info or logout verification
                    }
                    else if(x>=810*wratio && x<=820*wratio && y>=445*hratio && y<=460*hratio)//close the chat
                        {

                           chaton=0;
                           glutPostRedisplay();
                        }
                         else if(x>=847*wratio && x<=1000*wratio && y>=100*hratio && y<=500*hratio)//switch on the chat
                    {
                        chaton=1;
                        glutPostRedisplay();
                    }

        }
        else if(phase==5)
        {
            if(x>=840*wratio && x<=880*wratio && y>=940*hratio && y<=980*hratio)//logout
                    {
                        create=0;
                        phase=1;
                        glutPostRedisplay();
                                        int j;
            for(j=0;j<20;j++)
              name[j]='\0';
            for(j=0;j<20;j++)
              password[j]='\0';
            ich=0;
            jch=0;
            }
        }
        else if(phase==0)
        {
           if(x>=450*wratio && x<=550*wratio && y>=20*hratio && y<=60*hratio)
           {
                exit(0);
           }
        }
    }
   }

   void passivemouse(int x,int y)
   {
        y=h-y;


        if(x>=589*wratio && x<=830*wratio && y>=10*hratio && y<=890*hratio)
        {
            admove=1;
            glutPostRedisplay();
        }
        else
        {
            admove=0;
            glutPostRedisplay();
        }
   }

void userlogin()
{

   Text(name,588,920,0,0,0,GLUT_BITMAP_HELVETICA_18);
   password_text(password,706,920);
}

void chatinteraction()
{
    Text(userchat,640,25,0,0,0,GLUT_BITMAP_HELVETICA_18);
}



void box(int posx,int posy,float colorx,float colory,float colorz,int scalex)
{
            glPushMatrix();
            glColor3f(colorx,colory,colorz);
            glScalef(scalex,1,1);
            glTranslatef(posx,posy,0);
            glRectd(810,120,800,100);
            glPopMatrix();
}

void chatdataflow()
    {
       if(strcmp(userchat,"hi")==0)
        {
            hi=1;
            int j;
            for(j=0;j<19;j++) userchat[j]='\0';
            ichc=0;
        }
        else if(!strcmp(userchat,"hello"))
        {
            hello=1;
             int j;
            for(j=0;j<19;j++) userchat[j]='\0';
            ichc=0;

        }

    if(hi){
            glPushMatrix();
            glTranslatef(0,10+moveup,0);
           // box(0,0,1,1,1,1.5);
            Text("hi",800,100,0,0,0,GLUT_BITMAP_HELVETICA_18);//reply

        Text("hi",640,60,0,0,0,GLUT_BITMAP_HELVETICA_18);
        glPopMatrix();
        }
        if(hello)
        {
    glPushMatrix();
            glTranslatef(0,moveup,0);
           // box(0,0,1,1,1,1.5);
            Text("hello",800,100,0,0,0,GLUT_BITMAP_HELVETICA_18);//reply

        Text("hello",640,60,0,0,0,GLUT_BITMAP_HELVETICA_18);
        glPopMatrix();
        }
    }


void authenticateuser()
{

if((strcmp(name,c_username)==0) && (strcmp(password,c_password)==0) &&f_pass==1)
    {
        phase=5;
        glutPostRedisplay();


    }
 else if((strcmp(name,"aravind")==0) && (strcmp(password , "123456")==0)||
       (strcmp(name,"akshay")==0) && (strcmp(password , "123456")==0))
    {

        phase=2;
       // delay();
        glutPostRedisplay();
    }
    else//clear the password
    {
        loginfailed=1;
         int j;
            for(j=0;j<20;j++)
              name[j]='\0';
            for(j=0;j<20;j++)
              password[j]='\0';
            ich=0;
            jch=0;
    }

printf("%s %s\n",c_username,c_password);


}



void login_screen()//head blue color
{

    glColor3f(0.231,0.349,0.596);
    glRectd(1000,1000,0,870);
                //IS SAME AS THE FOLLOWING :
                //glBegin(GL_POLYGON);
                //glVertex2(x1, y1);
                //glVertex2(x2, y1);
                //glVertex2(x2, y2);
                //glVertex2(x1, y2);
                //glEnd();
	//Text("facebook",128,908,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24);
	HugeText("facebook",128,908,1,1,1,7,0.5);
	headbox();
	userlogin();
	createaccount();
	c_accountlogin();
	if(create==1)
	authenticate_createaccount();
	loginscreenvedio();
	glColor3f(0.8,0.8,0.8);
	glRectd(830,20,925,60);
	Text("Developers!",840,25,0,0,0,0);
		glutPostRedisplay();

}


 void pageconfig()//page configuration
   {
    glPushMatrix();
    glTranslated(0,-540*0,0);
    {
    newsfeed();
       page1();
    }glPopMatrix();
    glPushMatrix();
    glTranslated(0,-540*1,0);
       page2();
    glPopMatrix();
   // else if(page==3)
    glPushMatrix();
    glTranslated(0,-540*2,0);
       page3();
    glPopMatrix();
     //else if(page==4)
    glPushMatrix();
    glTranslated(0,-540*3,0);
       page4();
    glPopMatrix();
   //     else if(page==5)
    glPushMatrix();
    glTranslated(0,-540*4,0);
       page5();
    glPopMatrix();
     //   else if(page==6)
    glPushMatrix();
    glTranslated(0,-540*5,0);
       page6();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,-540*6,0);
       page7();
    glPopMatrix();
   glPushMatrix();
    glTranslated(0,-540*7,0);
       page8();
    glPopMatrix();
   glPushMatrix();
    glTranslated(0,-540*8,0);
      page9();
    glPopMatrix();
   }


void profile_screen()
{
     loginfailed=0;
    profilepic(3,580,.5);
    profileinfo();
  // newsfeed();
     ad();
     logo();
     chat();
     req();
     scrollbar();

    if(page==1)
   {
pageconfig();
}
     else if(page==2)
   {

   glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
    }else if(page==3)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
     }else if(page==4)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
    }    else if(page==5)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
     }   else if(page==6)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
    }
       else if(page==7)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
    }
       else if(page==8)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
    }
       else if(page==9)
    {glPushMatrix();
    glTranslated(0,540*(page-1),0);
       pageconfig();
    glPopMatrix();
    }
    nextbutton();
     prevbutton();
     glColor3f(0,0,0);
     //Text((char)page,340,30,0,0,0,GLUT_BITMAP_TIMES_ROMAN_10);
     glPushMatrix();
     glColor3f(0,0,0);
         glRasterPos2f(340, 30);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,48+page);
     glPopMatrix();
//     glrectd(500,500,450,450);
profilehead();

if(pokeon==1)
    pokes();
if(eventon==1)
    events();

   chatinteraction();
if(postit==0)
   posting();
}

void user_profile_screen()
{

userprofilepic();
profilehead();
req();
 profilebody();
 if(choise==1)
        timeline();
else if(choise==2)
        About();
    else if(choise==3)
        friends();
 else if(choise==4)
        photos();
profilepic(0,0,1);
 //chatbox();
 chat();
  chatinteraction();

}
void nopropic(float b1,float b2,float b3,float p1,float p2,float p3)
{
    glPushMatrix();
    glScaled(.3,.4,.5);
    glTranslated(200,400,0);
 glColor3f(b1,b2,b3);
 glRectd(80,0,280,200);
 glColor3f(p1,p2,p3);
    glBegin(GL_LINE_LOOP);
     glVertex2f(94,0);
     glVertex2f(141,21);
     glVertex2f(147,33);
     glVertex2f(150,35);
     glVertex2f(152,49);
     glVertex2f(143,61);
     glVertex2f(142,70);
     glVertex2f(138,76);
     glVertex2f(137,91);
     glVertex2f(143,93);
     glVertex2f(143,129);
     glVertex2f(153,141);
     glVertex2f(197,153);
     glVertex2f(197,150);
     glVertex2f(192,146);
     glVertex2f(211,127);
     glVertex2f(212,91);
     glVertex2f(215,91);
     glVertex2f(214,77);
     glVertex2f(209,69);
     glVertex2f(207,57);
     glVertex2f(200,50);
     glVertex2f(200,34);
     glVertex2f(210,20);
     glVertex2f(257,0);
     glVertex2f(94,0);
    glEnd();
    glPopMatrix();
}

void message_screen()
{
int i;
     glColor3f(1,1,1);
    glRectd(30,1000,550,0);
    glColor3f(.961,.969,.98);
    for(i=0;i<6;i++)
    glRectd(30,750+i*-120,210,850+i*-120);
    Text("Messages",50,880,0,0,0,0);
   glPushMatrix();                  //[rofile pics with different collors
   glTranslatef(-50,600,1);
   nopropic(0,0,1,1,1,1);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(-50,480,1);
   nopropic(1,0,1,0,1,1);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(-50,360,1);
   nopropic(0,1,1,1,0,1);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(-50,240,1);
   nopropic(0,0,1,1,1,1);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(-50,120,1);
   nopropic(0,.5,1,.4,.6,1);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(-50,00,1);
   nopropic(0.7,0.7,1,1,0,1);
   glPopMatrix();

glColor3f(0,rand()%9,rand()%8);
glRectd(240,750,500,850);
glColor3f(.427,.518,.706);
for(i=1;i<6;i++)
glRectd(240,750+i*-120,500,850+i*-120);
Text("hi",270,800,1,1,1,GLUT_BITMAP_8_BY_13);           //messages chats
Text("typing...",260,770,0,0,0,GLUT_BITMAP_9_BY_15);
Text("bye",270,700,1,1,1,GLUT_BITMAP_8_BY_13);
Text("good night -:)",270,680,1,1,1,GLUT_BITMAP_8_BY_13);
Text("How are you?",270,560,1,1,1,GLUT_BITMAP_8_BY_13);
Text("Nope.I was not there dat day",270,450,1,1,1,GLUT_BITMAP_8_BY_13);
Text("how dare you to talk me like dat...?",270,330,1,1,1,GLUT_BITMAP_8_BY_13);
Text("Don't talk to me again..It's Over",270,200,1,1,1,GLUT_BITMAP_8_BY_13);
glColor3f(0,0,0);
glRectd(215,100,225,850);
glColor3f(0,0,0);
glBegin(GL_POLYGON);
 glVertex2f(225,800);
 glVertex2f(240,790);
 glVertex2f(225,780);
glEnd();
Text("Alia Bhat",100,800,0,0,0,GLUT_BITMAP_9_BY_15);
Text("Deepika Padukone",100,680,0,0,0,GLUT_BITMAP_9_BY_15);
Text("Siddarth Malhotra",100,550,0,0,0,GLUT_BITMAP_9_BY_15);
Text("Ranveer Singh",100,450,0,0,0,GLUT_BITMAP_9_BY_15);
Text("Priyanka Chopra",100,330,0,0,0,GLUT_BITMAP_9_BY_15);
Text("Shraddha Kapoor",100,200,0,0,0,GLUT_BITMAP_9_BY_15);


for(i=0;i<2;i++)
    Text("2 hrs ago",440,770+i*-120,0,0,0,GLUT_BITMAP_8_BY_13);

for(i=2;i<6;i++)
    Text("yesterday",440,770+i*-120,0,0,0,GLUT_BITMAP_8_BY_13);
    ad();
   profilehead();
    chat();
     req();



}
void account_created()
{

    profilehead();
    glColor4f(0.9,0.9,0.9,0.8);
    glRectd(1000,1000,0,0);
     glColor3f(1,1,1);
        glRectd(840,980,880,940);
         glBegin(GL_LINE_LOOP);
         glVertex2f(840,980);
         glVertex2f(880,980);
         glVertex2f(880,940);
         glVertex2f(840,940);
         glVertex2f(840,980);
        glEnd();
        Text("LOGOUT",840,955,0,0,0,GLUT_BITMAP_9_BY_15);

    glColor3f(1,1,1);
    glRectd(800,800,200,200);
    HugeText("Attention...",420,700,0,0,0,2,0.3);
    Text("This feature is available only for paid users.!",350,600,0,0,0,0);
    Text("Be a part of our community and enjoy social networking",300,500,0,0,0,0);
     glPushMatrix();
        glTranslated(250,0,0);
        glRotated(fbangle+70,40,600,50);
        HugeText("f",40,700,0.231,0.349,0.596,20,0.5);
        glPopMatrix();
     glPushMatrix();
        glTranslated(650,0,0);
        glRotated(fbangle+70,40,700,50);
        HugeText("f",40,700,0.231,0.349,0.596,20,0.5);
        glPopMatrix();


fbangle+=1;



}
void headbox()//draw the username and sign in box
{
    glColor3d(1.0,1.0,1.0);//box color white
    glRectf(697,946,585,907);//user name white box
    glRectd(811,946,706,907);//sign in white box
    Text("Username:",585,955,1,1,1,GLUT_BITMAP_8_BY_13);
    Text("Password:",706,955,1,1,1,GLUT_BITMAP_8_BY_13);
if(loginfailed)
        glColor3f(0.9,0,0);
        else
    glColor3f(0.23,0.34,0.5/*968*/);//log in button box color

    glRectd(914,954,830,908);//login button
glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); // login button border
    glLineWidth(0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(914, 954);
    glVertex2f(830, 954);
    glVertex2f(830, 908);
    glVertex2f(914, 908);
    glEnd();
glPopMatrix();
if(loginfailed)
    Text("LOG IN!",850,925,rand()%2,rand()%2,1,GLUT_BITMAP_8_BY_13);
    else
      Text("LOG IN!",850,925,1,1,1,GLUT_BITMAP_8_BY_13);

}

void createaccount()
{
   //HugeText("Create an Account",563,776,0,0,0);
   Text("Create an account",563,776,0,0,0,GLUT_BITMAP_TIMES_ROMAN_24);
    Text("Its free and always will be!",566,719,0,0,0,GLUT_BITMAP_HELVETICA_12);

    glColor3d(1,1,1);//username box
    glRectd(859,681,563,615);
    if(f_uname==0)
    Text("Username",570,640,0.8,0.8,0.8,GLUT_BITMAP_HELVETICA_18);

    glColor3d(1,1,1);//mobile number box
    glRectd(859,600,563,538);
     if(f_mob==0)
    Text("Mobile Number",570,555,0.8,0.8,0.8,GLUT_BITMAP_HELVETICA_18);

     glColor3d(1,1,1);//mobile number reentry box
    glRectd(859,519,563,459);
     if(f_remob==0)
    Text("Re-enter Mobile Number",570,459+17,0.8,0.8,0.8,GLUT_BITMAP_HELVETICA_18);

     glColor3d(1,1,1);//password box
    glRectd(859,444,563,383);
     if(f_pass==0)
    Text("Password",570,383+17,0.8,0.8,0.8,GLUT_BITMAP_HELVETICA_18);

    Text("Birthday",570,340,0,0,0,GLUT_BITMAP_HELVETICA_18);
    glColor3d(1,1,1);//birthday box
    glRectd(859,317,563,269);
     if(f_birth==0)
    Text("eg.28/4/2016",570,269+17,0.8,0.8,0.8,GLUT_BITMAP_HELVETICA_18);

     glColor3d(0.137255,0.556863,0.137255);//birthday box
    //glRectd(859,225,563,115);

    glBegin(GL_POLYGON); //green box for create an account
     glColor3d(0.137255,0.556863,0.137255);

     glVertex2f(570,225);//left line
     glVertex2f(569,224);
     glVertex2f(568,223);
     glVertex2f(567,222);
     glVertex2f(566,221);
     glVertex2f(565,220);
     glVertex2f(564,219);
     glVertex2f(563,218);



     glVertex2f(563,125);//bottom line
     glVertex2f(564,124);
     glVertex2f(565,123);
     glVertex2f(566,122);
     glVertex2f(567,121);
     glVertex2f(568,120);
     glVertex2f(569,119);
     glVertex2f(570,118);


     glVertex2f(852,118);//right line
     glVertex2f(853,119);
     glVertex2f(854,120);
     glVertex2f(855,121);
     glVertex2f(856,122);
     glVertex2f(857,123);
     glVertex2f(858,124);
     glVertex2f(859,125);


     glVertex2f(859,218);//top line
     glVertex2f(858,219);
     glVertex2f(857,220);
     glVertex2f(856,221);
     glVertex2f(855,222);
     glVertex2f(854,223);
     glVertex2f(853,224);
     glVertex2f(852,225);
  glEnd();

  glPushMatrix();
  glColor3f(0,0,0);
  glLineWidth(1);
  glBegin(GL_LINE_LOOP); //green box outline for create an account


     glVertex2f(570,225);//left line
     glVertex2f(569,224);
     glVertex2f(568,223);
     glVertex2f(567,222);
     glVertex2f(566,221);
     glVertex2f(565,220);
     glVertex2f(564,219);
     glVertex2f(563,218);



     glVertex2f(563,125);//bottom line
     glVertex2f(564,124);
     glVertex2f(565,123);
     glVertex2f(566,122);
     glVertex2f(567,121);
     glVertex2f(568,120);
     glVertex2f(569,119);
     glVertex2f(570,118);


     glVertex2f(852,118);//right line
     glVertex2f(853,119);
     glVertex2f(854,120);
     glVertex2f(855,121);
     glVertex2f(856,122);
     glVertex2f(857,123);
     glVertex2f(858,124);
     glVertex2f(859,125);


     glVertex2f(859,218);//top line
     glVertex2f(858,219);
     glVertex2f(857,220);
     glVertex2f(856,221);
     glVertex2f(855,222);
     glVertex2f(854,223);
     glVertex2f(853,224);
     glVertex2f(852,225);

  glEnd();
  glPopMatrix();



Text("Create an account",590,170,1.0,1.0,1.0,GLUT_BITMAP_TIMES_ROMAN_24);


}

//shapes

void circlearc(float h,float k,float r)
{
	float i;
	glBegin(GL_LINE_LOOP);
		for(i=0;i<=360;i+=1)
			glVertex3f(h+r*cos(i*(float)pi/180),k+r*sin(i*(float)pi/180),0.0);
	glEnd();
}
void semicircle(float h,float k,float r)
{
	float i;
	glBegin(GL_POLYGON);
		for(i=160;i<=340;i+=1)
			glVertex3f(h+r*cos(i*(float)pi/180),k+r*sin(i*(float)pi/180),0.0);
	glEnd();

}
void semicirclearc(float h,float k,float r)
{
	float i;
	glBegin(GL_LINE_LOOP);
		for(i=160;i<=340;i+=1)
			glVertex3f(h+r*cos(i*(float)pi/180),k+r*sin(i*(float)pi/180),0.0);
	glEnd();
}
void ellipse(float h,float k,float r1,float r2)
{
	float i;
	glBegin(GL_POLYGON);
		for(i=0;i<=360;i+=1)
			glVertex3f(h+r1*cos(i*(float)pi/180),k+r2*sin(i*(float)pi/180),0.0);
	glEnd();
}
void circle(float h,float k,float r)
{
	float i;
	glBegin(GL_POLYGON);
		for(i=0;i<=360;i+=1)
			glVertex3f(h+r*cos(i*(float)pi/180),k+r*sin(i*(float)pi/180),0.0);
	glEnd();
}
void semicirclearcnormal(float h,float k,float r,int fill)
{
	float i;
	if(fill==0)
	glBegin(GL_LINE_LOOP);
	else
        glBegin(GL_POLYGON);
		for(i=180;i<=360;i+=1)
			glVertex3f(h+r*cos(i*(float)pi/180),k+r*sin(i*(float)pi/180),0.0);
	glEnd();
}

void profilehead()//head blue color
{
    	glColor3f(0.231,0.349,0.596);
    	glRectd(1000,1000,0,934);
    	glColor3f(1,1,1);
    	glRectd(84,986,68,952);
		Text("f",75,954,0.231,0.349,0.596,GLUT_BITMAP_TIMES_ROMAN_24);

		glColor3f(1.0,1.0,1.0);//Search Box
		glRectd(422,984,95,952);

		Text("Search",100,960,0,0,0,GLUT_BITMAP_HELVETICA_12);
        glColor3f(0.231,0.349,0.596);
				glRectd(595,980,637,940);//rectangle for home
        Text("Home",600,955,1,1,1,GLUT_BITMAP_HELVETICA_18);

        glColor3f(0.231,0.349,0.596);
		glRectd(648,980,691,940);//rectangle for profile
        Text("Profile",650,955,1,1,1,GLUT_BITMAP_HELVETICA_18);

        glColor3f(1,1,1);
        glRectd(840,980,880,940);
         glBegin(GL_LINE_LOOP);
         glVertex2f(840,980);
         glVertex2f(880,980);
         glVertex2f(880,940);
         glVertex2f(840,940);
         glVertex2f(840,980);
        glEnd();
        Text("LOGOUT",840,955,0,0,0,GLUT_BITMAP_9_BY_15);

         profilepic(550,860,.2);

}

void profileinfo()
{
    Text("Profile",60,740,0,0,0,GLUT_BITMAP_HELVETICA_12);
    Text("FAVORITES",40,680,0,0,0,GLUT_BITMAP_HELVETICA_12);
    Text("Newsfeed",60,620,0,0,0,GLUT_BITMAP_HELVETICA_12);
    Text("Messages",60,560,0,0,0,GLUT_BITMAP_HELVETICA_12);
    Text("Events",60,500,0,0,0,GLUT_BITMAP_HELVETICA_12);
  //  Text("Groups",60,440,0,0,0,GLUT_BITMAP_HELVETICA_12);
    Text("Pokes",60,440,0,0,0,GLUT_BITMAP_HELVETICA_12);
//   glRectd(60,620,100,650);

}

void newsfeed()
{
    glColor3f(1,1,1);
    glRectd(150,890,550,680);//first white box containing update status
    glColor3f(1,1,1);
    glRectd(150,660,550,10);//bottom news time line box
      Text("Update Status",175,840,0.0,0.0,0.0,GLUT_BITMAP_9_BY_15);
      glBegin(GL_LINE_STRIP);
       glColor3f(.929,.929,.929);//line above whats on your mind
       glVertex2f(155,810);
       glVertex2f(220,810);
       glVertex2f(230,820);
       glVertex2f(240,810);
       glVertex2f(550,810);
      glEnd();

      glBegin(GL_LINE_STRIP);//line below whats on your mind
       glColor3f(.929,.929,.929);
       glVertex2f(150,720);
       glVertex2f(550,720);
      glEnd();
      glColor3f(.441,.561,.827);//'update status' logo
      glRectd(155,860,173,830);
      glBegin(GL_LINE_LOOP);//pencil top
        glColor3f(1,1,1);
       glVertex2f(168.5,856.9);
       glVertex2f(170.9,851.7);
       glVertex2f(170.8,850.7);
       glVertex2f(168.5,853.8);
      glEnd();

      glBegin(GL_LINE_LOOP);//pencil mid
        glColor3f(1,1,1);
       glVertex2f(165.5,852.4);
       glVertex2f(167.7,847.8);
       glVertex2f(163.1,840.6);
       glVertex2f(160.6,843);
      glEnd();

     glBegin(GL_LINE_LOOP);//pencil bottom
        glColor3f(1,1,1);
       glVertex2f(158.4,838.7);
       glVertex2f(160.4,836.8);
       glVertex2f(157,833.9);
     glEnd();
      profilepic(150,660,.2);//pic near whats on you mind
    if(poston==0)
      Text("What's on your mind..?",210,760,.8,.8,.8,GLUT_BITMAP_HELVETICA_12);
      glBegin(GL_POLYGON);//post logo
       glColor3f(0.231,0.349,0.596);
       glVertex2f(500,715);
       glVertex2f(540,715);
       glVertex2f(540,685);
       glVertex2f(500,685);
      glEnd();
    Text("Post",510,695,1,1,1,GLUT_BITMAP_8_BY_13);
}
void page1()//ashish
{
    glColor3f(1,1,1);
    glRectd(150,-5940,550,660);
    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,560,1);
   nopropic(0,0,1,1,1,1);
   glPopMatrix();
    Text(" changed his profile pic",320,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Yesterday at 10:00pm",260,600,0,0,0,GLUT_BITMAP_8_BY_13);

     Text("Ashish Kirodian ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);

      //ashish uploaded the below image
    if(likeon1==0)
      {
          Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
          likeboff();
      }
    else if(likeon1==1)
      {

       Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);

glPushMatrix();
glScaled(1.5,1.5,0);
glTranslated(60,35,0);
    //photo 1
    glLineWidth(2);/////////////////////////////////////BILLLLLLLLLL
    glColor3f(0.65,0.8,0.7);
//  glRectd(200,342,60,110);
    glBegin(GL_POLYGON);//border for the pic
        glVertex2d(60,110);
            glVertex2d(200,110);
            glVertex2d(200,342);
            glVertex2d(60,342);
            glEnd();
            glColor3f(0,0,0);
            circlearc(170,300,20);//face
            glBegin(GL_LINES);//body line
            glVertex2f(170,280);
            glVertex2f(170,200);
            glEnd();

            glBegin(GL_LINES);//hands
            glVertex2f(170,270);
            glVertex2f(150,250);
            glVertex2f(170,270);
            glVertex2f(190,250);
            glEnd();

            glBegin(GL_LINES);//legs
            glVertex2f(170,200);
            glVertex2f(150,150);
            glVertex2f(170,200);
            glVertex2f(190,150);
            glEnd();

            glPointSize(4);//eyes
            glBegin(GL_POINTS);
            glVertex2f(165,312);
            glVertex2f(175,312);
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(170,295);
            glVertex2f(175,298);
            glVertex2f(170,295);
            glVertex2f(165,298);
    glEnd();

  Text("This is Bill!",70,322,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("Bill likes football",70,290,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("Bill doesn't argue about ",70,268,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("who's better between",70,253,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("Ronaldo and Messi.He ",70,238,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("just thinks he's lucky to ",70,223,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("see them play in his era",70,208,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("Bill is smart",70,170,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("Be like Bill",70,130,0,0,0,GLUT_BITMAP_HELVETICA_18);


glPopMatrix();
//end of pic uploaded by ashish
}

void page2()
{
    Text("Crasta ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text(" shared a photo",260,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Yesterday at 10:00pm",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(1,0,1,0,1,1);
glPopMatrix();
      if(likeon2==0)
    {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon2==1)
       {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);
glPushMatrix();
glScaled(1.3,1,0);
glTranslated(30,200,0);
     glColor3f(0,1,1);
    glRectd(100,20,360,360);
    glColor3f(1,1,0);
glRectd(280,280,350,350);//face
  glColor3f(0,0,0);//right eye
circlearc(297,330,5);
  glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2f(297,330);
  glEnd();
circlearc(333,330,5);//left eye
  glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2f(333,330);
  glEnd();

  glBegin(GL_POINTS);//nose
  glVertex2f(315,315);
  glEnd();

  glColor3f(1,1,1);//mouth
  glRectd(300,290,330,295);

glPointSize(2.5);//teeth
glColor3f(0,0,0);
glBegin(GL_POINTS);
glVertex2f(305,293);
glVertex2f(310,293);
glVertex2f(315,293);
glVertex2f(320,293);
glVertex2f(325,293);
glEnd();

glBegin(GL_LINE_LOOP);//body
glVertex2f(315,280);
glVertex2f(315,100);
glEnd();


glBegin(GL_LINE_STRIP);//hands
glVertex2f(280,150);
glVertex2f(315,230);
glVertex2f(350,150);
glEnd();


glBegin(GL_LINE_STRIP);//legs
glVertex2f(280,30);
glVertex2f(315,100);
glVertex2f(350,30);
glEnd();

Text("This is a gold rare bill",105,320,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("It appears only once  ",105,280,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("every 1000",105,240,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text(" \"Be Like Bill\" posts",105,200,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("\"Like\" this picture if",105,140,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("you want absolutely nothing",105,100,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("to happen",105,60,0,0,0,GLUT_BITMAP_HELVETICA_18);



glPopMatrix();
//end of pic uploaded by crasta

}


void page3()
{

     Text("Hebbal",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);

      //hebbal uploaded the below video
    Text(" shared",260,630,0,0,0,GLUT_BITMAP_9_BY_15);
    Text("WindMill Video  ",320,630,0,0,1,GLUT_BITMAP_8_BY_13);
      Text("Yesterday at 12:40am",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(0,1,1,1,0,1);
   glPopMatrix();
     if(likeon3==0)
          {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon3==1)
     {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }

Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);



glPushMatrix();
glScaled(1.1,1.2,0);
glTranslated(60,60,0);
   // glColor3f(1,1,1);
   // glRectd(400,280,100,120);
    glBegin(GL_POLYGON);//grass
      glColor3f(0.565, 0.933, 0.565);
     glVertex2f(400,280);
       glColor3f(0.565, 0.933, 0.565);
     glVertex2f(400,120);
      glColor3f(0.196, 0.804, 0.196);
     glVertex2f(100,120);
      glColor3f(0.196, 0.804, 0.196);
     glVertex2f(100,280);
     glEnd();

     glBegin(GL_POLYGON);//sky
      glColor3f(1,1,1);
     glVertex2f(400,420);
       glColor3f(0.7,0.7,0.7);
     glVertex2f(400,280);
      glColor3f(0.529, 0.808, 0.922);
     glVertex2f(100,280);
      glColor3f(0.529, 0.808, 0.922);
     glVertex2f(100,420);
     glEnd();
    //glRectd(400,420,100,280);
glPopMatrix();

frameNumber++;


	glPushMatrix();//near
	glTranslated(400,350,0);
	glScaled(50,50,1);
	windmill();
	glPopMatrix();


		glPushMatrix();//far
	glTranslated(200,400,0);
	glScaled(10,10,1);
	windmill();
	glPopMatrix();

		glPushMatrix();//far
	glTranslated(220,400,0);
	glScaled(10,10,1);
	windmill();
	glPopMatrix();

	glPushMatrix();//mid
	glTranslated(230,390,0);
	glScaled(30,30,1);
	windmill();
	glPopMatrix();

}
void page6()
{

     Text("Edwin ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text(" listening to music",260,630,0,0,0,GLUT_BITMAP_9_BY_15);
    Text("\"PSY-Gangnam Style\"",400,630,0,0,1,GLUT_BITMAP_8_BY_13);
      Text("10 Min ago",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(0,0,1,1,1,1);
   glPopMatrix();
   if(likeon6==0)
          {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon6==1)
       {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);


glPushMatrix();
glScaled(.35,.35,0);
glTranslated(480,600+rand()%2*2+rand()%2*2,0);
    glColor3f(0,0,0);
glBegin(GL_POLYGON);
 glVertex2f(175,534);
 glVertex2f(175,290);
 glVertex2f(104,290);

 glVertex2f(104,625);


glVertex2f(175,625);
 glVertex2f(185,656);
 glVertex2f(192,672);
 glVertex2f(202,696);
 glVertex2f(216,717);
 glVertex2f(228,731);
 glVertex2f(242,749);
 glVertex2f(266,772);
 glVertex2f(290,787);
 glVertex2f(307,798);
 glVertex2f(331,813);
 glVertex2f(348,821);
 glVertex2f(369,823);
 glVertex2f(395,831);
 glVertex2f(415,837);
 glVertex2f(441,840);
 glVertex2f(500,843);
 glVertex2f(577,841);
 glVertex2f(610,830);
 glVertex2f(639,824);
 glVertex2f(669,815);
 glVertex2f(693,804);
 glVertex2f(715,788);
 glVertex2f(744,771);
 glVertex2f(760,755);
 glVertex2f(765,747);
 glVertex2f(778,747);
 glVertex2f(790,716);
 glVertex2f(802,698);
 glVertex2f(813,678);
 glVertex2f(822,656);
 glVertex2f(826,630);
 glVertex2f(826,625);//next four points are the sec rect
 glVertex2f(903,625);
 glVertex2f(903,290);
 glVertex2f(826,290);
 glVertex2f(826,534);
 glVertex2f(807,537);
 glVertex2f(792,548);
 glVertex2f(780,557);
 glVertex2f(765,579);
 glVertex2f(760,605);
 glVertex2f(757,623);
 glVertex2f(754,641);
 glVertex2f(756,656);
 glVertex2f(730,672);
 glVertex2f(700,684);
 glVertex2f(667,695);
 glVertex2f(636,707);
 glVertex2f(597,714);
 glVertex2f(559,717);
 glVertex2f(519,722);
 glVertex2f(477,722);
 glVertex2f(432,720);
 glVertex2f(402,714);
 glVertex2f(373,707);
 glVertex2f(336,696);
 glVertex2f(307,686);
 glVertex2f(282,678);
 glVertex2f(265,668);
 glVertex2f(250,663);
 glVertex2f(249,642);
 glVertex2f(247,618);
 glVertex2f(238,593);
 glVertex2f(231,576);
 glVertex2f(221,560);
 glVertex2f(213,551);
 glVertex2f(196,542);
 glVertex2f(186,536);
 glVertex2f(175,534);
 glEnd();

 glBegin(GL_POLYGON);//human white face
 glColor3f(.969,.718,.537);
 glVertex2f(826,350);
 glVertex2f(826,534);
 glVertex2f(807,537);
 glVertex2f(792,548);
 glVertex2f(780,557);
 glVertex2f(765,579);
 glVertex2f(760,605);
 glVertex2f(757,623);
 glVertex2f(754,641);
 glVertex2f(756,656);
 glVertex2f(730,672);
 glVertex2f(700,684);
 glVertex2f(667,695);
 glVertex2f(636,707);
 glVertex2f(597,714);
 glVertex2f(559,717);
 glVertex2f(519,722);
 glVertex2f(477,722);
 glVertex2f(432,720);
 glVertex2f(402,714);
 glVertex2f(373,707);
 glVertex2f(336,696);
 glVertex2f(307,686);
 glVertex2f(282,678);
 glVertex2f(265,668);
 glVertex2f(250,663);
 glVertex2f(249,642);
 glVertex2f(247,618);
 glVertex2f(238,593);
 glVertex2f(231,576);
 glVertex2f(221,560);
 glVertex2f(213,551);
 glVertex2f(196,542);
 glVertex2f(186,536);
 glVertex2f(175,534);
 glVertex2f(175,350);
 glVertex2f(185,308);
 glVertex2f(191,291);
 glVertex2f(199,275);
 glVertex2f(209,260);
 glVertex2f(218,246);
 glVertex2f(232,229);
 glVertex2f(242,216);
 glVertex2f(255,203);
 glVertex2f(270,188);
 glVertex2f(281,177);
 glVertex2f(298,165);
 glVertex2f(319,150);
 glVertex2f(333,141);
 glVertex2f(350,133);
 glVertex2f(368,124);
 glVertex2f(393,118);
 glVertex2f(417,113);
 glVertex2f(438,106);
 glVertex2f(456,103);
 glVertex2f(484,104);
 glVertex2f(533,105);
 glVertex2f(550,107);
 glVertex2f(564,110);
 glVertex2f(577,113);
 glVertex2f(601,118);
 glVertex2f(620,126);
 glVertex2f(642,134);
 glVertex2f(667,146);
 glVertex2f(683,156);
 glVertex2f(702,167);
 glVertex2f(716,178);
 glVertex2f(732,189);
 glVertex2f(747,208);
 glVertex2f(756,220);
 glVertex2f(770,237);
 glVertex2f(781,255);
 glVertex2f(792,272);
 glVertex2f(803,289);
 glVertex2f(814,303);
 glVertex2f(821,328);
 glVertex2f(826,350);
glEnd();

glBegin(GL_POLYGON);//eye glass line
 glColor3f(0,0,0);
 glVertex2f(175,480);
 glVertex2f(826,480);
 glVertex2f(826,505);
 glVertex2f(175,505);
glEnd();

glBegin(GL_POLYGON);//right eye
glColor3f(0,0,0);
 glVertex2f(224,480);
 glVertex2f(225,459);
 glVertex2f(232,444);
 glVertex2f(237,430);
 glVertex2f(243,421);
 glVertex2f(252,411);
 glVertex2f(262,403);
 glVertex2f(274,393);
 glVertex2f(273,390);
 glVertex2f(286,386);
 glVertex2f(304,382);
 glVertex2f(316,379);
 glVertex2f(334,379);
 glVertex2f(344,379);
 glVertex2f(360,381);
 glVertex2f(373,383);
 glVertex2f(388,384);
 glVertex2f(403,386);
 glVertex2f(415,390);
 glVertex2f(430,400);
 glVertex2f(446,410);
 glVertex2f(457,419);
 glVertex2f(464,428);
 glVertex2f(469,439);
 glVertex2f(476,454);
 glVertex2f(480,465);
 glVertex2f(480,479);
 glVertex2f(480,480);
 glEnd();


glBegin(GL_POLYGON);//left eye
glColor3f(0,0,0);
 glVertex2f(524,480);
 glVertex2f(525,459);
 glVertex2f(532,444);
 glVertex2f(537,430);
 glVertex2f(543,421);
 glVertex2f(552,411);
 glVertex2f(562,403);
 glVertex2f(574,393);
 glVertex2f(573,390);
 glVertex2f(586,386);
 glVertex2f(604,382);
 glVertex2f(616,379);
 glVertex2f(634,379);
 glVertex2f(644,379);
 glVertex2f(660,381);
 glVertex2f(673,383);
 glVertex2f(688,384);
 glVertex2f(703,386);
 glVertex2f(715,390);
 glVertex2f(730,400);
 glVertex2f(746,410);
 glVertex2f(757,419);
 glVertex2f(764,428);
 glVertex2f(769,439);
 glVertex2f(776,454);
 glVertex2f(780,465);
 glVertex2f(780,479);
 glVertex2f(780,480);
 glEnd();

glLineWidth(5);//smile
 glBegin(GL_LINE_STRIP);
 glColor3f(.922,.604,.467);
  glVertex2f(360,310);
  glVertex2f(352,293);
  glVertex2f(359,275);
  glVertex2f(370,260);
  glVertex2f(383,245);
  glVertex2f(400,235);
  glVertex2f(422,224);
  glVertex2f(447,216);
  glVertex2f(477,211);
  glVertex2f(499,212);
  glVertex2f(526,213);
  glVertex2f(555,215);
  glVertex2f(577,223);
  glVertex2f(597,233);
  glVertex2f(621,244);
  glVertex2f(635,262);
  glVertex2f(644,276);
  glVertex2f(646,290);
  glVertex2f(646,300);
  glVertex2f(636,310);
glEnd();


glLineWidth(15);
 glBegin(GL_LINE_STRIP);
 glColor3f(.922,.604,.467);
  glVertex2f(463,335);
  glVertex2f(474,363);
  glVertex2f(524,364);
  glVertex2f(542,335);
  glEnd();

  glColor3f(.827,.827,.827);
  glRectd(104,625,140,900);
  glRectd(140,900,900,870);
  glRectd(900,870,860,625);

glBegin(GL_POLYGON);//right earphone
glColor3f(.827,.827,.827);
 glVertex2f(104,625);
 glVertex2f(77,617);
 glVertex2f(60,600);
 glVertex2f(46,577);
 glVertex2f(38,546);
 glVertex2f(31,527);
 glVertex2f(28,498);
 glVertex2f(25,475);
  glVertex2f(28,452);
 glVertex2f(26,414);
 glVertex2f(32,380);
  glVertex2f(39,360);
 glVertex2f(46,340);
 glVertex2f(55,318);
  glVertex2f(65,305);
 glVertex2f(78,290);
 glVertex2f(104,285);
 glEnd();


glBegin(GL_POLYGON);//left earphone
glColor3f(.827,.827,.827);
 glVertex2f(900,625);
 glVertex2f(909,617);
 glVertex2f(944,600);
 glVertex2f(960,577);
 glVertex2f(969,546);
 glVertex2f(973,527);
 glVertex2f(982,498);
 glVertex2f(987,475);
  glVertex2f(985,452);
 glVertex2f(977,414);
 glVertex2f(974,380);
  glVertex2f(969,360);
 glVertex2f(960,340);
 glVertex2f(944,318);
  glVertex2f(940,305);
 glVertex2f(930,290);
 glVertex2f(900,285);
 glEnd();


glPopMatrix();
glPushMatrix();
glColor3f(0,0,0);
glLineWidth(1);
glBegin(GL_LINE_LOOP);
 glVertex2f(160,210);
 glVertex2f(160,570);
 glVertex2f(520,570);
 glVertex2f(520,210);
glEnd();
glPopMatrix();
}

void page4()
{
       Text("Ashish  ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
        Text(" uploaded a photo",280,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Today at 08:00am",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(0,.5,1,.4,.6,1);
   glPopMatrix();
    if(likeon4==0)
         {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon4==1)
     {

        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
     } Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);





glPushMatrix();
glScaled(1.1,1.2,0);
glTranslated(55,77,0);
    glColor3f(0,0,0);
    glRectd(100,100,400,400);
    Text("A good friend",200,350,.738,.004,.015,0);
    Text("Helps you up",210,310,.805,.371,.028,GLUT_BITMAP_HELVETICA_18);
    Text("When you fall",210,270,.904,.943,.036,GLUT_BITMAP_9_BY_15);
    Text("A best friend",200,220,.007,.865,.007,0);
    Text("Laughs in your face",190,180,.070,.634,.715,GLUT_BITMAP_HELVETICA_18);
    Text("And trips you again!",180,140,.428,.148,.482,0);


glPopMatrix();


}

void page5()
{
     Text("Crasta  ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text(" shared",260,630,0,0,0,GLUT_BITMAP_9_BY_15);
    Text("MS DHONI-The best finisher's ",320,630,0,0,1,GLUT_BITMAP_8_BY_13);
    Text("Photo",490,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Yesterday at 10:00pm",220,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(0.7,0.7,1,1,0,1);
   glPopMatrix();
    if(likeon5==0)
          {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon5==1)
       {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }
      Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);





glPushMatrix();
glScaled(1.1,1.2,0);
glTranslated(60,55,0);
    glColor3f(.006,.012,.096);
    glRectd(100,120,400,420);
    Text("\"WHEN YOU FINISH ",105,370,1,1,1,0);
    Text("MANY GAMES,PEOPLE",110,320,1,1,1,0);
    Text("ALWAYS REMEMBER",110,270,1,1,1,0);
    Text("THE ONE YOU HAVE ",110,220,1,1,1,0);
    Text("NOT FINISHED\"",110,170,1,1,1,0);
    Text("--M.S.Dhoni",250,170,1,1,1,0);
glPopMatrix();

}

void page7()
{

     Text("Deepika ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
       Text(" shared",270,630,0,0,0,GLUT_BITMAP_9_BY_15);
    Text("Object Rotor's ",340,630,0,0,1,GLUT_BITMAP_8_BY_13);
    Text("Video",440,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Yesterday at 10:00pm",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(0,0.8,1,1,.8,1);
   glPopMatrix();
   if(likeon7==0)
          {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon7==1)
       {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }
      glColor3f(1,0,0);

glPushMatrix();
glScaled(13,13,0);
glTranslated(25,30,0);
glColor3f(0,0,1);
glRotatef(fbangle_s,1,1,1);
glutSolidCube(12);
glColor3f(0,rand()%9,rand()%9);
glutWireSphere(12,20,20);
glPopMatrix();
fbangle_s+=5;
glutPostRedisplay();
   Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);

glPushMatrix();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
 glVertex2f(160,210);
 glVertex2f(160,570);
 glVertex2f(520,570);
 glVertex2f(520,210);
glEnd();
glPopMatrix();
}
void page8()
{

    Text("Ashish",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text(" shared",260,630,0,0,0,GLUT_BITMAP_9_BY_15);
    Text("Computer World's ",320,630,0,0,1,GLUT_BITMAP_8_BY_13);
    Text("News",420,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Yesterday at 10:00pm",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(0.8,0.8,1,0,0,1);
   glPopMatrix();
       if(likeon8==0)
          {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon8==1)
       {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }
      glColor3f(1,0,0);
   Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);

glPushMatrix();
glScaled(1.1,1.2,0);
glTranslated(50,90,0);
    glColor3f(0.8,0.8,0.8);
    glRectd(100,100,400,350);
glPopMatrix();
Text("Only programmers will understand.....!",180,550,0,0,0,GLUT_BITMAP_HELVETICA_18);
Text("Semicolon",280,450,0,0,0,0);
  HugeText(";",300,350,0,0,0,10,1);
  Text("the solution to all compilation errors!",200,250,0,0,0,GLUT_BITMAP_HELVETICA_18);

  glPushMatrix();
  glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
 glVertex2f(160,210);
 glVertex2f(160,575);
 glVertex2f(500,575);
 glVertex2f(500,210);
glEnd();
glPopMatrix();
}

void page9()
{


     Text("Deepika ",220,630,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
       Text(" shared",280,630,0,0,0,GLUT_BITMAP_9_BY_15);
    Text("Object Rotor's ",340,630,0,0,1,GLUT_BITMAP_8_BY_13);
    Text("Video",440,630,0,0,0,GLUT_BITMAP_9_BY_15);
      Text("Yesterday at 10:00pm",240,600,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();                  //[rofile pics with different collors
   glScalef(.8,.8,0);
   glTranslatef(110,570,1);
   nopropic(.2,0.5,1,.4,1,.5);
   glPopMatrix();
    if(likeon9==0)
          {
      likeboff();
      Text("Like",180,180,.224,.224,.224,GLUT_BITMAP_HELVETICA_18);
    }else if(likeon9==1)
       {
        Text("Like",180,180,0,0,1,GLUT_BITMAP_HELVETICA_18);
       likebon();//like button
      }
      glColor3f(1,0,0);
    Text("Comment",240,180,.199,.199,.199,GLUT_BITMAP_HELVETICA_18);
    Text("Our reaction when teacher says one more small topic....",170,550,0,0,0,GLUT_BITMAP_HELVETICA_18);
glPushMatrix();
glScaled(1.1,1.2,0);
glTranslated(50,80,0);
    glColor3f(0.8,0.8,0.8);
    glRectd(100,100,400,370);
glPopMatrix();
int i; for(i=0;i<4;i++)
    profilepic(150+i*70,190,.5);
for(i=0;i<4;i++)
    profilepic(150+i*70,70,.5);

    glPushMatrix();
    glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
 glVertex2f(160,210);
 glVertex2f(160,570);
 glVertex2f(520,570);
 glVertex2f(520,210);
glEnd();
glPopMatrix();
}
void adtextmove()
{
    if(admove==0)
     cxx+=0.212;
     glTranslatef(0,+cxx,0);
    // printf("cxx=%f\n",cxx);
     if(cxx>=200)
     cxx=-20;
     glutPostRedisplay();
}

void ad()
{
    glColor3f(1,1,1);//ads box
    glRectd(589,890,830,10);
    glPushMatrix();
  adtextmove();
  glBegin(GL_POLYGON);//arrow mark in advertisemenet
   glColor3f(0,0,0);
   glVertex2f(605,830);
   glVertex2f(615,822.5);
   glVertex2f(605,815);
  glEnd();

  Text("I-Phone 7:Apple releases its new phone",620,820,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,765);
   glVertex2f(615,757.5);
   glVertex2f(605,750);
  glEnd();
    Text("New Android Version Launched:NINTENDO",620,755,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,700);
   glVertex2f(615,692.5);
   glVertex2f(605,685);
  glEnd();
    Text("Flipkart Big Billion Sale!",620,690,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,635);
   glVertex2f(615,627.5);
   glVertex2f(605,620);
  glEnd();
    Text("X-MEN:THE APOCALYPSE releases this friday!",620,625,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,570);
   glVertex2f(615,562.5);
   glVertex2f(605,555);
  glEnd();
  Text("Airtel gives free 2GB Data Get it right now!",620,560,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,505);
   glVertex2f(615,497.5);
   glVertex2f(605,490);
  glEnd();
  Text("IPL Season 9:Support your Team!",620,495,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,440);
   glVertex2f(615,432.5);
   glVertex2f(605,425);
  glEnd();
  Text("FAN Movie reviews:Bollywood Funda",620,430,0,0,0,GLUT_BITMAP_HELVETICA_12);

  glPushMatrix();
  glTranslated(0,-55,0);
    glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,440);
   glVertex2f(615,432.5);
   glVertex2f(605,425);
  glEnd();
  Text("Apple Mobile security cracked!!!!",620,430,0,0,0,GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();

    glPushMatrix();
  glTranslated(0,-55*2,0);
    glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,440);
   glVertex2f(615,432.5);
   glVertex2f(605,425);
  glEnd();
  Text("Donald Trump as president shocks all!!",620,430,0,0,0,GLUT_BITMAP_HELVETICA_12);
glPopMatrix();


glPushMatrix();
  glTranslated(0,-55*3,0);
    glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,440);
   glVertex2f(615,432.5);
   glVertex2f(605,425);
  glEnd();
  Text("Facebook will ban Candy crush soon. ",620,430,0,0,0,GLUT_BITMAP_HELVETICA_12);
glPopMatrix();


glPushMatrix();
  glTranslated(0,-55*4,0);
    glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   glVertex2f(605,440);
   glVertex2f(615,432.5);
   glVertex2f(605,425);
  glEnd();
  Text("Salman Khan getting married this year.",620,430,0,0,0,GLUT_BITMAP_HELVETICA_12);
glPopMatrix();





  glPopMatrix();



    glColor3f(0.9,0.9,0.9);
    glRectd(589,934,830,830);
    glColor3f(1,1,1);
    glRectd(589,890,830,820);//white box hack

    Text("Latest Updates:",600,850,0,0,0,GLUT_BITMAP_HELVETICA_18);


}


void logo()
{
    //logo for newsfeed
    glColor3f(0,0,0);
    glRectd(39,645,56,607);//border for newsfeed logo
    glColor3f(1,1,1);
    glRectd(40,643,55,609);//innerbox for newsfeed logo
    glColor3f(0.231,0.349,0.596);
    glRectd(48,640,53,638);//first line
    glColor3f(0.231,0.349,0.596);
    glRectd(48,633,53,631);//2nd line
    glColor3f(0,0,0);
    glRectd(43,624,53,622);//3rd line
    glColor3f(0.231,0.349,0.596);
    glRectd(41,619,53,617);//4th line
    glColor3f(0,0,0);
    glRectd(42,614,53,612);//5th line

    //logo for messages
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
     glVertex2f(40,577);
     glVertex2f(55,577);
     glVertex2f(55,560);
     glVertex2f(52,560);
     glVertex2f(48,550);
     glVertex2f(47,560);
     glVertex2f(40,560);
    glEnd();

    //logo for events
    glColor3f(.503,.089,.095);
    glBegin(GL_POLYGON);
    glVertex2f(43,523);
    glVertex2f(52,523);
    glVertex2f(55,518);
    glVertex2f(55,513);
    glVertex2f(40,513);
    glVertex2f(40,518);
    glEnd();
   /* glRectd(40,525,55,510);
    */glColor3f(0,0,0);
    glRectd(39,513,56,486);//outer border
    glColor3f(1,1,1);
    glRectd(40,512,55,488);//inner box
    Text("22",43,490,0,0,0,GLUT_BITMAP_8_BY_13);

    glPushMatrix();//poke symbol
    glTranslated(15,160,1);
    pokesymbol();
    glPopMatrix();
}

void profilepic(float X,float Y,float s)//X Y are the positions s for scaling
{
    float x=s;//x y a b c scales the profile pic
    float y=s;
    float a=s;
    float b=s;
    float c=s;

    glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);//out line for the profile pic
glVertex2d(201*x+X,671*y+Y);
glVertex2d(74*x+X,671*y+Y);
glVertex2d(74*x+X,394*y+Y);
glVertex2d(201*x+X,394*y+Y);
glEnd();

glColor3d(1,1,1);
glBegin(GL_POLYGON);//out line for the profile pic
glVertex2d(201*x+X,671*y+Y);
glVertex2d(74*x+X,671*y+Y);
glVertex2d(74*x+X,394*y+Y);
glVertex2d(201*x+X,394*y+Y);
glEnd();

glColor3f(1,1,1);//white face
glBegin(GL_POLYGON);
glVertex2f(63*x+X,548*y+Y);
glVertex2f(64*x+X,558*y+Y);
glVertex2f(65.3*x+X,569.8*y+Y);
glVertex2f(68.8*x+X,579*y+Y);
glVertex2f(70.8*x+X,593*y+Y);
glVertex2f(75.8*x+X,604.8*y+Y);
glVertex2f(80.3*x+X,611.8*y+Y);
glVertex2f(84.3*x+X,619*y+Y);
glVertex2f(93.8*x+X,628.3*y+Y);
glVertex2f(103*x+X,633.5*y+Y);
glVertex2f(150*x+X,630*y+Y);
glVertex2f(159*x+X,628*y+Y);
glVertex2f(169*x+X,623*y+Y);
glVertex2f(178*x+X,618*y+Y);
glVertex2f(188*x+X,609*y+Y);
glVertex2f(193*x+X,602*y+Y);
glVertex2f(200*x+X,593*y+Y);
glVertex2f(203*x+X,585*y+Y);
glVertex2f(207*x+X,574*y+Y);
glVertex2f(207*x+X,547*y+Y);
glVertex2f(202*x+X,536*y+Y);
glVertex2f(195*x+X,519*y+Y);
glVertex2f(181*x+X,498*y+Y);
glVertex2f(172*x+X,486*y+Y);
glVertex2f(155*x+X,477*y+Y);
glVertex2f(139*x+X,472*y+Y);
glVertex2f(125*x+X,474*y+Y);
glVertex2f(110*x+X,477*y+Y);//neck here
glVertex2f(99*x+X,481*y+Y);
glVertex2f(84*x+X,494*y+Y);
glVertex2f(75*x+X,510*y+Y);
glVertex2f(67*x+X,529*y+Y);
glVertex2f(63*x+X,548*y+Y);
glEnd();

glColor3f(0,0,0);//face border
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2f(63*x+X,548*y+Y);
glVertex2f(64*x+X,558*y+Y);
glVertex2f(65.3*x+X,569.8*y+Y);
glVertex2f(68.8*x+X,579*y+Y);
glVertex2f(70.8*x+X,593*y+Y);
glVertex2f(75.8*x+X,604.8*y+Y);
glVertex2f(80.3*x+X,611.8*y+Y);
glVertex2f(84.3*x+X,619*y+Y);
glVertex2f(93.8*x+X,628.3*y+Y);
glVertex2f(103*x+X,633.5*y+Y);
glVertex2f(150*x+X,630*y+Y);
glVertex2f(159*x+X,628*y+Y);
glVertex2f(169*x+X,623*y+Y);
glVertex2f(178*x+X,618*y+Y);
glVertex2f(188*x+X,609*y+Y);
glVertex2f(193*x+X,602*y+Y);
glVertex2f(200*x+X,593*y+Y);
glVertex2f(203*x+X,585*y+Y);
glVertex2f(207*x+X,574*y+Y);
glVertex2f(207*x+X,547*y+Y);
glVertex2f(202*x+X,536*y+Y);
glVertex2f(195*x+X,519*y+Y);
glVertex2f(181*x+X,498*y+Y);
glVertex2f(172*x+X,486*y+Y);
glVertex2f(155*x+X,477*y+Y);
glVertex2f(139*x+X,472*y+Y);
glVertex2f(125*x+X,474*y+Y);
glVertex2f(110*x+X,477*y+Y);//neck here
glVertex2f(99*x+X,481*y+Y);
glVertex2f(84*x+X,494*y+Y);
glVertex2f(75*x+X,510*y+Y);
glVertex2f(67*x+X,529*y+Y);
glVertex2f(63*x+X,548*y+Y);
glEnd();

glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);//neck
glVertex2f(110*x+X,477*y+Y);
glVertex2f(103*x+X,440*y+Y);
glEnd();

//eyes
glColor3f(1,1,1);
semicircle(110*a+X,570*b+Y,20*c);//left
semicircle(175*a+X,562*b+Y,20*c);//right
glColor3f(0,0,0);
glLineWidth(2);
semicirclearc(110*a+X,570*b+Y,20*c);//left black eye border
semicirclearc(175*a+X,562*b+Y,20*c);//right black eye border

glColor3f(0,0,0);
semicircle(115*a+X+rand()%2,568*b+Y,10*c);//left pupil
semicircle(180*a+X+rand()%2,561*b+Y,10*c);//right pupil

glColor3f(0,0,0);
glLineWidth(2);//mouth
glBegin(GL_LINE_STRIP);
glVertex2f(106*x+X,512*y+Y);
glVertex2f(108*x+X,517*y+Y);
glVertex2f(113*x+X,517*y+Y);
glVertex2f(146*x+X,508*y+Y);
glVertex2f(147*x+X,507*y+Y);
glVertex2f(151*x+X,507*y+Y);
glVertex2f(150*x+X,500*y+Y);
glEnd();

glLineWidth(2);//mouth down effect
glBegin(GL_LINE_STRIP);
glVertex2f(115*x+X,510*y+Y);
glVertex2f(117*x+X,509*y+Y);
glVertex2f(122*x+X,510*y+Y);
glVertex2f(129*x+X,507*y+Y);
glVertex2f(131*x+X,507*y+Y);
glVertex2f(136*x+X,505*y+Y);
glVertex2f(141*x+X,503*y+Y);
glEnd();

glBegin(GL_LINE_STRIP);//left cheek
glVertex2f(94*x+X,507*y+Y);
glVertex2f(91*x+X,510*y+Y);
glVertex2f(89*x+X,514*y+Y);
glVertex2f(90*x+X,519*y+Y);
glVertex2f(92*x+X,524*y+Y);
glVertex2f(93*x+X,526*y+Y);
glVertex2f(94*x+X,529*y+Y);
glEnd();

glBegin(GL_LINE_STRIP);//right cheek
glVertex2f(162*x+X,510*y+Y);
glVertex2f(162*x+X,508*y+Y);
glVertex2f(164*x+X,505*y+Y);
glVertex2f(164*x+X,503*y+Y);
glVertex2f(162*x+X,498*y+Y);
glVertex2f(157*x+X,493*y+Y);
glVertex2f(155*x+X,491*y+Y);
glVertex2f(153*x+X,487*y+Y);
glEnd();

}

void req()
{
     glColor3f(.929,.929,.929);
    glLineWidth(3);
    glBegin(GL_LINES);//right div line
        glVertex2d(847,933);
        glVertex2d(847,0);
    glEnd();

    Text("2 Candy Crush Requests",860,790,0,0,0,GLUT_BITMAP_HELVETICA_12);
    Text("Play Game!",860,750,0,0,0,GLUT_BITMAP_HELVETICA_12);
//XOX gameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    glBegin(GL_LINE_LOOP);
     glVertex2f(870,700);//following are rect and lines
     glVertex2f(990,700);
     glVertex2f(990,580);
     glVertex2f(870,580);
    glEnd();
    glBegin(GL_LINE_STRIP);
     glVertex2f(910,700);
     glVertex2f(910,580);
    glEnd();
    glBegin(GL_LINE_STRIP);
     glVertex2f(950,700);
     glVertex2f(950,580);
    glEnd();

    glBegin(GL_LINE_STRIP);
     glVertex2f(870,660);
     glVertex2f(990,660);
    glEnd();

    glBegin(GL_LINE_STRIP);
     glVertex2f(870,620);
     glVertex2f(990,620);
    glEnd();
   // Text("X",890,670,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("X",890,590,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("X",970,590,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("O",930,630,0,0,0,GLUT_BITMAP_HELVETICA_18);

    glColor3f(0.741, 0.718, 0.420+rand()%2);
    glRectd(980,570,865,530);
    Text("Play game!!",885,540,rand()%3,rand()%3,rand()%3,0);


}


void chatbox()//chatting box //must be interactive
{
    glColor3d(0.9,0.9,0.9);//box
  // glRectd(830,466,635,0);
    glBegin(GL_POLYGON);
                glVertex2d(830, 466);
                glVertex2d(635, 466);
                glVertex2d(635, 0);
                glVertex2d(830, 0);
     glEnd();



    glColor3f(0.231,0.349,0.596);//head
    glRectd(830,467,635,421);
    Text(username,645,430,1,1,1,GLUT_BITMAP_9_BY_15);
    Text("X",810,445,1,1,1,GLUT_BITMAP_HELVETICA_18);//close button
    glColor3f(1,1,1);
    glRectd(830,54,635,0);
    glColor3d(0.6,0.6,0.6);//box border
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
                glVertex2d(830, 466);
                glVertex2d(635, 466);
                glVertex2d(635, 0);
                glVertex2d(830, 0);
     glEnd();

if(typeamessage==0)
    Text("Type a message",640,25,0.9,0.9,0.9,GLUT_BITMAP_9_BY_15);
    if(chating==1)
     chatdataflow();

}


void timeline()
{
    glColor3f(1,1,1);
   glRectd(295,344,55,0);//left box
  //  glRectd(689,344,307,210);//right white box
    glRectd(685,182,305,0);//right bottom box
    Text("Intro",70,300,0,0,0,0);
    Text("+      Describe who you are",70,250,.306,.412,.635,GLUT_BITMAP_9_BY_15);
    Text("Lives in ",70,200,0,1,0,GLUT_BITMAP_HELVETICA_18);
    Text("Mangalore,Karnataka,India",120,200,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("From ",70,150,1,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("             Mangalore,Karnataka,India",70,150,0,0,0,GLUT_BITMAP_HELVETICA_18);

    glPushMatrix();
    glScaled(.95,0.7,0.0);
    glTranslated(174,-400,0);
        glColor3f(1,1,1);
    glRectd(150,890,550,680);//first white box containing update status
    glColor3f(1,1,1);
    glRectd(150,660,550,10);//bottom news time line box
      Text("Update Status",175,840,0.0,0.0,0.0,GLUT_BITMAP_9_BY_15);
      glBegin(GL_LINE_STRIP);
       glColor3f(.929,.929,.929);//line above whats on your mind
       glVertex2f(155,810);
       glVertex2f(220,810);
       glVertex2f(230,820);
       glVertex2f(240,810);
       glVertex2f(550,810);
      glEnd();

      glBegin(GL_LINE_STRIP);//line below whats on your mind
       glColor3f(.929,.929,.929);
       glVertex2f(150,720);
       glVertex2f(550,720);
      glEnd();
      glColor3f(.441,.561,.827);//'update status' logo
      glRectd(155,860,173,830);
      glBegin(GL_LINE_LOOP);//pencil top
        glColor3f(1,1,1);
       glVertex2f(168.5,856.9);
       glVertex2f(170.9,851.7);
       glVertex2f(170.8,850.7);
       glVertex2f(168.5,853.8);
      glEnd();

      glBegin(GL_LINE_LOOP);//pencil mid
        glColor3f(1,1,1);
       glVertex2f(165.5,852.4);
       glVertex2f(167.7,847.8);
       glVertex2f(163.1,840.6);
       glVertex2f(160.6,843);
      glEnd();

     glBegin(GL_LINE_LOOP);//pencil bottom
        glColor3f(1,1,1);
       glVertex2f(158.4,838.7);
       glVertex2f(160.4,836.8);
       glVertex2f(157,833.9);
     glEnd();
      profilepic(150,660,.2);//pic near whats on you mind

      Text("What's on your mind..?",210,760,.8,.8,.8,GLUT_BITMAP_HELVETICA_12);

      glBegin(GL_POLYGON);//post logo
       glColor3f(0.231,0.349,0.596);
       glVertex2f(500,715);
       glVertex2f(540,715);
       glVertex2f(540,685);
       glVertex2f(500,685);
      glEnd();
    Text("Post",510,695,1,1,1,GLUT_BITMAP_8_BY_13);


glPopMatrix();


 if(postit==1){
  glPushMatrix();
  glTranslated(180,-630,1);
    posting();
  glPopMatrix();
  profilepic(320,30,.2);
  }
}
void About()
{
    glColor3f(.965,.969,.973);
    glRectd(689,344,60,292);//top white box for about text
    Text("About",80,310,0.85,0.2,0.2,GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    glRectd(295,285,60,0);// left  white box
    Text("Overview-------------------",70,240,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("Work and Education----------",70,185,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("Contact and Basic Info-------",70,130,0,0,0,GLUT_BITMAP_HELVETICA_18);
    Text("Life Events------------------",70,75,0,0,0,GLUT_BITMAP_HELVETICA_18);

    glColor3f(1,1,1);
    glRectd(689,285,297,0);

      Text("An Engineer by profession and gamer by work!!",310,240,0,0,1,GLUT_BITMAP_9_BY_15);
    Text("Working and Educated ..lol..",310,185,0,0.3,1,GLUT_BITMAP_9_BY_15);
    Text("93423422323 ..call me !!",310,130,0.2,0.4,1,GLUT_BITMAP_9_BY_15);
    Text("Was born on some day..",310,75,0.4,0,1,GLUT_BITMAP_9_BY_15);


}

void friends()
{
glColor3f(.965,.969,.973);
glRectd(689,344,60,292);
Text("Friends",80,310,0,0,1,0);
glColor3f(1,1,1);
glRectd(689,285,60,0);
  glPushMatrix();

     glTranslatef(150,-450,0);
   glScalef(3,3,0);

   nopropic(0.5,0.5,0.5,rand()%2,1,1);
   glPopMatrix();
glPushMatrix();
glTranslated(-700,-150,0);
  Text(">>>>ALia Bhat",810,405,0,0,1,GLUT_BITMAP_9_BY_15);
  Text(">>>>>Priyanka Chopra",820,365,0,0,1,GLUT_BITMAP_9_BY_15);
  Text(">>>>>>John Abraham",830,325,0,0,1,GLUT_BITMAP_9_BY_15);
  Text(">>>>>>>Deepika Padukone",840,285,0,0,1,GLUT_BITMAP_9_BY_15);
  Text(">>>>>>>>Ranveer Singh",850,245,0,0,1,GLUT_BITMAP_9_BY_15);
  Text(">>>>>>>>>VArun Dawan",860,205,0,0,1,GLUT_BITMAP_9_BY_15);
  Text(">>>>>>>>>>>Siddarth Malhotra",870,165,0,0,1,GLUT_BITMAP_9_BY_15);
  glPopMatrix();
//Text("Friend List yet to be updated..!",80,250,.26,.25,.12,0);
}

void photos()
{
glColor3f(.965,.969,.973);
glRectd(689,344,60,292);
Text("Photos",80,310,0.5,0.2,0.6,0);
glColor3f(1,1,1);
glRectd(689,285,60,0);
  profilepic(30,-60,.5);


glPushMatrix();
glScaled(.15,.15,0);
glTranslated(980,760,0);
      glColor3f(0,0,0);
glBegin(GL_POLYGON);
 glVertex2f(175,534);
 glVertex2f(175,290);
 glVertex2f(104,290);

 glVertex2f(104,625);


glVertex2f(175,625);
 glVertex2f(185,656);
 glVertex2f(192,672);
 glVertex2f(202,696);
 glVertex2f(216,717);
 glVertex2f(228,731);
 glVertex2f(242,749);
 glVertex2f(266,772);
 glVertex2f(290,787);
 glVertex2f(307,798);
 glVertex2f(331,813);
 glVertex2f(348,821);
 glVertex2f(369,823);
 glVertex2f(395,831);
 glVertex2f(415,837);
 glVertex2f(441,840);
 glVertex2f(500,843);
 glVertex2f(577,841);
 glVertex2f(610,830);
 glVertex2f(639,824);
 glVertex2f(669,815);
 glVertex2f(693,804);
 glVertex2f(715,788);
 glVertex2f(744,771);
 glVertex2f(760,755);
 glVertex2f(765,747);
 glVertex2f(778,747);
 glVertex2f(790,716);
 glVertex2f(802,698);
 glVertex2f(813,678);
 glVertex2f(822,656);
 glVertex2f(826,630);
 glVertex2f(826,625);//next four points are the sec rect
 glVertex2f(903,625);
 glVertex2f(903,290);
 glVertex2f(826,290);
 glVertex2f(826,534);
 glVertex2f(807,537);
 glVertex2f(792,548);
 glVertex2f(780,557);
 glVertex2f(765,579);
 glVertex2f(760,605);
 glVertex2f(757,623);
 glVertex2f(754,641);
 glVertex2f(756,656);
 glVertex2f(730,672);
 glVertex2f(700,684);
 glVertex2f(667,695);
 glVertex2f(636,707);
 glVertex2f(597,714);
 glVertex2f(559,717);
 glVertex2f(519,722);
 glVertex2f(477,722);
 glVertex2f(432,720);
 glVertex2f(402,714);
 glVertex2f(373,707);
 glVertex2f(336,696);
 glVertex2f(307,686);
 glVertex2f(282,678);
 glVertex2f(265,668);
 glVertex2f(250,663);
 glVertex2f(249,642);
 glVertex2f(247,618);
 glVertex2f(238,593);
 glVertex2f(231,576);
 glVertex2f(221,560);
 glVertex2f(213,551);
 glVertex2f(196,542);
 glVertex2f(186,536);
 glVertex2f(175,534);
 glEnd();

 glBegin(GL_POLYGON);//human white face
 glColor3f(.969,.718,.537);
 glVertex2f(826,350);
 glVertex2f(826,534);
 glVertex2f(807,537);
 glVertex2f(792,548);
 glVertex2f(780,557);
 glVertex2f(765,579);
 glVertex2f(760,605);
 glVertex2f(757,623);
 glVertex2f(754,641);
 glVertex2f(756,656);
 glVertex2f(730,672);
 glVertex2f(700,684);
 glVertex2f(667,695);
 glVertex2f(636,707);
 glVertex2f(597,714);
 glVertex2f(559,717);
 glVertex2f(519,722);
 glVertex2f(477,722);
 glVertex2f(432,720);
 glVertex2f(402,714);
 glVertex2f(373,707);
 glVertex2f(336,696);
 glVertex2f(307,686);
 glVertex2f(282,678);
 glVertex2f(265,668);
 glVertex2f(250,663);
 glVertex2f(249,642);
 glVertex2f(247,618);
 glVertex2f(238,593);
 glVertex2f(231,576);
 glVertex2f(221,560);
 glVertex2f(213,551);
 glVertex2f(196,542);
 glVertex2f(186,536);
 glVertex2f(175,534);
 glVertex2f(175,350);
 glVertex2f(185,308);
 glVertex2f(191,291);
 glVertex2f(199,275);
 glVertex2f(209,260);
 glVertex2f(218,246);
 glVertex2f(232,229);
 glVertex2f(242,216);
 glVertex2f(255,203);
 glVertex2f(270,188);
 glVertex2f(281,177);
 glVertex2f(298,165);
 glVertex2f(319,150);
 glVertex2f(333,141);
 glVertex2f(350,133);
 glVertex2f(368,124);
 glVertex2f(393,118);
 glVertex2f(417,113);
 glVertex2f(438,106);
 glVertex2f(456,103);
 glVertex2f(484,104);
 glVertex2f(533,105);
 glVertex2f(550,107);
 glVertex2f(564,110);
 glVertex2f(577,113);
 glVertex2f(601,118);
 glVertex2f(620,126);
 glVertex2f(642,134);
 glVertex2f(667,146);
 glVertex2f(683,156);
 glVertex2f(702,167);
 glVertex2f(716,178);
 glVertex2f(732,189);
 glVertex2f(747,208);
 glVertex2f(756,220);
 glVertex2f(770,237);
 glVertex2f(781,255);
 glVertex2f(792,272);
 glVertex2f(803,289);
 glVertex2f(814,303);
 glVertex2f(821,328);
 glVertex2f(826,350);
glEnd();

glBegin(GL_POLYGON);//eye glass line
 glColor3f(0,0,0);
 glVertex2f(175,480);
 glVertex2f(826,480);
 glVertex2f(826,505);
 glVertex2f(175,505);
glEnd();

glBegin(GL_POLYGON);//right eye
glColor3f(0,0,0);
 glVertex2f(224,480);
 glVertex2f(225,459);
 glVertex2f(232,444);
 glVertex2f(237,430);
 glVertex2f(243,421);
 glVertex2f(252,411);
 glVertex2f(262,403);
 glVertex2f(274,393);
 glVertex2f(273,390);
 glVertex2f(286,386);
 glVertex2f(304,382);
 glVertex2f(316,379);
 glVertex2f(334,379);
 glVertex2f(344,379);
 glVertex2f(360,381);
 glVertex2f(373,383);
 glVertex2f(388,384);
 glVertex2f(403,386);
 glVertex2f(415,390);
 glVertex2f(430,400);
 glVertex2f(446,410);
 glVertex2f(457,419);
 glVertex2f(464,428);
 glVertex2f(469,439);
 glVertex2f(476,454);
 glVertex2f(480,465);
 glVertex2f(480,479);
 glVertex2f(480,480);
 glEnd();


glBegin(GL_POLYGON);//left eye
glColor3f(0,0,0);
 glVertex2f(524,480);
 glVertex2f(525,459);
 glVertex2f(532,444);
 glVertex2f(537,430);
 glVertex2f(543,421);
 glVertex2f(552,411);
 glVertex2f(562,403);
 glVertex2f(574,393);
 glVertex2f(573,390);
 glVertex2f(586,386);
 glVertex2f(604,382);
 glVertex2f(616,379);
 glVertex2f(634,379);
 glVertex2f(644,379);
 glVertex2f(660,381);
 glVertex2f(673,383);
 glVertex2f(688,384);
 glVertex2f(703,386);
 glVertex2f(715,390);
 glVertex2f(730,400);
 glVertex2f(746,410);
 glVertex2f(757,419);
 glVertex2f(764,428);
 glVertex2f(769,439);
 glVertex2f(776,454);
 glVertex2f(780,465);
 glVertex2f(780,479);
 glVertex2f(780,480);
 glEnd();

glLineWidth(5);//smile
 glBegin(GL_LINE_STRIP);
 glColor3f(.922,.604,.467);
  glVertex2f(360,310);
  glVertex2f(352,293);
  glVertex2f(359,275);
  glVertex2f(370,260);
  glVertex2f(383,245);
  glVertex2f(400,235);
  glVertex2f(422,224);
  glVertex2f(447,216);
  glVertex2f(477,211);
  glVertex2f(499,212);
  glVertex2f(526,213);
  glVertex2f(555,215);
  glVertex2f(577,223);
  glVertex2f(597,233);
  glVertex2f(621,244);
  glVertex2f(635,262);
  glVertex2f(644,276);
  glVertex2f(646,290);
  glVertex2f(646,300);
  glVertex2f(636,310);
glEnd();


glLineWidth(15);
 glBegin(GL_LINE_STRIP);
 glColor3f(.922,.604,.467);
  glVertex2f(463,335);
  glVertex2f(474,363);
  glVertex2f(524,364);
  glVertex2f(542,335);
  glEnd();

  glColor3f(.827,.827,.827);
  glRectd(104,625,140,900);
  glRectd(140,900,900,870);
  glRectd(900,870,860,625);

glBegin(GL_POLYGON);//right earphone
glColor3f(.827,.827,.827);
 glVertex2f(104,625);
 glVertex2f(77,617);
 glVertex2f(60,600);
 glVertex2f(46,577);
 glVertex2f(38,546);
 glVertex2f(31,527);
 glVertex2f(28,498);
 glVertex2f(25,475);
  glVertex2f(28,452);
 glVertex2f(26,414);
 glVertex2f(32,380);
  glVertex2f(39,360);
 glVertex2f(46,340);
 glVertex2f(55,318);
  glVertex2f(65,305);
 glVertex2f(78,290);
 glVertex2f(104,285);
 glEnd();


glBegin(GL_POLYGON);//left earphone
glColor3f(.827,.827,.827);
 glVertex2f(900,625);
 glVertex2f(909,617);
 glVertex2f(944,600);
 glVertex2f(960,577);
 glVertex2f(969,546);
 glVertex2f(973,527);
 glVertex2f(982,498);
 glVertex2f(987,475);
  glVertex2f(985,452);
 glVertex2f(977,414);
 glVertex2f(974,380);
  glVertex2f(969,360);
 glVertex2f(960,340);
 glVertex2f(944,318);
  glVertex2f(940,305);
 glVertex2f(930,290);
 glVertex2f(900,285);
 glEnd();


glPopMatrix();


glPushMatrix();
glScaled(.15,.15,0);
glTranslated(2180,790,0);

    glColor3f(.271,.404,.604);//blue rectangle
    glBegin(GL_POLYGON);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();

    glColor3f(0,0,0);//border for rectangle
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();

    glColor3f(0,0,0);//hand symbol
    glBegin(GL_LINE_LOOP);
     glVertex2f(196,507);
     glVertex2f(203,513);
     glVertex2f(206,520);
     glVertex2f(209,527);
     glVertex2f(212,540);
     glVertex2f(216,557);
     glVertex2f(219,564);
     glVertex2f(221,581);
     glVertex2f(223,590);
     glVertex2f(227,601);
     glVertex2f(231,627);
     glVertex2f(234,646);
     glVertex2f(238,661);
     glVertex2f(239,674);
     glVertex2f(242,685);
     glVertex2f(247,698);
     glVertex2f(250,717);
     glVertex2f(247,732);
     glVertex2f(247,745);
     glVertex2f(246,766);
     glVertex2f(245,782);
     glVertex2f(245,794);
     glVertex2f(246,813);
     glVertex2f(245,821);
     glVertex2f(248,827);
     glVertex2f(253,830);
     glVertex2f(259,826);
     glVertex2f(263,818);
     glVertex2f(269,806);
     glVertex2f(273,789);
     glVertex2f(279,766);
     glVertex2f(282,749);
     glVertex2f(282,727);
     glVertex2f(282,711);
     glVertex2f(282,700);
     glVertex2f(281,678);
     glVertex2f(281,666);
     glVertex2f(281,651);
     glVertex2f(281,639);
     glVertex2f(280,627);
     glVertex2f(279,617);
     glVertex2f(278,604);
     glVertex2f(355,604);
     glVertex2f(360,601);
     glVertex2f(363,593);
     glVertex2f(367,582);
     glVertex2f(371,572);
     glVertex2f(371,559);
     glVertex2f(371,545);
     glVertex2f(368,535);
     glVertex2f(363,523);
     glVertex2f(359,516);
     glVertex2f(359,509);
     glVertex2f(364,504);
     glVertex2f(370,495);
     glVertex2f(374,483);
     glVertex2f(374,471);
     glVertex2f(375,458);
     glVertex2f(372,446);
     glVertex2f(370,438);
     glVertex2f(365,429);
     glVertex2f(359,425);
     glVertex2f(354,423);
     glVertex2f(354,410);
     glVertex2f(359,408);
     glVertex2f(361,392);
     glVertex2f(364,381);
     glVertex2f(364,370);
     glVertex2f(362,361);
     glVertex2f(356,345);
     glVertex2f(350,336);
     glVertex2f(346,334);
     glVertex2f(341,333);
     glVertex2f(341,320);
     glVertex2f(348,305);
     glVertex2f(347,296);
     glVertex2f(347,291);
     glVertex2f(346,281);
     glVertex2f(344,271);
     glVertex2f(339,260);
     glVertex2f(332,250);
     glVertex2f(223,246);
     glVertex2f(215,255);
     glVertex2f(212,260);
     glVertex2f(209,266);
     glVertex2f(204,272);
     glVertex2f(199,276);
     glVertex2f(196,283);

glEnd();
glPopMatrix();

glPushMatrix();
glScaled(1.7,1.5,0);
glTranslated(280,120,0);
glColor3f(0,0,0);
glutSolidTeapot(15);

glPopMatrix();


glPushMatrix();
glScaled(1.7,1.5,0);
glTranslated(360,130,0);
glColor3f(0,0,1);
glutWireTorus(5,15,5,50);

glPopMatrix();

}

void prolin(float X,float Y,float s)//X Y are the positions s for scaling
{


 glLineWidth(2);
glBegin(GL_LINE_STRIP);
 glVertex2f(319*s+X,777*s+Y);
 glVertex2f(315*s+X,772*s+Y);
 glVertex2f(310*s+X,817*s+Y);
 glVertex2f(295*s+X,848*s+Y);
 glVertex2f(275*s+X,873*s+Y);
 glVertex2f(246*s+X,891*s+Y);
 glVertex2f(208*s+X,913*s+Y);
 glVertex2f(188*s+X,935*s+Y);
  glEnd();


}

void prolin2(float X,float Y,float s)
{
        glBegin(GL_LINE_STRIP);
  glVertex2f(433*s-X,779*s+Y);
    glVertex2f(437*s-X,795*s+Y);
       glVertex2f(456*s-X,847*s+Y);
          glVertex2f(476*s-X,870*s+Y);
            glVertex2f(506*s-X,892*s+Y);
              glVertex2f(545*s-X,911*s+Y);
                glVertex2f(556*s-X,921*s+Y);
                  glVertex2f(565*s-X,942*s+Y);
                  glEnd();
}

void chat()
{
  glColor3f(0.231,0.349,0.596);
  glRectd(1000,500,847,450);
  Text("Chat",880,475,1,1,1,GLUT_BITMAP_9_BY_15);
  Text("Ashish Kirodian",860,405,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("Priyanka Chopra",860,365,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("John Abraham",860,325,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("Deepika Padukone",860,285,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("Ranveer Singh",860,245,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("VArun Dawan",860,205,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("Siddarth Malhotra",860,165,0,0,0,GLUT_BITMAP_8_BY_13);
  Text("ALia Bhat",860,125,0,0,0,GLUT_BITMAP_8_BY_13);
  glColor3f(0,1,0);
  glPointSize(5);
  glBegin(GL_POINTS);
  //glVertex2f(980,410);
  glVertex2f(980,370);
  glVertex2f(980,330);
  //glVertex2f(980,290);
  glVertex2f(980,250);
  //glVertex2f(980,210);
  glVertex2f(980,170);
  glVertex2f(980,130);
  glEnd();
  if(chaton==1)
  {
      chatbox();
  }
}

void profilebody()
{
   glColor3f(.929,.929,.929);
    glLineWidth(3);
    glBegin(GL_LINES);//right div line for chat
        glVertex2d(847,933);
        glVertex2d(847,0);
    glEnd();

    //the heading
    Text("Timeline",219,380,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text("About",286,380,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text("Friends",345,380,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);
    Text("Photos",420,380,0.231,0.349,0.596,GLUT_BITMAP_HELVETICA_18);





}

void likeboff()
{
    glPushMatrix();
    glScaled(.06,0.05,0.0);
    glTranslated(2500,3200,0);

    glColor3f(.271,.404,.604);//blue rectangle
    glBegin(GL_POLYGON);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();

    glColor3f(0,0,0);//border for rectangle
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();

    glColor3f(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(196,507);
     glVertex2f(203,513);
     glVertex2f(206,520);
     glVertex2f(209,527);
     glVertex2f(212,540);
     glVertex2f(216,557);
     glVertex2f(219,564);
     glVertex2f(221,581);
     glVertex2f(223,590);
     glVertex2f(227,601);
     glVertex2f(231,627);
     glVertex2f(234,646);
     glVertex2f(238,661);
     glVertex2f(239,674);
     glVertex2f(242,685);
     glVertex2f(247,698);
     glVertex2f(250,717);
     glVertex2f(247,732);
     glVertex2f(247,745);
     glVertex2f(246,766);
     glVertex2f(245,782);
     glVertex2f(245,794);
     glVertex2f(246,813);
     glVertex2f(245,821);
     glVertex2f(248,827);
     glVertex2f(253,830);
     glVertex2f(259,826);
     glVertex2f(263,818);
     glVertex2f(269,806);
     glVertex2f(273,789);
     glVertex2f(279,766);
     glVertex2f(282,749);
     glVertex2f(282,727);
     glVertex2f(282,711);
     glVertex2f(282,700);
     glVertex2f(281,678);
     glVertex2f(281,666);
     glVertex2f(281,651);
     glVertex2f(281,639);
     glVertex2f(280,627);
     glVertex2f(279,617);
     glVertex2f(278,604);
     glVertex2f(355,604);
     glVertex2f(360,601);
     glVertex2f(363,593);
     glVertex2f(367,582);
     glVertex2f(371,572);
     glVertex2f(371,559);
     glVertex2f(371,545);
     glVertex2f(368,535);
     glVertex2f(363,523);
     glVertex2f(359,516);
     glVertex2f(359,509);
     glVertex2f(364,504);
     glVertex2f(370,495);
     glVertex2f(374,483);
     glVertex2f(374,471);
     glVertex2f(375,458);
     glVertex2f(372,446);
     glVertex2f(370,438);
     glVertex2f(365,429);
     glVertex2f(359,425);
     glVertex2f(354,423);
     glVertex2f(354,410);
     glVertex2f(359,408);
     glVertex2f(361,392);
     glVertex2f(364,381);
     glVertex2f(364,370);
     glVertex2f(362,361);
     glVertex2f(356,345);
     glVertex2f(350,336);
     glVertex2f(346,334);
     glVertex2f(341,333);
     glVertex2f(341,320);
     glVertex2f(348,305);
     glVertex2f(347,296);
     glVertex2f(347,291);
     glVertex2f(346,281);
     glVertex2f(344,271);
     glVertex2f(339,260);
     glVertex2f(332,250);
     glVertex2f(223,246);
     glVertex2f(215,255);
     glVertex2f(212,260);
     glVertex2f(209,266);
     glVertex2f(204,272);
     glVertex2f(199,276);
     glVertex2f(196,283);

glEnd();
glPopMatrix();
}

void likebon()
{
    glPushMatrix();
    glScaled(.06,0.05,0.0);
    glTranslated(2500,3200,0);

    glColor3f(.271,.404,.604);//blue rectangle
    glBegin(GL_POLYGON);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();

    glColor3f(0,0,0);//border for rectangle
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();

    glColor3f(0,0,1);
     glBegin(GL_LINE_LOOP);
     glVertex2f(196,507);
     glVertex2f(203,513);
     glVertex2f(206,520);
     glVertex2f(209,527);
     glVertex2f(212,540);
     glVertex2f(216,557);
     glVertex2f(219,564);
     glVertex2f(221,581);
     glVertex2f(223,590);
     glVertex2f(227,601);
     glVertex2f(231,627);
     glVertex2f(234,646);
     glVertex2f(238,661);
     glVertex2f(239,674);
     glVertex2f(242,685);
     glVertex2f(247,698);
     glVertex2f(250,717);
     glVertex2f(247,732);
     glVertex2f(247,745);
     glVertex2f(246,766);
     glVertex2f(245,782);
     glVertex2f(245,794);
     glVertex2f(246,813);
     glVertex2f(245,821);
     glVertex2f(248,827);
     glVertex2f(253,830);
     glVertex2f(259,826);
     glVertex2f(263,818);
     glVertex2f(269,806);
     glVertex2f(273,789);
     glVertex2f(279,766);
     glVertex2f(282,749);
     glVertex2f(282,727);
     glVertex2f(282,711);
     glVertex2f(282,700);
     glVertex2f(281,678);
     glVertex2f(281,666);
     glVertex2f(281,651);
     glVertex2f(281,639);
     glVertex2f(280,627);
     glVertex2f(279,617);
     glVertex2f(278,604);
     glVertex2f(355,604);
     glVertex2f(360,601);
     glVertex2f(363,593);
     glVertex2f(367,582);
     glVertex2f(371,572);
     glVertex2f(371,559);
     glVertex2f(371,545);
     glVertex2f(368,535);
     glVertex2f(363,523);
     glVertex2f(359,516);
     glVertex2f(359,509);
     glVertex2f(364,504);
     glVertex2f(370,495);
     glVertex2f(374,483);
     glVertex2f(374,471);
     glVertex2f(375,458);
     glVertex2f(372,446);
     glVertex2f(370,438);
     glVertex2f(365,429);
     glVertex2f(359,425);
     glVertex2f(354,423);
     glVertex2f(354,410);
     glVertex2f(359,408);
     glVertex2f(361,392);
     glVertex2f(364,381);
     glVertex2f(364,370);
     glVertex2f(362,361);
     glVertex2f(356,345);
     glVertex2f(350,336);
     glVertex2f(346,334);
     glVertex2f(341,333);
     glVertex2f(341,320);
     glVertex2f(348,305);
     glVertex2f(347,296);
     glVertex2f(347,291);
     glVertex2f(346,281);
     glVertex2f(344,271);
     glVertex2f(339,260);
     glVertex2f(332,250);
     glVertex2f(223,246);
     glVertex2f(215,255);
     glVertex2f(212,260);
     glVertex2f(209,266);
     glVertex2f(204,272);
     glVertex2f(199,276);
     glVertex2f(196,283);

glEnd();
glPopMatrix();
}

void userprofilepic()//the top white and grey box for the profile
{

//glColor3f(.8,.824,.826);//gray
glColor3f(0.075,0.102,0.165);//spiderman background
glRectd(689,934,60,370);
//glColor3f(.875 ,.106 ,.059);

//spider man....hehehe
glColor3d(0,0,0);

int x;
glLineWidth(5);
glColor3f(.875 ,.106 ,.059);


glBegin(GL_POLYGON);//outer border filllllllllllllllllllllllllllll
for(x=0;x<71;x++){

         glVertex2f(spid[x+x],spid[x+x+1]);
 }
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_LINE_LOOP);//outer border borderrrrrrrrrrrrrrrrrrrrrrr
for(x=0;x<71;x++){

         glVertex2f(spid[x+x],spid[x+x+1]);
 }
   glEnd();
glColor3f(0.075,0.102,0.165);
//glColor3f(.8,.824,.826);
glBegin(GL_POLYGON);//outer border
for(x=0;x<30;x++){///////////////////////////////////////////////////////////////

         glVertex2f(spid[x+x],spid[x+x+1]);
 }
   glEnd();

   glColor3f(0,0,0);

glBegin(GL_LINE_STRIP);//chin
for(x=0;x<12;x++){
         glVertex2f(chin[x+x],chin[x+x+1]);
 }
   glEnd();


   glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(374,674);
glVertex2f(346,812);//left
glVertex2f(374,674);
glVertex2f(401,820);//right
glVertex2f(374,674);
glVertex2f(315,775);
glVertex2f(374,674);
glVertex2f(432,785);
glVertex2f(374,674);
glVertex2f(293,724);
glVertex2f(374,674);
glVertex2f(284,684);
glVertex2f(374,674);
glVertex2f(285,630);
glVertex2f(374,674);
glVertex2f(288,592);
glVertex2f(374,674);
glVertex2f(312,548);
glVertex2f(374,674);
glVertex2f(374,520);
glVertex2f(374,674);
glVertex2f(437,541);
glVertex2f(374,674);
glVertex2f(463,589);
glVertex2f(374,674);
glVertex2f(470,640);
glVertex2f(374,674);
glVertex2f(466,684);
glVertex2f(374,674);
glVertex2f(452,743);
glEnd();





   glBegin(GL_POLYGON);//eyes center
   for(x=0;x<15;x++){
 glColor3f(.875,.106 ,.059);
         glVertex2f(mid[x+x],mid[x+x+1]);

 }
   glEnd();

   glBegin(GL_LINE_LOOP);//eyes center
   for(x=0;x<15;x++){
     glColor3f(0,0,0);
         glVertex2f(mid[x+x],mid[x+x+1]);
 }
   glEnd();






glBegin(GL_LINE_LOOP);
   for(x=0;x<32;x++){
     glColor3f(0,0,0);
         glVertex2f(facetexture[x+x]+15,facetexture[x+x+1]+33);
 }
   glEnd();

   glBegin(GL_LINE_LOOP);
   for(x=0;x<32;x++){
     glColor3f(0,0,0);
         glVertex2f(facetexture[x+x]+9,facetexture[x+x+1]-41);

 }
   glEnd();

prolin(0,0,1);//left to right body design
prolin(40,92,.9);
for(int i=0;i<50;i+=15)
    prolin(40+i,92+i,.9);
prolin2(0,0,1);

for(int i=1;i<40;i+=15){
prolin2(-25+i,100+i,0.9);
}

glBegin(GL_LINES);
glVertex2f(376,826);
glVertex2f(376,1000);
glEnd();


bodyt(0,10,1);
bodyt(0,40,1);
bodyt(-42,65,1.1);
bodyt(-160,90,1.4);
bodyt(-340,110,1.86);


//EYESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS



     glBegin(GL_POLYGON);//left eyes inner
for(x=0;x<23;x++){
glColor3f(1,1,1);
         glVertex2f(left[x+x],left[x+x+1]);
 }
   glEnd();


   glBegin(GL_POLYGON);//right eyes inner
for(x=0;x<24;x++){
    glColor3f(1,1,1);
            glVertex2f(right[x+x],right[x+x+1]);
 }
   glEnd();

   glLineWidth(10);

   glBegin(GL_LINE_STRIP);//left eyes
for(x=0;x<23;x++){

        glColor3f(0,0,0);
         glVertex2f(left[x+x],left[x+x+1]);
 }
   glEnd();

   glBegin(GL_LINE_STRIP);//right eyes
for(x=0;x<24;x++){
     glColor3f(0,0,0);
         glVertex2f(right[x+x],right[x+x+1]);
 }
   glEnd();



//eye endddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd


glColor3f(1,1,1);//white bottom time line about bar

glRectd(689,440,60,369);



}

void bodyt(float X,float Y,float s)
{
    glBegin(GL_LINE_STRIP);//chin
for(int x=0;x<12;x++){
         glVertex2f(chin[x+x]*s+X,chin[x+x+1]+Y);
 }
   glEnd();
}

void Text(const char *string,float x , float y,float colorx,float colory,float colorz,void *font)//writing character
{
    glColor3d(colorx,colory,colorz);
if(font==0)
    font = GLUT_BITMAP_TIMES_ROMAN_24;

   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   // glEnable(GL_BLEND);

    int len, i;
    glRasterPos2f(x, y);
        len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }

   // glDisable(GL_BLEND);
}

void HugeText(char *string,float x,float y,float colorx,float colory,float colorz,float line_width,float scale)
 {
    char *c;
    glPushMatrix();
        glColor3d(colorx, colory, colorz);//color of the string
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
       // glEnable(GL_BLEND);
        glTranslatef(x,y,0);
        glScalef(scale,scale,0);//size of the string
        glLineWidth(line_width);//width of the string
        for (c=string; *c != '\0'; c++)
        {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
        }
       // glDisable(GL_BLEND);
    glPopMatrix();
}

void password_text(char *string,float x,float y)                 //displays password entered as dots
{
  int i,len;

  len=(int)strlen(string);
  glRasterPos2f(x,y);
    for(i=0;i<len;i++)
      if(string[i]==8)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
      else
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,46);
}

void windmill()
 {
	int i;
	glColor3f(0.8, 0.8f, 0.9f);
	//glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glPushMatrix();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);
	glColor3f(0.4f, 0.4f, 0.8f);
		//glColor3f(0,0,0);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
	glPopMatrix();
}

void loginscreenvedio()
{


    glColor3f(0,0,0);
   glRectd(550,822,32,370);//black video screen
if(play_login==true)
{
   glBegin(GL_POLYGON);//colorful background
   glColor3f(0.888,0.129,0.086);
   glVertex2f(32,822);
   glColor3f(0.43,0.502,0.639);
   glVertex2f(550,822);
   glColor3f(0.408,0.729,0.702);
   glVertex2f(550,370);
   glColor3f(0.961,0.584,0.294);
   glVertex2f(32,370);
   glEnd();
//glRectd(550,860,5,5);//white full screen
   glPushMatrix();
    glLineWidth(1);
        glColor3d(0.432,0.232,0.2876);//color of the string
        glTranslatef(300,700,0);
        // glRotated(fbangle/2,0,0,0);

//        Scalef(0.6,0.9,0);//size of the string
    glutWireTorus(40,70,50,50);
    glColor3f(0.231,0.349,0.596);
    glRotated(fbangle/2,0,0,0);
    glutWireSphere(20,10,15);
      //glutWireSphere(50,34,34);
    glPopMatrix();

     glPushMatrix();
        glTranslated(250,-60,0);
        glRotated(fbangle+70,40,700,50);
        HugeText("f",40,700,0.231,0.349,0.596,20,0.5);
        glPopMatrix();



        fbangle+=6;

glPushMatrix();//left man
glScalef(0.6,0.6,0);
glTranslatef(0,200,0);
man();
glPopMatrix();

glPushMatrix();//fb signal on right man
glColor3f(0.231,0.349,0.596);
        glTranslatef(115,460,0);
         glRotated(fbangle/2,0,0,0);
    glutWireTorus(10,10,7,8);
glPopMatrix();

glPushMatrix();//right man
glScalef(0.6,0.6,0);
glTranslatef(600,200,0);
man();
glPopMatrix();

glPushMatrix();//fb signal on right man
glColor3f(0.231,0.349,0.596);
        glTranslatef(437,460,0);
         glRotated(fbangle/2,0,0,0);
    glutWireTorus(10,10,7,4);
glPopMatrix();


  for(int inc=0;inc<168;inc++)//left packet  path line
            {
            glPushMatrix();//left data packet
            glTranslatef(200+inc,230+inc,0);
            HugeText("/",-80,230,0.231,0.349,0.596,20,0.01);
            glPopMatrix();
        }
        for(int inc=0;inc<153;inc++)//right packet  path line
            {
                glPushMatrix();//left data packet
                 glTranslatef(245+inc,390-inc,200);
                HugeText("\\",40,230,0.231,0.349,0.596,20,0.01);
                glPopMatrix();
        }

if(mov==0)
fg=1;
    if(mov2==0&&fg==0){
      mov--;

    }
    else if(mov>=158)
    {
    mov=158;
        }
else if(fg==1){
     mov++;
     revs=0;
}
    else
    mov++;

    glPushMatrix();//left data packet
        glTranslatef(200+mov,230+mov,0);
        HugeText("/",-80,230,0.941, 0.902, 0.549,20,0.1);
        glPopMatrix();

if(mov==158&&mov2<140&&revs==0)
mov2++;
else if(mov2==0&&revs==1)
{
    mov2=0;
    fg=0;
}
else if(mov2==140||revs==1){
    mov2--;
    revs=1;
}
//printf("%d\n",mov2);

        glPushMatrix();//right data packet
        glTranslatef(250+mov2,376-mov2,200);
        HugeText("\\",40,230,0.941, 0.902, 0.549,20,0.1);
        glPopMatrix();
}


 if(play_login==false){
              // glRectd(550,822,32,370);
        playbutton();
        }
}
void playbutton()
{
        // glRectd(350,650,250,550);
        glColor4f(0.86,0.15,0.14,0.8);
        circle(300,600,50);
        glColor4f(1,1,1,0.8);
        glBegin(GL_TRIANGLES);
        glVertex2f(286,577);
        glVertex2f(286,625);
        glVertex2f(331,600);
        glEnd();
}

void nextbutton()//bottom scroll button
{
       glColor4f(0,0,0,0.4);
        glBegin(GL_TRIANGLES);
        glVertex2f(570,5);
        glVertex2f(560,55);
        glVertex2f(580,55);
        glEnd();
}

void prevbutton()
{
    glColor4f(0,0,0,0.4);
        glBegin(GL_TRIANGLES);
        glVertex2f(570,890);
        glVertex2f(560,840);
        glVertex2f(580,840);
    glEnd();

}


void scrollbar()
{
glColor3f(1,1,1);
glRectd(560,60,580,835);
glPushMatrix();
glTranslated(0,-85*page,0);
glColor3f(.914,.918,.929);
glRectd(561,834,579,918);
glPopMatrix();
}
void man()
{
    glColor3f(1,1,1);
    circle(164,618,12);//face
    glRectd(171,600,155,540);
    glBegin(GL_QUADS);//body
    glVertex2f(171,600);
    glVertex2f(171,580);
    glVertex2f(190,560);
    glVertex2f(195,570);

     glVertex2f(155,600);
    glVertex2f(155,580);
    glVertex2f(134,560);
    glVertex2f(129,570);
    glEnd();
glColor3f(1,0,0);
glLineWidth(2);
    glBegin(GL_LINES);//waist line
    glVertex2f(155,540);
     glVertex2f(171,540);
    glEnd();

glColor3f(1,1,1);
    glBegin(GL_POLYGON);//left leg
    glVertex2f(155,538);
     glVertex2f(163,538);
     glVertex2f(158,480);
     glVertex2f(150,480);
    glEnd();


     glBegin(GL_POLYGON);//right leg
    glVertex2f(163,538);
     glVertex2f(171,538);
     glVertex2f(176,480);
     glVertex2f(168,480);
    glEnd();
}

void c_accountlogin()
{
    	  if(success==0){
    	    Text(c_username,570,640,0,0,0,GLUT_BITMAP_HELVETICA_18);
		   Text(c_mobile,570,555,0,0,0,GLUT_BITMAP_HELVETICA_18);
		    Text(c_vermobile,570,459+17,0,0,0,GLUT_BITMAP_HELVETICA_18);
			 Text(c_password,570,383+17,0,0,0,GLUT_BITMAP_HELVETICA_18);
			    Text(c_birthday,570,269+17,0,0,0,GLUT_BITMAP_HELVETICA_18);
    	  }


}

void authenticate_createaccount()
{


    if(!strcasecmp(c_mobile,c_vermobile) &&f_pass==1)
    {
        success=1;
        Text("Account Created Successfully!!! Welcome To ",100,250,0,0,0,GLUT_BITMAP_TIMES_ROMAN_24);

        Text("FAcEBoOk!!",430,250,rand()%2,rand()%2,rand()%2,GLUT_BITMAP_TIMES_ROMAN_24);


    }
    else if(strcasecmp(c_mobile,c_vermobile)!=0){

success=1;
Text("Mobile numbers Didnt match !!! Failed to create the account!!",100,269+17,0,0,0,GLUT_BITMAP_TIMES_ROMAN_24);
    }
}


void pokes()
{
   glColor3f(1,1,1);
glRectd(140,350,05,10);
Text("Pokes:",50,320,0,0,0,0);

Text("Varun Poked you",10,250,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("Alia Poked you",10,200,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("You poked Shraddha",10,150,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("Shraddha Poked you",10,100,0,0,1,GLUT_BITMAP_HELVETICA_18);

glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(5,05);
glVertex2f(140,05);
glVertex2f(140,350);
glVertex2f(05,350);
glEnd();
glPushMatrix();
glTranslated(2,50,0);
pokesymbol();
glPopMatrix();

}

void pokesymbol()
{
    glPushMatrix();
glTranslated(15,260,0);
glScaled(.05,.05,0);
glColor3f(.271,.404,.604);//blue rectangle
    glBegin(GL_POLYGON);
     glVertex2f(127,220);
     glVertex2f(192,220);
     glVertex2f(192,530);
     glVertex2f(127,530);
    glEnd();
    //glPushMatrix();
    glColor3f(0,0,0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
     glVertex2f(359,520);
     glVertex2f(550,520);
    glEnd();
   // glPopMatrix();
    glLineWidth(1);
 glColor3f(0,0,0);//hand symbol
    glBegin(GL_LINE_LOOP);
     glVertex2f(196,507);
     glVertex2f(203,513);
     glVertex2f(206,520);
     glVertex2f(209,527);
     glVertex2f(212,540);
     glVertex2f(216,557);
     glVertex2f(219,564);
     glVertex2f(221,581);
     glVertex2f(223,590);
     glVertex2f(367,582);
     glVertex2f(371,572);
     glVertex2f(371,559);
     glVertex2f(371,545);
     glVertex2f(368,535);
     glVertex2f(363,523);
     glVertex2f(359,516);
     glVertex2f(359,509);
    // glVertex2f(600,530);
     glVertex2f(364,504);
     glVertex2f(370,495);
     glVertex2f(374,483);
     glVertex2f(374,471);
     glVertex2f(375,458);
     glVertex2f(372,446);
     glVertex2f(370,438);
     glVertex2f(365,429);
     glVertex2f(359,425);
     glVertex2f(354,423);
     glVertex2f(354,410);
     glVertex2f(359,408);
     glVertex2f(361,392);
     glVertex2f(364,381);
     glVertex2f(364,370);
     glVertex2f(362,361);
     glVertex2f(356,345);
     glVertex2f(350,336);
     glVertex2f(346,334);
     glVertex2f(341,333);
     glVertex2f(341,320);
     glVertex2f(348,305);
     glVertex2f(347,296);
     glVertex2f(347,291);
     glVertex2f(346,281);
     glVertex2f(344,271);
     glVertex2f(339,260);
     glVertex2f(332,250);
     glVertex2f(223,246);
     glVertex2f(215,255);
     glVertex2f(212,260);
     glVertex2f(209,266);
     glVertex2f(204,272);
     glVertex2f(199,276);
     glVertex2f(196,283);

glEnd();
glPopMatrix();
}

void events()
{
   glColor3f(1,1,1);
glRectd(140,350,10,10);
Text("Events:",50,320,0,0,0,0);
Text("Edwin ",20,250,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("Tomorrow Birthday",60,250,0,0,0,GLUT_BITMAP_HELVETICA_12);

Text("Deepika ",20,200,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("May 22 Birthday",70,200,0,0,0,GLUT_BITMAP_HELVETICA_12);

Text("Varun",20,150,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("May 29 Birthday",70,150,0,0,0,GLUT_BITMAP_HELVETICA_12);

Text("Alia",20,100,0,0,1,GLUT_BITMAP_HELVETICA_18);
Text("June 2 Birthday",70,100,0,0,0,GLUT_BITMAP_HELVETICA_12);

glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(10,10);
glVertex2f(140,10);
glVertex2f(140,350);
glVertex2f(10,350);
glEnd();



glPushMatrix();
glTranslated(-10,-175,0);
 glColor3f(.003,.089,.595);
    glBegin(GL_POLYGON);
    glVertex2f(43,523);
    glVertex2f(52,523);
    glVertex2f(55,518);
    glVertex2f(55,513);
    glVertex2f(40,513);
    glVertex2f(40,518);
    glEnd();
    glColor3f(0,0,0);
    glRectd(39,513,56,486);//outer border
    glColor3f(1,1,1);
    glRectd(40,512,55,488);//inner box
    Text("22",43,490,0,0,0,GLUT_BITMAP_8_BY_13);
glPopMatrix();
}


void posting()
{
Text(post,200,760,0,0,0,GLUT_BITMAP_9_BY_15);
}

void developers()
{
     glColor3f(0.231,0.349,0.596);
    glRectd(1000,1000,0,870);
    glRectd(0,0,1000,50);
//HugeText("facebook",350,908,1,1,1,7,0.5);
Text("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING ",240,800,0,0,0,0);
       Text("ST. JOSEPH ENGINEERING COLLEGE, MANGALURU-575 028",240,755,0,0,0,0);
       Text("MINI PROJECT ON:",420,650,0,0,0,0);
      HugeText("FACEBOOK",400,590,0.231,0.349,0.596,3,0.3);

       Text("SUBMITTED BY:",430,500,0,0,0,0);

         Text("ARAVIND PRABHU",200,440,0,0,0,0);
         Text("VI CSE - A",230,400,0,0,0,0);
         Text("4SO13CS021",225,360,0,0,0,0);

         Text("AKSHAY KUMAR CRASTA",600,440,0,0,0,0);
         Text("VI CSE - A",657,400,0,0,0,0);
         Text("4SO13CS009",650,360,0,0,0,0);



           glPushMatrix();
        glTranslated(250,-100,0);
        glRotatef(fbangle+70,40,600,50);
        HugeText("f",40,700,0.231,0.349,0.596,20,0.5);
        glPopMatrix();
     glPushMatrix();
        glTranslated(650,-100,0);
        glRotatef(fbangle+70,40,700,50);
        HugeText("f",40,700,0.231,0.349,0.596,20,0.5);
        glPopMatrix();


        fbangle+=1.9;
        glColor3f(1,1,1);
        glRectd(450,20,550,60);
        Text("Exit!!",480,28,0,0,0,0);
}

