#include<simplecpp>
#include<stdlib.h>

/*Project Name: Archery */
static int score=0;//Used for saving score of player throughout program
static int flag[10]={0,0,0,0,0,0,0,0,0,0};
int game();
int HTP();
void load()//FUNCTION FOR THE LOADING SCREEN
{
    const float aFx=650,aFy=450, textW= 1300,textH= 450;
    int i=1;
    Rectangle R(aFx,aFy,1300,900);
    R.setColor(COLOR(1,0,0));
    R.setFill(COLOR(1,0,0));
    Rectangle R0(aFx,aFy,textW,textH);
    R0.setColor(COLOR(255,255,255));
    R0.setFill(COLOR(255,255,255));
    Text t(650,450,"LOADING ARCHERY GAME....PLEASE WAIT");
    Rectangle R1(aFx,600,500,50);
    Rectangle R2(aFx,600,500,50);
    R2.setColor(COLOR(255,255,255));
    R2.setFill(COLOR(255,255,255));
    R1.setColor(COLOR(39,255,0));
    R1.setFill(COLOR(39,255,0));
    do
    {
        R2.move(20,0);
        wait(0.1);
        i=i+1;
    }while(i<25);
    wait(2);
}

int start_screen()//FUNCTION FOR THE START SCREEN OF THE GAME
{
    int i=1;
    const float aFx=650,aFy=450, textW= 1300,textH= 900, bFx=450,bFy=450, bLx=850,bLy=450, bEx=650,bEy=700, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(0,0,60));
    R.setFill(COLOR(0,0,60));
    Circle c1(bFx,bFy,75);
    c1.setColor(COLOR(255,255,255));
    c1.setFill(COLOR(255,255,255));
    Text t1(bFx,bFy,"Start Game");
    Rectangle R1(bFx,bFy,textWidth(" Start Game "),textHeight());
    wait(0.5);
    Circle c2(bLx,bLy,75);
    c2.setColor(COLOR(255,255,255));
    c2.setFill(COLOR(255,255,255));
    Text t2(bLx,bLy,"How to Play");
    Rectangle R2(bLx,bLy,textWidth(" How to Play "),textHeight());
    wait(0.5);
    Rectangle R0(bEx,bEy,100,50);
    R0.setColor(COLOR(255,255,255));
    R0.setFill(COLOR(255,255,255));
    Text t3(bEx,bEy,"Exit Game");
    Rectangle R3(bEx,bEy,textWidth(" Exit Game "),textHeight());
    while(i==1)
    {
        int clickPos = getClick();
        int cx = clickPos/65536;
        int cy = clickPos % 65536;
        if(bLx-bWidth/2<= cx && cx<= bLx+bWidth/2 && bLy-bHeight/2 <= cy && cy <= bLy+bHeight/2)//TO SELECT HOW TO PLAY
        {
            HTP();
        }
        if(bFx-bWidth/2<= cx && cx<= bFx+bWidth/2 && bFy-bHeight/2 <= cy && cy <= bFy+bHeight/2)//TO START GAME
        {
            game();
            return(0);
        }
        if(bEx-bWidth/2<= cx && cx<= bEx+bWidth/2 && bEy-bHeight/2 <= cy && cy <= bEy+bHeight/2)//TO EXIT FROM THE GAME
        {
            exit(0);
        }
        else
        {continue;}
    }
    return(0);
}

int HTP()//FUNCTION FOR THE HOW TO PLAY INSTRUCTIONS
{
    int i=1;
    const float aFx=650,aFy=100, textW= 650,textH= 2000, bLx= 650,bLy= 60, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(255,255,255));
    R.setFill(COLOR(255,255,255));
    Text t3(aFx,aFy,"Welcome Adventurer! This is a simple game of shoot and score.");
    Text t4(aFx,200,"Use 'w' to move your character UP");
    Text t5(aFx,250,"Use 's' to move your character DOWN");
    Text t6(aFx,300,"Use 'd' to shoot an arrow");
    Text t7(aFx,400,"Hit the white balloons and avoid the red balloons");
    Text t8(aFx,500,"Every white balloon hit gives 20 points");
    Text t9(aFx,600,"Every red balloon hit deducts 10 points");
    Text t10(aFx,700,"You can always press 'p' to exit midgame");
    Text tx(bLx,bLy,"Back");
    Rectangle b(bLx,bLy,textWidth(" Back "),textHeight());
    while(i==1)
    {
        int clickPos = getClick();
        int cx = clickPos/65536;
        int cy = clickPos % 65536;
        if(bLx-bWidth/2<= cx && cx<= bLx+bWidth/2 && bLy-bHeight/2 <= cy && cy <= bLy+bHeight/2)
        {
            i=0;
            return(0);
        }
        else
        {
            continue;
        }
    }
    return(0);
}

int scorecard()//FUNTION TO DISPLAY THE FINAL SCORE OF THE PLAYER
 {
    Rectangle r(650,400,450,200);
    r.setColor(COLOR(255,99,71));
    r.setFill(COLOR(255,99,71));
    Text t1(650,390,"GAME OVER");
    Text t2(620,450,"SCORE=");
    Text t3(670,450,(char)score);
    wait(3);
    score=0;
    for(int i=0;i<10;i++)
        { flag[i]=0;}
    start_screen();//AFTER VIEWING SCORECARD WE RETURN TO THE START SCREEN AGAIN
    return(0);
 }

int menu()//AN IN GAME MENU FUNCTION TO ALLOW THE PLAYER TO END THE GAME OR VIEW THE HOW TO PLAY INSTRUCTIONS
{
    int i=1;
    Rectangle r(650,400,450,200);
    r.setColor(COLOR(255,99,71));
    r.setFill(COLOR(255,99,71));
    Text t1(650,380,"Press 1 to end the game");
    Text t2(650,410,"Press 2 to go to How to Play menu");
    Text t3(650,440,"Press p to close menu");
    while(i==1)
    {
        XEvent e;//EVENT HANDLING TO TAKE USER INPUT TO FOLLOW CERTAIN INSTRUCTIONS
        nextEvent(e);
        char ev;
        if(keyPressEvent(e))
        {
            ev=charFromEvent(e);
        }
        else if (mouseButtonPressEvent)
        {
            continue;
        }
        switch(ev)
        {
            case '1':scorecard();
            return(0);
            break;
            case '2': HTP();
            break;
            case 'p':case'P':
            i=0;
            break;

        }
    }
    return(0);
}

class Body:public Composite //Creating body and feet of the man,class Body is a child class of Composite class
{
    Line *bd[6];
    Circle *cir[2];
public:
    Body(double x,double y,Color c,Composite* owner=NULL):Composite(x,y,owner)
    {
        bd[0]=new Line (58,78,58,125,this);
        bd[1]=new Line (58,125,38,142,this);
        bd[2]=new Line (58,125,82,142,this);
        bd[3]=new Line (58,99,35,105,this);
        bd[4]=new Line (35,105,52,89,this);
        bd[5]=new Line (58,99,102,99,this);
        cir[0]= new Circle(40,144,5,this);
        cir[1]= new Circle(84,144,5,this);
        cir[0]->setColor(c);
        cir[0]->setFill(c);
        cir[1]->setColor(c);
        cir[1]->setFill(c);
        bd[0]->setColor(c);
        bd[0]->setFill(c);
        bd[1]->setColor(c);
        bd[1]->setFill(c);
        bd[2]->setColor(c);
        bd[2]->setFill(c);
        bd[3]->setColor(c);
        bd[3]->setFill(c);
        bd[4]->setColor(c);
        bd[4]->setFill(c);
        bd[5]->setColor(c);
        bd[5]->setFill(c);
    }
};

class Bow:public Composite //Creating bow held by the man,class Bow is a child class of Composite
{
    Line *bw[4];
    public:
    Bow(double x,double y,Color c,Composite* owner=NULL):Composite(x,y,owner)
    {
        bw[0]=new Line (52,89,92,77,this);
        bw[1]=new Line (92,77,102,99,this);
        bw[2]=new Line (102,99,89,119,this);
        bw[3]=new Line (89,117,52,89,this);
        bw[0]->setColor(c);
        bw[1]->setColor(c);
        bw[2]->setColor(c);
        bw[3]->setColor(c);
    }
};
/*Creating the arrow held by the man;class Arrow is the child of class Composite
 This arrow shoots through the balloons in the game*/
class Arrow:public Composite
{
    Line *ar[3];
    public:
    Arrow(double x,double y,Composite* owner=NULL):Composite(x,y,owner)
    {
        ar[0]= new Line (104,75,164,75,this);
        ar[1]= new Line (154,65,164,75,this);
        ar[2]= new Line (154,85,164,75,this);
        ar[0]->setColor(COLOR(255,0,255));
        ar[0]->setFill(COLOR(255,0,255));
        ar[1]->setColor(COLOR(255,0,255));
        ar[1]->setFill(COLOR(255,0,255));
        ar[2]->setColor(COLOR(255,0,255));
        ar[2]->setFill(COLOR(255,0,255));
    }
 /*
	   movement()---->used to release arrow upon click
	   determines the arrow release position based on y co-ordinate of static arrow y coordinate.
 */
    void movement(double x,double y)
    {
        Arrow a2(x,y);
        repeat(30)
        {
            a2.move(50,0);
            wait(0.01);
        }
    }
};

/* Creating a class man which is a child class of class Composite.
   Integrating the head, body and bow of the man to move together. */
class Man:public Composite
{
    Circle *head;
    Body *body;
    Bow *bow;
    public:
    Man(double x,double y,Color c,Composite* owner=NULL):Composite(x,y,owner)
    {
        head=new Circle (60,60,20,this);
        head->setColor(c);
        head->setFill(c);
    }
    void forward(double d,bool repaintP=true)
    {
        forward(d,false);
        if(repaintP)
        repaint();
    }
};

//balloon code here : inheritance concept used
class Balloon:public Composite
{
    Circle *balloon1,*balloon2,*balloon3,*balloon4,*balloon5,*balloon6,*balloon7,*balloon8,*balloon9,*balloon10;
    int r=25,red=255,green=255,blue=255;
    public:
    Balloon(double x,double y,Composite*owner=NULL):Composite(x,y,owner)
    {
             balloon1=new Circle (400,103,r,this);
             balloon1->setColor(COLOR(255,255,255));
             balloon1->setFill(COLOR(255,255,255));
             balloon2=new Circle (600,263,r,this);
             balloon2->setColor(COLOR(255,255,255));
             balloon2->setFill(COLOR(255,255,255));
             balloon3=new Circle (250,423,r,this);
             balloon3->setColor(COLOR(255,0,0));
             balloon3->setFill(COLOR(255,0,0));
             balloon4=new Circle (900,583,r,this);
             balloon4->setColor(COLOR(255,255,255));
             balloon4->setFill(COLOR(255,255,255));
             balloon5=new Circle (300,343,r,this);
             balloon5->setColor(COLOR(255,0,0));
             balloon5->setFill(COLOR(255,0,0));
             balloon6=new Circle (700,503,r,this);
             balloon6->setColor(COLOR(255,255,255));
             balloon6->setFill(COLOR(255,255,255));
             balloon7=new Circle (400,183,r,this);
             balloon7->setColor(COLOR(255,0,0));
             balloon7->setFill(COLOR(255,0,0));
             balloon8=new Circle (500,463,r,this);
             balloon8->setColor(COLOR(255,255,255));
             balloon8->setFill(COLOR(255,255,255));
             balloon9=new Circle (600,543,r,this);
             balloon9->setColor(COLOR(255,0,0));
             balloon9->setFill(COLOR(255,0,0));
             balloon10=new Circle (800,223,r,this);
             balloon10->setColor(COLOR(255,255,255));
             balloon10->setFill(COLOR(255,255,255));
    }
    void effects()
    {
         balloon1->scale(2);balloon1->scale(.5);
         balloon2->scale(2);balloon2->scale(.5);
         balloon3->scale(2);balloon3->scale(.5);
         balloon4->scale(2);balloon4->scale(.5);
         balloon5->scale(2);balloon5->scale(.5);
         balloon6->scale(2);balloon6->scale(.5);
         balloon7->scale(2);balloon7->scale(.5);
         balloon8->scale(2);balloon8->scale(.5);
         balloon9->scale(2);balloon9->scale(.5);
         balloon10->scale(2);balloon10->scale(.5);
    }
/*
    score_delete ---> used to update scores,balloon effect,and balloon hide upon arrow hit
    Logic used   ---> when y-coordinate of the moving arrow matches with the balloon y coordinate it is a hit
    flags help in keeping check that repeated balloon scores are not added.
*/
    void score_delete(int y)
    {


        if(y==63)//balloon 1
        {
            flag[0]=flag[0]+1;
            if(flag[0]==1)
            {
                score=score+20;
                balloon1->scale(2);
                balloon1->hide();
            }
        }
        if(y==223)//balloon 4
        {
           flag[1]=flag[1]+1;
            if(flag[1]==1)
            {
                score=score+20;
                balloon2->scale(2);
                balloon2->hide();
            }
        }
        if(y==383)//balloon 6
        {
            flag[2]=flag[2]+1;
            if(flag[2]==1)
            {
                score=score-10;
                balloon3->scale(2);
                balloon3->hide();
            }
        }
        if(y==543)//balloon 10
        {
            flag[3]=flag[3]+1;
            if(flag[3]==1)
            {
                score=score+20;
                balloon4->scale(2);
                balloon4->hide();
            }
        }
        if(y==303)//balloon 5
        {
            flag[4]=flag[4]+1;
            if(flag[4]==1)
            {
                score=score-10;
                balloon5->scale(2);
                balloon5->hide();
            }
        }
        if(y==463)//balloon 8
        {
            flag[5]=flag[5]+1;
            if(flag[5]==1)
            {
                score=score+20;
                balloon6->scale(2);
                balloon6->hide();
            }
        }
        if(y==143) //balloon 2
        {
            flag[6]=flag[6]+1;
            if(flag[6]==1)
            {
                score=score-10;
                balloon7->scale(2);
                balloon7->hide();
            }
        }
        if(y==423)//balloon 7
        {
            flag[7]=flag[7]+1;
            if(flag[7]==1)
            {
                score=score+20;
                balloon8->scale(2);
                balloon8->hide();
            }
        }
        if(y==503)//balloon 9
        {
            flag[8]=flag[8]+1;
            if(flag[8]==1)
            {
                score=score-10;
                balloon9->scale(2);
                balloon9->hide();
            }
        }
        if(y==183)//balloon 3
        {
            flag[9]=flag[9]+1;
            if(flag[9]==1)
            {
                score=score+20;
                balloon10->scale(2);
                balloon10->hide();
            }
        }
    }
};

/*This is the function by which the entire game is controlled */
int game()
{
    Rectangle BG(0,0,4000,2000);
    BG.setColor(COLOR(0,0,60));
    BG.setFill(COLOR(255,255,255));
    Man m(57,78,COLOR(255,255,0));
    Body b1(58,78,COLOR(255,255,0));
    Bow b2(57,79,COLOR(255,255,0));
    score=0;
    Arrow a1(15,103);//static arrow attached to man
    Arrow a2(0,0);//dynamic arrow(movable arrow)
    Text text1(a2.getX()+55,a2.getY()+78,"WELCOME");
    wait(0.2);
    text1.hide();
    a2.hide();
    double x=a1.getX(),y=a1.getY(),arrowcount=0;
    Balloon ball(250,50);

/*
                                        **Game controls*
                            Used to display arrows left,Used to display current score
        Logic Used:Arrow release takes place from current location with the help of co-ordinates of static arrow
*/
/*THE GAME IS CONTROLLED BY THE COUNT OF THE ARROWS.
AFTER 6 ARROWS ARE USED THE GAME ENDS AND U EXIT THE GAME AFTER THE SCORECARD IS DISPLAYED*/
    while(arrowcount<6)
    {
        Text ending1(55,65,"Arrowcount");
        Text ending(55,79,char(6-arrowcount));
        Text board(120,65,"SCORE");
        Text sc(110,79,char(score));
        ending.scale(22);
        XEvent e;
        nextEvent(e);
        char ev;
        if(keyPressEvent(e))
        {
            ev=charFromEvent(e);
        }
        else if (mouseButtonPressEvent)
        {
            continue;
        }
        switch(ev)//SWITCH CASE USED FOR THE CONTROLLED MOVEMENT OF THE MAN(UP AND DOWN) AND TO SHOOT THE ARROW
        {
            case 'w':case 'W':
                m.move(0,-40);
                b1.move(0,-40);
                b2.move(0,-40);
                a1.move(0,-40);
                x=a1.getX();
                y=a1.getY();
                ball.effects();
                break;
            case 's':case'S':
                m.move(0,40);
                b1.move(0,40);
                b2.move(0,40);
                a1.move(0,40);
                x=a1.getX();
                y=a1.getY();
                ball.effects();
                break;
            case 'd':case 'D':
                a2.movement(x,y);
                arrowcount++;
                ball.score_delete(y);
                break;
            case 'p':case 'P':
                menu();
                break;
        }
    }
    if(arrowcount==6)
    {
        scorecard();

    }
    return(0);
}

main_program//MAIN FUNTION OF THE PROGRAM
{
    initCanvas("Archery: By Team Arrow", 1300, 900);//CREATION OF CANVAS
    load();//START LOAD SCREEN
    start_screen();//DISPLAY START SCREEN
}
