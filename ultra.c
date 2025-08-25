#include <xc.h> 
void delay(unsigned int a)
{
    while(a--);
}
void enable()
{
    RE1=1;
    delay(50);
    RE1=0;
    delay(50);
}
void command(char re,char rs)
{
    RE0=re;
    PORTD=rs;
    enable();
}
void display(int distance)
{
    int hun=distance/100; int tens=distance%100/10; int ones=distance%100%10;
      command(0,0x80);
    command(1,'0'+hun);
    command(1,'0'+tens);
    command(1,'0'+ones);
    command(1,'c');
    command(1,'m');
}