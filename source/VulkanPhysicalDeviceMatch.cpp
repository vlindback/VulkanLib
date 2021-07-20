#include "VulkanPhysicalDeviceMatch.hpp"

namespace vlindback::VulkanLib
{

    std::vector<vk::PhysicalDevice> VulkanPhysicalDeviceMatch::GetSupportedDevices(const std::span<vk::PhysicalDevice>& deviceList)
    {
        
        for (vk::PhysicalDevice device : deviceList)
        {
            // Does the device support:
            //  a) the features we require
            //  b) does it have the proper presentation support?
            //  c)
        }

    }
}