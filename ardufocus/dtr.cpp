/**
 * Ardufocus - Moonlite compatible focuser
 * Copyright (C) 2017-2019 João Brázio [joao@brazio.org]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "dtr.h"

void dtr_disable() {
#ifdef ENABLE_DTR_RESET
	if (g_config.dtr_reset == false) {
		IO::set_as_output(DTR_RESET_PINOUT);
	}
#endif
}

void dtr_reset(const bool& value) {
	g_config.dtr_reset = value;
	eeprom_save(&g_config);
}

uint8_t dtr_reset_get() { return (g_config.dtr_reset) ? 1 : 0; }
