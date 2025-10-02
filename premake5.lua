workspace "Spark"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Spark"
	location "Spark"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"SK_PLATFORM_WINDOWS",
			"SK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SK_DIST"
		optimize "On"

	--filter {"system:windows","configurations:Debug","configurations:Release","configurations:Dist"}
		--buildoptions "/utf-8"
		-- 为MSVC编译器添加/utf-8选项
    filter "toolset:msc*"
       buildoptions { "/utf-8" }

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
	}

	includedirs
	{
		"Spark/vendor/spdlog/include",
		"Spark/src"
	}

	links
	{
		"Spark"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"SK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SK_DIST"
		optimize "On"

	--filter {"system:windows","configurations:Debug","configurations:Release","configurations:Dist"}
		--buildoptions "/utf-8"
		-- 为MSVC编译器添加/utf-8选项
	filter "toolset:msc*"
		buildoptions { "/utf-8" }