#include"keyboard.h"


int hook = 0;


int kbd_test_scan(unsigned short ass)
{
	unsigned short keyboard;

	if(int irq_set = timer_subscribe_int()== -1)
		return -1;



	while( keyboard!= OUT_BUF) {
		/* Get a request message. */
		if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0)
		{
			printf("driver_receive failed with: %d", r);
			continue;
		}
		if (is_ipc_notify(ipc_status)) { /* received notification */
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /* hardware interrupt notification */
				if (msg.NOTIFY_ARG & irq_set)
				{ /* subscribed interrupt */






				}
				break;
			default:
				break; /* no other notifications expected: do nothing */
			}
		} else { /* received a standard message, not a notification */
			/* no standard messages expected: do nothing */

		}

	}




	if(KBD_unsubscribe_int()!= OK)
		return -1;
	return 0;
}




int kbd_test_leds(unsigned short n, unsigned short *leds)
{
    /* To be completed */
}

int kbd_test_timed_scan(unsigned short n) {
    /* To be completed */
}


