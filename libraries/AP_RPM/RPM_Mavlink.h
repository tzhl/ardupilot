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
// Author: Sriram Sami
#pragma once

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4 || CONFIG_HAL_BOARD == HAL_BOARD_VRBRAIN

#include "AP_RPM.h"
#include "RPM_Backend.h"

class AP_RPM_Mavlink : public AP_RPM_Backend
{
public:
    // constructor
    AP_RPM_Mavlink(AP_RPM &ranger, uint8_t instance, AP_RPM::RPM_State &_state);

    // the function is defined here - but it does nothing when called in
    // main update loop. This backend needs an external value to work.
    void update(void);

    // This is the function to be called from the point in the code that
    // receives a mavlink message with RPM values
    void update_from_external(float new_rpm);

private:
    uint8_t instance;
};

#endif
