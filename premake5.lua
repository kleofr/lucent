-- premake5.lua

-- Workspace: Lucent
workspace "Lucent"
   configurations { "Debug", "Release", "Dist" }
    architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Project: lucent (shared library)
project "lucent"
    location "lucent"
    kind "sharedlib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"
    
        defines
        {
            "LCNT_PLATFORM_WINDOWS",
            "LCNT_BUILD_DLL"
        }
    
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines { "LCNT_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "LCNT_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "LCNT_DIST" }
        optimize "On"

-- Project: Sandbox (console application)
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
        "lucent/vendor/spdlog/include",
        "lucent/src"
    }

    links
    {
        "lucent"
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"
    
        defines
        {
            "LCNT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines { "LCNT_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "LCNT_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "LCNT_DIST" }
        optimize "On"