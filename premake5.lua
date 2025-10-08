workspace "Spark"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Spark/vendor/GLFW/include"
IncludeDir["Glad"] = "Spark/vendor/Glad/include"
IncludeDir["ImGui"] = "Spark/vendor/imgui"
IncludeDir["glm"] = "Spark/vendor/glm"


group "Dependencies"
	include "Spark/vendor/GLFW"
	include "Spark/vendor/Glad"
	include "Spark/vendor/imgui"

group ""

project "Spark"
	location "Spark"
	kind "StaticLib"
	language "C++"
	
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "skpch.h"
	pchsource "Spark/src/skpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SK_PLATFORM_WINDOWS",
			"SK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "SK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SK_DIST"
		runtime "Release"
		optimize "on"

    --filter "toolset:msc*"
       --buildoptions { "/utf-8" }

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Spark/vendor/spdlog/include",
		"Spark/src",
		"Spark/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Spark"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SK_DIST"
		runtime "Release"
		optimize "on"

	--filter "toolset:msc*"
		--buildoptions { "/utf-8" }