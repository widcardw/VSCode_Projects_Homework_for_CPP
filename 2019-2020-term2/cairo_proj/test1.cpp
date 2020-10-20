//gcc -o hello hello.c -L /usr/lib/i386-linux-gnu/ -lcairo -I /usr/include/cairo

#include <cairo.h>
int main(int argc, char *argv[])
{
    cairo_surface_t *surface;
    cairo_t *cr;

    int width = 640, height = 480;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create(surface);
    //Draw
    cairo_set_line_width(cr, 10);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_rectangle(cr, width / 4, height / 4, width / 2, height / 2);
    cairo_stroke(cr);
    //Write output and clean up
    cairo_surface_write_to_png(surface, "rectangle.png");
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}