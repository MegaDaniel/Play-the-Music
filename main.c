#include "easyDSP-Expansion_Board.h"
#include "math.h"

#define SAMPLING_FREQ 12000
#define PI 3.14159265358979
#define loop_time 8000/2
unsigned short row=0,col=0,sample=0;
unsigned short digital=15,old_digital=15;
short DTMF_count=0,DTMF_flag=0;

long count=0;
int sit=1,music=0,LED[4]={0},i,Pb3,Pb4;

int main(void)
{

  Board_Init(); //Initial easyDSP-Expansion_Board
  Setup_Audio_Init(FS_12000_HZ,ADC_GAIN_0DB,DAC_ATTEN_0DB,LINE_INPUT);

  while(1)
  {

      if(music==2){
          LCD_PUT_CMD(LCD_FIRST_LINE);
          LCD_PUT_CHAR('D');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('R');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CMD(LCD_SECOND_LINE);
          LCD_PUT_CHAR('D');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('D');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
      }else if(music==3){
          LCD_PUT_CMD(LCD_FIRST_LINE);
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('F');
          LCD_PUT_CHAR('a');
          LCD_PUT_CHAR('S');
          LCD_PUT_CHAR('o');
          LCD_PUT_CMD(LCD_SECOND_LINE);
          LCD_PUT_CHAR('S');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('F');
          LCD_PUT_CHAR('a');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('R');
          LCD_PUT_CHAR('e');
      }else if(music==4){
          LCD_PUT_CMD(LCD_FIRST_LINE);
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CMD(LCD_SECOND_LINE);
          LCD_PUT_CHAR('D');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('S');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('S');
          LCD_PUT_CHAR('o');
      }else if(music==0){
          LCD_PUT_CMD(LCD_FIRST_LINE);
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CMD(LCD_SECOND_LINE);
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
      }else if(music==1){
          LCD_PUT_CMD(LCD_FIRST_LINE);
          LCD_PUT_CHAR('D');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('R');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('M');
          LCD_PUT_CHAR('e');
          LCD_PUT_CHAR('F');
          LCD_PUT_CHAR('a');
          LCD_PUT_CMD(LCD_SECOND_LINE);
          LCD_PUT_CHAR('S');
          LCD_PUT_CHAR('o');
          LCD_PUT_CHAR('L');
          LCD_PUT_CHAR('a');
          LCD_PUT_CHAR('S');
          LCD_PUT_CHAR('i');
          LCD_PUT_CHAR('D');
          LCD_PUT_CHAR('o');
      }
    if(Pb3==1){
        music+=1;
        if(music>4){
            music = 1;
        }
        Pb3 = 0;
    }
    if(Pb4==1){
        if(music==1){
            if (Read_SW(1)== 1 && Read_SW(2)== 1 && Read_SW(3)== 0 && Read_SW(4)== 0){
                LED[0]=1;
            }else{
                LED[0]=0;
            }
        }
        if(music==2){
            if (Read_SW(1)== 0 && Read_SW(2)== 1 && Read_SW(3)== 0 && Read_SW(4)== 0){
                LED[1]=1;
            }else{
                LED[1]=0;
            }
        }
        if(music==3){
            if (Read_SW(1)== 1 && Read_SW(2)== 0 && Read_SW(3)== 0 && Read_SW(4)== 1){
                LED[2]=1;
            }else{
                LED[2]=0;
            }
        }
        if(music==4){
            if (Read_SW(1)== 1 && Read_SW(2)== 1 && Read_SW(3)== 0 && Read_SW(4)== 1){
                LED[3]=1;
            }else{
                LED[3]=0;
            }
        }
        for(i=0;i<4;i++){
            if(LED[i]==1){
                Control_LED_ON(i+1);
            }else{
                Control_LED_OFF(i+1);
            }
        }

        Pb4 = 0;
    }
      digital = Read_keypad();
      switch(digital)
           {
           case 1:
            row=262.0;
            col=262.0;
            break;
           case 2:
            row=294.0;
            col=294.0;
            break;
           case 3:
            row=330.0;
            col=330.0;
            break;
           case 4:
            row=349.0;
            col=349.0;
            break;
           case 5:
            row=392.0;
            col=392.0;
            break;
           case 6:
            row=440.0;
            col=440.0;
            break;
           case 7:
            row=494.0;
            col=494.0;
            break;
           case 8:
            row=524.0;
            col=524.0;
            break;
           case 9:
            row=588.0;
            col=588.0;
            break;
           case 0:
            row=0;
            col=0;
            break;
          }
      if(DTMF_flag==1)
      {
          if(old_digital != digital)
          {
          DTMF_count = 0;
          DTMF_flag = 0;
          }
      }
  }
}
interrupt void INT4_ISR(void)
{
    if(DTMF_count < loop_time)
    {
       sample=10000*(sin(2.0*PI*DTMF_count*row*sit/SAMPLING_FREQ)+sin(2.0*PI*DTMF_count*col*sit/SAMPLING_FREQ));
       DTMF_count++;
    }
    else
    {
        sample = 0;
        DTMF_flag=1;
        old_digital = digital;
        DTMF_count = loop_time;
    }

    output_left_sample(sample);
    return;
}
interrupt void INT5_ISR(void)
{
    sit=1;
    return;
}

interrupt void INT6_ISR(void)
{
    sit=2;
    return;
}
interrupt void INT7_ISR(void)
{
    Pb3=1;
    return;
}

interrupt void INT8_ISR(void)
{
    Pb4=1;
    return;
}
