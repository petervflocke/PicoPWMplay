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


#ifndef __PICO_PLAY_AUDIO_H
#define __PICO_PLAY_AUDIO_H


#include "WavPwmAudio.h"

#define GPIO_KEY_PLAY                  14

#define GPIO_AUDIO_OUT_LEFT            16
#define GPIO_AUDIO_OUT_RIGHT           17


void Init();
void GPIO_CallBack(uint GPIO, uint32_t Events);

#endif
