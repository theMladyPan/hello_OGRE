#include "mytestapp.h"

using namespace std;

int main()
{
     MyTestApp app;
     app.initApp();
     app.getRoot()->startRendering();
     app.closeApp();
     return 0;
}
