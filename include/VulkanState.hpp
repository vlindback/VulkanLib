#pragma once

#include "VulkanApi.hpp"

namespace vlindback::VulkanLib
{
    class VulkanState
    {
        public:

            void SetDevicePtr(vk::Device device);
            void SetInstancePtr(vk::Instance instance);
            void SetPhysicalDevicePtr(vk::PhysicalDevice device);

        private:

            vk::UniqueInstance m_instance;
            vk::PhysicalDevice m_physicalDevice;
            vk::UniqueDevice m_device;

    };
}