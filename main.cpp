#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <ctime>
#include "Model_OBJ.h"

std::vector<Model_OBJ*> objs;
Model_OBJ obj;
float g_rotation;
int lookAtZ = 50;
glutWindow win;
int lookAtZ = 50; 


int frame=0,__time,timebase=0;

const char* filearray[] = {
#if 0
    "./obj/two-sided.obj",
    "./obj/venusm.obj",  
    "./obj/bunny.obj",  
    "./obj/cube.obj",   
    "./obj/teddy.obj", 
#endif
    "./obj/suzanne.obj",
    "./obj/cow.obj",
    0  
};
bool finish_without_update = false;

float g_fps( void (*func)(void), int n_frame )
{
  clock_t start, finish;
  int i;
  float fps;

  printf( "Performing benchmark, please wait" );
    start = clock();
    for( i=0; i<n_frame; i++ )
    {
     func();
    }
    printf( "done\n" );
    finish = clock();

  fps = float(n_frame)/(finish-start)*CLOCKS_PER_SEC;
  return fps;
}

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void show_fps()
{
    static char s[128];
    frame++;
    __time=glutGet(GLUT_ELAPSED_TIME);
    if (__time - timebase > 1000) {
        sprintf(s,"FPS:%4.2f",
            frame*1000.0/(__time-timebase));
        timebase = __time;
        frame = 0;
    }

    glPushMatrix();
    renderBitmapString(-12,18,0,(void *)GLUT_BITMAP_HELVETICA_18, s);
    glPopMatrix();
}

int frame=0,__time,timebase=0;

const char* filearray[] = {
#if 0
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/cube.obj",
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/teddy.obj",
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/bunny.obj",
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/two-sided.obj",
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/venusm.obj",
#endif
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/suzanne.obj",
    "C:/Users/user/Desktop/yzucs/yzucshomework/1061Computer_Graphics/opengl/project1/obj/cow.obj"
};
bool finish_without_update = false;

float g_fps( void (*func)(void), int n_frame )
{
  clock_t start, finish;
  int i;
  float fps;

  printf( "Performing benchmark, please wait" );
    start = clock();
    for( i=0; i<n_frame; i++ )
    {
     func();
    }
    printf( "done\n" );
    finish = clock();

  fps = float(n_frame)/(finish-start)*CLOCKS_PER_SEC;
  return fps;
}

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void show_fps()
{
    static char s[128];
    frame++;
    __time=glutGet(GLUT_ELAPSED_TIME);
    if (__time - timebase > 1000) {
        sprintf(s,"FPS:%4.2f",
            frame*1000.0/(__time-timebase));
        timebase = __time;
        frame = 0;
    }

    glPushMatrix();
    renderBitmapString(0,0,0,(void *)GLUT_BITMAP_HELVETICA_18, s);
    glPopMatrix();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //視線的座標及方向
    //------gluLookAt( x1 , y1 , z1 , x2 , y2 , z2 , x3 , y3 , z3 ) 有9個參數，代表3個座標點,其實是兩個座標點和一個向量
    //第一個座標是攝影機的位置座標
    //第二個座標是攝影機所要拍攝的物體位置座標,只是要確定拍攝方向
    //第三個座標是攝影機正上方的向量
    gluLookAt( 20,0,lookAtZ, 20,0,0, 0,1,0);
    for(int i=0;i<objs.size();i++)
    {
        glPushMatrix();
            glTranslatef(objs[i]->get_x(), objs[i]->get_y(), objs[i]->get_z());

            //glRotatef(angle , x ,y ,z)
            //angle 正負影響選轉方向 大小影響旋轉速度
            //x,y,z 正負影響旋轉方向 , 大小影響旋轉位置
            glRotatef(objs[i]->get_a(),(i%3)==0,(i%3)==1,(i%3)==2);
            //glRotatef(90,0,1,0);
            objs[i]->set_a((objs[i]->get_a()+rand()%10));
            //obj.Draw(i);
            objs[i]->Draw();
        glPopMatrix();
    }
    show_fps();
<<<<<<< HEAD

=======
        
>>>>>>> eric
    if( finish_without_update )
        glFinish();
    else
        glutSwapBuffers();
}


void initialize ()
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, win.width, win.height);
    GLfloat aspect = (GLfloat) win.width / win.height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel( GL_SMOOTH );
    //glClearColor( 0.0f, 0.1f, 0.0f, 0.5f );
    glClearColor(1.0, 1.0, 0.6, 1.0);
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1 };
    GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
    glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
    glEnable( GL_LIGHT0 );
    glEnable( GL_COLOR_MATERIAL );
    glShadeModel( GL_SMOOTH );
    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
    glDepthFunc( GL_LEQUAL );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}


void keyboard ( unsigned char key, int x, int y )
{
  switch ( key ) {
    case KEY_ESCAPE:
      exit ( 0 );
      break;
<<<<<<< HEAD

=======
    
>>>>>>> eric
    case 'F':
    case 'f':
     finish_without_update = true;
     printf( "%f fps\n", g_fps( display, 100 ) );
     finish_without_update = false;
     break;
<<<<<<< HEAD
=======
     
>>>>>>> eric
    default:
        printf("key %c "+key);
      break;
  }
}

<<<<<<< HEAD
void keyPress(int key,int x,int y)
{

    switch(key){
        case 27 :
            exit(0);
            break;
        case GLUT_KEY_UP :
                lookAtZ += 1;
                glutPostRedisplay();
                printf("ZOOM OUT lookAtZ : %d \n",lookAtZ);
            break;
        case GLUT_KEY_DOWN :
            if(lookAtZ > 1)
            {
                lookAtZ -= 1;
                glutPostRedisplay();
                printf("ZOOM IN lookAtZ : %d \n",lookAtZ);
            }else
            {
                printf("ZOOM INT already equal to zero : %d \n",lookAtZ);
            }
            break;
        default:
            break;
    }
=======
void keyPress(int key,int x,int y) 
{ 
 
    switch(key){ 
        case GLUT_KEY_UP : 
                lookAtZ += 2; 
                glutPostRedisplay(); 
                printf("ZOOM OUT lookAtZ : %d \n",lookAtZ); 
            break; 
        case GLUT_KEY_DOWN : 
            if(lookAtZ > 1) 
            { 
                lookAtZ -= 2; 
                glutPostRedisplay(); 
                printf("ZOOM IN lookAtZ : %d \n",lookAtZ); 
            }else 
            { 
                printf("ZOOM INT already equal to zero : %d \n",lookAtZ); 
            } 
            break; 
        default: 
            break; 
    } 
>>>>>>> eric
}

int main(int argc, char *argv[])
{
    int loop = 100;
<<<<<<< HEAD
    // set window values
    win.width = 800;
    win.height = 600;
    win.title = (char*)"cs569 project1 demo";
    win.field_of_view_angle = 45;
    win.z_near = 1.0f;
    win.z_far = 500.0f;
=======
    char temp[256];
    char title[256] = "cs569 project1 demo [1056102 1056105]   ";
    
    // set window values
    win.width = 1280;
    win.height = 800;
    win.title = 0;
    win.field_of_view_angle = 45;
    win.z_near = 1.0f;
    win.z_far = 1000.0f;
>>>>>>> eric

    srand (time(NULL));

    if(argc > 1) loop = strtol(argv[1], NULL, 10);

    // initialize and run program
    glutInit(&argc, argv);                                      // GLUT initialization
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
    glutInitWindowSize(win.width,win.height);                   // set window size
    glutCreateWindow(win.title);                                // create Window
    glutDisplayFunc(display);                                   // register Display Function
    glutIdleFunc( display );                                    // register Idle Function
    glutKeyboardFunc( keyboard );                               // register Keyboard Handler
<<<<<<< HEAD
    glutSpecialFunc(keyPress);                                  // register Keyboard zoomin/zoomout
    initialize();

    printf("Test with count: %d\n", loop);

    for(int i=0;i<loop;i++){
        Model_OBJ *o = new Model_OBJ();

        o->Load((char*)filearray[i%(sizeof(filearray)/sizeof(char*))]);
        //o->Load((char*)filearray[1]);
        o->set_xyz((rand()%100)-50,(rand()%100)-50,(rand()%500)*-1);
        o->set_a(rand()%360);
=======
    glutSpecialFunc(keyPress);                                  // register Keyboard zoomin/zoomout 

    initialize();
    
    sprintf(temp, "Object count: %d", loop);
    printf("%s\n", temp);
    strcat(title, temp);
    glutSetWindowTitle(title);
    
    for(int i=0;i<loop;i++){
        float x, y, z, a;
        Model_OBJ *o = new Model_OBJ();

        o->Load((char*)filearray[i%((sizeof(filearray)/sizeof(char*))-1)]);
        
        a =  rand()%360;
        z = (rand()%500)*-1;
        y = (rand()%100)-50;
        x = ((rand()%100)-50) * z/50;

        o->set_xyz(x, y, z);
        o->set_a(a);
>>>>>>> eric

        objs.push_back(o);
    }

    glutMainLoop();                                             // run GLUT mainloop
    return 0;
}


