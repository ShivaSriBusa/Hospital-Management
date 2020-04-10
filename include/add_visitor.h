#define size 10

struct visitor
{
    char phoneNo[size];
    char *name,*address;
}v1;

int add_visitor(char *filename,char *str,char*ph);
