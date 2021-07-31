#include "VulkanPhysicalDeviceMatch.hpp"

namespace vlindback::VulkanLib
{

    std::vector<PhysicalDeviceMatch > VulkanPhysicalDeviceMatch::GetSupportedDevices(const std::span<vk::PhysicalDevice>& deviceList)
    {
        std::vector<PhysicalDeviceMatch> matches;

        decltype(PhysicalDeviceMatch::deviceMatchScore) deviceScore = 0;

        for (vk::PhysicalDevice device : deviceList)
        {
            // Does the device support:
            //  a) the features we require
            //  b) does it have the proper presentation support?
            //  c)

            // We do the following because it's less code than the alternative and I'm feeble brained
            // from the covid vaccine at the moment so idk...

            // We could just straight up reinterpret_cast and read the memory, however this way
            // is standard conforming and doesn't break strict aliasing rules.
            const vk::PhysicalDeviceFeatures deviceFeatures = device.getFeatures();
            const constexpr std::size_t sizeOfDeviceFeatures = sizeof(vk::PhysicalDeviceFeatures);
            const constexpr std::size_t numberOfDeviceFeatures = sizeOfDeviceFeatures / sizeof(vk::Bool32);

            std::array<vk::Bool32, numberOfDeviceFeatures> actual;
            std::array<vk::Bool32, numberOfDeviceFeatures> required;
            std::memcpy(&actual, &deviceFeatures, sizeOfDeviceFeatures);
            std::memcpy(&required, &m_requiredFeatures, sizeOfDeviceFeatures);

            bool requiredFeatureMissing = false;

            for (std::size_t idx = 0; idx < numberOfDeviceFeatures; ++idx)
            {
                // if REQUIRED is 0 then ACTUAL can be any
                // if REQUIRED is 1 then ACTUAL must be 1
                // if ACTUAL is 0 then REQUIRED must be 0
                // if ACTUAL is 1 then REQUIRED can be any
                if (!required[idx] || actual[idx])
                {
                    // Feature matches.
                }
                else
                {
                    // Feature doesn't match.
                    requiredFeatureMissing = true;
                    break;
                }
            }

            if (!requiredFeatureMissing)
            {
                matches.emplace_back(device, deviceScore);
            }
        }

    }
}