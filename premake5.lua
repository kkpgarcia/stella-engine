workspace "StellaEngine"
    architecture "x64"
	startproject "Sandbox"

    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "vendor/GLFW/include"
includeDir["SPDLOG"] = "vendor/spdlog/include"
includeDir["GLAD"] = "vendor/GLAD/include"
includeDir["imgui"] = "vendor/imgui"
includeDir["glm"] = "vendor/glm"

include "vendor/GLFW"
include "vendor/GLAD"
include "vendor/imgui"

project "StellaEngine"
    location "StellaEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "StellaPH.h"
    pchsource "src/StellaPH.cpp"
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.ini"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/%{includeDir.SPDLOG}",
        "%{includeDir.GLFW}",
        "%{includeDir.GLAD}",
        "%{includeDir.imgui}",
        "%{includeDir.glm}"
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "STELLA_PLATFORM_WINDOWS",
            "STELLA_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        filter "configurations:Debug"
            defines "STELLA_DEBUG"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines "STELLA_RELEASE"
            runtime "Release"
            optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "StellaEngine/%{includeDir.SPDLOG}",
        "StellaEngine/src",
        "/vendor",
        "%{includeDir.glm}"
    }

    links {
        "StellaEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "STELLA_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "STELLA_DEBUG"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines "STELLA_RELEASE"
            runtime "Release"
            optimize "On"