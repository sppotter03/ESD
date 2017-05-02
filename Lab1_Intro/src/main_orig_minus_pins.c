/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

int main (void)
{
	board_init();

	/* Insert application code here, after the board has been initialized. */
	bool led_state = LED_0_INACTIVE;
	bool button_state = BUTTON_0_INACTIVE;

	while (1)
	{
		/* Is button pressed? */
		if (ioport_get_pin_level(PIN_PC24) == BUTTON_0_ACTIVE)
		{
			// If button is now pressed, but it was not pressed last time 
			// through the loop (ie button_state is Inactive), then we 
			// have detected the edge trigger from Inactive -> Active
			// Now we can turn the LED on or off
			if(button_state == BUTTON_0_INACTIVE)
			{
				if(led_state == LED_0_ACTIVE)
				{
					ioport_set_pin_level(PIN_PC07, LED_0_INACTIVE);
					led_state = LED_0_INACTIVE;
				}
				else
				{
					ioport_set_pin_level(LED_0_PIN, LED_0_ACTIVE);
					led_state = LED_0_ACTIVE;
				}
			}
			button_state = BUTTON_0_ACTIVE;
		}
		else
		{
			button_state = BUTTON_0_INACTIVE;
		}
	}
}
