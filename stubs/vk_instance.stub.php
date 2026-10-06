<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class VkInstance
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkPhysicalDevice
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkDevice
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkQueue
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkApplicationInfo
{
    public ?object $pNext = null;

    public ?string $pApplicationName = null;

    public int $applicationVersion = 0;

    public ?string $pEngineName = null;

    public int $engineVersion = 0;

    public int $apiVersion = 0;
}

/**
 * @not-serializable
 */
final class VkInstanceCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public ?VkApplicationInfo $pApplicationInfo = null;

    public int $enabledLayerCount = 0;

    public array $enabledLayerNames = [];

    public int $enabledExtensionCount = 0;

    public array $enabledExtensionNames = [];
}

/**
 * @not-serializable
 */
final class VkDeviceQueueCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $queueFamilyIndex = 0;

    public array $pQueuePriorities = [];
}

/**
 * @not-serializable
 */
final class VkPhysicalDeviceFeatures
{
    public bool $robustBufferAccess = false;

    public bool $fullDrawIndexUint32 = false;

    public bool $imageCubeArray = false;

    public bool $independentBlend = false;

    public bool $geometryShader = false;

    public bool $tessellationShader = false;

    public bool $sampleRateShading = false;

    public bool $dualSrcBlend = false;

    public bool $logicOp = false;

    public bool $multiDrawIndirect = false;

    public bool $drawIndirectFirstInstance = false;

    public bool $depthClamp = false;

    public bool $depthBiasClamp = false;

    public bool $fillModeNonSolid = false;

    public bool $depthBounds = false;

    public bool $wideLines = false;

    public bool $largePoints = false;

    public bool $alphaToOne = false;

    public bool $multiViewport = false;

    public bool $samplerAnisotropy = false;

    public bool $textureCompressionETC2 = false;

    public bool $textureCompressionASTC_LDR = false;

    public bool $textureCompressionBC = false;

    public bool $occlusionQueryPrecise = false;

    public bool $pipelineStatisticsQuery = false;

    public bool $vertexPipelineStoresAndAtomics = false;

    public bool $fragmentStoresAndAtomics = false;

    public bool $shaderTessellationAndGeometryPointSize = false;

    public bool $shaderImageGatherExtended = false;

    public bool $shaderStorageImageExtendedFormats = false;

    public bool $shaderStorageImageMultisample = false;

    public bool $shaderStorageImageReadWithoutFormat = false;

    public bool $shaderStorageImageWriteWithoutFormat = false;

    public bool $shaderUniformBufferArrayDynamicIndexing = false;

    public bool $shaderSampledImageArrayDynamicIndexing = false;

    public bool $shaderStorageBufferArrayDynamicIndexing = false;

    public bool $shaderStorageImageArrayDynamicIndexing = false;

    public bool $shaderClipDistance = false;

    public bool $shaderCullDistance = false;

    public bool $shaderFloat64 = false;

    public bool $shaderInt64 = false;

    public bool $shaderInt16 = false;

    public bool $shaderResourceResidency = false;

    public bool $shaderResourceMinLod = false;

    public bool $sparseBinding = false;

    public bool $sparseResidencyBuffer = false;

    public bool $sparseResidencyImage2D = false;

    public bool $sparseResidencyImage3D = false;

    public bool $sparseResidency2Samples = false;

    public bool $sparseResidency4Samples = false;

    public bool $sparseResidency8Samples = false;

    public bool $sparseResidency16Samples = false;

    public bool $sparseResidencyAliased = false;

    public bool $variableMultisampleRate = false;

    public bool $inheritedQueries = false;
}

/**
 * @not-serializable
 */
final class VkPhysicalDeviceFeatures2
{
    public ?object $pNext = null;

    public VkPhysicalDeviceFeatures $features;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkPhysicalDevicePortabilitySubsetFeaturesKHR
{
    public ?object $pNext = null;

    public bool $constantAlphaColorBlendFactors = false;

    public bool $events = false;

    public bool $imageViewFormatReinterpretation = false;

    public bool $imageViewFormatSwizzle = false;

    public bool $imageView2DOn3DImage = false;

    public bool $multisampleArrayImage = false;

    public bool $mutableComparisonSamplers = false;

    public bool $pointPolygons = false;

    public bool $samplerMipLodBias = false;

    public bool $separateStencilMaskRef = false;

    public bool $shaderSampleRateInterpolationFunctions = false;

    public bool $tessellationIsolines = false;

    public bool $tessellationPointMode = false;

    public bool $triangleFans = false;

    public bool $vertexAttributeAccessBeyondStride = false;
}

/**
 * @not-serializable
 */
final class VkDeviceCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public array $pQueueCreateInfos = [];

    public int $enabledLayerCount = 0;

    public array $enabledLayerNames = [];

    public int $enabledExtensionCount = 0;

    public array $enabledExtensionNames = [];

    public ?VkPhysicalDeviceFeatures $pEnabledFeatures = null;
}

/**
 * @not-serializable
 */
final class VkPhysicalDeviceLimits
{
    public int $maxImageDimension1D = 0;

    public int $maxImageDimension2D = 0;

    public int $maxImageDimension3D = 0;

    public int $maxImageDimensionCube = 0;

    public int $maxImageArrayLayers = 0;

    public int $maxTexelBufferElements = 0;

    public int $maxUniformBufferRange = 0;

    public int $maxStorageBufferRange = 0;

    public int $maxPushConstantsSize = 0;

    public int $maxMemoryAllocationCount = 0;

    public int $maxSamplerAllocationCount = 0;

    public int $bufferImageGranularity = 0;

    public int $sparseAddressSpaceSize = 0;

    public int $maxBoundDescriptorSets = 0;

    public int $maxPerStageDescriptorSamplers = 0;

    public int $maxPerStageDescriptorUniformBuffers = 0;

    public int $maxPerStageDescriptorStorageBuffers = 0;

    public int $maxPerStageDescriptorSampledImages = 0;

    public int $maxPerStageDescriptorStorageImages = 0;

    public int $maxPerStageDescriptorInputAttachments = 0;

    public int $maxPerStageResources = 0;

    public int $maxDescriptorSetSamplers = 0;

    public int $maxDescriptorSetUniformBuffers = 0;

    public int $maxDescriptorSetUniformBuffersDynamic = 0;

    public int $maxDescriptorSetStorageBuffers = 0;

    public int $maxDescriptorSetStorageBuffersDynamic = 0;

    public int $maxDescriptorSetSampledImages = 0;

    public int $maxDescriptorSetStorageImages = 0;

    public int $maxDescriptorSetInputAttachments = 0;

    public int $maxVertexInputAttributes = 0;

    public int $maxVertexInputBindings = 0;

    public int $maxVertexInputAttributeOffset = 0;

    public int $maxVertexInputBindingStride = 0;

    public int $maxVertexOutputComponents = 0;

    public int $maxTessellationGenerationLevel = 0;

    public int $maxTessellationPatchSize = 0;

    public int $maxTessellationControlPerVertexInputComponents = 0;

    public int $maxTessellationControlPerVertexOutputComponents = 0;

    public int $maxTessellationControlPerPatchOutputComponents = 0;

    public int $maxTessellationControlTotalOutputComponents = 0;

    public int $maxTessellationEvaluationInputComponents = 0;

    public int $maxTessellationEvaluationOutputComponents = 0;

    public int $maxGeometryShaderInvocations = 0;

    public int $maxGeometryInputComponents = 0;

    public int $maxGeometryOutputComponents = 0;

    public int $maxGeometryOutputVertices = 0;

    public int $maxGeometryTotalOutputComponents = 0;

    public int $maxFragmentInputComponents = 0;

    public int $maxFragmentOutputAttachments = 0;

    public int $maxFragmentDualSrcAttachments = 0;

    public int $maxFragmentCombinedOutputResources = 0;

    public int $maxComputeSharedMemorySize = 0;

    public array $maxComputeWorkGroupCount = [];

    public int $maxComputeWorkGroupInvocations = 0;

    public array $maxComputeWorkGroupSize = [];

    public int $subPixelPrecisionBits = 0;

    public int $subTexelPrecisionBits = 0;

    public int $mipmapPrecisionBits = 0;

    public int $maxDrawIndexedIndexValue = 0;

    public int $maxDrawIndirectCount = 0;

    public float $maxSamplerLodBias = 0.0;

    public float $maxSamplerAnisotropy = 0.0;

    public int $maxViewports = 0;

    public array $maxViewportDimensions = [];

    public array $viewportBoundsRange = [];

    public int $viewportSubPixelBits = 0;

    public int $minMemoryMapAlignment = 0;

    public int $minTexelBufferOffsetAlignment = 0;

    public int $minUniformBufferOffsetAlignment = 0;

    public int $minStorageBufferOffsetAlignment = 0;

    public int $minTexelOffset = 0;

    public int $maxTexelOffset = 0;

    public int $minTexelGatherOffset = 0;

    public int $maxTexelGatherOffset = 0;

    public float $minInterpolationOffset = 0.0;

    public float $maxInterpolationOffset = 0.0;

    public int $subPixelInterpolationOffsetBits = 0;

    public int $maxFramebufferWidth = 0;

    public int $maxFramebufferHeight = 0;

    public int $maxFramebufferLayers = 0;

    public int $framebufferColorSampleCounts = 0;

    public int $framebufferDepthSampleCounts = 0;

    public int $framebufferStencilSampleCounts = 0;

    public int $framebufferNoAttachmentsSampleCounts = 0;

    public int $maxColorAttachments = 0;

    public int $sampledImageColorSampleCounts = 0;

    public int $sampledImageIntegerSampleCounts = 0;

    public int $sampledImageDepthSampleCounts = 0;

    public int $sampledImageStencilSampleCounts = 0;

    public int $storageImageSampleCounts = 0;

    public int $maxSampleMaskWords = 0;

    public bool $timestampComputeAndGraphics = false;

    public float $timestampPeriod = 0.0;

    public int $maxClipDistances = 0;

    public int $maxCullDistances = 0;

    public int $maxCombinedClipAndCullDistances = 0;

    public int $discreteQueuePriorities = 0;

    public array $pointSizeRange = [];

    public array $lineWidthRange = [];

    public float $pointSizeGranularity = 0.0;

    public float $lineWidthGranularity = 0.0;

    public bool $strictLines = false;

    public bool $standardSampleLocations = false;

    public int $optimalBufferCopyOffsetAlignment = 0;

    public int $optimalBufferCopyRowPitchAlignment = 0;

    public int $nonCoherentAtomSize = 0;
}

/**
 * @not-serializable
 */
final class VkPhysicalDeviceSparseProperties
{
    public bool $residencyStandard2DBlockShape = false;

    public bool $residencyStandard2DMultisampleBlockShape = false;

    public bool $residencyStandard3DBlockShape = false;

    public bool $residencyAlignedMipSize = false;

    public bool $residencyNonResidentStrict = false;
}

/**
 * @not-serializable
 */
final class VkPhysicalDeviceProperties
{
    public int $apiVersion = 0;

    public int $driverVersion = 0;

    public int $vendorID = 0;

    public int $deviceID = 0;

    public int $deviceType = 0;

    public string $deviceName = '';

    public string $pipelineCacheUUID = '';

    public VkPhysicalDeviceLimits $limits;

    public VkPhysicalDeviceSparseProperties $sparseProperties;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkExtent3D
{
    public int $width = 0;

    public int $height = 0;

    public int $depth = 0;
}

/**
 * @not-serializable
 */
final class VkQueueFamilyProperties
{
    public int $queueFlags = 0;

    public int $queueCount = 0;

    public int $timestampValidBits = 0;

    public VkExtent3D $minImageTransferGranularity;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkMemoryType
{
    public int $propertyFlags = 0;

    public int $heapIndex = 0;
}

/**
 * @not-serializable
 */
final class VkMemoryHeap
{
    public int $size = 0;

    public int $flags = 0;
}

/**
 * @not-serializable
 */
final class VkPhysicalDeviceMemoryProperties
{
    public array $memoryTypes = [];

    public array $memoryHeaps = [];
}

/**
 * @not-serializable
 */
final class VkFormatProperties
{
    public int $linearTilingFeatures = 0;

    public int $optimalTilingFeatures = 0;

    public int $bufferFeatures = 0;
}

/**
 * @not-serializable
 */
final class VkExtensionProperties
{
    public string $extensionName = '';

    public int $specVersion = 0;
}

function vkCreateInstance(VkInstanceCreateInfo $pCreateInfo, null $pAllocator, ?VkInstance &$pInstance): int {}

function vkDestroyInstance(VkInstance $instance, null $pAllocator): void {}

function vkEnumerateInstanceExtensionProperties(?string $pLayerName, ?array &$pProperties): int {}

function vkEnumeratePhysicalDevices(VkInstance $instance, ?array &$pPhysicalDevices): int {}

function vkGetPhysicalDeviceProperties(VkPhysicalDevice $physicalDevice, ?VkPhysicalDeviceProperties &$pProperties): void {}

function vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice $physicalDevice, ?array &$pQueueFamilyProperties): void {}

function vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice $physicalDevice, ?VkPhysicalDeviceMemoryProperties &$pMemoryProperties): void {}

function vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice $physicalDevice, int $format, ?VkFormatProperties &$pFormatProperties): void {}

function vkEnumerateDeviceExtensionProperties(VkPhysicalDevice $physicalDevice, ?string $pLayerName, ?array &$pProperties): int {}

function vkCreateDevice(VkPhysicalDevice $physicalDevice, VkDeviceCreateInfo $pCreateInfo, null $pAllocator, ?VkDevice &$pDevice): int {}

function vkDestroyDevice(VkDevice $device, null $pAllocator): void {}

function vkGetDeviceQueue(VkDevice $device, int $queueFamilyIndex, int $queueIndex, ?VkQueue &$pQueue): void {}

function vkDeviceWaitIdle(VkDevice $device): int {}

function vkGetPhysicalDeviceFeatures2(VkPhysicalDevice $physicalDevice, VkPhysicalDeviceFeatures2 $pFeatures): void {}

