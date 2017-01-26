/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4 || CONFIG_HAL_BOARD == HAL_BOARD_VRBRAIN

#include "RPM_Mavlink.h"

/*
   open the sensor in constructor
*/
AP_RPM_Mavlink::AP_RPM_Mavlink(AP_RPM &_ap_rpm, uint8_t _instance, AP_RPM::RPM_State &_state) :
    AP_RPM_Backend(_ap_rpm, _instance, _state)
{
    instance = _instance;
}

void AP_RPM_Mavlink::update(void)
{
    // Do nothing - we need an external value to do any work!
    return;
}

void AP_RPM_Mavlink::update_from_external(float new_rpm)
{
    // Update the current state rpm purely from the new value
    state.rate_rpm = new_rpm;

    // Apply any scaling set in the system
    state.rate_rpm *= ap_rpm._scaling[state.instance];

    // Highest signal quality just so that we pass over any filters
    state.signal_quality = 1.0f;

    // Update last update time (now)
    state.last_reading_ms = AP_HAL::millis();
}

#endif // CONFIG_HAL_BOARD
