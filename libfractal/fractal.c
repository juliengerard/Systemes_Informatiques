#include <stdlib.h>
#include "fractal.h"

struct fractal *fractal_new(const char *name, int width, int height, double a, double b)
{

    struct fractal * fract = (struct fractal *) malloc(sizeof(struct fractal));

    if(fract==NULL)
    {
      return NULL;
    }
    printf("DANS FRACTAL NEW\n");
      strcpy(fract->name,name); //Checker si bonne taille?
      fract->width = width;
      printf("fractal_new width = %d", fract->width);
      fract->height = height;
      fract->r = a;
      fract->c = b;
      fract->tab = (int *)malloc(sizeof(int)*width*height);
      if(fract->tab==NULL)
      {
        return NULL;
      }
      fract->moyenne=0.0;
      return fract;

}

void fractal_free(struct fractal *f)
{

    free(f->tab);
    free(f); //Verifier si bien desalloue??
}

const char *fractal_get_name(const struct fractal *f)
{

    return f->name;
}

int fractal_get_value(const struct fractal *f, int x, int y)
{

    return f->tab[(f->width)*y +x];


}

void fractal_set_value(struct fractal *f, int x, int y, int val)
{


    f->tab[(f->width)*y +x]=val;

}

int fractal_get_width(const struct fractal *f)
{

    return f->width;
}

int fractal_get_height(const struct fractal *f)
{

    return f->height;
}

double fractal_get_a(const struct fractal *f)
{

    return f->r;
}

double fractal_get_b(const struct fractal *f)
{

    return f->c;
}
