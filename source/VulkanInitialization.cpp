#include "VulkanInitialization.hpp"

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
}