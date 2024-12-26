workspace "Aora"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	toolset "v143"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Aora/vendor/GLFW/include"

include "Aora/vendor/GLFW"

project "Aora"
	location "Aora"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "aopch.h"
	pchsource "Aora/src/aopch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
		
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{prj.name}/vendor/glm",
		os.getenv("VULKAN_SDK") .. "/Include"
	}

	libdirs
	{
		os.getenv("VULKAN_SDK") .. "/Lib"
	}

	links
	{
		"GLFW",
		"vulkan-1",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AO_PLATFORM_WINDOWS",
			"AO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AO_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/Events/**.h",
        "%{prj.name}/src/Events/**.cpp",
        "%{prj.name}/Platform/Windows/**.h",
        "%{prj.name}/Platform/Windows/**.cpp"
	}

	includedirs
	{
		"Aora/vendor/spdlog/include",
		"Aora/src",
		"Aora/vendor/glm",
		os.getenv("VULKAN_SDK") .. "/Include"
	}

	libdirs
	{
		os.getenv("VULKAN_SDK") .. "/Lib"
	}

	links
	{
		"Aora"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AO_DIST"
		runtime "Release"
		optimize "On"