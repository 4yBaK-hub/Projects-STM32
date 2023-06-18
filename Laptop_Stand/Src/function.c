/* Includes ------------------------------------------------------------------*/
#include "function.h"

/*----------------------------------------------------------------------------*/
/* Functions for Notebook_stand                                               */
/*----------------------------------------------------------------------------*/

#define  WAIT_TIME       30
#define  TEMPERATURE_ON  64
#define  TEMPERATURE_OFF 54

extern uint8_t PCdata[100];
char inData1[80];

uint8_t packet_received = 0;
uint8_t FAN_state=0;
uint16_t no_data=0;             // Variable for wait to the new data, if no_data = time , uc go to sleep
uint8_t sleep=0;

////Load Template
void Set_template(void)
{ 
   ST77xx_FillScreen(RGB565(255, 255, 255)); 
   //// Template
    dispcolor_printf(5, 1, FONTID_16F, RGB565(255, 0, 0),"CPU");
    dispcolor_printf(5, 25, FONTID_16F, RGB565(255, 0, 0),"Mem"); 
    
   dispcolor_printf(125, 1, FONTID_16F, RGB565(255, 0, 255),""); 
   dispcolor_printf(145, 1, FONTID_16F, RGB565(255, 0, 255),"% ");
   dispcolor_printf(125, 25,  FONTID_16F, RGB565(255, 0, 255),"");
   dispcolor_printf(145, 25,  FONTID_16F, RGB565(255, 0, 255),"% ");
    
   dispcolor_DrawRectangle(43, 0, 118, 17,0xEF01);
   
   dispcolor_DrawRectangle(43, 24, 118, 40, 0xEF01);//0xC515
    
   dispcolor_DrawLine(0, 47, 159, 47, 0xEF90);
   
   dispcolor_printf(35, 57, FONTID_16F, RGB565(255, 0, 0),"T:");
   dispcolor_DrawCircle(79, 58, 2, 0);
   dispcolor_printf(55, 57, FONTID_16F, 0,"");
   
   dispcolor_printf(96, 57, FONTID_16F, RGB565(255, 0, 0),"Hdd:"); 
   dispcolor_DrawCircle(156, 58, 2, 0);
   dispcolor_printf(132, 57, FONTID_16F,0,"");
   
   
   dispcolor_printf(2, 56, FONTID_6X8M, RGB565(255, 255, 0),"FAN"); 
   dispcolor_DrawCircleFilled(10, 72, 2, RGB565(0,255, 255));
   dispcolor_DrawLine(25, 47, 25, 79, 0xEF90);
}

void update_display(void)
{
  if (packet_received)
  {  
    uint8_t k=0, temperature=0, load_cpu=0, load_mem=0;
    uint16_t lenght = 0;
    uint8_t var = 0;
    
    no_data =0;
   // clear_numbers();
     for(uint8_t i=0 ; i<sizeof(PCdata); i++)
     {
       if (PCdata[i] != ';')
       {       
           if (k==0)
           {              
              lenght = dispcolor_DrawChar_Bg(55 + lenght, 57, FONTID_16F, PCdata[i], 0,0xFFFF)+1;    // display  temperature of CPU        
              temperature = (uint8_t)((PCdata[i-var]-48)*10+(PCdata[i]-48));                         //convert temperature from symbols to uint8_t   
              var++;
           }
           else if (k==3)
           {
              lenght = dispcolor_DrawChar_Bg(132 + lenght, 57, FONTID_16F, PCdata[i], 0,0xFFFF)+1;   // display  temperature of HDD
           }
           else if (k==4)
           {
              lenght = dispcolor_DrawChar_Bg(125 + lenght, 1, FONTID_16F, PCdata[i], RGB565(255, 0, 255),0xFFFF)+1;     /// display load CPU
              load_cpu = (uint8_t)((PCdata[i-var]-48)*10+(PCdata[i]-48));                                               //convert from symbols to uint8_t 
              var++;
           }
           else if (k==6)
           {
              lenght = dispcolor_DrawChar_Bg(125 + lenght, 25, FONTID_16F, PCdata[i], RGB565(255, 0, 255),0xFFFF)+1;     /// display  load Memory  
              load_mem = (uint8_t)((PCdata[i-var]-48)*10+(PCdata[i]-48));                                                //convert from symbols to uint8_t 
              var++;
           }
       }
       else {k++;lenght=0;var=0;}     
     }
    update_loadbars(load_cpu, load_mem);
    drive_FAN(temperature);
    packet_received=0;
  }
  else if ((no_data == WAIT_TIME)&(packet_received == 0))
  {
    sleep=1;
    no_data=0;
    ST77xx_DisplayPower(0);
    dispcolor_SetBrightness(0);
    HAL_TIM_Base_Stop(&htim2);
    __WFI();
  }
}

void update_loadbars(uint8_t cpu, uint8_t mem)
{
  uint8_t cpu_start_x = 45, cpu_start_y = 2, 
          cpu_end_x= 117,      cpu_end_y = 17, 
          mem_start_x=45,   mem_start_y = 26,
          mem_end_x = 117,   mem_end_y = 40;
  cpu=(char)(cpu*0.72);
  mem=(char)(mem*0.72);
   
  dispcolor_DrawRectangleFilled( cpu_start_x, cpu_start_y, cpu_start_x+cpu , cpu_end_y, RGB565(255, 0, 255));    // display new bar
  dispcolor_DrawRectangleFilled( cpu_start_x+cpu+1, cpu_start_y, cpu_end_x, cpu_end_y, 0xFFFF);                  //clear old bar
  
  dispcolor_DrawRectangleFilled( mem_start_x,  mem_start_y, mem_start_x+mem, mem_end_y, RGB565(255, 0, 255));
  dispcolor_DrawRectangleFilled( mem_start_x+mem+1, mem_start_y, mem_end_x, mem_end_y, 0xFFFF);
}

void drive_FAN(uint8_t temp)
{
  if ((temp >= TEMPERATURE_ON)&(FAN_state == 0))
  {
      HAL_GPIO_WritePin(GPIOB, FAN_Pin, GPIO_PIN_SET);
      dispcolor_DrawCircleFilled(10, 72, 2,  RGB565(127,0, 255));
      FAN_state = 1;
  }
  else if ((temp < TEMPERATURE_OFF)&(FAN_state == 1))
  {
      HAL_GPIO_WritePin(GPIOB, FAN_Pin, GPIO_PIN_RESET);
      dispcolor_DrawCircleFilled(10, 72, 2, RGB565(0,255, 255));
      FAN_state = 0;
  }
}

void clear_numbers(void)
{
  dispcolor_DrawRectangleFilled(55, 57, 78, 73, 0xFFFF);
  dispcolor_DrawRectangleFilled(132, 57, 155, 73, 0xFFFF);
  dispcolor_DrawRectangleFilled(125, 0, 144, 42, 0xFFFF);  
}



