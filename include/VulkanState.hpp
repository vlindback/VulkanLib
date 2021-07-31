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

            vk::Instance Instance() noexcept;
            

        private:

            vk::UniqueInstance m_instance;
            vk::UniqueDevice m_device;
            vk::PhysicalDevice m_physicalDevice;
            std::vector<vk::PhysicalDevice> m_availablePhysicalDevices;
    };
}