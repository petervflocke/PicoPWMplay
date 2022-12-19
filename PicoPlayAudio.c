// PicoRecPlayAudio - Raspberry Pi Pico Audio Record/Playbak/WAV File
// Copyright (C) 2022 Jason Birch
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/irq.h"
#include "PicoPlayAudio.h"
#include "WAVData.h"


static unsigned char GpioKey = false;


int main(int argc, char* argv[])
{
   Init();
   while (true)
   {
      sleep_ms(100);
      gpio_put(PICO_DEFAULT_LED_PIN, (GpioKey != false));

      switch (GpioKey)
      {
         case GPIO_KEY_PLAY:
            WavPwmPlayAudio(DING_WAV);
            while (WavPwmIsPlaying());
            GpioKey = false;
            break;
      }
   };
}


void Init()
{
   stdio_init_all();

   gpio_init(PICO_DEFAULT_LED_PIN);
   gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
   gpio_pull_up(GPIO_KEY_PLAY);
   gpio_set_irq_enabled_with_callback(GPIO_KEY_PLAY, GPIO_IRQ_EDGE_FALL, true, &GPIO_CallBack);
   WavPwmInit(GPIO_AUDIO_OUT_LEFT);
}

void GPIO_CallBack(uint GPIO, uint32_t Events)
{
   static unsigned int LastInt = 0;

   if (!LastInt || time_us_32() - LastInt > 200000)
   {
      GpioKey = GPIO;
      gpio_put(PICO_DEFAULT_LED_PIN, 1);
   }
   LastInt = time_us_32();
}
