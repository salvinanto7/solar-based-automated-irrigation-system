#include<reg52.h>

sbit add_a=P0^0;              //declaring control pins
sbit add_b=P0^1;
sbit add_c=P0^2;
sbit ale=P0^3;
sbit oe=P0^4;
sbit eoc=P0^5;
sbit soc=P0^6;

sbit motor1=P1^0;               //declaring outputpins
sbit motor2=P1^1;
sbit motor3=P1^2;
sbit motor4=P1^3;
sbit pump=P1^7;
sbit mst_inp=P3^5;

#define adc_out P2
 
int binr,binr1,binr2;

void delay(int time);
void read_adc();
void solar_track();
void moisture_control();

void main()
{         
          eoc=1;
          ale=0;
          oe=0;
          soc=0;
					
          while(1)
         {				
               solar_track();
               moisture_control();
         }
}

void solar_track()          //solar tracker 
{   
    add_a=0;
    add_b=0;
    add_c=0;
	  delay(1);
    read_adc();
    binr1=binr;
	  
    add_a=1;
    add_b=0;
    add_c=0;
	  delay(1);
    read_adc();
    binr2=binr;
    if(binr1==binr2)        //Stationary
            {
        motor1=0;  //P1.3
        motor2=0;
        motor3=0;
        motor4=0;
    }
    else if(binr1>binr2)  //Clockwise
           {
			  motor1=0;
        motor2=1;
        motor3=0;
        motor4=1;
           }    
    else                  //Anticlockwise
            {
        motor1=1;
        motor2=0;
        motor3=1;
        motor4=0;
    }
	  delay(10);
		

}

void moisture_control()       //automated irrigation
{
  if(mst_inp==0)
    pump=1;
	else
		pump=0;
}

void delay(int time)
{
  int i,j;  
	for(i=0;i<time;i++)
        for(j=0;j<100;j++);        
}

void read_adc()
{
    binr=0;
    ale=1;
    soc=1;
    delay(1);
    ale=0;
    soc=0;
    while(eoc==1);
    while(eoc==0);
    oe=1;
    binr=adc_out;
    delay(1);
    oe=0;
}
