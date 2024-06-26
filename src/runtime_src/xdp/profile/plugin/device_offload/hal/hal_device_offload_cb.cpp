/**
 * Copyright (C) 2016-2020 Xilinx, Inc
 * Copyright (C) 2023 Advanced Micro Devices, Inc. - All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#define XDP_PLUGIN_SOURCE

#include "xdp/profile/plugin/device_offload/hal/hal_device_offload_cb.h"
#include "xdp/profile/plugin/device_offload/hal/hal_device_offload_plugin.h"

namespace xdp {
  static HALDeviceOffloadPlugin deviceOffloadPluginInstance ;

  // This function gets called in a callback at the HAL/Shim layer.
  //  It has to be a hardware run.
  static void updateDeviceHAL(void* handle)
  {
    deviceOffloadPluginInstance.updateDevice(handle) ;
  }

  static void flushDeviceHAL(void* handle)
  {
    deviceOffloadPluginInstance.flushDevice(handle) ;
  }

} // end namespace xdp 

extern "C"
void updateDeviceHAL(void* handle) 
{
  xdp::updateDeviceHAL(handle) ;
}

extern "C"
void flushDeviceHAL(void* handle)
{
  xdp::flushDeviceHAL(handle) ;
}

