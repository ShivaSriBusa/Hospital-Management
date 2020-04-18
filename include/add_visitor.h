#ifndef size
#define size 11
#endif // size
#ifndef  __add_visitor__
#define  __add_visitor__
#endif // __add_visitor__
struct visitor
{
    char phoneNo[size];
    char *name,*address;
}v1;

int add_visitor(char *filename,char *str,char*ph);
