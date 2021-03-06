#pragma once

#include "eseed/window/window.hpp"

#include <vulkan/vulkan.hpp>
#include <vector>
#include <optional>

class ResourceManager {
public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager(
        const std::vector<const char*>& instanceExtensionNames,
        const std::vector<const char*>& instanceLayerNames,
        const std::vector<const char*>& deviceExtensionNames,
        std::shared_ptr<esdw::Window> window
    );
    ~ResourceManager();

    std::optional<vk::SurfaceCapabilitiesKHR> getSurfaceCapabilities();
    std::optional<std::vector<vk::SurfaceFormatKHR>> getSurfaceFormats();

    const vk::Instance& getInstance() { return instance; }
    const vk::PhysicalDevice& getPhysicalDevice() { return physicalDevice; }
    const vk::Device& getDevice() { return device; }
    const std::optional<vk::SurfaceKHR>& getSurface() { return surface; }
    const std::optional<uint32_t> getGraphicsQueueFamily() { 
        return graphicsQueueFamily;
    }

private:
    vk::Instance instance;
    std::optional<vk::SurfaceKHR> surface;
    vk::PhysicalDevice physicalDevice;
    vk::Device device;

    std::optional<uint32_t> graphicsQueueFamily;
};