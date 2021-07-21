#pragma once

#include "VulkanApi.hpp"

#include <span>

namespace vlindback::VulkanLib
{
    class VulkanPhysicalDeviceMatch
    {
        public:



            std::vector<vk::PhysicalDevice> GetSupportedDevices(const std::span<vk::PhysicalDevice>& deviceList);


        private:

            vk::PhysicalDeviceProperties m_requiredProperties;


    };
}