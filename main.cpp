#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "Model_OBJ.h"

std::vector<Model_OBJ*> objs;
Model_OBJ obj;
float g_rotation;
glutWindow win;
const char* filearray[] = {
    "./data/cow.obj",
    "./data/newcow.obj"

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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
   //���u���y�ФΤ�V
   //------gluLookAt( x1 , y1 , z1 , x2 , y2 , z2 , x3 , y3 , z3 ) ��9�ӰѼơA�N��3�Ӯy���I,���O��Ӯy���I�M�@�ӦV�q
   //�Ĥ@�Ӯy�ЬO��v������m�y��
   //�ĤG�Ӯy�ЬO��v���ҭn���᪺�����m�y��,�u�O�n�T�w�����V
   //�ĤT�Ӯy�ЬO��v�����W�誺�V�q
	gluLookAt( 20,0,50, 20,0,0, 0,1,0);

    for(int i=0;i<objs.size();i++)
    {
        glPushMatrix();
            glTranslatef(objs[i]->get_x(), objs[i]->get_y(), objs[i]->get_z());

            //glRotatef(angle , x ,y ,z)
            //angle ���t�v�T�����V �j�p�v�T����t��
            //x,y,z ���t�v�T�����V , �j�p�v�T�����m
            glRotatef(g_rotation,0,1,0);
            glRotatef(90,0,1,0);
            g_rotation = g_rotation + 0.2;  //����t�׻��W���V����V�C
            //obj.Draw(i);
            objs[i]->Draw();
        glPopMatrix();
    }
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
    
    case 'F':
    case 'f':
     finish_without_update = true;
     printf( "%f fps\n", g_fps( display, 100 ) );
     finish_without_update = false;
     break;
     
    default:
      break;
  }
}

int main(int argc, char *argv[])
{
    // set window values
	win.width = 1280;
	win.height = 800;
	win.title = (char*)"cs569 project1 demo";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	srand (time(NULL));


	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
	glutInitWindowSize(win.width,win.height);					// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);									// register Display Function
	glutIdleFunc( display );									// register Idle Function
    glutKeyboardFunc( keyboard );								// register Keyboard Handler
	initialize();

    for(int i=0;i<100;i++){
    		Model_OBJ *o = new Model_OBJ();

        o->Load((char*)filearray[i%(sizeof(filearray)/sizeof(char*))]);
        //o->set_xyz(i*5.0f,i%5,rand()%20);
        o->set_xyz((rand()%100)-50,(rand()%100)-50,(rand()%500)*-1);

        objs.push_back(o);
    }

	glutMainLoop();												// run GLUT mainloop
	return 0;
}


