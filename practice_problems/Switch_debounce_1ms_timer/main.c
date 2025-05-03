/******************************************************************************

Write SW filter to de-bounce switch press in circuits

In C, declaring a volatile variable c involves using the volatile keyword 
before or after the data type in the variable declaration. This keyword 
informs the compiler that the value of the variable may change unexpectedly 
by external factors, such as hardware or another thread, thus preventing the 
compiler from performing certain optimizations.

The volatile keyword ensures that every read and write operation on the 
variable c is performed directly in memory, rather than relying on cached 
values or compiler optimizations. This is crucial when dealing with 
memory-mapped hardware registers, global variables modified by interrupt 
service routines, or variables shared between multiple threads.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

volatile state prevState = buttonReleased;
volatile unsigned int buttonDownCnt = 0;
volatile unsigned int buttonUpCnt = 0;


int GPIOLevelGet(int button_id)
{
    return 0;
}

//ISR generated only for buttton press, not button release
void ISR_buttonPress(void)
{
	/* start 1ms periodic timer if not already running */
	start_timer(ISR_timer_1ms);
}

// Check for button pressed or released condition
void ISR_timer_1ms(void)
{
    if(prevState == buttonReleased)
    {
        // true only if button down reads LOW for 20 consecutive ms
        if(GPIOLevelGet(1) == 0)
		{
			buttonDownCnt++;
			
			if(buttonDownCnt >= 20)
			{
				buttonDownCnt = 0;
				prevState = buttonPressed;
				
				printf("Button pressed\n");
			    //stop_timer(ISR_timer_1ms);
			}
		}
		else
		{
			buttonDownCnt = 0;
		}
    }
    else if(prevState == buttonPressed)
    {
        // true only if button down reads HIGH for 20 consecutive ms
        if(GPIOLevelGet(1) == 1)
		{
			buttonUpCnt++;
			
			if(buttonUpCnt >= 20)
			{
				buttonUpCnt = 0;
				prevState = buttonReleased;
				
				printf("Button released\n");
				stop_timer(ISR_timer_1ms);
			}
		}
		else
		{
			buttonUpCnt = 0;
		}
    }

}
int main()
{
    printf("Hello World");

    return 0;
}
