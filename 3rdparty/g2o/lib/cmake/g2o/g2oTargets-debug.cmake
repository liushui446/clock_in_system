#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "g2o::freeglut_minimal" for configuration "Debug"
set_property(TARGET g2o::freeglut_minimal APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::freeglut_minimal PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_ext_freeglut_minimal_d.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_ext_freeglut_minimal_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::freeglut_minimal )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::freeglut_minimal "${_IMPORT_PREFIX}/lib/g2o_ext_freeglut_minimal_d.lib" "${_IMPORT_PREFIX}/bin/g2o_ext_freeglut_minimal_d.dll" )

# Import target "g2o::stuff" for configuration "Debug"
set_property(TARGET g2o::stuff APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::stuff PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_stuff_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_stuff_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::stuff )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::stuff "${_IMPORT_PREFIX}/lib/g2o_stuff_d.lib" "${_IMPORT_PREFIX}/bin/g2o_stuff_d.dll" )

# Import target "g2o::opengl_helper" for configuration "Debug"
set_property(TARGET g2o::opengl_helper APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::opengl_helper PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_opengl_helper_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "OpenGL::GL;OpenGL::GLU"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_opengl_helper_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::opengl_helper )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::opengl_helper "${_IMPORT_PREFIX}/lib/g2o_opengl_helper_d.lib" "${_IMPORT_PREFIX}/bin/g2o_opengl_helper_d.dll" )

# Import target "g2o::core" for configuration "Debug"
set_property(TARGET g2o::core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::core PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_core_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::stuff"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_core_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::core )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::core "${_IMPORT_PREFIX}/lib/g2o_core_d.lib" "${_IMPORT_PREFIX}/bin/g2o_core_d.dll" )

# Import target "g2o::g2o_cli_library" for configuration "Debug"
set_property(TARGET g2o::g2o_cli_library APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_cli_library PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_cli_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_cli_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_cli_library )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_cli_library "${_IMPORT_PREFIX}/lib/g2o_cli_d.lib" "${_IMPORT_PREFIX}/bin/g2o_cli_d.dll" )

# Import target "g2o::g2o_cli_application" for configuration "Debug"
set_property(TARGET g2o::g2o_cli_application APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_cli_application PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_cli_application )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_cli_application "${_IMPORT_PREFIX}/bin/g2o.exe" )

# Import target "g2o::g2o_hierarchical_library" for configuration "Debug"
set_property(TARGET g2o::g2o_hierarchical_library APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_hierarchical_library PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_hierarchical_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_hierarchical_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_hierarchical_library )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_hierarchical_library "${_IMPORT_PREFIX}/lib/g2o_hierarchical_d.lib" "${_IMPORT_PREFIX}/bin/g2o_hierarchical_d.dll" )

# Import target "g2o::g2o_simulator_library" for configuration "Debug"
set_property(TARGET g2o::g2o_simulator_library APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_simulator_library PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_simulator_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::types_slam3d_addons;g2o::types_slam3d;g2o::types_slam2d_addons;g2o::types_slam2d;g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_simulator_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_simulator_library )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_simulator_library "${_IMPORT_PREFIX}/lib/g2o_simulator_d.lib" "${_IMPORT_PREFIX}/bin/g2o_simulator_d.dll" )

# Import target "g2o::g2o_simulator2d_application" for configuration "Debug"
set_property(TARGET g2o::g2o_simulator2d_application APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_simulator2d_application PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_simulator2d.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_simulator2d_application )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_simulator2d_application "${_IMPORT_PREFIX}/bin/g2o_simulator2d.exe" )

# Import target "g2o::g2o_simulator3d_application" for configuration "Debug"
set_property(TARGET g2o::g2o_simulator3d_application APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_simulator3d_application PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_simulator3d.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_simulator3d_application )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_simulator3d_application "${_IMPORT_PREFIX}/bin/g2o_simulator3d.exe" )

# Import target "g2o::g2o_anonymize_observations_application" for configuration "Debug"
set_property(TARGET g2o::g2o_anonymize_observations_application APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::g2o_anonymize_observations_application PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_anonymize_observations.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::g2o_anonymize_observations_application )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::g2o_anonymize_observations_application "${_IMPORT_PREFIX}/bin/g2o_anonymize_observations.exe" )

# Import target "g2o::types_data" for configuration "Debug"
set_property(TARGET g2o::types_data APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_data PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_data_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core;g2o::types_slam2d;g2o::freeglut_minimal;g2o::opengl_helper"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_data_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_data )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_data "${_IMPORT_PREFIX}/lib/g2o_types_data_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_data_d.dll" )

# Import target "g2o::types_slam2d" for configuration "Debug"
set_property(TARGET g2o::types_slam2d APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_slam2d PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_slam2d_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core;g2o::opengl_helper;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_slam2d_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_slam2d )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_slam2d "${_IMPORT_PREFIX}/lib/g2o_types_slam2d_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_slam2d_d.dll" )

# Import target "g2o::types_slam3d" for configuration "Debug"
set_property(TARGET g2o::types_slam3d APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_slam3d PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_slam3d_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core;g2o::opengl_helper;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_slam3d_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_slam3d )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_slam3d "${_IMPORT_PREFIX}/lib/g2o_types_slam3d_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_slam3d_d.dll" )

# Import target "g2o::types_sba" for configuration "Debug"
set_property(TARGET g2o::types_sba APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_sba PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_sba_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core;g2o::types_slam3d"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_sba_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_sba )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_sba "${_IMPORT_PREFIX}/lib/g2o_types_sba_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_sba_d.dll" )

# Import target "g2o::types_sim3" for configuration "Debug"
set_property(TARGET g2o::types_sim3 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_sim3 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_sim3_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::types_sba"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_sim3_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_sim3 )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_sim3 "${_IMPORT_PREFIX}/lib/g2o_types_sim3_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_sim3_d.dll" )

# Import target "g2o::types_icp" for configuration "Debug"
set_property(TARGET g2o::types_icp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_icp PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_icp_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::types_sba;g2o::types_slam3d"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_icp_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_icp )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_icp "${_IMPORT_PREFIX}/lib/g2o_types_icp_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_icp_d.dll" )

# Import target "g2o::types_sclam2d" for configuration "Debug"
set_property(TARGET g2o::types_sclam2d APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_sclam2d PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_sclam2d_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::types_slam2d;g2o::core;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_sclam2d_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_sclam2d )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_sclam2d "${_IMPORT_PREFIX}/lib/g2o_types_sclam2d_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_sclam2d_d.dll" )

# Import target "g2o::types_slam2d_addons" for configuration "Debug"
set_property(TARGET g2o::types_slam2d_addons APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_slam2d_addons PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_slam2d_addons_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::types_slam2d;g2o::core;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_slam2d_addons_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_slam2d_addons )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_slam2d_addons "${_IMPORT_PREFIX}/lib/g2o_types_slam2d_addons_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_slam2d_addons_d.dll" )

# Import target "g2o::types_slam3d_addons" for configuration "Debug"
set_property(TARGET g2o::types_slam3d_addons APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::types_slam3d_addons PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_types_slam3d_addons_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::types_slam3d;g2o::core;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_types_slam3d_addons_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::types_slam3d_addons )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::types_slam3d_addons "${_IMPORT_PREFIX}/lib/g2o_types_slam3d_addons_d.lib" "${_IMPORT_PREFIX}/bin/g2o_types_slam3d_addons_d.dll" )

# Import target "g2o::solver_pcg" for configuration "Debug"
set_property(TARGET g2o::solver_pcg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_pcg PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_solver_pcg_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_solver_pcg_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::solver_pcg )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::solver_pcg "${_IMPORT_PREFIX}/lib/g2o_solver_pcg_d.lib" "${_IMPORT_PREFIX}/bin/g2o_solver_pcg_d.dll" )

# Import target "g2o::solver_dense" for configuration "Debug"
set_property(TARGET g2o::solver_dense APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_dense PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_solver_dense_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_solver_dense_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::solver_dense )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::solver_dense "${_IMPORT_PREFIX}/lib/g2o_solver_dense_d.lib" "${_IMPORT_PREFIX}/bin/g2o_solver_dense_d.dll" )

# Import target "g2o::solver_structure_only" for configuration "Debug"
set_property(TARGET g2o::solver_structure_only APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_structure_only PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_solver_structure_only_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_solver_structure_only_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::solver_structure_only )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::solver_structure_only "${_IMPORT_PREFIX}/lib/g2o_solver_structure_only_d.lib" "${_IMPORT_PREFIX}/bin/g2o_solver_structure_only_d.dll" )

# Import target "g2o::solver_eigen" for configuration "Debug"
set_property(TARGET g2o::solver_eigen APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_eigen PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/g2o_solver_eigen_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "g2o::core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/g2o_solver_eigen_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS g2o::solver_eigen )
list(APPEND _IMPORT_CHECK_FILES_FOR_g2o::solver_eigen "${_IMPORT_PREFIX}/lib/g2o_solver_eigen_d.lib" "${_IMPORT_PREFIX}/bin/g2o_solver_eigen_d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
