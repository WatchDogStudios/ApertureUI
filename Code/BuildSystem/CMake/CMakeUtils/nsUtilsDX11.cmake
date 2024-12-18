# #####################################
# ## DXVK Support
# #####################################

set(NS_BUILD_EXPERIMENTAL_DXVK OFF CACHE BOOL "Whether to emulate DX11 on Linux using DXVK-native support.")

# #####################################
# ## ns_link_target_dx11(<target>)
# #####################################

function(ns_link_target_dx11 TARGET_NAME)
	ns_requires_d3d()

	get_property(NS_DX11_LIBRARY GLOBAL PROPERTY NS_DX11_LIBRARY)

	# only execute find_package once
	if(NOT NS_DX11_LIBRARY)
	
		if(NS_CMAKE_PLATFORM_WINDOWS)
			find_package(DirectX11 REQUIRED)

			if(DirectX11_FOUND)
				set_property(GLOBAL PROPERTY NS_DX11_LIBRARY ${DirectX11_LIBRARY})
				set_property(GLOBAL PROPERTY NS_DX11_LIBRARIES ${DirectX11_D3D11_LIBRARIES})
			endif()

		elseif(NS_CMAKE_PLATFORM_LINUX AND NS_BUILD_EXPERIMENTAL_DXVK)
			pkg_search_module(DirectX11 REQUIRED dxvk-d3d11)
			pkg_search_module(DirectX11GI REQUIRED dxvk-dxgi)
			if(DirectX11_FOUND AND DirectX11GI_FOUND)
				list(APPEND allDxLibs ${DirectX11_LINK_LIBRARIES} ${DirectX11GI_LINK_LIBRARIES})
				list(APPEND allDxIncludes ${DirectX11_INCLUDE_DIRS} ${DirectX11GI_INCLUDE_DIRS})
				set_property(GLOBAL PROPERTY NS_DX11_LIBRARY "DXVK")
				set_property(GLOBAL PROPERTY NS_DX11_LIBRARIES ${allDxLibs})
				set_property(GLOBAL PROPERTY NS_DX11_INCLUDES ${allDxIncludes})
			endif()
		endif()		
	endif()

	get_property(NS_DX11_LIBRARY GLOBAL PROPERTY NS_DX11_LIBRARY)
	get_property(NS_DX11_LIBRARIES GLOBAL PROPERTY NS_DX11_LIBRARIES)

	if(${NS_DX11_LIBRARY} MATCHES "DXVK")
		# Add DXVK headers as system headers so that clang does not complain about warnings.
		get_property(NS_DX11_INCLUDES GLOBAL PROPERTY NS_DX11_INCLUDES)
		target_include_directories(${TARGET_NAME} SYSTEM PUBLIC ${NS_DX11_INCLUDES})
		target_compile_definitions(${TARGET_NAME} PUBLIC NS_USE_DXVK)
	endif()

	target_link_libraries(${TARGET_NAME}
		PRIVATE
		${NS_DX11_LIBRARIES})

	if(NS_CMAKE_ARCHITECTURE_ARM)
		if(CMAKE_SIZEOF_VOID_P EQUAL 8)
			set(DX11_COPY_DLLS_BIT "arm64")
		else()
			set(DX11_COPY_DLLS_BIT "arm")
		endif()
	else()
		if(CMAKE_SIZEOF_VOID_P EQUAL 8)
			set(DX11_COPY_DLLS_BIT "x64")
		else()
			set(DX11_COPY_DLLS_BIT "x86")
		endif()
	endif()

	# arm dll is not provided in the windows SDK.
	if(NOT NS_CMAKE_ARCHITECTURE_ARM)
		if(${NS_DX11_LIBRARY} MATCHES "/8\\.0/")
			set(DX11_COPY_DLLS_WINSDKVERSION "8.0")
			set(DX11_COPY_DLLS_DLL_VERSION "46")
		elseif(${NS_DX11_LIBRARY} MATCHES "/8\\.1/")
			set(DX11_COPY_DLLS_WINSDKVERSION "8.1")
			set(DX11_COPY_DLLS_DLL_VERSION "47")
		elseif(${NS_DX11_LIBRARY} MATCHES "/10/")
			set(DX11_COPY_DLLS_WINSDKVERSION "10")
			set(DX11_COPY_DLLS_DLL_VERSION "47")
		endif()
	endif()

	if(${DX11_COPY_DLLS_WINSDKVERSION})
		add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"%ProgramFiles(x86)%/Windows Kits/${DX11_COPY_DLLS_WINSDKVERSION}/Redist/D3D/${DX11_COPY_DLLS_BIT}/d3dcompiler_${DX11_COPY_DLLS_DLL_VERSION}.dll"
			$<TARGET_FILE_DIR:${TARGET_NAME}>
			WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		)
	endif()
endfunction()

# #####################################
# ## ns_requires_d3d()
# #####################################
macro(ns_requires_d3d)
	ns_requires_one_of(NS_CMAKE_PLATFORM_WINDOWS NS_BUILD_EXPERIMENTAL_DXVK)
endmacro()