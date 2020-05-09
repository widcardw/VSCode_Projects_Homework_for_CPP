#include <cairo.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cairo_surface_t *surface;
    cairo_t *cr;
    //Prepare drawing area
    int width = 512, height = 512;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create(surface);
    //Drawing
    cairo_select_font_face(cr, "微软雅黑",
                           CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 10.0);
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
    cairo_move_to(cr, 0, 10);
    cairo_show_text(cr, "你好世界");
    //Destroy
    cairo_destroy(cr);
    cairo_surface_write_to_png(surface, "hello.png");
    cairo_surface_destroy(surface);
    return 0;
}