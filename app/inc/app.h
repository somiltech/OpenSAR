

#ifndef APP_H_
#define APP_H_

#include "Os.h"
#if defined(WIN32)
#define SetEvent SetEvent2
#endif
#include "debug.h"

#include <stdio.h>

#include "Can.h"
#include "CanIf.h"
#include "CanTp.h"
#include "PduR.h"
#include "Com.h"
#include "Dcm.h"
#include "Dio.h"
#include "Port.h"
#if defined(WIN32)
#include "Stmo.h"
#endif

#include "Diag.h"

// ========= APP Module
#include "app_led.h"
#include "app_gauge.h"

#endif /* APP_H_ */

