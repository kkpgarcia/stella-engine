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

include "vendor/GLFW"
include "vendor/GLAD"
include "vendor/imgui"

project "StellaEngine"
    location "StellaEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "StellaPH.h"
    pchsource "src/StellaPH.cpp"
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/%{includeDir.SPDLOG}",
        "%{includeDir.GLFW}",
        "%{includeDir.GLAD}",
        "%{includeDir.imgui}"
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "STELLA_PLATFORM_WINDOWS",
            "STELLA_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines {
                "STELLA_DEBUG",
                "STELLA_ENABLE_ASSERTS"
            }
            symbols "On"

        filter "configurations:Release"
            defines "STELLA_RELEASE"
            optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"  
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "StellaEngine/%{includeDir.SPDLOG}",
        "StellaEngine/src"
    }

    links {
        "StellaEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "STELLA_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines {
                "STELLA_DEBUG",
                "STELLA_ENABLE_ASSERTS"
            }
            symbols "On"

        filter "configurations:Release"
            defines "STELLA_RELEASE"
            optimize "On"