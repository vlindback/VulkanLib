#include "VulkanInitialization.hpp"

#include "VulkanPhysicalDeviceMatch.hpp"

#include <exception>

namespace vlindback::VulkanLib
{
    VulkanState VulkanInitialization::Initialize()
    {
        VulkanState state;

        // Instance creation

        vk::ApplicationInfo applicationInfo;
        applicationInfo.setApiVersion(m_apiVersion);
        applicationInfo.setApplicationVersion(m_applicationVersion);
        applicationInfo.setEngineVersion(m_engineVersion);
        applicationInfo.setPApplicationName(m_applicationName.c_str());
        applicationInfo.setPEngineName(m_engineName.c_str());

        vk::InstanceCreateInfo instanceCreateInfo;
        instanceCreateInfo.setPApplicationInfo(&applicationInfo);
        instanceCreateInfo.setEnabledExtensionCount(m_instanceExtensions.size());
        instanceCreateInfo.setPpEnabledExtensionNames(m_instanceExtensions.data());
        instanceCreateInfo.setEnabledLayerCount(m_instanceLayers.size());
        instanceCreateInfo.setPpEnabledLayerNames(m_instanceLayers.data());
        
        state.SetInstancePtr(vk::createInstance(instanceCreateInfo));



        // Find an appropriate physical device.
        // TODO: check if empty. let user know
        std::vector availablePhysicalDevices = state.Instance().enumeratePhysicalDevices();

        bool physicalDeviceFound = false;

        // Do we not have a preset device?
        if (!m_presetPhysicalDeviceName.empty())
        {
            // Blindly trust the user, just use this device if it exists.

            physicalDeviceFound = true;

            for (vk::PhysicalDevice device : availablePhysicalDevices)
            {
                vk::PhysicalDeviceProperties deviceProperties = device.getProperties();
                if (std::strcmp(deviceProperties.deviceName, m_presetPhysicalDeviceName.c_str()) == 0)
                {
                    physicalDeviceFound = true;
                    state.SetPhysicalDevicePtr(device);
                }
            }
        }
        
        // In case there's no preset, or the preset was missing, we search for an
        // appropriate device.
        if (!physicalDeviceFound)
        {
            VulkanPhysicalDeviceMatch deviceMatcher;
            std::vector deviceMatches = deviceMatcher.GetSupportedDevices(availablePhysicalDevices);
        }



        return state;
    }

    void VulkanInitialization::AddInstanceLayer(std::string_view name)
    {
        m_instanceLayers.emplace_back(name);
    }

    void VulkanInitialization::AddInstanceExtension(std::string_view name)
    {
        m_instanceExtensions.emplace_back(name);
    }

    void VulkanInitialization::AddDeviceLayer(std::string_view name)
    {
        m_deviceLayers.emplace_back(name);
    }

    void VulkanInitialization::AddDeviceExtension(std::string_view name)
    {
        m_deviceExtensions.emplace_back(name);
    }

    void VulkanInitialization::SetPresetPhysicalDeviceName(std::string_view name)
    {
        m_presetPhysicalDeviceName = name;
    }
}