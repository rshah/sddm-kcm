include(KDE4Defaults)
include(MacroLibrary)

include_directories( 
    ${KDE4_INCLUDES}
    ${CMAKE_CURRENT_SOURCE_DIR}/cursortheme/
    ${CMAKE_CURRENT_SOURCE_DIR}/configwidgets/
)

set(SDDM_CONFIG_FILE         "/etc/sddm.conf"             CACHE PATH      "Path of the sddm config file")
    
configure_file(config.h.in config.h IMMEDIATE @ONLY)
add_subdirectory(configwidgets)

set(SDDM_KCM_SRCS
    sddmkcm.cpp
    themeconfig.cpp
    themesmodel.cpp
    thememetadata.cpp
    themesdelegate.cpp
    advanceconfig.cpp
    usersmodel.cpp
    cursortheme/thememodel.cpp
    cursortheme/legacytheme.cpp
    cursortheme/xcursortheme.cpp
    cursortheme/cursortheme.cpp
    cursortheme/sortproxymodel.cpp
    cursortheme/dummytheme.cpp
)

set(SDDM_KCM_UI
    ui/themeconfig.ui
    ui/advanceconfig.ui)

kde4_add_ui_files(SDDM_KCM_SRCS ${SDDM_KCM_UI})
kde4_add_plugin(kcm_sddm ${SDDM_KCM_SRCS})

target_link_libraries(kcm_sddm
    ${KDE4_KDEUI_LIBS}
    ${KDE4_PLASMA_LIBS}
    ${KDE4_KIO_LIBS}
    ${QT_QTUITOOLS_LIBRARY}
    ${QT_QTDECLARATIVE_LIBRARY}
    ${X11_LIBRARIES}
    sddm_config_widgets
)

if (X11_Xcursor_FOUND)
   target_link_libraries(kcm_sddm ${X11_Xcursor_LIB})
endif (X11_Xcursor_FOUND)
if (X11_Xfixes_FOUND)
   target_link_libraries(kcm_sddm ${X11_Xfixes_LIB})
endif (X11_Xfixes_FOUND)

install(TARGETS kcm_sddm DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES qml/main.qml DESTINATION ${DATA_INSTALL_DIR}/sddm-kcm)


