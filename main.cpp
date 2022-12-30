#include <app.hpp>
#include <time.h>

int main()
{
    fm::app app;

    app.setResolution(400, 533, "jump!");
    app.setUp();
    app.setTextures();
    app.plts();
    app.run();

    return 0;
}