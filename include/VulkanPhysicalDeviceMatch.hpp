#pragma once

#include "VulkanApi.hpp"

#include <span>

namespace vlindback::VulkanLib
{
    struct PhysicalDeviceMatch
    {
        vk::PhysicalDevice devicePtr;
        std::size_t deviceMatchScore;
    };

    class VulkanPhysicalDeviceMatch
    {
        public:



            std::vector<PhysicalDeviceMatch> GetSupportedDevices(const std::span<vk::PhysicalDevice>& deviceList);


        private:

            vk::PhysicalDeviceFeatures m_requiredFeatures;


    };
}