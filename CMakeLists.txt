cmake_minimum_required(VERSION 3.16)
project(PixeloramaThumbnailer)

set(CMAKE_CXX_STANDARD 17)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDEFrameworkCompilerSettings)
find_package(KF6 REQUIRED COMPONENTS KIO Archive)

add_library(pixeloramathumbnailer MODULE pixeloramathumbnailer.cpp)
target_link_libraries(pixeloramathumbnailer KF6::KIOWidgets KF6::Archive)

install(TARGETS pixeloramathumbnailer DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf6/thumbcreator)
install(FILES pixeloramathumbnailer.json DESTINATION ${KDE_INSTALL_METAINFODIR})
