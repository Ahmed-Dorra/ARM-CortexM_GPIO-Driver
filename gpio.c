/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: source file for the ARM_cortex-M GPIO driver
 *
 * Author: Ahmed_Dorra
 *
 *******************************************************************************/
#include "Relavent_Macros.h"
#include "gpio.h"
#include "tm4c123gh6pm_registers.h"



void GPIO_init(uint8 port_num)
{
  volatile uint32 delay = 0;
  
   switch(port_num)
  {
  case PORTA_ID: SYSCTL_REGCGC2_REG |= 0x00000001;
   delay = SYSCTL_REGCGC2_REG;                                    /* this equal operation will give us the 3 clockcycle delay we want*/ 
  break;
  
  case PORTB_ID: SYSCTL_REGCGC2_REG |= 0x00000002;
   delay = SYSCTL_REGCGC2_REG;                                     
  break;
  
  case PORTC_ID: SYSCTL_REGCGC2_REG |= 0x00000004;
   delay = SYSCTL_REGCGC2_REG;                                  
  break;
  
  case PORTD_ID: SYSCTL_REGCGC2_REG |= 0x00000008;
   delay = SYSCTL_REGCGC2_REG;                                  
  break;
  
  case PORTE_ID: SYSCTL_REGCGC2_REG |= 0x00000010;
   delay = SYSCTL_REGCGC2_REG;                                  
  break;
  
  case PORTF_ID: SYSCTL_REGCGC2_REG |= 0x00000020;
   delay = SYSCTL_REGCGC2_REG;                                  
  break;
  
  
  }
}



void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionState direction)
{
  switch(port_num)
  {
  case PORTA_ID:
  CLEAR_BIT(GPIO_PORTA_AMSEL_REG, pin_num);                                              /* Disable Analog on Pin */
  CLEAR_BIT(GPIO_PORTA_AFSEL_REG , pin_num);                                            /* Disable alternative function on Pin */
  SET_BIT(GPIO_PORTA_DEN_REG ,pin_num);                                                 /* Enable Digital I/O on Pin */
  GPIO_PORTA_PCTL_REG = (GPIO_PORTA_PCTL_REG &~(0x0000000F << (4*pin_num)));            /*Enter the mode of gpio in control register*/   
  if(direction == PIN_INPUT)
  {
  CLEAR_BIT(GPIO_PORTA_DIR_REG,pin_num);
  }
  else if(direction == PIN_OUTPUT)
  {
  SET_BIT(GPIO_PORTA_DIR_REG,pin_num);
  }  
  break;
    
  case PORTB_ID:
  CLEAR_BIT(GPIO_PORTB_AMSEL_REG, pin_num);                                              /* Disable Analog on Pin */
  CLEAR_BIT(GPIO_PORTB_AFSEL_REG , pin_num);                                            /* Disable alternative function on Pin */
  SET_BIT(GPIO_PORTB_DEN_REG ,pin_num);                                                 /* Enable Digital I/O on Pin */
  GPIO_PORTB_PCTL_REG = (GPIO_PORTB_PCTL_REG &~(0x0000000F << (4*pin_num)));            /*Enter the mode of gpio in control register*/   
  if(direction == PIN_INPUT)
  {
  CLEAR_BIT(GPIO_PORTB_DIR_REG,pin_num);
  }
  else if(direction == PIN_OUTPUT)
  {
  SET_BIT(GPIO_PORTB_DIR_REG,pin_num);
  }  
  break;
    
  case PORTC_ID:
  CLEAR_BIT(GPIO_PORTC_AMSEL_REG, pin_num);                                              /* Disable Analog on Pin */
  CLEAR_BIT(GPIO_PORTC_AFSEL_REG , pin_num);                                            /* Disable alternative function on Pin */
  SET_BIT(GPIO_PORTC_DEN_REG ,pin_num);                                                 /* Enable Digital I/O on Pin */
  GPIO_PORTC_PCTL_REG = (GPIO_PORTC_PCTL_REG &~(0x0000000F << (4*pin_num)));            /*Enter the mode of gpio in control register*/   
  if(direction == PIN_INPUT)
  {
  CLEAR_BIT(GPIO_PORTC_DIR_REG,pin_num);
  }
  else if(direction == PIN_OUTPUT)
  {
  SET_BIT(GPIO_PORTC_DIR_REG,pin_num);
  }    
  break;
    
  case PORTD_ID:
  CLEAR_BIT(GPIO_PORTD_AMSEL_REG, pin_num);                                              /* Disable Analog on Pin */
  CLEAR_BIT(GPIO_PORTD_AFSEL_REG , pin_num);                                            /* Disable alternative function on Pin */
  SET_BIT(GPIO_PORTD_DEN_REG ,pin_num);                                                 /* Enable Digital I/O on Pin */
  GPIO_PORTD_PCTL_REG = (GPIO_PORTD_PCTL_REG &~(0x0000000F << (4*pin_num)));            /*Enter the mode of gpio in control register*/   
  if(direction == PIN_INPUT)
  {
  CLEAR_BIT(GPIO_PORTD_DIR_REG,pin_num);
  }
  else if(direction == PIN_OUTPUT)
  {
  SET_BIT(GPIO_PORTD_DIR_REG,pin_num);
  }    
  break;
    
  case PORTE_ID:
  CLEAR_BIT(GPIO_PORTE_AMSEL_REG, pin_num);                                              /* Disable Analog on Pin */
  CLEAR_BIT(GPIO_PORTE_AFSEL_REG , pin_num);                                            /* Disable alternative function on Pin */
  SET_BIT(GPIO_PORTE_DEN_REG ,pin_num);                                                 /* Enable Digital I/O on Pin */
  GPIO_PORTE_PCTL_REG = (GPIO_PORTE_PCTL_REG &~(0x0000000F << (4*pin_num)));            /*Enter the mode of gpio in control register*/   
  if(direction == PIN_INPUT)
  {
  CLEAR_BIT(GPIO_PORTE_DIR_REG,pin_num);
  }
  else if(direction == PIN_OUTPUT)
  {
  SET_BIT(GPIO_PORTE_DIR_REG,pin_num);
  }    
  break;
    
  case PORTF_ID:
  GPIO_PORTF_LOCK_REG = 0x4C4F434B;                                                   /* unlocking commit register by putting magic number in lock register*/
  SET_BIT(GPIO_PORTF_CR_REG, pin_num);                                               /*setting the bit correspond to our pin to 1 so changes on that pin takeplace*/
  CLEAR_BIT(GPIO_PORTF_AMSEL_REG, pin_num);                                              /* Disable Analog on Pin */
  CLEAR_BIT(GPIO_PORTF_AFSEL_REG , pin_num);                                            /* Disable alternative function on Pin */
  SET_BIT(GPIO_PORTF_DEN_REG ,pin_num);                                                 /* Enable Digital I/O on Pin */
  GPIO_PORTF_PCTL_REG = (GPIO_PORTF_PCTL_REG &~(0x0000000F << (4*pin_num)));            /*Enter the mode of gpio in control register*/         
  if(direction == PIN_INPUT)
  {
  CLEAR_BIT(GPIO_PORTF_DIR_REG,pin_num);
  }
  else if(direction == PIN_OUTPUT)
  {
  SET_BIT(GPIO_PORTF_DIR_REG,pin_num);
  }    
  break;
    
  }     
  
}

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
 if(port_num > MAX_NUM_OF_PORTS || port_num < MIN_NUM_OF_PORTS || pin_num < PIN0_ID || \
			pin_num > MAX_NUM_OF_PINS_PER_PORT)
{
		/*DO NOTHING*/
}
else
{
  switch(port_num)
  {
  case PORTA_ID :
    
    if(value == LOGIC_HIGH)
    {
      SET_BIT(GPIO_PORTA_DATA_REG,pin_num);
    }
    else if(value == LOGIC_LOW)
    {
      CLEAR_BIT(GPIO_PORTA_DATA_REG,pin_num);
    }
    break;
    
  case PORTB_ID :
    
    if(value == LOGIC_HIGH)
    {
      SET_BIT(GPIO_PORTB_DATA_REG,pin_num);
    }
    else if(value == LOGIC_LOW)
    {
      CLEAR_BIT(GPIO_PORTB_DATA_REG,pin_num);
    }
    break;
    
  case PORTC_ID :
    if(value == LOGIC_HIGH)
    {
      SET_BIT(GPIO_PORTC_DATA_REG,pin_num);
    }
    else if(value == LOGIC_LOW)
    {
      CLEAR_BIT(GPIO_PORTC_DATA_REG,pin_num);
    }
    break;
    
  case PORTD_ID :
    if(value == LOGIC_HIGH)
    {
      SET_BIT(GPIO_PORTD_DATA_REG,pin_num);
    }
    else if(value == LOGIC_LOW)
    {
      CLEAR_BIT(GPIO_PORTD_DATA_REG,pin_num);
    }
    break;
    
    case PORTE_ID :
    if(value == LOGIC_HIGH)
    {
      SET_BIT(GPIO_PORTE_DATA_REG,pin_num);
    }
    else if(value == LOGIC_LOW)
    {
      CLEAR_BIT(GPIO_PORTE_DATA_REG,pin_num);
    }
    break;
    
    case PORTF_ID :
    if(value == LOGIC_HIGH)
    {
      SET_BIT(GPIO_PORTF_DATA_REG,pin_num);
    }
    else if(value == LOGIC_LOW)
    {
      CLEAR_BIT(GPIO_PORTF_DATA_REG,pin_num);
    }
    break;
  }
  
 }

}

void GPIO_setupPortDirection(uint8 port_num, GPIO_PORTDirectionState direction)
{
switch(port_num)
  {
  case PORTA_ID:
  CLEAR_ALL(GPIO_PORTA_AMSEL_REG);                                              /* Disable Analog on Port */
  CLEAR_ALL(GPIO_PORTA_AFSEL_REG);                                             /* Disable alternative function on Port */
  SET_ALL(GPIO_PORTA_DEN_REG);                                                 /* Enable Digital I/O on Port */
  GPIO_PORTA_PCTL_REG = 0x00000000;                                            /*Set the mode of gpio in control register*/   
  if(direction == PORT_INPUT)
  {
  CLEAR_ALL(GPIO_PORTA_DIR_REG);
  }
  else if(direction == PORT_OUTPUT)
  {
  SET_ALL(GPIO_PORTA_DIR_REG);
  }  
  break;
    
  case PORTB_ID:
  CLEAR_ALL(GPIO_PORTB_AMSEL_REG);                                              /* Disable Analog on Port */
  CLEAR_ALL(GPIO_PORTB_AFSEL_REG);                                            /* Disable alternative function on Port */
  SET_ALL(GPIO_PORTB_DEN_REG);                                                 /* Enable Digital I/O on Port */
  GPIO_PORTB_PCTL_REG = 0x00000000;                                            /*Set the mode of gpio in control register*/   
  if(direction == PORT_INPUT)
  {
  CLEAR_ALL(GPIO_PORTB_DIR_REG);
  }
  else if(direction == PORT_OUTPUT)
  {
  SET_ALL(GPIO_PORTB_DIR_REG);
  }  
  break;
    
  case PORTC_ID:
  CLEAR_ALL(GPIO_PORTC_AMSEL_REG);                                              /* Disable Analog on Port */
  CLEAR_ALL(GPIO_PORTC_AFSEL_REG);                                            /* Disable alternative function on Port */
  SET_ALL(GPIO_PORTC_DEN_REG);                                                 /* Enable Digital I/O on Port */
  GPIO_PORTC_PCTL_REG = 0x00000000;                                            /*Set the mode of gpio in control register*/   
  if(direction == PORT_INPUT)
  {
  CLEAR_ALL(GPIO_PORTC_DIR_REG);
  }
  else if(direction == PORT_OUTPUT)
  {
  SET_ALL(GPIO_PORTC_DIR_REG);
  }  
  break;
    
  case PORTD_ID:
  CLEAR_ALL(GPIO_PORTD_AMSEL_REG);                                              /* Disable Analog on Port */
  CLEAR_ALL(GPIO_PORTD_AFSEL_REG);                                            /* Disable alternative function on Port */
  SET_ALL(GPIO_PORTD_DEN_REG);                                                 /* Enable Digital I/O on Port */
  GPIO_PORTD_PCTL_REG = 0x00000000;                                            /*Set the mode of gpio in control register*/   
  if(direction == PORT_INPUT)
  {
  CLEAR_ALL(GPIO_PORTD_DIR_REG);
  }
  else if(direction == PORT_OUTPUT)
  {
  SET_ALL(GPIO_PORTD_DIR_REG);
  }  
  break;
    
  case PORTE_ID:
  CLEAR_ALL(GPIO_PORTE_AMSEL_REG);                                              /* Disable Analog on Port */
  CLEAR_ALL(GPIO_PORTE_AFSEL_REG);                                            /* Disable alternative function on Port */
  SET_ALL(GPIO_PORTE_DEN_REG);                                                 /* Enable Digital I/O on Port */
  GPIO_PORTB_PCTL_REG = 0x00000000;                                            /*Set the mode of gpio in control register*/   
  if(direction == PORT_INPUT)
  {
  CLEAR_ALL(GPIO_PORTE_DIR_REG);
  }
  else if(direction == PORT_OUTPUT)
  {
  SET_ALL(GPIO_PORTE_DIR_REG);
  }  
  break;
    
  case PORTF_ID:
  GPIO_PORTF_LOCK_REG = 0x4C4F434B;
  SET_ALL(GPIO_PORTF_CR_REG);
  CLEAR_ALL(GPIO_PORTF_AMSEL_REG);                                              /* Disable Analog on Port */
  CLEAR_ALL(GPIO_PORTF_AFSEL_REG);                                            /* Disable alternative function on Port */
  SET_ALL(GPIO_PORTF_DEN_REG);                                                 /* Enable Digital I/O on Port */
  GPIO_PORTF_PCTL_REG = 0x00000000;                                            /*Set the mode of gpio in control register*/   
  if(direction == PORT_INPUT)
  {
  CLEAR_ALL(GPIO_PORTF_DIR_REG);
  }
  else if(direction == PORT_OUTPUT)
  {
  SET_ALL(GPIO_PORTF_DIR_REG);
  }  
  break;
    
  }       
}


void GPIO_writePort(uint8 port_num, uint8 value)
{
  if(port_num > MAX_NUM_OF_PORTS || port_num < MIN_NUM_OF_PORTS)
  {
    /*DO NOTHING*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID :
      GPIO_PORTA_DATA_REG = value;
      break;
      
    case PORTB_ID :
      GPIO_PORTB_DATA_REG = value;
      break;
      
    case PORTC_ID :
      GPIO_PORTC_DATA_REG = value;
      break;
      
    case PORTD_ID :
      GPIO_PORTD_DATA_REG = value;
      break;
      
    case PORTE_ID :
      GPIO_PORTE_DATA_REG = value;
      break;
      
    case PORTF_ID :
      GPIO_PORTF_DATA_REG = value;
      break;
      
    }
  }
} 


uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
  if(port_num > MAX_NUM_OF_PORTS || port_num < MIN_NUM_OF_PORTS || pin_num < PIN0_ID || \
    pin_num > MAX_NUM_OF_PINS_PER_PORT)
  {
    /*No Condition so it will break if -else statement and reach the end of the function
    *  which is return LOGIC_LOW and that is what we want in case there is something
    *  wrong with inputs coming to the function*/
  }
  else
  {
    switch(port_num)
    {
      
    case PORTA_ID :
      if(BIT_IS_SET(GPIO_PORTA_DATA_REG,pin_num))
      {
        return LOGIC_HIGH;
      }
      else
      {
        return LOGIC_LOW;
      }
      break;
      
    case PORTB_ID :
      if(BIT_IS_SET(GPIO_PORTB_DATA_REG,pin_num))
      {
        return LOGIC_HIGH;
      }
      else
      {
        return LOGIC_LOW;
      }
      break;
      
    case PORTC_ID :
      if(BIT_IS_SET(GPIO_PORTC_DATA_REG,pin_num))
      {
        return LOGIC_HIGH;
      }
      else
      {
        return LOGIC_LOW;
      }
      break;
      
    case PORTD_ID :
      if(BIT_IS_SET(GPIO_PORTD_DATA_REG,pin_num))
      {
        return LOGIC_HIGH;
      }
      else
      {
        return LOGIC_LOW;
      }
      break;
      
      case PORTE_ID :
      if(BIT_IS_SET(GPIO_PORTE_DATA_REG,pin_num))
      {
        return LOGIC_HIGH;
      }
      else
      {
        return LOGIC_LOW;
      }
      break;
      
      case PORTF_ID :
      if(BIT_IS_SET(GPIO_PORTF_DATA_REG,pin_num))
      {
        return LOGIC_HIGH;
      }
      else
      {
        return LOGIC_LOW;
      }
      break;
    }
    
  }
  
  return LOGIC_LOW;
}

uint8 GPIO_readPort(uint8 port_num)
{
  if(port_num > MAX_NUM_OF_PORTS || port_num < MIN_NUM_OF_PORTS)
  {
    /*DO NOTHING*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID :
      return GPIO_PORTA_DATA_REG;
      break;
      
    case PORTB_ID :
      return GPIO_PORTB_DATA_REG;
      break;
      
    case PORTC_ID :
      return GPIO_PORTC_DATA_REG;
      break;
      
    case PORTD_ID :
      return GPIO_PORTD_DATA_REG;
      break;
      
    case PORTE_ID :
      return GPIO_PORTE_DATA_REG;
      break;
      
    case PORTF_ID :
      return GPIO_PORTF_DATA_REG;
      break;
    }
  }
  return LOGIC_LOW;
}



void GPIO_setPullup(uint8 port_num, uint8 pin_num)
{
  
  switch(port_num)
    {
    case PORTA_ID :
      SET_BIT(GPIO_PORTA_PUR_REG,pin_num);
      break;
      
    case PORTB_ID :
      SET_BIT(GPIO_PORTB_PUR_REG,pin_num);
      break;
      
    case PORTC_ID :
      SET_BIT(GPIO_PORTC_PUR_REG,pin_num);
      break;
      
    case PORTD_ID :
      SET_BIT(GPIO_PORTD_PUR_REG,pin_num);
      break;
      
    case PORTE_ID :
     SET_BIT(GPIO_PORTE_PUR_REG,pin_num);
      break;
      
    case PORTF_ID :
      SET_BIT(GPIO_PORTF_PUR_REG,pin_num);
      break;
    }
}
  
void GPIO_setPulldown(uint8 port_num, uint8 pin_num)
{
  switch(port_num)
    {
    case PORTA_ID :
      SET_BIT(GPIO_PORTA_PDR_REG,pin_num);
      break;
      
    case PORTB_ID :
      SET_BIT(GPIO_PORTB_PDR_REG,pin_num);
      break;
      
    case PORTC_ID :
      SET_BIT(GPIO_PORTC_PDR_REG,pin_num);
      break;
      
    case PORTD_ID :
      SET_BIT(GPIO_PORTD_PDR_REG,pin_num);
      break;
      
    case PORTE_ID :
     SET_BIT(GPIO_PORTE_PDR_REG,pin_num);
      break;
      
    case PORTF_ID :
      SET_BIT(GPIO_PORTF_PDR_REG,pin_num);
      break;
    }
}
