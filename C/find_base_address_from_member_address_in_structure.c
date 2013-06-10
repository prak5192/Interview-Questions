#if 0

Write the logic to find the 
the base address of the structure 
by using the address of the element 
of the structure..


#endif


typedef struct A{
    int a;
    char b;
    int c;
}my_struct;




int foo(int *ptr){
    
    // Find the base address of the structure

}


int main(void){
    my_struct hello = {20,'Z',34};

    ret = foo(&hello.a);

    retutn 0;
}
