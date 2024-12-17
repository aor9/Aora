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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Aora/vendor/spdlog/include",
		"Aora/src"
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
		symbols "On"

	filter "configurations:Release"
		defines "AO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AO_DIST"
		optimize "On"