/*
* Configuration of module: Port (Port_Cfg.c)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    TMS570
*
* Module vendor:           ArcCore
* Generator version:       2.0.0
*
* Generated by Arctic Studio (http://arccore.com) 
*/

	

#include "Port.h"



const Port_ConfigType PortConfigData =
{
    .pins = {
    	{
			.pin = PORT_PIN_DCAN1_TX,
			.conf = ( PORT_PIN_OUT | PORT_FUNC | PORT_PULL_NONE ),
		},			 
    	{
			.pin = PORT_PIN_DCAN1_RX,
			.conf = ( PORT_PIN_IN | PORT_FUNC | PORT_PULL_NONE ),
		},			 
    	{
			.pin = PORT_PIN_GIOA3,
			.conf = ( PORT_PIN_OUT | PORT_FUNC_NO | PORT_PULL_NONE ),
		},			  
    }
};