#pragma once

#include "VulkanApi.hpp"
#include "VulkanState.hpp"

#include <string>
#include <vector>

namespace vlindback::VulkanLib
{
    class VulkanInitialization
    {
        public:


            VulkanState Initialize();

            void AddInstanceLayer(std::string_view name);
            void AddInstanceExtension(std::string_view name);
            void AddDeviceLayer(std::string_view name);
            void AddDeviceExtension(std::string_view name);


        private:

            std::string m_applicationName;
            std::string m_engineName;
            std::uint32_t m_applicationVersion = 0;
            std::uint32_t m_engineVersion = 0;
            std::uint32_t m_apiVersion = VK_API_VERSION_1_1;

            std::vector<const char*> m_instanceLayers;
            std::vector<const char*> m_instanceExtensions;
            std::vector<const char*> m_deviceLayers;
            std::vector<const char*> m_deviceExtensions;
    };
}