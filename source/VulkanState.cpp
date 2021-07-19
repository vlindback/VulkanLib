#include "VulkanState.hpp"

namespace vlindback::VulkanLib
{
    void VulkanState::SetDevicePtr(vk::Device device)
    {
        m_device.reset(device);
    }

    void VulkanState::SetInstancePtr(vk::Instance instance)
    {
        m_instance.reset(instance);
    }

    void VulkanState::SetPhysicalDevicePtr(vk::PhysicalDevice device)
    {
        m_physicalDevice = device;
    }
}