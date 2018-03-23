#ifndef THREADS_H
#define THREADS_H

#include <cmsis_os2.h>
#include "LCD_driver.h"
#include <MKL25Z4.H>

#define THREAD_READ_TS_PERIOD_MS (50)  // 1 tick/ms
#define THREAD_READ_ACCELEROMETER_PERIOD_MS (100)  // 1 tick/ms
#define THREAD_SOUND_PERIOD_MS (100)  // 1 tick/ms
#define THREAD_UPDATE_SCREEN_PERIOD_MS (50)

#define THREADS_ARE_SAME_PRIORITY (1)		
#define MEASURE_REFILL_LATENCY (1)

#define USE_LCD_MUTEX (1)

// Defines and instructions for demonstration
/*
1. Baseline: System crashes in display of roll or pitch
2. Increase default stack size in RTX_Config.h to 512, then 768
3. Now display is OK, but no audio. Why don't audio threads run? Set breakpoint in 
	one - is never hit. Then look at thread information in debugger.
4. Work back to start - Check return value when creating threads
5. Reduce default stack sizes, but use larger custom stack size for Read Accelerometer
6. Should work now.
*/

#define DEMO_DEFAULT_READ_ACCEL_STK_SZ (1)


// Custom stack sizes for larger threads
#define READ_ACCEL_STK_SZ 768

void Init_Debug_Signals(void);

// Events for sound generation and control
#define EV_PLAYSOUND (1) 
#define EV_SOUND_ON (2)
#define EV_SOUND_OFF (4)

#define EV_REFILL_SOUND_BUFFER  (1)

void Create_OS_Objects(void);
 
extern osThreadId_t t_Read_TS, t_Read_Accelerometer, t_Sound_Manager, t_US, t_Refill_Sound_Buffer;
extern osMutexId_t LCD_mutex;

 
// Game Constants
#define PADDLE_WIDTH (40)
#define PADDLE_HEIGHT (15)
#define PADDLE_Y_POS (LCD_HEIGHT-4-PADDLE_HEIGHT)
 
#endif // THREADS_H
